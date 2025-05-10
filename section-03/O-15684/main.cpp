/*
 * Problem: 15684
 * URL: https://www.acmicpc.net/problem/15684
 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr int MAX_ADD_ROW = 3;
constexpr int INVALID_RESULT = -1;

int rowSize = 0, colSize = 0, presetRowSize = 0;

void readLadder(int &presetRowSize, vector<vector<bool>> &ladder) {
  for (int presetIndex = 0; presetIndex < presetRowSize; ++presetIndex) {
    int rowIndex = 0, spanIndex = 0;
    cin >> rowIndex >> spanIndex;
    ladder[rowIndex][spanIndex] = true;
  }
};

bool validateLadder(vector<vector<bool>> &ladder) {

  for (int spanIndex = 1; spanIndex <= colSize; ++spanIndex) {
    int startCol = spanIndex;
    for (int rowIndex = 1; rowIndex <= rowSize; ++rowIndex) {
      if (ladder[rowIndex][spanIndex] == true) {
        startCol++;
      }

      if (ladder[rowIndex][spanIndex - 1] == true) {
        startCol--;
      }
    }
    if (startCol != spanIndex) {
      return false;
    }
  }
  return true;
};

void controlLadder(int &minCount,
                   int currentCount,
                   pair<int, int> currentPosition,
                   vector<vector<bool>> &ladder) {

  if (currentCount >= minCount || currentCount > MAX_ADD_ROW) {
    return;
  }

  if (validateLadder(ladder)) {
    minCount = min(minCount, currentCount);
    return;
  }

  auto [currentRow, currentSpan] = currentPosition;

  for (int rowIndex = currentRow; rowIndex <= rowSize; ++rowIndex) {

    for (int spanIndex = 1; spanIndex < colSize; ++spanIndex) {
      bool currentLine = ladder[rowIndex][spanIndex];
      bool rightLine = ladder[rowIndex][spanIndex + 1];
      bool leftLine = ladder[rowIndex][spanIndex - 1];

      if (currentLine || rightLine || leftLine) {
        continue;
      }
      ladder[rowIndex][spanIndex] = true;
      pair<int, int> nextPosition = {rowIndex, spanIndex};
      controlLadder(minCount, currentCount + 1, nextPosition, ladder);
      ladder[rowIndex][spanIndex] = false;
    }
  }
};

int main() {

  cin >> colSize >> presetRowSize >> rowSize;

  vector<vector<bool>> ladder(rowSize + 2, vector<bool>(colSize + 2, false));
  readLadder(presetRowSize, ladder);

  int minCount = INT_MAX;
  int initCount = 0;
  pair<int, int> startPosition = {1, 0};
  controlLadder(minCount, initCount, startPosition, ladder);

  if (minCount == INT_MAX) {
    cout << INVALID_RESULT;
  } else {
    cout << minCount;
  }

  return 0;
}