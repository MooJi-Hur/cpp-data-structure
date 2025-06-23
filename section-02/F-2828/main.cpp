/*
 * Problem: 2828
 * URL: https://www.acmicpc.net/problem/2828
 */

#include <iostream>

using namespace std;

int main() {

  // in
  int screenSize = 0, basketSize = 0;
  int appleSize = 0;

  // out
  int minDistance = 0;

  cin >> screenSize >> basketSize;
  cin >> appleSize;

  // logic
  int basketStart = 1;
  int basketEnd = basketStart + basketSize - 1;

  for (int appleIndex = 0; appleIndex < appleSize; ++appleIndex) {

    int target = 0;
    cin >> target;

    bool targetInBasket = target >= basketStart && target <= basketEnd;

    if (targetInBasket) {
      continue;
    }

    bool moveRight = target > basketStart;

    int move = 0;

    if (moveRight) {
      move = target - basketEnd;
      basketStart += move;
      basketEnd += move;
    } else {
      move = basketStart - target;
      basketStart -= move;
      basketEnd -= move;
    }

    minDistance += move;
  }

  cout << minDistance;
  return 0;
}