/*
 * Problem: 14497
 * URL: https://www.acmicpc.net/problem/14497
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// in
int rowSize = 0, colSize = 0;
int startY = 0, startX = 0;
int goalY = 0, goalX = 0;

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
  inGrid.resize(rowSize, vector<char>(colSize));

  for (auto &row : inGrid) {
    for (auto &cell : row) {

      cin >> cell;
      if (cell == START) {
        cell = EMPTY;
      }
      if (cell == END) {
        cell = FRIEND;
      }
    }
  }
};

void jump(int currentY, int currentX) {

  for (auto [deltaY, deltaX] : DELTAS) {
    int nextY = currentY + deltaY;
    int nextX = currentX + deltaX;

    bool isInBound =
        nextY >= 0 && nextY < rowSize && nextX >= 0 && nextX < colSize;
    bool isVisitable = isInBound && !visited[nextY][nextX];
    bool isNextEmpty = isVisitable && (inGrid[nextY][nextX] == EMPTY);

    if (isVisitable) {
      if (inGrid[nextY][nextX] == EMPTY) {
        jump(nextY, nextX);

      } else if (inGrid[nextY][nextX] == FRIEND) {
        inGrid[nextY][nextX] = EMPTY;
      }
      visited[nextY][nextX] = true;
    }
  }
}

int main() {

  cin >> rowSize >> colSize;
  cin >> startX >> startY;
  cin >> goalX >> goalY;

  readGrid();
  cout << inGrid[goalY - 1][goalX - 1] << '\n';

  int whileCount = 5;
  while (whileCount > 0) {
    whileCount--;
    visited.clear();
    visited.resize(rowSize, vector<bool>(colSize, false));
    visited[startY][startX] = true;

    jump(startY, startX);
    jumpCount++;
    cout << jumpCount << '\n';
  }

  cout << jumpCount;
  return 0;
}