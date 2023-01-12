/**
	@file hw9.cpp
	@author Eric Goldfien
	@date August 12, 2014
	@brief This is my submission for hw8, all classes and main are 
	contained in this file.  The program asks the user for some input
	and then puts whatever was input into a linked list (in this case it's
	ints but the list class is templated and can take any well defined
	type), it then displays the list and lets the user input more data
	into any spot of the list.  It then downsizes the list, reverses it
	then sorts it.  Another list is created and then merged with the sorted
	list.  This program was created off the textbook example in chapter 12
	by templating the textbooks class and adding functions to the list class,
	the node and iterator classes are from the book just templated and 
	iterator has ++, -- and == operators added.  I was a bit confused
	as to wether sort should be a member function or not, I made it one
	as it needs access to lots of private variables and it made more
	sense that way.
*/

#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

//Declare classes and functions
template <typename T> class Node;
template <typename T> class List;
template <typename T> class Iterator;
template<typename T>
void downsize(List<T>& names);
template<typename T>
T maximum(List<T>& list);
template<typename T>
List<T> merge(List<T> a,List<T> b);

//Declare values 
int x;
size_t index;
int value;


//************************************************************************************************************************************************
/**
	@class Node<T>
	@brief holds an object and a pointer to a previous and next node
*/
template<typename T>
class Node
{
public:
	//Constructor:

	/**One parameter constructor
		@param t is the object to be added to the node
	*/
	Node(T t)
	{
		data = t;
		previous = nullptr;
		next = nullptr;
	}

private:
	T data;
	Node<T>* previous;
	Node<T>* next;

	friend class List<T>;
	friend class Iterator<T>;
};
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**
	@class List<T>
	@brief holds pointers to the first and last nodes of a list and has a size member
*/
template<typename T>
class List
{
public:
	//Constructor:	
	
	/**Initializes the first and last to nullptr and size to 0*/
	List()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}


	//Mutators:

	/**Adds a node to the back of the list and increments size
		@param data is the object to be stored in the node
	*/
	void push_back(T data)
	{
		Node<T>* new_node = new Node<T>(data);

		if (last == nullptr){ //List is empty
			first = new_node;
			last = new_node;
		}
		else{
			new_node->previous = last; //set the previous pointer to the old last of the list
			last->next = new_node; //set the old last's next pointer to new node
			last = new_node; //set the new last to what was pushed back
		}

		size++;
		return;
	}


	/**Adds a node to the front of the list and increments size
		@param data is the object to be stored in the node
	*/
	void push_front(T data)
	{
		if (first == nullptr) push_back(data); //if empty just push_back
		else{
			Node<T>* new_node = new Node<T>(data);
			first->previous = new_node;
			new_node->next = first;
			first = new_node;
			size++;	
		}

		return;
	}


	/**Reverses the entries of the list*/
	void reverse()
	{
		for (size_t i = 0; i < get_size(); i++){
			Iterator<T> posb = end(); //get last entry
			--posb;
			Iterator<T> posf = begin();
			for (size_t j = 0; j < i; j++){
				if(j < get_size() - 1) ++posf;
			}
			insert(posf, posb.get()); //insert last entry in the right spot based on for loop
			erase(posb); //erase last entry
		}
		return;
	}


	/**Inserts a node at the position of a passed in iterator and increments size
		@param iter is the iterator with the position of the new node
		@param t is the object the new node will store
	*/
	void insert(Iterator<T> iter, T t)
	{
		if (iter.position == nullptr){ //inserting into an empty list or end of list
			push_back(t);
			return;
		}

		Node<T>* after = iter.position;
		Node<T>* before = after->previous;
		Node<T>* new_node = new Node<T>(t);
		new_node->previous = before;
		new_node->next = after;
		after->previous = new_node;
		
		if (before == nullptr) first = new_node; //insert at beginning
		else before->next = new_node;

		size++;
		return;
	}


	/**Insert a node at a given indes
		@param index is the index to insert at
		@param value is the object to be stored in the node at that index
	*/
	void insertAt(size_t index, T value)
	{
		if (index >= get_size()) push_back(value); //if bigger than the list than just push_back
		else if (index == 0) push_front(value); //if index == 0 push_front
		else{
			Iterator<T> pos; //start at the front iterate index times then insert
			pos = begin();
			for (size_t i = 0; i < index; i++){
				++pos;
			}
			insert(pos, value);
		}
		return;
	}


	/**Erases the node at the iterators position and decrement size
		@param iter is the iterator who's position is to be erased
		@return r is an iterator pointing to the node after the node to be erased
	*/
	Iterator<T> erase(Iterator<T> iter)
	{
		assert(iter.position != nullptr);
		Node<T>* remove = iter.position;
		Node<T>* before = remove->previous;
		Node<T>* after = remove->next;

		if (remove == first) first = after;
		else before->next = after;

		if (remove == last) last = before;
		else after->previous = before;

		size--;
		Iterator<T> r;
		r.position = after;
		r.container = this;
		delete remove;
		
		return r;
	}


	/**Uses selection sort to sort list from smallest to biggest*/
	void sort()
	{
		Iterator<T> a;
		Iterator<T> b;
		Iterator<T> c;
		
		for (a = begin(); !(a == end()); ++a){
			T temp = a.get();
			T temp2 = a.get();
			c = a;
			for (b = a; !(b == end()); ++b){
				if (b.get() <= temp){ //find smallest remaining entry
					temp = b.get();
					c = b; //set c = to the smallest entry
				}
			}
			a.position->data = c.get(); //swap the first non set entry with the smallest remaining
			c.position->data = temp2;
		}
		return;
	}


	/**Swaps the entries in other and the calling list
		@param other is the list to swap entries with
	*/
	void swap(List<T>& other)
	{
		Iterator<T> apos = begin();
		Iterator<T> opos = other.begin();
		size_t s;

		if (get_size() < other.get_size()) s = get_size(); //find the smaller list
		else s = other.get_size();

		for (size_t i = 0; i < s; i++){ //swap the entries up to the size of the smaller list
			T temp = apos.get();
			apos.position->data = opos.get();
			opos.position->data = temp;
			apos++;
			opos++;
		}
		return;
	}


	//Accesors:
	
	/**Prints out the list in the correct (a,b,c) format*/
	void print() 
	{
		Iterator<int> pos;
		cout << "(";
		for (pos = begin(); !(pos == end()); ++pos){
			if (++pos == end()){
				--pos;
				cout << pos.get() << ")";
			}
			else{
				--pos;
				cout << pos.get() << ",";
			}
		}
		return;
	}


	/**Sets an iterator to the beginning of the list
		@return iter is an iterator pointing to the first entry of the list
	*/
	Iterator<T> begin()
	{
		Iterator<T> iter;
		iter.position = first;
		iter.container = this;
		return iter;
	}


	/**Sets an iterator to the end of the list
		@return iter is
	*/
	Iterator<T> end()
	{
		Iterator<T> iter;
		iter.position = nullptr;
		iter.container = this;
		return iter;
	}


	/**Returns the size of the list
		@return size is the size of the list
	*/
	size_t get_size(){ return size; }

