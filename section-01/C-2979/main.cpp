/*
 * Problem: 2979
 * URL: https://www.acmicpc.net/problem/2979
 */
#include <array>
#include <iostream>

using namespace std;

constexpr int MAX_TIME = 100;
constexpr int NUM_OF_CAR = 3;

int main() {

  array<int, NUM_OF_CAR + 1> fees;

  for (size_t i = 1; i < fees.size(); ++i) {
    cin >> fees[i];
  }

  array<int, MAX_TIME + 1> carCounts;
  carCounts.fill(0);

  for (int i = 0; i < NUM_OF_CAR; ++i) {
    int arrivedTime = 0, leaveTime = 0;
    cin >> arrivedTime >> leaveTime;

    for (int j = arrivedTime; j < leaveTime; ++j) {
      carCounts[j]++;
    }
  }

  int totalPrice = 0;
  for (int carCount : carCounts) {
    totalPrice += carCount * fees[carCount];
  }

  cout << totalPrice;

  return 0;
}
