// euler31.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution for project euler 31 found https://projecteuler.net/problem=31

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 200;
    vector<int> coins = {2, 5, 10, 20, 50, 100, 200 };
    //can set all combos to 1 as n x 1p coins is a combo for every value
    vector<long long> combos(n + 1, 1);
    for (int c : coins) {
        for (int i = c; i <= n; i++) {
            combos[i] += combos[i - c];
        }
    }
    cout << combos[n] << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

