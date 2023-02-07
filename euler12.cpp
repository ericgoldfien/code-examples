// euler12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to https://projecteuler.net/problem=12

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool hasFiveHundredFactors(long long n) {

    vector<int> factors;
    for (int i = 1; i < floor(sqrt(n)); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    }

    return (factors.size() > 500);
}

int main()
{
    vector<int> triangleNumbers = { 0, 1 };
    bool solved = false;
    long long i = 2;
    while (!solved) {
        triangleNumbers.push_back(i + triangleNumbers[i - 1]);
        solved = hasFiveHundredFactors(triangleNumbers[i]);
        i++;
    }


    cout << triangleNumbers[i-1] << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


