// euler35.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 35 https://projecteuler.net/problem=35

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//find all the primes under a given size using a sieve method
void findPrimes(vector<bool>& primes) {
    for (int i = 4; i < primes.size(); i += 2) primes[i] = false;
    int ceil = floor(sqrt(primes.size()));
    for (int p = 3; p < ceil; p += 2) {
        if (primes[p] == true) {
            for (int j = p * p; j < primes.size(); j += 2 * p) primes[j] = false;
        }
    }

    return;
}


//function to rotate an integer n once by moving the leading digit to the end
int rotate(int n) {
    string temp = to_string(n);
    temp = temp + temp[0];
    temp.erase(temp.begin(), temp.begin() + 1);
    return stoi(temp);
}


//Function to check if a number is a circular prime, if the number is circular
//it is added to the set of circular primes passed by reference as well as
//all its rotations
void isCircular(int n, set<int>& circulars, vector<bool>& primes) {
    vector<int> temp = { n };
    //if not a prime number return
    if (!primes[n]) return;
    //if n is a rotation of a previous circular number no need to continue return
    else if (circulars.count(n) != 0) return;
    else {
        for (int i = 0; i < to_string(n).length()-1; i++) {
            //this line checks if there is a 0 in any of the digits
            if (to_string(n).length() != to_string(rotate(n)).length()) return;
            else n = rotate(n);

            if (!primes[n]) return;
            temp.push_back(n);
        }
    }
    //add n and all it's rotations to the set of circular primes
    for (int t : temp) circulars.insert(t);
    return;
}

int main()
{
    vector<bool> primes(1000000, true);
    findPrimes(primes);
    set<int> circulars;
    circulars.insert(2);
    circulars.insert(3);
    circulars.insert(5);
    circulars.insert(7);
    circulars.insert(11);
    for (int i = 13; i < 1000000; i+=2) {
        isCircular(i, circulars, primes);
    }

    cout << circulars.size() << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

