/*
 * Problem: 13913
 * URL: https://www.acmicpc.net/problem/13913
 */

#include <array>
#include <climits>
#include <iostream>
#include <map>
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
map<int, vector<int>> routes;

void findFamily() {
  queue<int> bfsQueue;

  bfsQueue.push(startPoint);
  visited[startPoint] = 1;
  routes[startPoint].push_back(startPoint);

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
      routes[nextPosition] = routes[currentPosition];

      routes[nextPosition].push_back(nextPosition);
    }
    routes[currentPosition].clear();
  }
};

int main() {

  cin >> startPoint >> endPoint;

  if (startPoint == endPoint) {
    cout << 0 << '\n' << endPoint;
  } else {
    findFamily();

    for (auto [key, row] : routes) {
      cout << key << " : ";
      for (auto cell : row) {
        cout << cell << ' ';
      }
      cout << '\n';
    }

    cout << visited[endPoint] - 1 << '\n';

    for (int position : routes[endPoint]) {
      cout << position << ' ';
    }
  }
  return 0;
}