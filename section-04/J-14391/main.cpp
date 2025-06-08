/*
 * Problem: 14391
 * URL: https://www.acmicpc.net/problem/14391
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;
vector<vector<int>> inGrid;

constexpr char ZERO = '0';

// out
int maxScore = 0;

void readGrid() {
  inGrid.resize(rowSize, vector<int>(colSize, 0));

  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex] - ZERO;
    }
  }
};

void findMax() {

  for (int combiIndex = 0; combiIndex < (1 << (rowSize * colSize));
       ++combiIndex) {
    int sum = 0;

    for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
      int rowSum = 0;

      for (int colIndex = 0; colIndex < colSize; ++colIndex) {
        int cellIndex = rowIndex * colSize + colIndex;

        bool isRowCombi = ((combiIndex & (1 << cellIndex)) != 0);
        if (isRowCombi) {
          rowSum = rowSum * 10 + inGrid[rowIndex][colIndex];

        } else {
          sum += rowSum;
          rowSum = 0;
        }
      }

      sum += rowSum;
    }

    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      int colSum = 0;

      for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
        int cellIndex = rowIndex * colSize + colIndex;

        bool isColCombi = ((combiIndex & (1 << cellIndex)) == 0);
        if (isColCombi) {
          colSum = colSum * 10 + inGrid[rowIndex][colIndex];

        } else {
          sum += colSum;
          colSum = 0;
        }
      }

      sum += colSum;
    }

    maxScore = max(maxScore, sum);
  }
};

int main() {
  cin >> rowSize >> colSize;

  readGrid();

  findMax();

  cout << maxScore;
  return 0;
}