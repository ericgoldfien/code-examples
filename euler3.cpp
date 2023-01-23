// euler3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//using prime factorization method from https://www.geeksforgeeks.org/prime-factor/
vector<int> primeFactors(long long n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n / 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) factors.push_back(n);
    return factors;
}

int main()
{
    long long num = 600851475143;
    vector<int> res = primeFactors(num);
    cout << res[res.size() - 1] << endl;
    
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
