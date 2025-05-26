/*
 * Problem: 1094
 * URL: https://www.acmicpc.net/problem/1094
 */

#include <bit>
#include <iostream>

using namespace std;

// in
int digit = 1;

// out
int bitCount = 0;

// logic
constexpr int MAX_DIGIT = 64;
constexpr int MAX_PLACE = 6;

int main() {

  cin >> digit;

  for (int bitIndex = 0; bitIndex <= MAX_PLACE; ++bitIndex) {

    if ((digit & (MAX_DIGIT >> bitIndex)) > 0) {
      bitCount++;
    }
  }

  cout << bitCount;
  return 0;
}