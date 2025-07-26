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
constexpr char SWAN = 'L';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<char>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string row;
    getline(cin >> ws, row);

    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex];
    }
  }
};

void initFloodFills(vector<vector<char>> &inGrid,
                    queue<pair<int, int>> &swanQueue,
                    vector<vector<bool>> &swanVisited,
                    queue<pair<int, int>> &waterQueue,
                    vector<vector<bool>> &waterVisited) {

  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      char currentCell = inGrid[rowIndex][colIndex];

      bool isFirstSWAN = currentCell == SWAN && swanQueue.empty();
      if (isFirstSWAN) {
        swanQueue.push({rowIndex, colIndex});
        swanVisited[rowIndex][colIndex] = true;
      }

      bool isWater = currentCell == WATER || currentCell == SWAN;
      if (isWater) {
        waterQueue.push({rowIndex, colIndex});
        waterVisited[rowIndex][colIndex] = true;
      }
    }
  }
};

void moveSwan(bool &canMeet,
              vector<vector<char>> &inGrid,
              queue<pair<int, int>> &swanQueue,
              vector<vector<bool>> &swanVisited,
              queue<pair<int, int>> &swanNextQueue) {

  while (!swanQueue.empty()) {
    auto [currentRow, currentCol] = swanQueue.front();
    swanQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool needVisit = isInRow && isInCol && !swanVisited[nextRow][nextCol];

      if (needVisit) {
        swanVisited[nextRow][nextCol] = true;
        char nextCell = inGrid[nextRow][nextCol];

        if (nextCell == SWAN) {
          canMeet = true;
        } else if (nextCell == WATER) {
          swanQueue.push({nextRow, nextCol});
        } else if (nextCell == ICE) {
          swanNextQueue.push({nextRow, nextCol});
        }
      }
    }
  }
};

void meltIce(vector<vector<char>> &inGrid,
             queue<pair<int, int>> &waterQueue,
             vector<vector<bool>> &waterVisited,
             queue<pair<int, int>> &waterNextQueue) {
  while (!waterQueue.empty()) {
    auto [currentRow, currentCol] = waterQueue.front();
    waterQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool needVisit = isInRow && isInCol && !waterVisited[nextRow][nextCol];
      bool needMelting = needVisit && inGrid[nextRow][nextCol] == ICE;

      if (needMelting) {
        waterNextQueue.push({nextRow, nextCol});
        waterVisited[nextRow][nextCol] = true;
        inGrid[nextRow][nextCol] = WATER;
      }
    }
  }
};

int main() {

  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<char>> inGrid(rowCount, vector<char>(colCount));
  readGrid(inGrid);

  queue<pair<int, int>> swanQueue;
  vector<vector<bool>> swanVisited(rowCount, vector<bool>(colCount, false));

  queue<pair<int, int>> waterQueue;
  vector<vector<bool>> waterVisited(rowCount, vector<bool>(colCount, false));
  initFloodFills(inGrid, swanQueue, swanVisited, waterQueue, waterVisited);

  bool canMeet = false;
  int dayCount = 0;
  queue<pair<int, int>> swanNextQueue;
  queue<pair<int, int>> waterNextQueue;

  while (true) {
    moveSwan(canMeet, inGrid, swanQueue, swanVisited, swanNextQueue);
    if (canMeet)
      break;
    meltIce(inGrid, waterQueue, waterVisited, waterNextQueue);

    swap(swanQueue, swanNextQueue);
    swap(waterQueue, waterNextQueue);

    swanNextQueue = queue<pair<int, int>>();
    waterNextQueue = queue<pair<int, int>>();

    dayCount++;
  };

  cout << dayCount;

  return 0;
}