// euler36.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 36(Double-base palindromes) https://projecteuler.net/problem=36

#include <iostream>
#include <string>

using namespace std;

//checks if a string is a palindrome by comparing characters from the outside in
bool isPalindrome(string s) {

    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }

    return true;
}


//function to convert an integer into a binary string
string decToBinary(int n) {
    
    int dig;
    string s;
    string res;
    while (n > 0) {
        dig = n % 2;
        s += to_string(dig);
        n /= 2;
    }

    //reverses string
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }

    return res;
}


int main()
{
    long long sum = 0;

    //only need to check odd numbers as binary nums can't have leading zeros so its last digit must be 1 thus odd
    for (int i = 1; i < 1000000; i += 2) {
        if (isPalindrome(to_string(i)) && isPalindrome(decToBinary(i))) sum += i;
    }

    cout << sum << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


