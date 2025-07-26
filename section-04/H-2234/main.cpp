/*
 * Problem: 2234
 * URL: https://www.acmicpc.net/problem/2234
 */

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;

constexpr int WEST = 1;
constexpr int NORTH = 2;
constexpr int EAST = 4;
constexpr int SOUTH = 8;

vector<vector<int>> inGrid;

int roomCount = 0;
int initRoomMaxArea = 0;
int fixedRoomMaxArea = 0;

// logic
constexpr int DIRECTIONS = 4;
pair<int, int> DELTAS[DIRECTIONS] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

vector<vector<int>> roomNumbers;
map<int, int> roomAreas;

void readGrid() {
  inGrid.resize(rowSize, vector<int>(colSize, 0));

  for (auto &row : inGrid) {
    for (auto &cell : row) {
      cin >> cell;
    }
  }
}

int calcRoom(int currentRow, int currentCol, int areaCount) {

  roomNumbers[currentRow][currentCol] = roomCount;
  roomAreas[roomCount] = areaCount;

  for (int deltaIndex = 0; deltaIndex < DIRECTIONS; ++deltaIndex) {

    auto [deltaRow, deltaCol] = DELTAS[deltaIndex];

    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    bool isOutBound =
        nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize;
    if (isOutBound) {
      continue;
    }

    bool hasWall = (inGrid[currentRow][currentCol] & (1 << deltaIndex));
    if (hasWall) {
      continue;
    }

    bool isVisited = roomNumbers[nextRow][nextCol] != 0;
    if (isVisited) {
      continue;
    }

    areaCount = calcRoom(nextRow, nextCol, areaCount + 1);
  }
  return areaCount;
}

void searchRoom() {
  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {

      if (roomNumbers[rowIndex][colIndex] != 0) {
        continue;
      }
      roomCount++;

      initRoomMaxArea = max(initRoomMaxArea, calcRoom(rowIndex, colIndex, 1));
    }
  }
}

void simulateRoom() {
  for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
    for (int colIndex = 0; colIndex < colSize; ++colIndex) {
      int currentRoom = roomNumbers[rowIndex][colIndex];

      if (rowIndex + 1 < rowSize) {
        int eastRoom = roomNumbers[rowIndex + 1][colIndex];

        if (currentRoom != eastRoom) {
          fixedRoomMaxArea = max(fixedRoomMaxArea,
                                 roomAreas[currentRoom] + roomAreas[eastRoom]);
        }
      }

      if (colIndex + 1 < colSize) {
        int southRoom = roomNumbers[rowIndex][colIndex + 1];

        if (currentRoom != southRoom) {
          fixedRoomMaxArea = max(fixedRoomMaxArea,
                                 roomAreas[currentRoom] + roomAreas[southRoom]);
        }
      }
    }
  }
}

int main() {

  cin >> colSize >> rowSize;
  readGrid();

  roomNumbers.resize(rowSize, vector<int>(colSize, 0));
  searchRoom();

  simulateRoom();

  cout << roomCount << '\n' << initRoomMaxArea << '\n' << fixedRoomMaxArea;

  return 0;
}