/*
 * Problem: 14620
 * URL: https://www.acmicpc.net/problem/14620
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr int MAX_COST = 987654321;

constexpr bool FLOWER = true;
constexpr bool LOAD = false;

constexpr int SEED_COUNT = 3;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(vector<vector<int>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      cin >> inGrid[rowIndex][colIndex];
    }
  }
};

void calcCosts(int &minCost,
               pair<int, int> &startPoint,
               vector<vector<int>> &inGrid,
               vector<pair<int, int>> &seedsCandidate) {

  if (seedsCandidate.size() == SEED_COUNT) {
    int localCost = 0;
    for (auto [seedRow, seedCol] : seedsCandidate) {
      int unitPrice = inGrid[seedRow][seedCol];
      localCost += unitPrice;
      cout << seedRow << ' ' << seedCol << ' ' << unitPrice << ' ' << localCost
           << '\n';
    }
    cout << seedsCandidate.size() << '\n';

    minCost = min(minCost, localCost);
    return;
  }

  auto [startRow, startCol] = startPoint;

  for (size_t rowIndex = startRow + 1; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = startCol + 1; colIndex < inGrid[0].size();
         ++colIndex) {
      pair<int, int> currentPoint = {rowIndex, colIndex};

      for (auto [seedRow, seedCol] : seedsCandidate) {
        bool canSeed = seedRow != rowIndex || seedCol != colIndex;

        break;
      }
      seedsCandidate.push_back(currentPoint);
      calcCosts(minCost, currentPoint, inGrid, seedsCandidate);
      seedsCandidate.pop_back();
    }
  }

  return;
};

int main() {

  int sideLength = 0;
  cin >> sideLength;

  vector<vector<int>> inGrid(sideLength, vector<int>(sideLength));
  readGrid(inGrid);

  int minCost = MAX_COST;
  pair<int, int> startPoint = {1, 1};
  vector<pair<int, int>> seedsCandidate;
  calcCosts(minCost, startPoint, inGrid, seedsCandidate);

  //   for (auto row : inGrid) {
  //     for (auto cell : row) {
  //       cout << cell << ' ';
  //     }
  //     cout << '\n';
  //   }
  return 0;
};