/*
 * Problem: 13913
 * URL: https://www.acmicpc.net/problem/13913
 */

#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// in
int startPoint = 0;
int endPoint = 0;

constexpr int MAX_POSITION = 100000;

// out
int minTime = INT_MAX;
array<int, MAX_POSITION + 1> visited{};
array<int, MAX_POSITION + 1> history{};
vector<int> routes;

void findFamily() {
  queue<int> bfsQueue;

  bfsQueue.push(startPoint);
  visited[startPoint] = 1;

  while (!bfsQueue.empty()) {
    int currentPosition = bfsQueue.front();
    bfsQueue.pop();

    if (currentPosition == endPoint) {
      return;
    }

    for (int nextPosition :
         {currentPosition + 1, currentPosition - 1, currentPosition * 2}) {
      if (nextPosition < 0 || nextPosition > MAX_POSITION ||
          visited[nextPosition]) {
        continue;
      }

      bfsQueue.push(nextPosition);
      visited[nextPosition] = visited[currentPosition] + 1;
      history[nextPosition] = currentPosition;
    }
  }
};

int main() {

  cin >> startPoint >> endPoint;

  if (startPoint == endPoint) {
    cout << 0 << '\n' << endPoint;
  } else {
    findFamily();

    cout << visited[endPoint] - 1 << '\n';

    for (int routeIndex = endPoint; routeIndex != startPoint;
         routeIndex = history[routeIndex]) {
      routes.push_back(history[routeIndex]);
    }

    reverse(routes.begin(), routes.end());
    routes.push_back(endPoint);

    for (int position : routes) {
      cout << position << ' ';
    }
  }
  return 0;
}