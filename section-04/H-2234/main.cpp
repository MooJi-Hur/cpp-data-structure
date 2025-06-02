/*
 * Problem: 2234
 * URL: https://www.acmicpc.net/problem/2234
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;

constexpr int WEST = 1;
constexpr int NORTH = 2;
constexpr int EAST = 4;
constexpr int SOUTH = 8;

vector<vector<int>> wallInfos;

// out
int roomCount = 0;
int maxInitRoomArea = 0;
int maxAreaExceptOneWall = 0;

// logic
vector<vector<bool>> visited;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void readCells() {
  wallInfos.resize(rowSize, vector<int>(colSize, 0));

  for (auto &row : wallInfos) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }
};

int goNextRoom(int currentRow, int currentCol, int roomArea) {

  for (int deltaIndex = 0; deltaIndex < DIRECTIONS; ++deltaIndex) {
    auto [deltaRow, deltaCol] = DELTAS[deltaIndex];

    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    bool isOutBound =
        nextRow < 0 || nextCol < 0 || nextRow >= rowSize || nextCol >= colSize;

    if (isOutBound) {
      continue;
    }

    int hasBlock = wallInfos[currentRow][currentCol] & (1 << deltaIndex);
    bool stopNext = hasBlock || visited[nextRow][nextCol];

    if (stopNext) {
      continue;
    }

    visited[nextRow][nextCol] = true;
    roomArea = goNextRoom(nextRow, nextCol, roomArea + 1);
  }
  return roomArea;
};

void searchRoom(int &maxValue) {
  visited.clear();
  visited.resize(rowSize, vector<bool>(colSize, false));
  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {

      if (!visited[rowIndex][colIndex]) {
        visited[rowIndex][colIndex] = 1;
        maxValue = max(maxValue, goNextRoom(rowIndex, colIndex, 1));

        if (&maxValue == &maxInitRoomArea) {
          roomCount++;
        }
      }
    }
  }
};

void simulateWall() {
  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      for (int deltaIndex = 0; deltaIndex < DIRECTIONS; ++deltaIndex) {
        int originWall = wallInfos[rowIndex][colIndex];

        wallInfos[rowIndex][colIndex] = wallInfos[rowIndex][colIndex] ^=
            (1 << deltaIndex);

        searchRoom(maxAreaExceptOneWall);

        wallInfos[rowIndex][colIndex] = originWall;
      }
    }
  }
};

int main() {

  cin >> colSize >> rowSize;

  readCells();

  searchRoom(maxInitRoomArea);

  simulateWall();

  cout << roomCount << '\n' << maxInitRoomArea << '\n' << maxAreaExceptOneWall;

  return 0;
}
