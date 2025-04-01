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

constexpr char ROAD = '1';
constexpr char WALL = '0';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<bool>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string currentRow;
    getline(cin >> ws, currentRow);
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = (currentRow[colIndex] == ROAD);
    }
  }
};

void countVisitGrid(vector<vector<bool>> &inGrid,
                    vector<vector<int>> &visitCountGrid) {

  pair<int, int> startNode = {0, 0};
  queue<pair<int, int>> bfsQueue;
  bfsQueue.push(startNode);
  visitCountGrid[0][0] = true;

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool canMove =
          isInBoundRow && isInBoundCol && (inGrid[nextRow][nextCol] == true);

      bool canVisit = canMove && (visitCountGrid[nextRow][nextCol] == 0);

      if (canVisit) {
        bfsQueue.push({nextRow, nextCol});
        visitCountGrid[nextRow][nextCol] =
            visitCountGrid[currentRow][currentCol] + 1;
      }
    }
  }
};

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<bool>> inGrid(rowCount, vector<bool>(colCount, false));
  readGrid(inGrid);

  vector<vector<int>> visitCountGrid(rowCount, vector<int>(colCount, 0));
  countVisitGrid(inGrid, visitCountGrid);

  int lastRow = rowCount - 1, lastCol = colCount - 1;
  cout << visitCountGrid[lastRow][lastCol];
  return 0;
}