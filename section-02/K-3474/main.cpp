/*
 * Problem: 3474
 * URL: https://www.acmicpc.net/problem/3474
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void readTestCases(vector<int> &testCases) {
  int testCaseSize = testCases.size();

  for (int testCaseIndex = 0; testCaseIndex < testCaseSize; ++testCaseIndex) {
    cin >> testCases[testCaseIndex];
  }
}

void countLeftZero(vector<int> testCases, vector<int> &leftZeroCounts) {
  int testCaseSize = testCases.size();

  int maxInNumber = *max_element(testCases.begin(), testCases.end());

  double logTwoBaseTen = log(2);
  double logFiveBaseTen = log(5);
  int logInNumberBaseTen = static_cast<int>(log(maxInNumber));

  int maxTwoFactorCount = (logInNumberBaseTen / logTwoBaseTen);
  int maxFiveFactorCount = (logInNumberBaseTen / logFiveBaseTen);

  vector<int> factors(maxInNumber + 1);
  iota(factors.begin(), factors.end(), 0);

  vector<int> twoCounts(maxInNumber + 1);
  for (int twoCount = 0; twoCount < maxTwoFactorCount; ++twoCount) {
    for (int numberIndex = 1; numberIndex <= maxInNumber; ++numberIndex) {
      bool isTwoTimes = (factors[numberIndex] % 2 == 0);
      if (isTwoTimes) {
        twoCounts[numberIndex]++;
        factors[numberIndex] /= 2;
      }
    }
  }

  vector<int> fiveCounts(maxInNumber + 1);
  for (int fiveCount = 0; fiveCount < maxFiveFactorCount; ++fiveCount) {
    for (int numberIndex = 1; numberIndex <= maxInNumber; ++numberIndex) {
      bool isFiveTimes = (factors[numberIndex] % 5 == 0);
      if (isFiveTimes) {
        fiveCounts[numberIndex]++;
        factors[numberIndex] /= 5;
      }
    }
  }

  for (int testCaseIndex = 0; testCaseIndex < testCaseSize; ++testCaseIndex) {
    int inNumber = testCases[testCaseIndex];

    vector<int>::iterator twoStart = twoCounts.begin() + 1;
    vector<int>::iterator twoEnd = twoStart + inNumber;
    int twoFactorSum = accumulate(twoStart, twoEnd, 0);

    vector<int>::iterator fiveStart = fiveCounts.begin() + 1;
    vector<int>::iterator fiveEnd = fiveStart + inNumber;
    int fiveFactorSum = accumulate(fiveStart, fiveEnd, 0);

    int tenFactorCount = min(twoFactorSum, fiveFactorSum);

    leftZeroCounts[testCaseIndex] = tenFactorCount;
  }
}

void printZeroCounts(vector<int> &leftZeroCounts) {
  for (const int leftZeroCount : leftZeroCounts) {
    cout << leftZeroCount << '\n';
  }
}

int main() {

  int testCaseCount = 0;
  cin >> testCaseCount;

  vector<int> testCases(testCaseCount);
  readTestCases(testCases);

  vector<int> leftZeroCounts(testCaseCount);
  countLeftZero(testCases, leftZeroCounts);

  printZeroCounts(leftZeroCounts);
  return 0;
}