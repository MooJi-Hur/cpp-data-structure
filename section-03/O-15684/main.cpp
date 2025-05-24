/*
 * Problem: 15684
 * URL: https://www.acmicpc.net/problem/15684
 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0, preRowSize = 0;

// out
int minAddedRow = INT_MAX;

constexpr int MAX_ADDED_ROW = 3;
constexpr int NO_RESULT = -1;

// logic
vector<vector<bool>> ladder;

void readPreRow() {
  ladder.resize(rowSize + 1, vector<bool>(colSize + 1, false));

  for (int preRowIndex = 0; preRowIndex < preRowSize; ++preRowIndex) {
    int rowIndex = 0, colIndex = 0;
    cin >> rowIndex >> colIndex;

    ladder[rowIndex][colIndex] = 1;
  }
};

bool validateLadder() {

  for (int colIndex = 1; colIndex <= colSize; ++colIndex) {
    int startCol = colIndex;

    for (int rowIndex = 1; rowIndex <= rowSize; ++rowIndex) {
      if (ladder[rowIndex][startCol]) {
        startCol++;
      } else if (ladder[rowIndex][startCol - 1]) {
        startCol--;
      }
    }

    if (startCol != colIndex) {
      return false;
    }
  }

  return true;
};

void controlLadder(int currentRow, int currentCol, int currentCount) {

  bool isOutOfLimit = currentCount > MAX_ADDED_ROW;
  bool isOutOfMin = currentCount >= minAddedRow;

  if (isOutOfLimit || isOutOfMin) {
    return;
  }

  if (validateLadder()) {
    minAddedRow = min(minAddedRow, currentCount);

    return;
  }

  for (int nextRow = currentRow; nextRow <= rowSize; ++nextRow) {
    for (int nextCol = 1; nextCol < colSize; ++nextCol) {
      bool isInvalidRow = ladder[nextRow][nextCol] ||
                          (nextCol > 1 && ladder[nextRow][nextCol - 1]) ||
                          (nextCol < colSize && ladder[nextRow][nextCol + 1]);

      if (isInvalidRow)
        continue;

      ladder[nextRow][nextCol] = true;
      controlLadder(nextRow, nextCol, currentCount + 1);
      ladder[nextRow][nextCol] = false;
    }
  }
};

int main() {

  cin >> colSize >> preRowSize >> rowSize;

  readPreRow();

  int startRow = 1;
  int initCount = 0;
  controlLadder(startRow, 1, initCount);

  if (minAddedRow == INT_MAX) {
    cout << NO_RESULT;
  } else {
    cout << minAddedRow;
  }

  return 0;
}