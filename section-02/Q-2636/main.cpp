/*
 * Problem: 2636
 * URL: https://www.acmicpc.net/problem/2636
 */

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<int>> &cheeseGrid) {
  for (size_t rowIndex = 0; rowIndex < cheeseGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < cheeseGrid[0].size(); ++colIndex) {
      bool isCheese;
      cin >> isCheese;
      cheeseGrid[rowIndex][colIndex] = isCheese;
    }
  }
};

void traceCheese(pair<int, int> &startNode,
                 vector<vector<int>> &cheeseGrid,
                 vector<vector<bool>> &visited,
                 vector<int> &cheeseCounts,
                 int &totalHours) {

  stack<pair<int, int>> dfsQueue;
  dfsQueue.push(startNode);

  while (!dfsQueue.empty()) {
    auto [currentRow, currentCol] = dfsQueue.top();
    dfsQueue.pop();

    bool isVisited = visited[currentRow][currentCol] == true;
    if (!isVisited) {
      visited[currentRow][currentCol] = true;

      int neighborCount = 0;
      for (auto [deltaRow, deltaCol] : DELTAS) {
        int nextRow = currentRow + deltaRow;
        int nextCol = currentCol + deltaCol;

        bool isInBoundRow = nextRow >= 0 && nextRow < (int)cheeseGrid.size();
        bool isInBoundCol = nextCol >= 0 && nextCol < (int)cheeseGrid[0].size();

        bool canOpen = isInBoundRow && isInBoundCol &&
                       (cheeseGrid[nextRow][nextCol] == true);

        bool canVisit = canOpen && (visited[nextRow][nextCol] == false);

        if (canVisit) {

          dfsQueue.push({nextRow, nextCol});
        }

        if (cheeseGrid[nextRow][nextCol] == true) {
          neighborCount++;
        }
      }
      cheeseGrid[currentRow][currentCol] = neighborCount;
    }
  }
};

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<int>> cheeseGrid(rowCount, vector<int>(colCount, 0));
  readGrid(cheeseGrid);

  vector<int> cheeseCounts;
  vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
  int totalHours = 1;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int colIndex = 0; colIndex < colCount; ++colIndex) {
      pair<int, int> startNode = {rowIndex, colIndex};
      if (cheeseGrid[rowIndex][colIndex]) {
        traceCheese(startNode, cheeseGrid, visited, cheeseCounts, totalHours);
        totalHours++;
      }
    }
  }
  for (vector<int> row : cheeseGrid) {
    for (int col : row) {
      cout << col << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  return 0;
}