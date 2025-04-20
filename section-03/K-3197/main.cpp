/*
 * Problem: 3197
 * URL: https://www.acmicpc.net/problem/3197
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char WATER = '.';
constexpr char ICE = 'X';
constexpr char BIRD = 'L';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<char>> &inGrid,
              vector<pair<int, int>> &birdPositions) {

  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex];

      if (row[colIndex] == BIRD) {
        birdPositions.push_back({rowIndex, colIndex});
      }
    }
  }
};

void meetBirds(bool &canMeet,
               vector<vector<char>> &inGrid,
               vector<pair<int, int>> &birdPositions,
               vector<pair<int, int>> &icePositions) {

  auto [startRow, startCol] = *birdPositions.begin();
  queue<pair<int, int>> bfsQueue;
  bfsQueue.push({startRow, startCol});

  vector<vector<bool>> visited(inGrid.size(),
                               vector<bool>(inGrid[0].size(), false));
  visited[startRow][startCol] = true;

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool needVisit = isInRow && isInCol && !visited[nextRow][nextCol];
      bool canMove = needVisit && (inGrid[nextRow][nextCol] == WATER);
      bool readyMeet = needVisit && (inGrid[nextRow][nextCol] == BIRD);

      if (needVisit) {
        switch (inGrid[nextRow][nextCol]) {
        case ICE:
          icePositions.push_back({nextRow, nextCol});
          break;
        case WATER:
          bfsQueue.push({nextRow, nextCol});
          visited[nextRow][nextCol] = true;
          break;
        case BIRD:
          canMeet = true;
          break;

        default:
          break;
        }
      }
    }
  }
};

void meltIce(vector<vector<char>> &inGrid,
             vector<pair<int, int>> &icePositions) {
  for (auto [iceRow, iceCol] : icePositions) {
    inGrid[iceRow][iceCol] = WATER;
  }

  for (auto row : inGrid) {
    for (char cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
  }

  cout << '\n';
};

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<char>> inGrid(rowCount, vector<char>(colCount));
  vector<pair<int, int>> birdPositions;

  readGrid(inGrid, birdPositions);

  bool canMeet = false;
  int dayCount = 0;

  do {
    dayCount++;
    vector<pair<int, int>> icePositions;
    meetBirds(canMeet, inGrid, birdPositions, icePositions);

    if (!icePositions.empty()) {
      meltIce(inGrid, icePositions);
    }

  } while (canMeet == false);

  cout << dayCount;
  return 0;
}
