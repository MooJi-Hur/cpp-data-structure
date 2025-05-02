/*
 * Problem: 15684
 * URL: https://www.acmicpc.net/problem/15684
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_ADDED_LINE = 3;
constexpr int INVALID_RESULT = -1;

int rowSize = 0, colSize = 0, maxRowCount = 0;

void readLadder(vector<vector<bool>> &ladder) {
  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    int inRow = 0, inLeftCol = 0;
    cin >> inRow >> inLeftCol;

    ladder[inRow][inLeftCol] = true;
  }
};

bool isValidLadder(vector<vector<bool>> &ladder) {
  for (int colIndex = 1; colIndex <= colSize; ++colIndex) {
    int startCol = (int)colIndex;
    for (int rowIndex = 1; rowIndex <= maxRowCount; ++rowIndex) {
      if (ladder[rowIndex][startCol]) {
        startCol++;
      } else if (ladder[rowIndex][startCol - 1]) {
        startCol--;
      }
    }
    if (startCol != (int)colIndex) {
      return false;
    }
  }
  return true;
};

void controlLadder(int &minAddedLine,
                   int startRow,
                   int addedLineCount,
                   vector<vector<bool>> &ladder) {

  bool isCountOverRange = addedLineCount > MAX_ADDED_LINE;
  bool isCountOverMin = addedLineCount >= minAddedLine;

  if (isCountOverRange || isCountOverMin) {
    return;
  }

  if (isValidLadder(ladder)) {
    minAddedLine = min(minAddedLine, addedLineCount);
    return;
  }

  for (int rowIndex = startRow; rowIndex <= maxRowCount; ++rowIndex) {
    for (int colIndex = 1; colIndex < colSize; ++colIndex) {

      if (ladder[rowIndex][colIndex] || ladder[rowIndex][colIndex - 1] ||
          ladder[rowIndex][colIndex + 1]) {
        continue;
      }
      ladder[rowIndex][colIndex] = true;
      controlLadder(minAddedLine, rowIndex, addedLineCount + 1, ladder);

      ladder[rowIndex][colIndex] = false;
    }
  }
};

int main() {

  cin >> colSize >> rowSize >> maxRowCount;

  vector<vector<bool>> ladder(maxRowCount + 2, vector<bool>(colSize + 2, 0));
  readLadder(ladder);

  int minAddedLine = INT_MAX;
  int startRow = 1;
  int initAddedLineCount = 0;
  controlLadder(minAddedLine, startRow, initAddedLineCount, ladder);

  if (minAddedLine == INT_MAX) {
    cout << INVALID_RESULT;
  } else {
    cout << minAddedLine;
  }

  return 0;
}