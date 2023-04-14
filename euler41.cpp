// euler41.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 41(Pandigital Primes) https://projecteuler.net/problem=41 

#include <iostream>
#include <vector>
#include <set>
#include <string>

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

//checks if a number is pandigital by seeing if the size of the set of unique digits is
//equal to the length of the int converted to a string
bool isPandigital(int n) {

    set<int> digits;
    string num = to_string(n);
    for (char dig : num) {
        if (dig == '0' || int(dig - '0') > num.size()) return false;
        digits.insert(dig);
    }
    return digits.size() == num.length();
}

int main()
{
    vector<bool> primes(987654322, true);
    findPrimes(primes);
    cout << "Primes calculated" << endl;
    int res = 0;
    for (int i = 987654321; i >= 0; i -= 2) {
        if (primes[i] && isPandigital(i)) {
            res = i;
            break;
        }
    }
    
    cout << res << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

