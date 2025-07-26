/*
 * Problem: 1068
 * URL: https://www.acmicpc.net/problem/1068
 */

#include <iostream>
#include <vector>

using namespace std;

constexpr int ROOT = -1;

int dfs(int startNode, int &delNode, vector<vector<int>> &adjacencyList) {
  int leafCount = 0;
  int childrenCount = 0;

  for (int node : adjacencyList[startNode]) {
    if (node == delNode) {
      continue;
    }
    childrenCount++;

    leafCount += dfs(node, delNode, adjacencyList);
  }

  if (childrenCount == 0) {
    return 1;
  }

  return leafCount;
};

int main() {
  int nodeCount = 0;
  cin >> nodeCount;

  int rootIndex = -1;
  vector<vector<int>> adjacencyList(nodeCount);
  for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex) {
    int parentNode = ROOT;
    cin >> parentNode;

    if (parentNode == ROOT) {
      rootIndex = nodeIndex;
      continue;
    }

    adjacencyList[parentNode].push_back(nodeIndex);
  }

  int delNode = -1;
  cin >> delNode;

  if (delNode == rootIndex) {
    cout << 0;
    return 0;
  }
  cout << dfs(rootIndex, delNode, adjacencyList);
  //
  return 0;
}