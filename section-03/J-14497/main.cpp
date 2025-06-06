/*
 * Problem: 14497
 * URL: https://www.acmicpc.net/problem/14497
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;
int startRow = 0, startCol = 0;
int goalRow = 0, goalCol = 0;

vector<vector<char>> inGrid;

constexpr char EMPTY = '0';
constexpr char FRIEND = '1';
constexpr char START = '*';
constexpr char END = '#';

// out
int jumpCount = 0;

// logic

vector<vector<bool>> visited;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid() {
  inGrid.resize(rowSize + 1, vector<char>(colSize + 1));

  for (int rowIndex = 1; rowIndex <= rowSize; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 1; colIndex <= colSize; ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex - 1];
    }
  }
};

void searchRoom() {

  queue<pair<int, int>> currentBFS;
  queue<pair<int, int>> nextBFS;

  visited.resize(rowSize + 1, vector<bool>(colSize + 1, false));
  visited[startRow][startCol] = true;
  currentBFS.push({startRow, startCol});

  while (true) {
    jumpCount++;

    while (!currentBFS.empty()) {

      auto [currentRow, currentCol] = currentBFS.front();
      currentBFS.pop();

      for (auto [deltaRow, deltaCol] : DELTAS) {
        int nextRow = currentRow + deltaRow;
        int nextCol = currentCol + deltaCol;

        bool isOutBound = nextRow <= 0 || nextRow > rowSize || nextCol <= 0 ||
                          nextCol > colSize;

        if (isOutBound) {
          continue;
        }

        if (visited[nextRow][nextCol]) {
          continue;
        }

        char nextCell = inGrid[nextRow][nextCol];
        visited[nextRow][nextCol] = true;

        if (nextCell == FRIEND) {
          inGrid[nextRow][nextCol] = EMPTY;
          nextBFS.push({nextRow, nextCol});
        } else if (nextCell == EMPTY) {
          currentBFS.push({nextRow, nextCol});
        } else if (nextCell == END) {
          cout << jumpCount;
          break;
        }
      }
    }

    if (nextBFS.empty()) {
      break;
    }

    currentBFS.swap(nextBFS);
    nextBFS = queue<pair<int, int>>{};
  }
};

int main() {

  cin >> rowSize >> colSize;
  cin >> startRow >> startCol;
  cin >> goalRow >> goalCol;

  readGrid();

  searchRoom();

  return 0;
}