/*
 * Problem: 15353
 * URL: https://www.acmicpc.net/problem/15353
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> operandA;
stack<int> operandB;

constexpr char ZERO = '0';

string sumResult;

void readOperands() {
  string a, b;
  cin >> a >> b;

  for (size_t aIndex = 0; aIndex < a.size(); ++aIndex) {
    operandA.push(a[aIndex] - ZERO);
  }

  for (size_t bIndex = 0; bIndex < b.size(); ++bIndex) {
    operandB.push(b[bIndex] - ZERO);
  }
}

void calc() {
  int roundNumber = 0;
  int firstOperander = 0;
  int secondOperander = 0;

  while (!operandA.empty() || !operandB.empty()) {

    if (!operandA.empty()) {
      firstOperander = operandA.top();
      operandA.pop();
    } else {
      firstOperander = 0;
    }

    if (!operandB.empty()) {
      secondOperander = operandB.top();
      operandB.pop();
    } else {
      secondOperander = 0;
    }

    int localSum = firstOperander + secondOperander + roundNumber;

    if (localSum >= 10) {
      roundNumber = 1;
      localSum -= 10;
    } else {
      roundNumber = 0;
    }

    sumResult = char(localSum + ZERO) + sumResult;
  }

  if (roundNumber == 1) {
    sumResult = '1' + sumResult;
  }
}

int main() {

  readOperands();

  calc();

  cout << sumResult;

  return 0;
}
