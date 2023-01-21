// euler2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> fib{ 1, 2 };
    int result = 0;
    int i = 2;
    while (fib[i - 2] + fib[i - 1] < 4000000) {
        fib.push_back(fib[i - 2] + fib[i - 1]);
        i++;
    }

    for (int j = 1; j < fib.size(); j += 3) result += fib[j];

    std::cout << result << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
