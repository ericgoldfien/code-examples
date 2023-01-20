// euler1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i = 1;
    int result = 0;
    int mult5;
    while (i * 3 < 1000) {
        mult5 = i * 5;
        result += i*3;
        //avoid duplicates where number is divisible by 5 and 3 and since i*5 will hit 1000 first 
        //it stops adding those once it happens
        if (mult5 % 3 != 0 && mult5 < 1000) result += mult5;
        i++;
    }
    std::cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

