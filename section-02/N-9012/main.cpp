/*
 * Problem: 9012
 * URL: https://www.acmicpc.net/problem/9012
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int inSize;

int main() {
  cin >> inSize;

  for (int inIndex = 0; inIndex < inSize; ++inIndex) {
    string inRow;
    getline(cin >> ws, inRow);

    stack<char> parenthesisStack;
    for (int colIndex = 0; colIndex < inRow.size(); ++colIndex) {
      if (parenthesisStack.empty()) {
        parenthesisStack.push(inRow[colIndex]);
        continue;
      }

      string lastTwo = string() + parenthesisStack.top() + inRow[colIndex];

      bool isPair = lastTwo == "()";

      if (isPair) {
        parenthesisStack.pop();
      } else {
        parenthesisStack.push(inRow[colIndex]);
      }
    }

    if (parenthesisStack.empty()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  //
  return 0;
}