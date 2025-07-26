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

constexpr int START_COUNT = 1;

// logic
constexpr int WAYS = 3;

void findFamily() {
  queue<int> bfsQueue;
  bfsQueue.push(startPosition);
  visited[startPosition] = START_COUNT;
  routeCounts[startPosition] = 1;

  while (!bfsQueue.empty()) {
    int currentPosition = bfsQueue.front();
    bfsQueue.pop();

    if (currentPosition == endPosition) {
      break;
    }

    for (int nextPosition :
         {currentPosition + 1, currentPosition - 1, currentPosition * 2}) {

      bool isInBound = nextPosition >= 0 && nextPosition <= MAX_POSITION;

      if (isInBound) {
        if (!visited[nextPosition]) {
          bfsQueue.push(nextPosition);
          visited[nextPosition] += visited[currentPosition] + 1;
          routeCounts[nextPosition] += routeCounts[currentPosition];

        } else if (visited[nextPosition] == visited[currentPosition] + 1) {
          routeCounts[nextPosition] += routeCounts[currentPosition];
        }
      }
    }
  }
};

int main() {

  cin >> startPosition >> endPosition;

  if (startPosition == endPosition) {
    cout << 0 << '\n' << 1;

  } else {
    findFamily();

    cout << visited[endPosition] - START_COUNT << '\n'
         << routeCounts[endPosition];
  }

  return 0;
}