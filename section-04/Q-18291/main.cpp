/*
 * Problem: 18291
 * URL: https://www.acmicpc.net/problem/18291
 */

#include <iostream>

using namespace std;

// in
int testCaseSize = 0;
int bridgeSize = 0;

// out
constexpr int DIVISOR = 1000000000 + 7;

long long getRemainder(long long caseExp) {

  if (caseExp < 0) {
    return 1;
  }

  if (caseExp <= 1) {
    return (1 << caseExp) % DIVISOR;
  }

  long long dividendExp = (caseExp / 2);
  long long remainderN =
      (getRemainder(dividendExp) * getRemainder(dividendExp)) % DIVISOR;

  bool isOdd = (caseExp % 2) != 0;
  if (isOdd) {
    remainderN = (remainderN * 2) % DIVISOR;
  }

  return remainderN;
};

int main() {

  cin >> testCaseSize;

  for (int testIndex = 0; testIndex < testCaseSize; ++testIndex) {

    cin >> bridgeSize;

    long long caseExp = bridgeSize - 2;
    cout << getRemainder(caseExp) << '\n';
  }

  return 0;
}
