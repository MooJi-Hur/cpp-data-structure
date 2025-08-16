/*
 * Problem: 16637
 * URL: https://www.acmicpc.net/problem/16637
 */

#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
int inSize;
vector<int> inOperands;
vector<char> inOperators;

constexpr char ZERO = '0';

// out
int maxResult = INT_MIN;

void readExpression() {
  string inRow;
  getline(cin >> ws, inRow);

  for (int inIndex = 0; inIndex < inSize; ++inIndex) {
    if (inIndex % 2 == 0) {
      inOperands.push_back(inRow[inIndex] - ZERO);
    } else {
      inOperators.push_back(inRow[inIndex]);
    }
  }
}

int calcOperater(int firstValue, int secondValue, char inOperator) {
  if (inOperator == '+') {
    return firstValue + secondValue;
  } else if (inOperator == '-') {
    return firstValue - secondValue;
  } else if (inOperator == '*') {
    return firstValue * secondValue;
  }

  return -1;
}

void simulateExpression(int currentIndex, int prevResult) {
  if (currentIndex == inOperators.size()) {
    maxResult = max(maxResult, prevResult);
    return;
  }

  int currentResult = calcOperater(prevResult, inOperands[currentIndex + 1],
                                   inOperators[currentIndex]);

  simulateExpression(currentIndex + 1, currentResult);

  if (currentIndex + 1 >= inOperators.size()) {
    return;
  }

  int secondValue =
      calcOperater(inOperands[currentIndex + 1], inOperands[currentIndex + 2],
                   inOperators[currentIndex + 1]);

  currentResult =
      calcOperater(prevResult, secondValue, inOperators[currentIndex]);

  simulateExpression(currentIndex + 2, currentResult);
}

int main() {

  cin >> inSize;

  readExpression();

  simulateExpression(0, inOperands[0]);

  cout << maxResult;

  return 0;
}