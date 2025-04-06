/*
 * Problem: 1068
 * URL: https://www.acmicpc.net/problem/1068
 */

#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

constexpr int ROOT_FLAG = -1;

void removeNodes(int &removeId, map<int, vector<int>> &children) {

  stack<int> dfsStack;
  dfsStack.push(removeId);

  vector<bool> visited(children.size() - 1, false);

  while (!dfsStack.empty()) {
    int currentNode = dfsStack.top();
    dfsStack.pop();

    if (visited[currentNode]) {
      continue;
    }
    visited[currentNode] = true;

    if (!children[currentNode].empty()) {
      for (int childId : children[currentNode]) {
        dfsStack.push(childId);
      }
    }
    children.erase(currentNode);
  }
};

int main() {
  int nodeCount = 0;
  cin >> nodeCount;

  map<int, vector<int>> children;
  vector<int> parentIds(nodeCount);
  for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex) {
    int parentId = ROOT_FLAG;
    cin >> parentId;
    children[nodeIndex];
    children[parentId].push_back(nodeIndex);

    parentIds[nodeIndex] = parentId;
  }

  int removeId = ROOT_FLAG;
  cin >> removeId;

  int parentId = parentIds[removeId];

  for (auto iter = children[parentId].begin(); iter != children[parentId].end();
       ++iter) {
    if (*iter == removeId) {
      children[parentId].erase(iter);
      break;
    }
  }

  removeNodes(removeId, children);

  int leafCount = 0;

  for (auto node : children) {
    int nodeId = node.first;
    if (children[nodeId].empty()) {
      if (nodeId != ROOT_FLAG) {
        leafCount++;
      }
    };
  }
  cout << leafCount;

  return 0;
}