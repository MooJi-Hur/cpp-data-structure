/*
 * Problem: 12851
 * URL: https://www.acmicpc.net/problem/12851
 */

#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

// in
int startPosition = 0;
int endPosition = 0;

constexpr int MAX_POSITION = 100000;

// out
array<int, MAX_POSITION + 1> visited{};
array<int, MAX_POSITION + 1> routeCounts{};

int minTime = INT_MAX;

// logic
constexpr int WAYS = 3;

int getNextPosition(int wayIndex, int currentIndex) {
  if (wayIndex == 0) {
    return currentIndex + 1;
  } else if (wayIndex == 1) {
    return currentIndex - 1;
  } else if (wayIndex == 2) {
    return currentIndex * 2;
  } else {
    return 0;
  }
}

void findFamily() {
  queue<int> bfsQueue;
  bfsQueue.push(startPosition);
  visited[startPosition] = 0;

  while (!bfsQueue.empty()) {
    int currentPosition = bfsQueue.front();
    bfsQueue.pop();

    if (currentPosition == endPosition) {
      break;
    }

    for (int wayIndex = 0; wayIndex < WAYS; ++wayIndex) {
      int nextPosition = getNextPosition(wayIndex, currentPosition);

      bool isInBound = nextPosition >= 0 && nextPosition <= MAX_POSITION;

      bool canMoveNext = isInBound && (visited[nextPosition] == 0);
      bool isEndPosition = isInBound && (nextPosition == endPosition);

      if (canMoveNext) {
        bfsQueue.push(nextPosition);
        visited[nextPosition] += visited[currentPosition] + 1;
      }

      if (isEndPosition) {
        int timeCount = visited[endPosition];
        minTime = min(minTime, timeCount);
        routeCounts[timeCount]++;
      }
    }
  }
};

int main() {

  cin >> startPosition >> endPosition;

  findFamily();

  cout << minTime << '\n' << routeCounts[minTime];
  return 0;
}