/*
 * Problem: 1285
 * URL: https://www.acmicpc.net/problem/1285
 */

#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
int sideLength = 0;

constexpr char HEAD = 'H';
constexpr char TAIL = 'T';

vector<vector<char>> inGrid;
vector<vector<bool>> reverseRowCounts;
vector<vector<bool>> reverseColCounts;
// out
int minTailCount = INT_MAX;

// logic

void readGrid() {
  inGrid.resize(sideLength, vector<char>(sideLength, HEAD));

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      inGrid[rowIndex][colIndex] = row[colIndex];
    }
  }
};

void reverseCoins() {

  for (int candidateIndex = 0; candidateIndex < (1 << sideLength);
       ++candidateIndex) {
    for (int combiIndex = 0; combiIndex < sideLength; ++combiIndex) {
      if (candidateIndex & (1 << combiIndex)) {
        cout << combiIndex << ' ';
      }
    }
    cout << '\n';
  }
};

int main() {

  cin >> sideLength;

  readGrid();

  reverseRowCounts.resize(sideLength, vector<bool>(sideLength, false));
  reverseCoins();

  cout << minTailCount;
  return 0;
}