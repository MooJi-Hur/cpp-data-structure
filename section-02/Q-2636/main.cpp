/*
 * Problem: 2636
 * URL: https://www.acmicpc.net/problem/2636
 */

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

constexpr int CHEESE = 1;
constexpr int WALL = 0;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<bool>> &inGrid) {
  for (vector<bool> &row : inGrid) {
    for (vector<bool>::reference cell : row) {
      int inCell = 0;
      cin >> inCell;
      cell = (inCell == CHEESE);
    }
  }
};

void findOpenNodes(vector<vector<bool>> &inGrid,
                   int &hourCount,
                   set<pair<int, int>> &openNodes,
                   vector<vector<bool>> &visited,
                   vector<vector<int>> &history) {

  pair<int, int> startNode = {0, 0};
  stack<pair<int, int>> dfsStack;

  dfsStack.push(startNode);
  openNodes.insert(startNode);

  while (!dfsStack.empty()) {
    auto [currentRow, currentCol] = dfsStack.top();
    dfsStack.pop();

    if (visited[currentRow][currentCol]) {
      continue;
    }
    visited[currentRow][currentCol] = true;

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      if (isInBoundRow && isInBoundCol) {

        bool canVisit = (visited[nextRow][nextCol] == false);
        bool isWall = (inGrid[nextRow][nextCol] == WALL);

        if (canVisit) {
          pair<int, int> nextNode = {nextRow, nextCol};
          if (isWall) {
            openNodes.insert(nextNode);
            dfsStack.push(nextNode);
          } else {
            history[nextRow][nextCol] = hourCount;
          }
        }
      }
    }
  }
};

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<bool>> inGrid(rowCount, vector<bool>(colCount, false));
  readGrid(inGrid);

  int hourCount = 1;
  map<int, int> cheeseCounts;
  set<pair<int, int>> openNodes;
  vector<vector<int>> history(rowCount, vector<int>(colCount, 0));

  while (openNodes.size() < rowCount * colCount) {
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    findOpenNodes(inGrid, hourCount, openNodes, visited, history);

    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int colIndex = 0; colIndex < colCount; ++colIndex) {
        if (history[rowIndex][colIndex] == hourCount) {
          inGrid[rowIndex][colIndex] = WALL;
          cheeseCounts[hourCount]++;
        }
      }
    }
    hourCount++;
  }

  auto latest = cheeseCounts.rbegin();
  cout << latest->first << '\n' << latest->second;

  return 0;
}