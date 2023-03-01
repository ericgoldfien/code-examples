// euler39.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler #39 https://projecteuler.net/problem=39

#include <iostream>
#include <vector>

using namespace std;

//Calculate how many unique right triangles have a perimeter of n
int numRightTris(int n) {
	int c;
	int count = 0;
	for (int a = 1; a < n; a++) {
		for (int b = a; a + b < n; b++) {
			c = n - a - b;
			if ((a * a) + (b * b) == (c * c)) count++;
		}
	}

	return count;
}


int main()
{
	vector<int> res(1000, 0);

	//calculate and store number of triangles for perimeter length 5 through 1000
	for (int i = 5; i < 1000; i++) {
		res[i] = numRightTris(i);
	}

	int ans = 0;
	int max = 0;
	//find the index with the largest value and save the index
	for (int i = 0; i < res.size(); i++) {
		if (res[i] > max) {
			max = res[i];
			ans = i;
		}
	}


	cout << ans << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu