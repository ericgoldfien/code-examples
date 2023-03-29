// euler21.cpp : This file contains the 'main' function. Program execution begins and ends there.
// my solution to project euler 21 (amicable numbers) https://projecteuler.net/problem=21

#include <iostream>
#include <vector>
#include <set>

using namespace std;

//function to find the factors of an integer
vector<int> factors(int n) {
    vector<int> f = { 1 };
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) f.push_back(i);
    }
    return f;
}

void findAmicable(int a, set<int>& amicables) {
    
    if (amicables.count(a) != 0) return;
    int b = 0;
    int c = 0;
    vector<int> aFac = factors(a);
    for (int i : aFac) b += i;
    if (b == a) return;
    vector<int> bFac = factors(b);
    for (int j : bFac) c += j;

    if (c == a) {
        amicables.insert(a);
        amicables.insert(b);
    }
    return;
}

int main()
{
    int res = 0;
    set<int> amicables;
    for (int i = 1; i < 10000; i++) {
        findAmicable(i, amicables);
    }

    for (auto am : amicables) res += am;


    cout << res << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

