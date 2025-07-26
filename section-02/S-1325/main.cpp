/*
 * Problem: 1325
 * URL: https://www.acmicpc.net/problem/1325
 */

#include <iostream>
#include <vector>

using namespace std;

int dfs(int &computerIndex,
        vector<vector<int>> &adjacencyList,
        vector<bool> &visited) {
  visited[computerIndex] = true;
  int targetCount = 1;

  for (int next : adjacencyList[computerIndex]) {
    if (!visited[next]) {
      targetCount += dfs(next, adjacencyList, visited);
    }
  }
  return targetCount;
};

int main() {
  int computerCount = 0, edgeCount = 0;
  cin >> computerCount >> edgeCount;

  vector<vector<int>> adjacencyList(computerCount + 1);
  for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
    int targetComputer = 0, sourceComputer = 0;
    cin >> targetComputer >> sourceComputer;

    adjacencyList[sourceComputer].push_back(targetComputer);
  }

  int maxTargetCount = 0;
  vector<int> targetCounts(computerCount + 1, 0);
  for (int computerIndex = 1; computerIndex <= computerCount; ++computerIndex) {
    vector<bool> visited(computerCount + 1, false);
    targetCounts[computerIndex] = dfs(computerIndex, adjacencyList, visited);

    maxTargetCount = max(maxTargetCount, targetCounts[computerIndex]);
  }

  for (int computerIndex = 1; computerIndex <= computerCount; ++computerIndex) {
    if (maxTargetCount == targetCounts[computerIndex]) {
      cout << computerIndex << ' ';
    }
  }
  return 0;
}