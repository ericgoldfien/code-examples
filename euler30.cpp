// euler30.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler #30 https://projecteuler.net/problem=30

#include <iostream>
#include <string>

using namespace std;

bool sumOfFifth(int n) {
    int sum = 0;
    int copy = n;
    while (copy != 0) {
        int dig = copy % 10;
        sum += (dig * dig * dig * dig * dig);
        copy = copy / 10;
    }
    return sum == n;
}


int main()
{
    int sum = 0;
    for (int i = 2; i < 1000000; i++) {
        if (sumOfFifth(i)) sum += i;
    }

    cout << sum << endl;
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
