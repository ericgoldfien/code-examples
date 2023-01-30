// euler7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to https://projecteuler.net/problem=7

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes{ 2,3,5,7,11 };
    int num = 13;
    int flag = 0;
    while (primes.size() < 10001) {
        for (int p : primes) {
            flag = 0;
            if (num % p == 0) {
                flag = 1;
                break;
            }
        
        }
        if (flag == 0) primes.push_back(num);
        num += 2;
    }

    cout << primes[primes.size() - 1] << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


