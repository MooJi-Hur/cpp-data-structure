/*
 * Problem: 15686
 * URL: https://www.acmicpc.net/problem/15686
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

struct ShopSorter {
  int houseRowAvg, houseColAvg;

  ShopSorter(int rowAvg, int colAvg)
      : houseRowAvg(rowAvg), houseColAvg(colAvg) {}

  bool operator()(pair<int, int> a, pair<int, int> b) const {
    int houseAvgToA = 0, houseAvgToB = 0;

    auto [rowA, colA] = a;
    auto [rowB, colB] = b;

    houseAvgToA = abs(houseRowAvg - rowA) + abs(houseColAvg - colA);
    houseAvgToB = abs(houseRowAvg - rowB) + abs(houseColAvg - colB);

    return houseAvgToA < houseAvgToB;
  }
};

void buildPoints(int &cityBlockCount,
                 int &houseRowSum,
                 int &houseColSum,
                 vector<pair<int, int>> &housePoints,
                 vector<pair<int, int>> &shopPoints);

void selectMaxProfitShops(int &maxShopCount,
                          int &houseRowSum,
                          int &houseColSum,
                          vector<pair<int, int>> &housePoints,
                          vector<pair<int, int>> &shopPoints);

void updateCityShopDistance(int &cityShopDistace,
                            vector<pair<int, int>> &housePoints,
                            vector<pair<int, int>> &shopPoints);

void printCityShopDistance(int &cityShopDistace);

int main() {
  int cityBlockCount = 0, maxShopCount = 0;

  cin >> cityBlockCount >> maxShopCount;

  int cityShopDistace = 0;

  int houseRowSum = 0, houseColSum = 0;

  vector<pair<int, int>> housePoints;
  vector<pair<int, int>> shopPoints;

  buildPoints(cityBlockCount, houseRowSum, houseColSum, housePoints,
              shopPoints);

  selectMaxProfitShops(maxShopCount, houseRowSum, houseColSum, housePoints,
                       shopPoints);

  updateCityShopDistance(cityShopDistace, housePoints, shopPoints);

  printCityShopDistance(cityShopDistace);

  return 0;
}

void buildPoints(int &cityBlockCount,
                 int &houseRowSum,
                 int &houseColSum,
                 vector<pair<int, int>> &housePoints,
                 vector<pair<int, int>> &shopPoints) {

  constexpr int EMPTY = 0;
  constexpr int HOUSE = 1;
  constexpr int SHOP = 2;

  for (int rowIndex = 0; rowIndex < cityBlockCount; ++rowIndex) {
    for (int colIndex = 0; colIndex < cityBlockCount; ++colIndex) {
      int currentPlace = EMPTY;
      cin >> currentPlace;

      switch (currentPlace) {
      case HOUSE:
        housePoints.push_back({rowIndex, colIndex});
        houseRowSum += rowIndex;
        houseColSum += colIndex;
        break;
      case SHOP:
        shopPoints.push_back({rowIndex, colIndex});
        break;
      default:
        break;
      }
    }
  }
}

// 조합을 사용한 방식으로 수정 필요
void selectMaxProfitShops(int &maxShopCount,
                          int &houseRowSum,
                          int &houseColSum,
                          vector<pair<int, int>> &housePoints,
                          vector<pair<int, int>> &shopPoints) {

  int houseRowAvg = housePoints.empty() ? 0 : houseRowSum / housePoints.size();
  int houseColAvg = housePoints.empty() ? 0 : houseColSum / housePoints.size();

  sort(shopPoints.begin(), shopPoints.end(),
       ShopSorter(houseRowAvg, houseColAvg));

  int shopCountToKeep = min(maxShopCount, static_cast<int>(shopPoints.size()));

  shopPoints.resize(shopCountToKeep);
};

void updateCityShopDistance(int &cityShopDistace,
                            vector<pair<int, int>> &housePoints,
                            vector<pair<int, int>> &shopPoints) {

  for (auto [houseRow, houseCol] : housePoints) {
    int minHouseShopDistance = INT_MAX;

    for (auto [shopRow, shopCol] : shopPoints) {
      int localHouseShopDistance = 0;

      localHouseShopDistance =
          abs(houseRow - shopRow) + abs(houseCol - shopCol);

      minHouseShopDistance = min(minHouseShopDistance, localHouseShopDistance);
    }

    cityShopDistace += minHouseShopDistance;
  }
};

void printCityShopDistance(int &cityShopDistace) { cout << cityShopDistace; };