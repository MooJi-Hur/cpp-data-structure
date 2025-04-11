/*
 * Problem: 4179
 * URL: https://www.acmicpc.net/problem/4179
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr char WALL = '#';
constexpr char PATH = '.';
constexpr char NAME = 'J';
constexpr char FIRE = 'F';

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

constexpr int INF = 987654321;

void readGrid(vector<vector<char>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex];
    }
  }
};

void traceFire(vector<vector<char>> &inGrid, vector<vector<int>> &fireHistory) {
  queue<pair<int, int>> bfsQueue;

  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      bool isFire = inGrid[rowIndex][colIndex] == FIRE;
      bool canVisit = fireHistory[rowIndex][colIndex] == INF;

      if (isFire && canVisit) {

        bfsQueue.push({rowIndex, colIndex});
        fireHistory[rowIndex][colIndex] = 0;
      }
    }
  }

  while (!bfsQueue.empty()) {
    auto [currentRow, currentCol] = bfsQueue.front();
    bfsQueue.pop();

    for (auto [deltaRow, deltaCol] : DELTAS) {
      int nextRow = currentRow + deltaRow;
      int nextCol = currentCol + deltaCol;

      bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
      bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

      bool isSafeNext =
          isInBoundRow && isInBoundCol && inGrid[nextRow][nextCol] != WALL;

      bool canMove = isSafeNext && fireHistory[nextRow][nextCol] == INF;

      if (canMove) {
        fireHistory[nextRow][nextCol] = fireHistory[currentRow][currentCol] + 1;
        bfsQueue.push({nextRow, nextCol});
      }
    }
  }
};

void tracePerson(vector<vector<char>> &inGrid,
                 vector<vector<int>> &personHistory,
                 vector<vector<int>> &fireHistory,
                 int &timeCount) {

  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      if (inGrid[rowIndex][colIndex] == NAME) {
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({rowIndex, colIndex});
        personHistory[rowIndex][colIndex] = 0;

        while (!bfsQueue.empty()) {
          auto [currentRow, currentCol] = bfsQueue.front();
          bfsQueue.pop();

          bool isBorderRow =
              currentRow == 0 || currentRow == (int)inGrid.size() - 1;
          bool isBorderCol =
              currentCol == 0 || currentCol == (int)inGrid[0].size() - 1;

          bool isSafe = personHistory[currentRow][currentCol] <
                        fireHistory[currentRow][currentCol];

          if ((isBorderRow || isBorderCol) && isSafe) {
            timeCount = personHistory[currentRow][currentCol] + 1;
            return;
          }

          for (auto [deltaRow, deltaCol] : DELTAS) {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
            bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();

            bool isSafeNext = isInBoundRow && isInBoundCol &&
                              inGrid[nextRow][nextCol] != WALL;

            int nextTime = personHistory[currentRow][currentCol] + 1;
            bool isBeforeFire =
                isSafeNext && (nextTime < fireHistory[nextRow][nextCol]);

            bool canMove =
                isBeforeFire && personHistory[nextRow][nextCol] == INF;

            if (canMove) {
              personHistory[nextRow][nextCol] =
                  personHistory[currentRow][currentCol] + 1;
              bfsQueue.push({nextRow, nextCol});
            }
          }
        }
      }
    }
  }
}

int main() {
  int rowCount = 0, colCount = 0;
  cin >> rowCount >> colCount;

  vector<vector<char>> inGrid(rowCount, vector<char>(colCount, '\0'));
  readGrid(inGrid);

  vector<vector<int>> fireHistory(rowCount, vector<int>(colCount, INF));
  vector<vector<int>> personHistory(rowCount, vector<int>(colCount, INF));

  traceFire(inGrid, fireHistory);

  int timeCount = -1;
  tracePerson(inGrid, personHistory, fireHistory, timeCount);

  if (timeCount == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  cout << timeCount;

  return 0;
}