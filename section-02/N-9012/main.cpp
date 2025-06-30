/*
 * Problem: 9012
 * URL: https://www.acmicpc.net/problem/9012
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// in
int testSize = 0;

// out
string VAILED = "YES";
string INVALIED = "NO";

// logic
string VPS = "()";

int main() {
  cin >> testSize;

  for (int testIndex = 0; testIndex < testSize; ++testIndex) {
    string row;
    getline(cin >> ws, row);

    stack<char> parenthesisStack;

    for (char letter : row) {
      if (parenthesisStack.empty()) {
        parenthesisStack.push(letter);
        continue;
      }

      char topLetter = parenthesisStack.top();

      string currentPair = string() + topLetter + letter;

      if (currentPair == VPS) {
        parenthesisStack.pop();
      } else {
        parenthesisStack.push(letter);
      }
    }

    if (parenthesisStack.empty()) {
      cout << VAILED << '\n';
    } else {
      cout << INVALIED << '\n';
    }
  }
  return 0;
}