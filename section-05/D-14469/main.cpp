/*
 * Problem: 14469
 * URL: https://www.acmicpc.net/problem/14469
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

  int cowSize = 0;
  cin >> cowSize;

  map<int, vector<int>> cows;
  for (int cowIndex = 0; cowIndex < cowSize; ++cowIndex) {
    int inTime = 0, testTime = 0;
    cin >> inTime >> testTime;
    cows[inTime].push_back(testTime);
  }

  int currentTime = 0;

  for (auto [arrived, tests] : cows) {
    for (int time : tests) {
      currentTime += (max(0, arrived - currentTime) + time);
    }
  }

  cout << currentTime;
  return 0;
}
