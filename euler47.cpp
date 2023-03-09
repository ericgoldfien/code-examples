// euler47.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 47 https://projecteuler.net/problem=47

#include <iostream>
#include <vector>
#include <set>


using namespace std;

//using prime factorization method from https://www.geeksforgeeks.org/prime-factor/
set<int> primeFactors(long long n) {
    set<int> factors;
    while (n % 2 == 0) {
        factors.insert(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.insert(i);
            n = n / i;
        }
    }

    if (n > 2) factors.insert(n);
    return factors;
}

//compares the sets of prime factors between two numbers, if there is a single match returns false
bool diffFactors(set<int> a, set<int> b) {
    
    for (auto k : a) {
        if (b.count(k) != 0) return false;
    }
    return true;
}

int main()
{
    bool found = false;
    vector<int> nums = { 647, 648, 649, 650 };
    vector<set<int>> factors = {primeFactors(647), primeFactors(648), primeFactors(649), primeFactors(650)};

    while (!found) {
        //if all 4 nums have 4 unique prime factors and no two nums in a row have a similar factor found is true
        if (factors[0].size() == 4 && factors[1].size() == 4 && factors[2].size() == 4 && factors[3].size() == 4) {
            if (diffFactors(factors[0], factors[1]) && diffFactors(factors[1], factors[2]) && diffFactors(factors[2], factors[3])) found = true;
        }
        else {
            nums.erase(nums.begin());
            factors.erase(factors.begin());
            nums.push_back(nums[2] + 1);
            factors.push_back(primeFactors(nums[3]));
        }
        
    }

    cout << nums[0] << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