private:
	Node<T>* first;
	Node<T>* last;
	size_t size;

	friend class Iterator<T>;
};
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**
	@class Iterator<T>
	@brief iterator object for a templated linked list, contains a pointer to the list
	it's iterating through and the current node
*/
template<typename T>
class Iterator
{
public:
	//Constructor:

	/**Sets the list and node its pointing to nullptr*/
	Iterator()
	{
		position = nullptr;
		container = nullptr;
	}


	//Accessors:

	/**Gets the data from the node being pointed to
		@return position->data is the object the pointed to node is storing
	*/
	T get()
	{
		assert(position != nullptr); //if position exists
		return position->data; // return the T from the node
	}


	/**Checks if two iterators are pointing to the same node
		@param b is the iterator the calling iterator is compared to
		@return position==b.position is the result of whether the node of the calling 
		iterator is equal to the node of b
	*/
	bool equals(Iterator<T> b) const
	{
		return position == b.position;
	}


	//Mutators:

	/**Goes to the next node in the list*/
	void next()
	{
		assert(position != nullptr); //if position exists
		position = position->next; //go to the next node from the given node
	}


	/**Overloads pre-fix ++ using next()
		@return *this is the iterator it was called on pointing to the next node
	*/
	Iterator<T>& operator++(){
		next();
		return *this;
	}


	/**Overloads post-fix ++ using next()
		@param i is an unused int
		@return copy is the calling iterator before being incremented
	*/
	Iterator<T> operator++(int i){
		Iterator<T> copy = *this;
		++(*this);
		return copy;
	}


	/**Goes to the previous node in the list*/
	void previous()
	{
		assert(position != container->first); //not the first object in the list
		if (position == nullptr) position = container->last; //if position is empty go to the last in the list
		else position = position->previous; //go to the previous node from the given node
	}


