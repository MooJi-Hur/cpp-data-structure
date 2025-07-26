/*
 * Problem: 1189
 * URL: https://www.acmicpc.net/problem/1189
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char PATH = '.';
constexpr char WALL = 'T';

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

int comeBackHome(int &pathDistance,
                 pair<int, int> currentPoint,
                 vector<vector<char>> &inGrid,
                 vector<vector<int>> &visited) {

  int unitDistance = 0;

  auto [currentRow, currentCol] = currentPoint;

  int endRow = 0, endCol = (int)inGrid[0].size() - 1;
  bool isEndPoint = currentRow == endRow && currentCol == endCol;

  if (isEndPoint) {
    if (pathDistance == visited[endRow][endCol]) {
      return 1;
    }
    return 0;
  }

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    bool isInRow = nextRow >= 0 && nextRow < (int)inGrid.size();
    bool isInCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

    bool needVisit = isInRow && isInCol && !visited[nextRow][nextCol];
    bool canMoveNext = needVisit && (inGrid[nextRow][nextCol] == PATH);

    if (canMoveNext) {
      visited[nextRow][nextCol] = visited[currentRow][currentCol] + 1;
      pair<int, int> nextPoint = {nextRow, nextCol};
      unitDistance += comeBackHome(pathDistance, nextPoint, inGrid, visited);
      visited[nextRow][nextCol] = 0;
    }
  }
  return unitDistance;
};

int main() {
  int rowSize = 0, colSize = 0, pathDistance = 0;
  cin >> rowSize >> colSize >> pathDistance;

  vector<vector<char>> inGrid(rowSize, vector<char>(colSize, PATH));
  readGrid(inGrid);

  pair<int, int> startPoint = {rowSize - 1, 0};
  vector<vector<int>> visited(rowSize, vector<int>(colSize, false));
  visited[rowSize - 1][0] = true;

  cout << comeBackHome(pathDistance, startPoint, inGrid, visited);

  return 0;
}