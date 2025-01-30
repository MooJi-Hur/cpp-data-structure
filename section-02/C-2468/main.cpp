/*
 * Problem: 2468
 * URL: https://www.acmicpc.net/problem/2468
 */

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> deltas[DIRECTIONS] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<bool>> visited;

// Called in main
void readGrid(int &maxSafeHeight, vector<vector<int>> &originGrid);

void computeMaxSafeZones(int &maxSafeHeight,
                         int &maxSafeZoneCount,
                         vector<vector<int>> &originGrid);

void printSafeZoneCount(int maxSafeZoneCount);

// Called in computeMaxSafeZones
void createSafeZoneGrid(int &currentSafeHeight,
                        vector<vector<int>> &originGrid,
                        vector<vector<bool>> &safeZoneGrid);

int countSafeZones(vector<vector<bool>> &safeZoneGrid);

// Called in countSafeZones
void exploreSafeZone(int &currentSafeZoneCount,
                     int startRow,
                     int startCol,
                     vector<vector<bool>> &safeZoneGrid,
                     vector<vector<bool>> &visited);

// Called in exploreSafeZone
bool canMoveNext(int rowIndex,
                 int colIndex,
                 vector<vector<bool>> &grid,
                 vector<vector<bool>> &visited);

int main() {
  int gridSize;
  cin >> gridSize;

  int maxSafeHeight = 0;
  vector<vector<int>> originGrid(gridSize, vector<int>(gridSize));
  readGrid(maxSafeHeight, originGrid);

  int maxSafeZoneCount = 0;
  computeMaxSafeZones(maxSafeHeight, maxSafeZoneCount, originGrid);

  printSafeZoneCount(maxSafeZoneCount);

  return 0;
}

void readGrid(int &maxSafeHeight, vector<vector<int>> &originGrid) {
  for (auto &row : originGrid) {
    for (auto &cell : row) {
      cin >> cell;

      if (cell > maxSafeHeight) {
        maxSafeHeight = cell;
      }
    }
  }
};

void computeMaxSafeZones(int &maxSafeHeight,
                         int &maxSafeZoneCount,
                         vector<vector<int>> &originGrid) {

  for (int currentSafeHeight = maxSafeHeight; currentSafeHeight >= 1;
       --currentSafeHeight) {
    size_t gridSize = originGrid.size();
    vector<vector<bool>> safeZoneGrid(gridSize, vector<bool>(gridSize, false));
    createSafeZoneGrid(currentSafeHeight, originGrid, safeZoneGrid);

    int currentSafeZoneCount = countSafeZones(safeZoneGrid);
    maxSafeZoneCount = max(maxSafeZoneCount, currentSafeZoneCount);
  }
};

void printSafeZoneCount(int maxSafeZoneCount) { cout << maxSafeZoneCount; };

void createSafeZoneGrid(int &currentSafeHeight,
                        vector<vector<int>> &originGrid,
                        vector<vector<bool>> &safeZoneGrid) {

  for (size_t rowIndex = 0; rowIndex < originGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < originGrid.size(); ++colIndex) {
      int originCell = originGrid[rowIndex][colIndex];

      bool isSafePoint = originCell >= currentSafeHeight;

      if (isSafePoint) {
        safeZoneGrid[rowIndex][colIndex] = true;
      }
    }
  }
};

int countSafeZones(vector<vector<bool>> &safeZoneGrid) {
  int currentSafeZoneCount = 0;

  visited.assign(safeZoneGrid.size(), vector<bool>(safeZoneGrid.size(), false));

  for (size_t rowIndex = 0; rowIndex < safeZoneGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < safeZoneGrid.size(); ++colIndex) {
      bool notVisited = !visited[rowIndex][colIndex];
      bool maskedCell = safeZoneGrid[rowIndex][colIndex];

      if (notVisited && maskedCell) {
        exploreSafeZone(currentSafeZoneCount, rowIndex, colIndex, safeZoneGrid,
                        visited);
      }
    }
  }

  return currentSafeZoneCount;
};

void exploreSafeZone(int &currentSafeZoneCount,
                     int startRow,
                     int startCol,
                     vector<vector<bool>> &safeZoneGrid,
                     vector<vector<bool>> &visited) {
  ++currentSafeZoneCount;

  stack<pair<int, int>> dfsStack;
  visited[startRow][startCol] = true;
  dfsStack.push({startRow, startCol});

  while (!dfsStack.empty()) {
    auto [currentRow, currentCol] = dfsStack.top();
    dfsStack.pop();

    for (auto &[deltaRow, deltaCol] : deltas) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isValidMoveNext =
          canMoveNext(nextRow, nextCol, safeZoneGrid, visited);

      if (isValidMoveNext) {
        visited[nextRow][nextCol] = true;
        dfsStack.push({nextRow, nextCol});
      }
    }
  }
};

bool canMoveNext(int rowIndex,
                 int colIndex,
                 vector<vector<bool>> &grid,
                 vector<vector<bool>> &visited) {
  int gridSize = grid.size();
  bool isAboveMin = rowIndex >= 0 && colIndex >= 0;
  bool isBelowMax = rowIndex < gridSize && colIndex < gridSize;
  bool isInBounds = isAboveMin && isBelowMax;

  bool isSafeMove = isInBounds && (grid[rowIndex][colIndex] == true);

  bool isValidMove = isSafeMove && !visited[rowIndex][colIndex];

  return isValidMove;
};
