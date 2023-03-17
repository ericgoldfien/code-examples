// euler34.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 34 https://projecteuler.net/problem=34

#include <iostream>
#include <vector>

using namespace std;

//simple function for calculating n!
int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool sumOfFactorials(int n, vector<int>& facts) {
    int sum = 0;
    int copy = n;
    while (copy != 0) {
        int dig = copy % 10;
        sum += facts[dig];
        copy = copy / 10;
    }
    return sum == n;
}


int main()
{
    //since we're only using single digit factorials I stored their values to avoid
    //repeat calculations
    vector<int> facts(10, 0);
    int res = 0;
    for (int i = 0; i < 10; i++) facts[i] = factorial(i);
    for (int j = 3; j < 1000000; j++) {
        if (sumOfFactorials(j, facts)) res += j;
    }
    cout << res << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


