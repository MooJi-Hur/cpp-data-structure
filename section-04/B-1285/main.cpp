/*
 * Problem: 1285
 * URL: https://www.acmicpc.net/problem/1285
 */

#include <bitset>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
int sideLength = 0;
constexpr int MAX_PLACE = 20;
constexpr int TAIL = 'T';

vector<bitset<MAX_PLACE>> rows;

// out
int minTailCount = INT_MAX;

void readRows() {
  rows.resize(sideLength, 0);

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    string row;
    getline(cin >> ws, row);

    bitset<MAX_PLACE> bitPlace = 1;
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {

      if (row[colIndex] == TAIL) {
        rows[rowIndex] |= bitPlace;
      }
      bitPlace = (bitPlace << 1);
    }
  }
};

void countTails(int currentRow) {
  if (currentRow == sideLength) {
    int tailCount = 0;
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      int tailColCount = 0;
      for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
        if (rows[rowIndex][colIndex]) {
          tailColCount++;
        }
      }
      tailCount += min(tailColCount, sideLength - tailColCount);
    }
    minTailCount = min(minTailCount, tailCount);
    return;
  }

  countTails(currentRow + 1);
  rows[currentRow] = ~rows[currentRow];
  countTails(currentRow + 1);
};

int main() {

  cin >> sideLength;

  readRows();

  countTails(0);

  cout << minTailCount;

  return 0;
}