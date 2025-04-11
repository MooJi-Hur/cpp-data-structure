/*
 * Problem: 4179
 * URL: https://www.acmicpc.net/problem/4179
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char WALL = '#';
constexpr char PATH = '.';
constexpr char JEEHUN = 'J';
constexpr char FIRE = 'F';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<char>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex];
    }
  }
};

void moveNext(pair<int, int> &startNode,
              vector<vector<char>> &inGrid,
              vector<vector<bool>> &visited) {

  auto [startRow, startCol] = startNode;

  if (visited[startRow][startCol]) {
    return;
  }
  visited[startRow][startCol] = true;

  queue<pair<int, int>> bfsQueue;

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    char currentCell = inGrid[currentRow][currentCol];
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      char nextCell = inGrid[nextRow][nextCol];

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();
      bool isSafeNext = isInBoundRow && isInBoundCol && nextCell == PATH;
      bool canMove = isSafeNext && !visited[nextRow][nextCol];

      if (canMove) {
        bool needMove = currentCell == FIRE || currentCell == JEEHUN;
        if (needMove) {
          visited[nextRow][nextCol] = true;
          bfsQueue.push({nextRow, nextCol});
          if (currentCell == FIRE) {
            inGrid[nextRow][nextCol] = FIRE;
          }
        }
      }
    }
  }
};

int main() {

  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<char>> inGrid(rowCount, vector<char>(colCount));
  readGrid(inGrid);

  bool isPossible = true;
  bool isGoal = false;
  int timeCount = 0;

  while (!isGoal) {
    for (int startRow = 0; startRow < rowCount; ++startRow) {
      for (int startCol = 0; startCol < colCount; ++startCol) {
        vector<vector<bool>> visitedJ(rowCount, vector<bool>(colCount, false));
        vector<vector<bool>> visitedF(rowCount, vector<bool>(colCount, false));

        if (inGrid[startRow][startCol] == JEEHUN) {
          pair<int, int> startNode = {startRow, startCol};
          moveNext(startNode, inGrid, visitedJ);
        }
      }
    }

    for (int startRow = 0; startRow < rowCount; ++startRow) {
      for (int startCol = 0; startCol < colCount; ++startCol) {
      }
    }

    if (!isPossible) {
      cout << "IMPOSSIBLE";
      return 0;
    }

    if (true) {
      isGoal = true;
    }
    timeCount++;
  }

  cout << timeCount;

  return 0;
}
