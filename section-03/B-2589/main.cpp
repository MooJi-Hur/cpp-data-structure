/*
 * Problem: 2589
 * URL: https://www.acmicpc.net/problem/2589
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char LAND = 'L';
constexpr char SEA = 'W';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<bool>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = (row[colIndex] == LAND);
    }
  }
};

void findSecondTreasure(int &hours,
                        pair<int, int> &startNode,
                        vector<vector<bool>> &inGrid,
                        vector<vector<bool>> &visited,
                        vector<vector<int>> &distance) {

  queue<pair<int, int>> dfsQueue;
  dfsQueue.push(startNode);

  while (!dfsQueue.empty()) {
    auto [currentRow, currentCol] = dfsQueue.front();
    dfsQueue.pop();

    hours = max(hours, distance[currentRow][currentCol]);

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool isSafeNext =
          isInBoundRow && isInBoundCol && (inGrid[nextRow][nextCol] == true);
      bool canMoveNext = isSafeNext && (visited[nextRow][nextCol] == false);

      if (canMoveNext) {
        dfsQueue.push({nextRow, nextCol});
        visited[nextRow][nextCol] = true;
        distance[nextRow][nextCol] += distance[currentRow][currentCol] + 1;
      }
    }
  }
};

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<bool>> inGrid(rowCount, vector<bool>(colCount, false));
  readGrid(inGrid);

  int hours = 0;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int colIndex = 0; colIndex < colCount; ++colIndex) {
      pair<int, int> startNode = {rowIndex, colIndex};
      vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
      vector<vector<int>> distance(rowCount, vector<int>(colCount, 0));

      visited[rowIndex][colIndex] = true;
      if (inGrid[rowIndex][colIndex] == true) {
        findSecondTreasure(hours, startNode, inGrid, visited, distance);
      }
    }
  }

  cout << hours;
  return 0;
}