/*
 * Problem: 14502
 * URL: https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;

constexpr int EMPTY = 0;
constexpr int WALL = 1;
constexpr int VIRUS = 2;

// out
int currentSafeSize = 0;
int maxSafeSize = 0;

// logic
constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

constexpr int MAX_WALL_COUNT = 3;

vector<vector<int>> inGrid;

void readGrid() {
  inGrid.resize(rowSize, vector<int>(colSize, 0));

  for (auto &row : inGrid) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }
}

void countSafeSize(vector<vector<int>> &currentGrid) {

  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      if (currentGrid[rowIndex][colIndex] == EMPTY) {
        currentSafeSize++;
      }
    }
  }
}

void spreadVirus(vector<vector<int>> &currentGrid) {

  queue<pair<int, int>> bfsQueue;

  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      int currentCell = currentGrid[rowIndex][colIndex];

      if (currentCell == VIRUS) {

        pair<int, int> startIndex = {rowIndex, colIndex};

        bfsQueue.push(startIndex);

        while (!bfsQueue.empty()) {

          auto [currentRow, currentCol] = bfsQueue.front();
          bfsQueue.pop();

          currentGrid[currentRow][currentCol] = VIRUS;

          for (auto [deltaRow, deltaCol] : DELTAS) {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isInBound = nextRow >= 0 && nextRow < rowSize &&
                             nextCol >= 0 && nextCol < colSize;

            if (!isInBound) {
              continue;
            }

            bool canMoveNext = currentGrid[nextRow][nextCol] == EMPTY;
            if (canMoveNext) {
              pair<int, int> nextCell = {nextRow, nextCol};
              bfsQueue.push(nextCell);
            }
          }
        }
      }
    }
  }

  countSafeSize(currentGrid);
}

void simulateWall(int startIndex, int currentCount) {
  if (currentCount >= MAX_WALL_COUNT) {
    vector<vector<int>> currentGrid = inGrid;

    currentSafeSize = 0;
    spreadVirus(currentGrid);

    maxSafeSize = max(maxSafeSize, currentSafeSize);
    return;
  }

  for (int currentIndex = startIndex; currentIndex < (rowSize * colSize);
       ++currentIndex) {

    int rowIndex = currentIndex / colSize;
    int colIndex = currentIndex % colSize;

    int currentCell = inGrid[rowIndex][colIndex];

    if (currentCell != EMPTY) {
      continue;
    }

    inGrid[rowIndex][colIndex] = WALL;
    simulateWall(currentIndex + 1, currentCount + 1);
    inGrid[rowIndex][colIndex] = EMPTY;
  }
}

int main() {

  cin >> rowSize >> colSize;

  readGrid();

  int startIndex = 0;
  int initCount = 0;
  simulateWall(startIndex, initCount);

  cout << maxSafeSize;

  return 0;
}