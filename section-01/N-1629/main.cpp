/*
 * Problem: 1629
 * URL: https://www.acmicpc.net/problem/1629
 */

#include <iostream>

using namespace std;

// in
long long baseA = 0, expB = 0, quotientC = 0;

// out
long long remainderA = 0;

long long divideAndConquer(long long currentBase, long long currentExp) {
  if (currentExp == 1) {
    return currentBase % quotientC;
  }
  long long currentReminder = divideAndConquer(currentBase, currentExp / 2);
  currentReminder = (currentReminder * currentReminder) % quotientC;
  bool isOdd = currentExp % 2 != 0;
  if (isOdd) {
    currentReminder = (currentReminder * currentBase) % quotientC;
  };

  return currentReminder;
};

int main() {

  cin >> baseA >> expB >> quotientC;

  cout << divideAndConquer(baseA, expB);
  return 0;
}
