/*
 * Problem: 1325
 * URL: https://www.acmicpc.net/problem/1325
 */

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

void findRelations(int &computerCount,
                   int startNode,
                   map<int, set<int>> &adjacencyList,
                   map<int, set<int>, greater<int>> &computerDegrees) {
  stack<int> dfsStack;
  dfsStack.push(startNode);

  vector<bool> visited(computerCount + 1);

  int degreeCount = 0;

  while (!dfsStack.empty()) {
    int currentNode = dfsStack.top();
    dfsStack.pop();

    if (visited[currentNode]) {
      continue;
    }
    visited[currentNode] = true;

    for (int nextNode : adjacencyList[currentNode]) {
      dfsStack.push(nextNode);
      adjacencyList[startNode].insert(nextNode);
      degreeCount++;
    }
  }
  computerDegrees[degreeCount].insert(startNode);
};

int main() {
  int computerCount = 0, edgeCount = 0;
  cin >> computerCount >> edgeCount;

  map<int, set<int>> adjacencyList;
  map<int, set<int>, greater<int>> computerDegrees;
  for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
    int computerA = 0, computerB = 0;
    cin >> computerA >> computerB;
    adjacencyList[computerB].insert(computerA);
  }

  for (auto [key, nodes] : adjacencyList) {
    findRelations(computerCount, key, adjacencyList, computerDegrees);
  }

  auto maxDegreeItor = computerDegrees.begin();
  for (auto computerIt = maxDegreeItor->second.begin();
       computerIt != maxDegreeItor->second.end(); ++computerIt) {
    cout << *computerIt << ' ';
  }

  return 0;
}
