/*
 * Problem: 17136
 * URL: https://www.acmicpc.net/problem/17136
 */

#include <array>
#include <climits>
#include <iostream>
#include <utility>

using namespace std;

constexpr int SIDE_SIZE = 10;
constexpr int MAX_BLOCK_SIZE = 5;

array<int, MAX_BLOCK_SIZE + 1> blockCount;

void readGrid(array<array<int, SIDE_SIZE>, SIDE_SIZE> &inGrid) {
  for (auto &row : inGrid) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }
};

bool canAdd(int &blockSize,
            pair<int, int> currentPoint,
            array<array<int, SIDE_SIZE>, SIDE_SIZE> &inGrid) {

  auto [currentRow, currentCol] = currentPoint;

  bool isOutBound = currentRow + blockSize > (int)inGrid.size() ||
                    currentCol + blockSize > (int)inGrid[0].size();

  if (isOutBound) {
    return false;
  }
  for (int rowIndex = currentRow; rowIndex < currentRow + blockSize;
       ++rowIndex) {
    for (int colIndex = currentCol; colIndex < currentCol + blockSize;
         ++colIndex) {

      bool isEmpty = inGrid[rowIndex][colIndex] == 0;

      if (isEmpty) {
        return false;
      }
    }
  }

  return true;
};

void controlBlock(int isDetach,
                  int &blockSize,
                  pair<int, int> currentPoint,
                  array<array<int, SIDE_SIZE>, SIDE_SIZE> &inGrid) {
  auto [currentRow, currentCol] = currentPoint;

  for (int rowIndex = currentRow; rowIndex < currentRow + blockSize;
       ++rowIndex) {
    for (int colIndex = currentCol; colIndex < currentCol + blockSize;
         ++colIndex) {
      inGrid[rowIndex][colIndex] = isDetach ? 1 : 0;
    }
  }
};

void addBlock(int &minCount,
              int attachCount,
              pair<int, int> currentPoint,
              array<array<int, SIDE_SIZE>, SIDE_SIZE> &inGrid) {

  if (attachCount >= minCount) {
    return;
  }

  auto [currentRow, currentCol] = currentPoint;
  pair<int, int> nextPoint;

  if (currentRow == SIDE_SIZE) {
    minCount = min(minCount, attachCount);

    return;
  }

  if (currentCol == SIDE_SIZE) {
    nextPoint = {currentRow + 1, 0};
    addBlock(minCount, attachCount, nextPoint, inGrid);
    return;
  }

  if (inGrid[currentRow][currentCol] == 0) {
    nextPoint = {currentRow, currentCol + 1};
    addBlock(minCount, attachCount, nextPoint, inGrid);
    return;
  }

  for (int blockSize = MAX_BLOCK_SIZE; blockSize > 0; --blockSize) {
    if (canAdd(blockSize, currentPoint, inGrid)) {
      if (blockCount[blockSize] == 0) {
        return;
      }

      blockCount[blockSize]--;
      controlBlock(false, blockSize, currentPoint, inGrid);

      nextPoint = {currentRow, currentCol + blockSize};
      addBlock(minCount, attachCount + 1, nextPoint, inGrid);

      controlBlock(true, blockSize, currentPoint, inGrid);
      blockCount[blockSize]++;
    }
  }
};

int main() {
  array<array<int, SIDE_SIZE>, SIDE_SIZE> inGrid;
  readGrid(inGrid);

  int minCount = INT_MAX;
  int attachCount = 0;
  pair<int, int> startPoint = {0, 0};
  blockCount.fill(5);
  addBlock(minCount, attachCount, startPoint, inGrid);

  if (minCount == INT_MAX) {
    cout << -1;
  } else {
    cout << minCount;
  }

  return 0;
}