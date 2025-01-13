/*
 * Problem: 10988
 * URL: https://www.acmicpc.net/problem/10988
 */

#include <iostream>
#include <string>

using namespace std;

string getInput()
{
    string myInput;

    cin >> myInput;

    return myInput;
}

void printOutput(bool myOutput)
{
    cout << myOutput << '\n';
}

int main()
{
    bool isPalindrome = false;

    string inWord = getInput();

    cout << inWord << '\n';

    isPalindrome = true;

    printOutput(isPalindrome);

    return 0;
}
