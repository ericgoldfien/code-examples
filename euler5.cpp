// euler5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// solution to euler question 5 https://projecteuler.net/problem=5
//

#include <iostream>
#include <vector>

using namespace std;

bool isDivisible(vector<int>& div, int n) {

	for (int d : div) {
		if (n % d != 0) return false;
	}
	return true;
}

int main()
{
	vector<int> div{ 11,12,13,14,15,16,17,18,19 };
	int res = 0;
	int num = 20;
	while (res == 0) {
		if (isDivisible(div, num)) {
			res = num;
		}
		num += 20;
	}
	cout << res << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

