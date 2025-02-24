/*
 * Problem: 2559
 * URL: https://www.acmicpc.net/problem/2559
 */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int MAX_DATE_COUNT = 100000;
constexpr int MIN_DAY_DEGREE = -100;

int main() {

  int dateCount = 2;
  int continueCount = 1;
  cin >> dateCount >> continueCount;

  vector<int> temperatures(dateCount);
  for (int i = 0; i < dateCount; ++i) {
    cin >> temperatures[i];
  }

  int sumMax = MIN_DAY_DEGREE * MAX_DATE_COUNT - 1;

  int windowCount = dateCount - continueCount + 1;

  for (int i = 0; i < windowCount; ++i) {
    int localSum = 0;
    for (int j = i; j < i + continueCount; ++j) {
      localSum += temperatures[j];
    }

    if (localSum > sumMax) {
      sumMax = localSum;
    }
  }

  cout << sumMax;

  return 0;
}