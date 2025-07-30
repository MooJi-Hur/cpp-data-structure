/*
 * Problem: 9934
 * URL: https://www.acmicpc.net/problem/9934
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// in
int treeHeight;
vector<int> inNodes;

// out
map<int, vector<int>> sortedByLevel;

// logic

void readNodes() {
  int nodeSize = (1 << treeHeight) - 1;
  inNodes.resize(nodeSize);

  for (int nodeIndex = 0; nodeIndex < nodeSize; ++nodeIndex) {
    cin >> inNodes[nodeIndex];
  }
}

void findNextLevel(int startIndex, int endIndex, int currentLevel) {
  if (currentLevel > treeHeight) {
    return;
  }

  // startIndex = 4, endIndex = 6 -> halfSize = 1, midIndex = 5;
  int halfSize = (endIndex - startIndex) >> 1;

  int midIndex = startIndex + halfSize;
  sortedByLevel[currentLevel].push_back(inNodes[midIndex]);

  findNextLevel(startIndex, midIndex - 1, currentLevel + 1);
  findNextLevel(midIndex + 1, endIndex, currentLevel + 1);
}

void printNodes() {
  for (int levelIndex = 1; levelIndex <= sortedByLevel.size(); ++levelIndex) {
    for (int nodeIndex = 0; nodeIndex < sortedByLevel[levelIndex].size();
         ++nodeIndex) {
      cout << sortedByLevel[levelIndex][nodeIndex] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  cin >> treeHeight;

  readNodes();

  findNextLevel(0, inNodes.size() - 1, 1);

  printNodes();

  return 0;
}