	/**Overloads the pre-fix -- operator using previous()
		@return *this is the calling iterator after being decremented
	*/
	Iterator<T>& operator--(){
		previous();
		return *this;
	}


	/**Overloads the post-fix -- operator using previous()
		@param i is an unused int
		@return copy is the calling iterator before being decremented
	*/
	Iterator<T> operator--(int i){
		Iterator<T> copy = *this;
		--(*this);
		return copy;
	}

private:
	Node<T>* position;
	List<T>* container;

	friend class List<T>;
};	


/**Overloads the == operator using equals(Iterator<T> b)
	@param a is the iterator to the left of the ==
	@param b is the iterator to the right of the ==
	@return a.equals(b) is the result returned from member function equals
*/
template<typename T>
bool operator==(Iterator<T> a, Iterator<T> b)
	{
		return a.equals(b);
	}
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**Creates the output as described in the assignment*/
int main()
{
	//Prompt the user for input
	cout << "Please input a set of nonnegative numbers for a list (Enter -1 when you are" << endl
		 << "finished): " << endl;

	//Create an integer list and then input values
	List<int> list;
	while (x != -1){
		cin >> x;
		if (x != -1) list.push_back(x);
	}

	//Display the list
	cout << "Your list is" << endl;
	list.print();
	cout << endl << endl;

	//Ask the user to input more values at specified indices
	while (index != -1){
		cout << "Select an index for insertion (enter -1 when finished:  ";
		cin >> index;
		if (index != -1){
			cout << "Select a value for insertion:  ";
			cin >> value;
			list.insertAt(index, value);
		}
	}

	//Display the list with additions
	cout << endl << "The augmented list is" << endl;
	list.print();
	cout << endl << endl;

	//Find the maximum and size of the list and display them
	cout << "The maximum of the List is:  " << maximum(list) << endl;
	cout << "The size of your List is:  " << list.get_size() << endl;

	//Downsize and display the list
	cout << "When we remove every second value from the list we are left with" << endl;
	downsize(list); list.print();

	//Sort the downsized list and display it
	cout << endl << "When we sort this downsized list we obtain" << endl;
	list.sort(); list.print();

	//Reverse the sorted list and display it
	cout << endl << "And this sorted list in reverse order is" << endl;
	list.reverse(); list.print(); 
	
	//Create a second list
	List<int> extra;
	extra.push_back(2); extra.push_back(3);
	extra.push_back(5); extra.push_back(7);
	extra.push_back(11);
	
	//Merge the user created list and the second list
	cout << endl << "If we merge this list with the list (2,3,5,7,11) we obtain" << endl;
	merge(list, extra).print(); cout << endl;

	return 0;
}
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**Deletes every other object in a list
	@param names is the list to be downsized
*/
template<typename T>
void downsize(List<T>& names){
	Iterator<T> pos;
	pos = names.begin();
	++pos;
	while (!(pos == names.end())){
		pos = names.erase(pos);
		if (!(pos == names.end())) ++pos;
	}
	return;
}
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**Finds and returns the largest object in the list
	@param list is the list we want to find the max of
	@return max is the largest object in the list
*/
template<typename T>
T maximum(List<T>& list)
{
	Iterator<int> pos;
	pos = list.begin();
	T max = pos.get();

	for (pos = list.begin(); !(pos == list.end()); ++pos){
		if (pos.get() > max) max = pos.get();
	}
	return max;
}
//************************************************************************************************************************************************



//************************************************************************************************************************************************
/**Creates a new list from merging two lists
	@param a is the first list
	@param b is the second list
	@return merged is the new list created by merging a and b
*/
template<typename T>
List<T> merge(List<T> a,List<T> b)
{
	List<T> merged;
	int flag = 0;
	size_t size;

	Iterator<T> apos = a.begin();
	Iterator<T> bpos = b.begin();

	if (a.get_size() < b.get_size()){ //find which list is smaller
		size = a.get_size();
	}
	else{
		size = b.get_size();
		flag = 1;
	}

	for (size_t i = 0; i < size; i++){ //up until the size of the smaller list add object from a then b
		merged.push_back(apos.get());
		merged.push_back(bpos.get());
		apos++;
		bpos++;
	}

	if (flag == 0){ //after all elements from smaller list added push_back the rest of the bigger list
		for (size_t i = size; i < b.get_size(); i++){
			merged.push_back(bpos.get());
			bpos++;
		}
	}
	else{
		for (size_t i = size; i < a.get_size(); i++){
			merged.push_back(apos.get());
			apos++;
		}
	}

	return merged;
}
//************************************************************************************************************************************************