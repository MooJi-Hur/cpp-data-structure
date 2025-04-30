/*
 * Problem: 14620
 * URL: https://www.acmicpc.net/problem/14620
 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr int MAX_SEED_COUNT = 3;

constexpr int DIRECTIONS = 5;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readPrices(vector<vector<int>> &prices) {

  for (size_t rowIndex = 0; rowIndex < prices.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < prices[0].size(); ++colIndex) {
      cin >> prices[rowIndex][colIndex];
    }
  }
};

bool canPlant(pair<int, int> &currentPoint, vector<vector<bool>> &visited) {

  auto [currentRow, currentCol] = currentPoint;
  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    bool isOutRow = nextRow < 0 || nextRow >= (int)visited.size();
    bool isOutCol = nextCol < 0 || nextCol >= (int)visited[0].size();

    if (isOutRow || isOutCol) {
      return false;
    }

    if (visited[nextRow][nextCol]) {
      return false;
    }
  }
  return true;
};

int plantFlower(pair<int, int> currentPoint,
                vector<vector<int>> &prices,
                vector<vector<bool>> &visited) {
  auto [currentRow, currentCol] = currentPoint;
  int cost = 0;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    visited[nextRow][nextCol] = true;
    cost += prices[nextRow][nextCol];
  }
  return cost;
};

void removeFlower(pair<int, int> currentPoint, vector<vector<bool>> &visited) {
  auto [currentRow, currentCol] = currentPoint;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;

    visited[nextRow][nextCol] = false;
  }
};

void calcPrice(int &minPrice,
               int flowerCount,
               int sumPrice,
               vector<vector<int>> &prices,
               vector<vector<bool>> &visited) {

  if (flowerCount == MAX_SEED_COUNT) {
    minPrice = min(minPrice, sumPrice);

    return;
  }

  for (size_t rowIndex = 1; rowIndex < visited.size() - 1; ++rowIndex) {
    for (size_t colIndex = 1; colIndex < visited[0].size() - 1; ++colIndex) {

      pair<int, int> currentPoint = {rowIndex, colIndex};
      if (canPlant(currentPoint, visited)) {
        int cost = plantFlower(currentPoint, prices, visited);
        calcPrice(minPrice, flowerCount + 1, sumPrice + cost, prices, visited);
        removeFlower(currentPoint, visited);
      }
    }
  }
};

int main() {
  int sideSize = 0;
  cin >> sideSize;

  vector<vector<int>> prices(sideSize, vector<int>(sideSize, 0));
  readPrices(prices);

  int minPrice = INT_MAX;

  int initFlowerCount = 0;
  int initSumPrice = 0;

  vector<vector<bool>> visited(sideSize, vector<bool>(sideSize, false));

  calcPrice(minPrice, initFlowerCount, initSumPrice, prices, visited);

  cout << minPrice;
  return 0;
}