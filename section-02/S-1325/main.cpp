/*
 * Problem: 1325
 * URL: https://www.acmicpc.net/problem/1325
 */

#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_COMPUTER_COUNT = 10000;
constexpr int MAX_EDGE_COUNT = 100000;

int calcAdjacencyCount(vector<vector<int>> &adjacencyList,
                       int &startIndex,
                       array<bool, MAX_COMPUTER_COUNT + 1> &visited) {
  int edgeCount = 1;
  visited[startIndex] = true;
  for (int node : adjacencyList[startIndex]) {
    if (visited[node]) {
      continue;
    }
    edgeCount += calcAdjacencyCount(adjacencyList, node, visited);
  }

  return edgeCount;
};

int main() {

  int computerCount = 0, edgeCount = 0;
  cin >> computerCount >> edgeCount;

  vector<vector<int>> adjacencyList(MAX_COMPUTER_COUNT + 1);

  for (int computerIndex = 0; computerIndex < edgeCount; ++computerIndex) {
    int computerA = 0, computerB = 0;
    cin >> computerA >> computerB;

    adjacencyList[computerB].push_back(computerA);
  }

  int maxCount = 0;
  vector<int> adjacencyCounts(MAX_COMPUTER_COUNT + 1);
  array<bool, MAX_COMPUTER_COUNT + 1> visited;

  for (int computerIndex = 1; computerIndex <= computerCount; ++computerIndex) {
    visited.fill(false);
    adjacencyCounts[computerIndex] =
        calcAdjacencyCount(adjacencyList, computerIndex, visited);

    maxCount = max(maxCount, adjacencyCounts[computerIndex]);
  }

  for (int computerIndex = 1; computerIndex <= computerCount; ++computerIndex) {
    if (adjacencyCounts[computerIndex] == maxCount) {
      cout << computerIndex << ' ';
    }
  }

  return 0;
}