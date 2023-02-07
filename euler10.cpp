// euler10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to https://projecteuler.net/problem=10

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//find all the primes under a given size using a sieve method
void findPrimes(vector<bool>& primes) {
    for (int i = 4; i < primes.size(); i += 2) primes[i] = false;
    int ceil = floor(sqrt(primes.size()));
    for (int p = 3; p < ceil; p += 2) {
        if (primes[p] == true) {
            for (int j = 3 * p; j < primes.size(); j += 2*p) primes[j] = false;
        }
    }

    return;
}

int main()
{
    vector<bool> primes(2000000, true);
    findPrimes(primes);
    long long sum = 2;
    for (int i =3; i < 2000000; i+=2) {
        if (primes[i]) sum += i;
    }

    cout << sum << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


