/*
 * Problem: 17071
 * URL: https://www.acmicpc.net/problem/17071
 */

#include <array>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

// in
int startPoint = 0, endPoint = 0;

// out
constexpr int OUT_OF_RESULT = -1;
constexpr int MAX_POSITION = 500000;

int minTime = INT_MAX;

// logic
array<array<bool, MAX_POSITION + 1>, 2> visited{}; // timeCount % 2

int solve() {
  int timeCount = 0;

  if (startPoint == endPoint) {
    return timeCount;
  }

  queue<int> bfsQueue;

  visited[timeCount % 2][startPoint] = true;
  bfsQueue.push(startPoint);

  while (true) {
    endPoint += timeCount;

    bool isOutEnd = endPoint > MAX_POSITION;
    if (isOutEnd) {
      return OUT_OF_RESULT;
    }

    if (visited[timeCount % 2][endPoint])
      return timeCount;

    timeCount++;

    int levelSize = bfsQueue.size();

    for (int levelStep = 0; levelStep < levelSize; ++levelStep) {
      int currentPosition = bfsQueue.front();
      bfsQueue.pop();

      for (int nextPosition :
           {currentPosition - 1, currentPosition + 1, currentPosition * 2}) {

        bool isOutBound = nextPosition < 0 || nextPosition > MAX_POSITION;
        if (isOutBound)
          continue;

        bool isVisitedMod = visited[timeCount % 2][nextPosition] == true;
        if (isVisitedMod)
          continue;

        visited[timeCount % 2][nextPosition] = true;
        bfsQueue.push(nextPosition);
      }
    }
  }

  return OUT_OF_RESULT;
}

int main() {
  cin >> startPoint >> endPoint;

  cout << solve();

  return 0;
}