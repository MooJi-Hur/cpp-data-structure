/*
 * Problem: 3474
 * URL: https://www.acmicpc.net/problem/3474
 */

#include <iostream>
#include <vector>

using namespace std;

void readTestCases(vector<int> &numberOrder) {
  for (size_t numberIndex = 0; numberIndex < numberOrder.size();
       ++numberIndex) {

    cin >> numberOrder[numberIndex];
  }
}

void countRightZero(vector<int> &numberOrder, vector<int> &rightZeroCounts) {

  for (size_t inNumberIndex = 0; inNumberIndex < numberOrder.size();
       ++inNumberIndex) {

    int inNumber = numberOrder[inNumberIndex];
    if (inNumber < 5) {
      continue;
    }

    int rightZeroCount = 0;
    int divider = inNumber;

    while (divider >= 1) {
      divider = divider / 5;
      rightZeroCount += divider;
    }

    rightZeroCounts[inNumberIndex] = rightZeroCount;
  }
}

void printZeroCounts(vector<int> &rightZeroCounts) {

  for (int rightZeroCount : rightZeroCounts) {
    cout << rightZeroCount << '\n';
  }
}

int main() {

  int testCaseCount = 0;
  cin >> testCaseCount;

  vector<int> numberOrder(testCaseCount, 0);
  vector<int> rightZeroCounts(testCaseCount, 0);
  readTestCases(numberOrder);

  countRightZero(numberOrder, rightZeroCounts);

  printZeroCounts(rightZeroCounts);
  return 0;
}