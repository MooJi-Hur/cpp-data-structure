/*
 * Problem: 13244
 * URL: https://www.acmicpc.net/problem/13244
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

  int testSize;
  cin >> testSize;

  for (int testIndex = 0; testIndex < testSize; ++testIndex) {
    bool isTree = true;
    int nodeSize = 0, edgeSize = 0;
    cin >> nodeSize >> edgeSize;

    vector<vector<int>> edges(nodeSize + 1);

    for (int edgeIndex = 0; edgeIndex < edgeSize; ++edgeIndex) {
      int a = 0, b = 0;
      cin >> a >> b;

      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    if (nodeSize - edgeSize != 1) {
      isTree = false;
      cout << "graph" << '\n';
      continue;
    }

    for (int nodeIndex = 1; nodeIndex <= nodeSize; ++nodeIndex) {
      if (edges[nodeIndex].empty()) {
        isTree = false;

        continue;
      }
    }

    if (isTree) {
      cout << "tree" << '\n';
    } else {
      cout << "graph" << '\n';
    }
  }

  return 0;
}