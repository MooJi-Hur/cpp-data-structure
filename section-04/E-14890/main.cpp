/*
 * Problem: 14890
 * URL: https://www.acmicpc.net/problem/14890
 */

#include <iostream>
#include <vector>

using namespace std;

// in
int sideLength, ladderWidth;
vector<vector<int>> inGridOrigin;
vector<vector<int>> inGridRotate;

// out
int pathCount;

void readGrid() {
  inGridOrigin.resize(sideLength, vector<int>(sideLength, 0));
  inGridRotate.resize(sideLength, vector<int>(sideLength, 0));

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      int cell = 0;
      cin >> cell;
      inGridOrigin[rowIndex][colIndex] = cell;
      inGridRotate[colIndex][rowIndex] = cell;
    }
  }
}

void buildLadder(vector<vector<int>> &inGrid) {

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    int currentLadder = 1;
    int colIndex;

    for (colIndex = 0; colIndex < sideLength - 1; ++colIndex) {
      int currentCell = inGrid[rowIndex][colIndex];
      int nextCell = inGrid[rowIndex][colIndex + 1];
      if (currentCell == nextCell) {
        currentLadder++;
      } else if ((currentCell + 1 == nextCell) &&
                 (currentLadder >= ladderWidth)) { // /_| 2 3
        currentLadder = 1;                         // 초기화
      } else if ((currentCell - 1 == nextCell) &&
                 (currentLadder >= 0)) { // 3 2 |_
        currentLadder = -ladderWidth + 1;
      } else {
        break;
      }
    }
    if (colIndex == sideLength - 1 && currentLadder >= 0) {
      pathCount++;
    }
  }
}

int main() {

  cin >> sideLength >> ladderWidth;

  readGrid();

  buildLadder(inGridOrigin);
  buildLadder(inGridRotate);

  cout << pathCount;

  return 0;
}