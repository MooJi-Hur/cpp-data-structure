/*
 * Problem: 17136
 * URL: https://www.acmicpc.net/problem/17136
 */

#include <array>
#include <climits>
#include <iostream>
#include <numeric>

using namespace std;

// in
constexpr int ATTACHABLE = 1;
constexpr int EMPTY_CELL = 0;

constexpr int SIDE_SIZE = 10;
constexpr int SQUARE_SIZE = SIDE_SIZE * SIDE_SIZE;
array<array<int, SIDE_SIZE>, SIDE_SIZE> inBoard;

// out
int minSumPaper = INT_MAX;
constexpr int OUT_OF_RESULT = -1;

// logic
constexpr int PAPER_TYPES = 5;
constexpr int MAX_PAPER_COUNT = 5;
array<int, PAPER_TYPES + 1> paperCounts{};

void readBoard() {
  for (auto &row : inBoard) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }
};

bool canAttatch(int startRow, int startCol, int paperSize) {
  if (paperCounts[paperSize] >= MAX_PAPER_COUNT) {
    return false;
  }

  int rowSize = startRow + paperSize;
  int colSize = startCol + paperSize;

  if (rowSize > SIDE_SIZE || colSize > SIDE_SIZE) {
    return false;
  }

  for (int rowIndex = startRow; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = startCol; colIndex < colSize; ++colIndex) {
      int currentCell = inBoard[rowIndex][colIndex];

      if (currentCell == EMPTY_CELL) {
        return false;
      }
    }
  }
  return true;
};

void setPapers(bool isDetach, int startRow, int startCol, int paperSize) {

  int rowSize = startRow + paperSize;
  int colSize = startCol + paperSize;

  for (int rowIndex = startRow; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = startCol; colIndex < colSize; ++colIndex) {
      int currentCell = inBoard[rowIndex][colIndex];

      inBoard[rowIndex][colIndex] = isDetach ? ATTACHABLE : EMPTY_CELL;
    }
  }

  for (auto &row : inBoard) {
    for (auto &cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
};

void testPapers(int currentIndex) {
  int currentRow = currentIndex / SIDE_SIZE;
  int currentCol = currentIndex % SIDE_SIZE;

  int currentCell = inBoard[currentRow][currentCol];

  int nextIndex = currentIndex + 1;

  if (currentCell == EMPTY_CELL) {
    testPapers(nextIndex);
    return;
  } else {
    // cout << currentIndex << '\n';
    // cout << currentRow << ' ' << currentCol << '\n';
  }

  int sumPaper = accumulate(paperCounts.begin(), paperCounts.end(), 0);

  if (sumPaper >= minSumPaper) {
    cout << '\n';
    return;
  }

  if (currentIndex >= SQUARE_SIZE) {

    minSumPaper = min(minSumPaper, sumPaper);
    cout << '\n';
    return;
  }

  for (int paperSize = PAPER_TYPES; paperSize > 0; --paperSize) {

    if (canAttatch(currentRow, currentCol, paperSize)) {
      cout << paperSize << ' ' << currentIndex << '\n';

      paperCounts[paperSize]++;
      setPapers(false, currentRow, currentCol, paperSize);

      nextIndex = currentIndex + paperSize;
      testPapers(nextIndex);

      paperCounts[paperSize]--;
      setPapers(true, currentRow, currentCol, paperSize);
    }
  }
};

int main() {

  readBoard();

  int startIndex = 0;
  testPapers(startIndex);

  if (minSumPaper == INT_MAX) {
    cout << OUT_OF_RESULT;
  } else {
    cout << minSumPaper;
  }

  return 0;
}