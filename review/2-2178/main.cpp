/*
 * Problem: 2178
 * URL: https://www.acmicpc.net/problem/2178
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char CAN_MOVE = '1';
constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<bool>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string rows = "";
    getline(cin >> ws, rows);

    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = (rows[colIndex] == CAN_MOVE);
    }
  }
}

void searchGrid(vector<vector<bool>> &inGrid, vector<vector<int>> &visited) {
  queue<pair<int, int>> bfsQueue;

  pair<int, int> startNode = {0, 0};
  int endRow = inGrid.size(), endCol = inGrid[0].size();

  bfsQueue.push(startNode);
  visited[0][0]++;

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < endRow;
      bool isInBoundCol = nextCol >= 0 && nextCol < endCol;

      bool canMove =
          isInBoundRow && isInBoundCol && (inGrid[nextRow][nextCol] == true);

      bool canVisit = canMove && visited[nextRow][nextCol] == 0;

      if (canVisit) {
        bfsQueue.push({nextRow, nextCol});
        visited[nextRow][nextCol] = visited[currentRow][currentCol] + 1;
      }
    }
  }
}

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<bool>> inGrid(rowCount, vector<bool>(colCount, false));
  readGrid(inGrid);

  vector<vector<int>> visited(rowCount, vector<int>(colCount, 0));
  searchGrid(inGrid, visited);

  cout << visited[rowCount - 1][colCount - 1];

  return 0;
}