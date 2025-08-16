/*
 * Problem: 15686
 * URL: https://www.acmicpc.net/problem/15686
 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int sideLength, maxShopCount;

constexpr int HOME = 1;
constexpr int SHOP = 2;

vector<vector<int>> shopCombis;
vector<pair<int, int>> homes, shops;

int minDistance = INT_MAX;

void readGrid() {
  cin >> sideLength >> maxShopCount;

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      int placeInfo = 0;
      cin >> placeInfo;

      if (placeInfo == HOME) {
        homes.push_back({rowIndex, colIndex});
      }

      if (placeInfo == SHOP) {
        shops.push_back({rowIndex, colIndex});
      }
    }
  }
}

void combiShops(int startIndex, vector<int> shopCombi) {
  if (maxShopCount == shopCombi.size()) {
    shopCombis.push_back(shopCombi);
    return;
  }

  for (size_t nextIndex = startIndex + 1; nextIndex < shops.size();
       ++nextIndex) {
    shopCombi.push_back(nextIndex);
    combiShops(nextIndex, shopCombi);
    shopCombi.pop_back();
  }
}

void calcMinDistance() {
  for (vector<int> shopCombi : shopCombis) {
    int distanceCombi = 0;
    for (pair<int, int> home : homes) {
      int minHomeToShop = INT_MAX;
      for (int shopIndex : shopCombi) {
        int homeToShop = abs(home.first - shops[shopIndex].first) +
                         abs(home.second - shops[shopIndex].second);

        minHomeToShop = min(minHomeToShop, homeToShop);
      }
      distanceCombi += minHomeToShop;
    }
    minDistance = min(minDistance, distanceCombi);
  }
}

int main() {

  readGrid();

  combiShops(-1, vector<int>{});

  calcMinDistance();

  cout << minDistance;
  return 0;
}