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
int maxValue = INT_MIN;

void readExpression() {
  string inExpression;
  cin >> inExpression;
  for (int inIndex = 0; inIndex < inSize; ++inIndex) {
    if (inIndex % 2 == 0) {
      inOperands.push_back(inExpression[inIndex] - ZERO);

    } else {
      inOperators.push_back(inExpression[inIndex]);
    }
  }
}

int calcExpression(int firstValue, int secondValue, char inOperator) {
  if (inOperator == '+') {
    return firstValue + secondValue;
  } else if (inOperator == '-') {
    return firstValue - secondValue;
  } else if (inOperator == '*') {
    return firstValue * secondValue;
  }
  return 0;
}

void simulateExpression(int currentIndex, int prevResult) {

  if (currentIndex >= inOperators.size()) {
    maxValue = max(maxValue, prevResult);
    return;
  }

  int currentResult = calcExpression(prevResult, inOperands[currentIndex + 1],
                                     inOperators[currentIndex]);
  simulateExpression(currentIndex + 1, currentResult);

  if (currentIndex + 1 < inOperators.size()) {
    int secondValue = calcExpression(inOperands[currentIndex + 1],
                                     inOperands[currentIndex + 2],
                                     inOperators[currentIndex + 1]);

    currentResult =
        calcExpression(prevResult, secondValue, inOperators[currentIndex]);

    simulateExpression(currentIndex + 2, currentResult);
  }
}

int main() {

  cin >> inSize;
  readExpression();

  simulateExpression(0, inOperands[0]);

  cout << maxValue;
  return 0;
}
