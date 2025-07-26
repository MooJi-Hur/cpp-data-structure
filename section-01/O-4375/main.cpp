/*
 * Problem: 4375
 * URL: https://www.acmicpc.net/problem/4375
 */

#include <iostream>

using namespace std;

int main() {
  int n = 0;

  while (cin >> n) {

    int countPlace = 1;
    int remainderN = 1 % n;

    while (remainderN != 0) {

      remainderN = (remainderN * 10 + 1) % n;

      countPlace++;
    }
    cout << countPlace << '\n';
  }

  return 0;
}
