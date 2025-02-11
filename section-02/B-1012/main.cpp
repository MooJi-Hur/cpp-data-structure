/*
 * Problem: 1012
 * URL: https://www.acmicpc.net/problem/1012
 */

#include <array>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void updatePlant(int &plantCount, vector<vector<bool>> &plantedGrid) {
  for (int plant = 0; plant < plantCount; ++plant) {
    int plantRowIndex = -1, plantColIndex = -1;

    cin >> plantColIndex >> plantRowIndex;

    plantedGrid[plantRowIndex][plantColIndex] = true;
  }
}

bool isInBound(int rowIndex, int colIndex, int rowSize, int colSize) {

  bool isAboveMin = rowIndex >= 0 && colIndex >= 0;
  bool isBelowMax = rowIndex < rowSize && colIndex < colSize;

  bool isInBound = isAboveMin && isBelowMax;

  return isInBound;
}

void getPlantedGroups(int &bugCount,
                      vector<vector<bool>> &plantedGrid,
                      vector<vector<bool>> &visited) {
  int plantRowCount = plantedGrid.size();
  int plantColCount = plantedGrid[0].size();

  for (int rowIndex = 0; rowIndex < plantRowCount; ++rowIndex) {
    for (int colIndex = 0; colIndex < plantColCount; ++colIndex) {
      bool isStartPoint = !visited[rowIndex][colIndex] &&
                          (plantedGrid[rowIndex][colIndex] == true);

      if (isStartPoint) {
        stack<pair<int, int>> dfsStack;
        visited[rowIndex][colIndex] = true;
        dfsStack.push({rowIndex, colIndex});
        bugCount++;

        while (!dfsStack.empty()) {
          auto [currentRow, currentCol] = dfsStack.top();

          dfsStack.pop();

          for (auto &[deltaRow, deltaCol] : DELTAS) {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isSafeNext =
                isInBound(nextRow, nextCol, plantRowCount, plantColCount);

            bool isValidNext = isSafeNext && !visited[nextRow][nextCol] &&
                               (plantedGrid[nextRow][nextCol] == true);

            if (isValidNext) {
              visited[nextRow][nextCol] = true;
              dfsStack.push({nextRow, nextCol});
            }
          }
        }
      }
    }
  }
}

int main() {

  int testCaseCount = 0;

  cin >> testCaseCount;

  for (int i = 0; i < testCaseCount; ++i) {
    int rowCount = 0, colCount = 0;
    int plantCount = 0;

    int bugCount = 0;

    cin >> colCount >> rowCount >> plantCount;

    vector<vector<bool>> plantedGrid(rowCount, vector<bool>(colCount, false));
    updatePlant(plantCount, plantedGrid);

    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    getPlantedGroups(bugCount, plantedGrid, visited);

    cout << bugCount << '\n';
  }

  return 0;
}
