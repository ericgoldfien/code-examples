// euler14.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to https://projecteuler.net/problem=14

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


//Calculates the collatz sequence for variable num.  Used dynamic programming since
//some sequences contain already calculated sequences so it's faster to just look that
//sequence length up if already found.
void collatz(map<int, int>& c, int num) {
    
    int count = 1;
    long long n = num;
    while (n != 1) {
        //if the current number in the sequence already has it's length found add it to
        //the current count and return
        if (c.count(n) > 0) {
            c[num] = count + c[n] - 1;
            return;
        }
        if (n % 2 == 0) {
            n /= 2;
            count++;
        }
        else {
            n = n * 3 + 1;
            count++;
        }
    }
    c[num] = count;
    return;
}

int main()
{
    //store the found collatz lengths in a map
    map<int, int> c;
    c[1] = 1;
    c[2] = 2;
    c[4] = 3;
    for (int i = 3; i < 1000000; i++) {
        collatz(c, i);
    }

    int max = 0;
    int res = 0;
    for (auto it = c.begin(); it != c.end(); it++) {
        if (it->second > max) {
            max = it->second;
            res = it->first;
        }
    }

    cout << res << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


