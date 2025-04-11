/*
 * Problem: 16234
 * URL: https://www.acmicpc.net/problem/16234
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr int MAX_DAYS = 2000;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void readGrid(vector<vector<int>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      cin >> inGrid[rowIndex][colIndex];
    }
  }
};

void movePeople(int &minDiffer,
                int &maxDiffer,
                int &sum,
                pair<int, int> &startNode,
                vector<vector<int>> &inGrid,
                vector<pair<int, int>> &unions,
                vector<vector<bool>> &visited) {

  auto [startRow, startCol] = startNode;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = startRow + deltaRow;
    int nextCol = startCol + deltaCol;

    bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
    bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

    if (isInBoundRow && isInBoundCol) {
      int differ = abs(inGrid[startRow][startCol] - inGrid[nextRow][nextCol]);

      bool canMove = !visited[nextRow][nextCol] &&
                     (differ >= minDiffer && differ <= maxDiffer);

      if (canMove) {
        pair<int, int> nextNode = {nextRow, nextCol};
        visited[nextRow][nextCol] = true;
        sum += inGrid[nextRow][nextCol];
        unions.push_back({nextRow, nextCol});
        movePeople(minDiffer, maxDiffer, sum, nextNode, inGrid, unions,
                   visited);
      }
    }
  }
};

int main() {

  int sideLength = 0, minDiffer = 0, maxDiffer = 0;
  cin >> sideLength >> minDiffer >> maxDiffer;

  vector<vector<int>> inGrid(sideLength, vector<int>(sideLength, -1));
  readGrid(inGrid);

  int dayCount = 0;
  int sum = 0;
  while (dayCount <= MAX_DAYS) {
    bool hasUnion = false;
    vector<pair<int, int>> unions;
    vector<vector<bool>> visited(sideLength, vector<bool>(sideLength, false));

    for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
      for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
        pair<int, int> startNode = {rowIndex, colIndex};

        if (!visited[rowIndex][colIndex]) {
          unions.clear();
          visited[rowIndex][colIndex] = true;
          sum = inGrid[rowIndex][colIndex];
          unions.push_back(startNode);
          movePeople(minDiffer, maxDiffer, sum, startNode, inGrid, unions,
                     visited);

          if (unions.size() == 1) {
            continue;
          }

          int avg = sum / unions.size();
          for (auto [unionRow, unionCol] : unions) {
            inGrid[unionRow][unionCol] = avg;
            hasUnion = true;
          }
        }
      }
    }

    if (!hasUnion) {
      break;
    }
    dayCount++;
  }

  cout << dayCount;

  return 0;
}