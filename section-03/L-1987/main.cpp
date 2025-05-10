/*
 * Problem: 1987
 * URL: https://www.acmicpc.net/problem/1987
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int rowSize, colSize;
constexpr int MAX_SIDE_LENGTH = 20;
constexpr char LARGE_START = 'A';
constexpr char LARGE_END = 'Z';

vector<vector<char>> inBoard;

constexpr int LARGE_CHAR_SIZE = LARGE_END - LARGE_START + 1;
vector<bool> visitedChar(LARGE_CHAR_SIZE);

int maxCellCount;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readBoard() {
  inBoard.resize(rowSize, vector<char>(colSize));

  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      inBoard[rowIndex][colIndex] = row[colIndex];
    }
  }
};

void go(int cellCount, pair<int, int> currentPoint) {
  maxCellCount = max(maxCellCount, cellCount);

  auto [currentRow, currentCol] = currentPoint;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    bool isOutBound =
        nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize;

    if (isOutBound) {

      continue;
    }

    int nextCharIndex = inBoard[nextRow][nextCol] - LARGE_START;
    bool isNewChar = visitedChar[nextCharIndex] == false;

    if (isNewChar) {

      visitedChar[nextCharIndex] = true;

      pair<int, int> nextPoint = {nextRow, nextCol};
      go(cellCount + 1, nextPoint);

      visitedChar[nextCharIndex] = false;
    }
  }
};

int main() {
  cin >> rowSize >> colSize;
  readBoard();

  int initCellCount = 1;

  pair<int, int> initPoint = {0, 0};
  int startCharIndex = inBoard[0][0] - LARGE_START;
  visitedChar[startCharIndex] = true;

  go(initCellCount, initPoint);

  cout << maxCellCount;
  return 0;
}
