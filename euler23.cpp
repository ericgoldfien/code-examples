// euler23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

//Function that sums the factors of an integer and compares if the sum is larger than the input int n
bool isAbundant(int n) {
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum > n;
}


int main()
{
    int res = 0;

    vector<bool> canSum(28124, false);
    vector<int> abundants;
    
    for (int a = 12; a < 28111; a++) {
        if (isAbundant(a)) abundants.push_back(a);
    }

    for (int i = 0; i < abundants.size(); i++) {
        for (int j = i; j < abundants.size(); j++) {
            if ((abundants[i] + abundants[j]) <= 28123) canSum[abundants[i] + abundants[j]] = true;
            else { break; }
        }
    }

    for (int k = 1; k < canSum.size(); k++) {
        if (!canSum[k]) res += k;
    }

    cout << res << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

