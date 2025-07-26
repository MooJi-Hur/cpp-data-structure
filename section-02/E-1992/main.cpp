/*
 * Problem: 1992
 * URL: https://www.acmicpc.net/problem/1992
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// in
int gridSize = 0;
vector<vector<char>> inGrid;
constexpr char ZERO = '0';

// logic
constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

vector<string> zips;

// out
string zipResult;

void readGrid() {
  inGrid.resize(gridSize, vector<char>(gridSize));
  for (int rowIndex = 0; rowIndex < gridSize; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 0; colIndex < gridSize; ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex] - ZERO;
    }
  }
}

void flatGrid(int currentRow, int currentCol, int currentSize) {
  if (currentSize == 1) {
    zips.push_back(to_string(inGrid[currentRow][currentCol]));
    return;
  }

  int nextSize = currentSize >> 1;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow * nextSize;
    int nextCol = currentCol + deltaCol * nextSize;

    flatGrid(nextRow, nextCol, nextSize);
  }
}

void zipGrid() {
  int currentSize = gridSize;

  vector<string> currentString = zips;
  vector<string> nextString;

  while (currentString.size() > 1) {

    for (int unitIndex = 0; unitIndex < (int)currentString.size();
         unitIndex = unitIndex + 4) {

      string zipCandidate;

      for (int cellIndex = 0; cellIndex < 4; ++cellIndex) {

        zipCandidate += currentString[unitIndex + cellIndex];
      }

      if (zipCandidate == "0000") {
        nextString.push_back("0");
      } else if (zipCandidate == "1111") {
        nextString.push_back("1");
      } else {
        nextString.push_back("(" + zipCandidate + ")");
      }
    }

    currentString = nextString;
    nextString = vector<string>{};

    currentSize = currentSize >> 1;
  }

  zipResult = currentString[0];
}

int main() {
  cin >> gridSize;

  readGrid();

  flatGrid(0, 0, gridSize);

  zipGrid();

  cout << zipResult;

  return 0;
}