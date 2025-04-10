/*
 * Problem: 16234
 * URL: https://www.acmicpc.net/problem/16234
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

constexpr int DIRECTIONS = 3;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {{1, 0}, {1, 1}, {0, 1}};

void readGrid(vector<vector<int>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {

      cin >> inGrid[rowIndex][colIndex];
    }
  }
};

void movePeople(pair<int, int> &startNode,
                vector<vector<int>> &inGrid,
                vector<vector<bool>> &visited) {

  queue<pair<int, int>> bfsQueue;
  bfsQueue.push(startNode);
  visited[startNode.first][startNode.second] = true;

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      if (isInBoundRow && isInBoundCol) {
      }
    }
  }
};

int main() {
  int sideLength = 0, minDiffer = 0, maxDiffer = 0;
  cin >> sideLength >> minDiffer >> maxDiffer;

  vector<vector<int>> inGrid(sideLength, vector<int>(sideLength, -1));
  readGrid(inGrid);

  int dayCount = -1;
  bool hasOpenWall = true;

  while (true) {

    for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
      for (int colIndex = 0; colIndex < sideLength; ++colIndex) {

        vector<vector<bool>> visited(sideLength,
                                     vector<bool>(sideLength, false));

        pair<int, int> startNode = {rowIndex, colIndex};
        movePeople(startNode, inGrid, visited);
      }
    }

    dayCount++;
    if (!hasOpenWall) {
      break;
    }
  }

  cout << dayCount;

  return 0;
}