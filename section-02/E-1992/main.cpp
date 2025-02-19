/*
 * Problem: 1992
 * URL: https://www.acmicpc.net/problem/1992
 */

#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char BLACK_DOT = '1';

void readGrid(vector<vector<bool>> &grid) {
  int sideLength = grid.size();

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    string rowPixel;
    getline(cin >> ws, rowPixel);
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      grid[rowIndex][colIndex] = (rowPixel[colIndex] == BLACK_DOT);
    }
  }
}

void zipGrid(vector<vector<bool>> &grid, string &zipPixel) {
  int sideLength = grid.size();

  int startRow = 0;
  int startCol = 0;

  if (grid.size() <= 1) {
    zipPixel += to_string(grid[startRow][startCol]);
    return;
  }

  vector<vector<int>> visitedSideLength(sideLength,
                                        vector<int>(sideLength, sideLength));

  pair<int, int> startPoint = {startRow, startCol};

  stack<pair<int, int>> dfsStack;
  dfsStack.push(startPoint);

  while (!dfsStack.empty()) {
    pair<int, int> currentPoint = dfsStack.top();
    int currentRow = currentPoint.first;
    int currentCol = currentPoint.second;

    dfsStack.pop();

    int localSum = 0;

    int localSideLength = visitedSideLength[currentRow][currentCol];
    int localMaxRow = currentRow + localSideLength;
    int localMaxCol = currentCol + localSideLength;

    for (int rowIndex = currentRow; rowIndex < localMaxRow; ++rowIndex) {
      for (int colIndex = currentCol; colIndex < localMaxCol; ++colIndex) {
        localSum += grid[rowIndex][colIndex];

        if (localSideLength > 1) {
          visitedSideLength[currentRow][currentCol] = localSideLength >> 1;
        }
      }
    }

    bool sameValues =
        (localSum == 0 || localSum == (localSideLength * localSideLength));

    if (sameValues) {
      zipPixel += to_string(grid[currentRow][currentCol]);
    } else {
      localSideLength = visitedSideLength[currentRow][currentCol];
      int rowMax = localSideLength + currentRow;
      int colMax = localSideLength + currentCol;
      bool rowInBound = rowMax < sideLength;
      bool colInBound = colMax < sideLength;
      bool validLocalSideLength =
          rowInBound && colInBound && localSideLength > 1;

      if (localSideLength > 1) {
        zipPixel += "[";

        dfsStack.push({rowMax, colMax});
        dfsStack.push({rowMax, currentCol});
        dfsStack.push({currentRow, colMax});
        dfsStack.push({currentRow, currentCol});
      }
    }
  }

  // debug
  for (auto visitedRow : visitedSideLength) {
    for (int sideLength : visitedRow) {
      cout << sideLength << ' ';
    }
    cout << '\n';
  }
}

int main() {
  int sideLength = 0;
  cin >> sideLength;

  vector<vector<bool>> grid(sideLength, vector<bool>(sideLength, false));
  readGrid(grid);

  string zipPixel;
  zipGrid(grid, zipPixel);

  cout << zipPixel;
  return 0;
}