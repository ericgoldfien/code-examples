// euler4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// solution for https://projecteuler.net/problem=4
//

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int n) {

    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

//Only searching from 999 to 900 for i*j to limit multiplications, if val not found parameters will expand
int main()
{
    for (int i = 999; i >= 900; i--) {
        int flag = 0;
        for (int j = 999; j >= 900; j--) {
            if (isPalindrome(i * j)) {
                cout << i * j << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


