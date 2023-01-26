// euler6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to projecy euler 6 https://projecteuler.net/problem=6
//

#include <iostream>

using namespace std;

int main()
{
	long long sumOfSquares = 0;
	long long squareOfSums = 0;

	for (int i = 1; i <= 100; i++) {
		sumOfSquares += i * i;
		squareOfSums += i;
	}
	squareOfSums *= squareOfSums;

	cout << squareOfSums - sumOfSquares;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

