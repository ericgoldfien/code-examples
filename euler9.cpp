// euler9.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 9 https://projecteuler.net/problem=9

#include <iostream>

using namespace std;

int main()
{
	int c;
	for (int a = 1; a < 1000; a++) {
		for (int b = a; a + b < 1000; b++) {
			c = 1000 - a - b;
			if ((a * a) + (b * b) == (c * c)) cout << a * b * c;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


