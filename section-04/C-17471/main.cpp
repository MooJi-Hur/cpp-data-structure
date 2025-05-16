/*
 * Problem: 17471
 * URL: https://www.acmicpc.net/problem/17471
 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int blockSize = 0;

vector<int> populations;
vector<vector<int>> neighbors;

//

int minDiffer = INT_MAX;
constexpr int OUT_OF_RESULT = -1;

//
vector<bool> unionNames;
constexpr bool UNION_A = false;
constexpr bool UNION_B = true;

vector<int> visited;

void readPopulations() {
  populations.resize(blockSize + 1, 0);

  for (int blockIndex = 1; blockIndex <= blockSize; ++blockIndex) {
    cin >> populations[blockIndex];
  }
};

void readNeighbors() {
  neighbors.resize(blockSize + 1);

  for (int blockIndex = 1; blockIndex <= blockSize; ++blockIndex) {
    int neighborSize = 0;
    cin >> neighborSize;

    for (int neighborCount = 0; neighborCount < neighborSize; ++neighborCount) {
      int neighborIndex = 0;
      cin >> neighborIndex;
      neighbors[blockIndex].push_back(neighborIndex);
    }
  }
};

pair<int, int> calcUnion(int currentIndex, bool unionName) {
  visited[currentIndex] = true;

  int connectedCount = 1;
  int sumPopulation = populations[currentIndex];

  for (int neighborIndex : neighbors[currentIndex]) {
    bool needVisit = visited[neighborIndex] == false;
    bool isSameUnion = unionNames[neighborIndex] == unionName;

    if (needVisit && isSameUnion) {

      auto [neighborCount, neighborPopulation] =
          calcUnion(neighborIndex, unionName);

      connectedCount += neighborCount;
      sumPopulation += neighborPopulation;
    }
  }

  pair<int, int> updatedUnion = {connectedCount, sumPopulation};
  return updatedUnion;
};

void buildUnions() {
  unionNames.resize(blockSize + 1, false);

  for (int combiIndex = 1; combiIndex <= (1 << blockSize); ++combiIndex) {

    visited.clear();
    visited.resize(blockSize + 1, false);

    int aStartIndex = -1, bStartIndex = -1;

    for (int blockIndex = 1; blockIndex <= blockSize; ++blockIndex) {
      bool unionName = combiIndex & (1 << (blockIndex - 1));
      unionNames[blockIndex] = unionName;

      if (unionName == UNION_A) {
        aStartIndex = blockIndex;
      } else {
        bStartIndex = blockIndex;
      }
    }

    bool isOneUnion = aStartIndex == -1 || bStartIndex == -1;

    if (isOneUnion) {
      continue;
    }

    pair<int, int> unionA = calcUnion(aStartIndex, UNION_A);
    pair<int, int> unionB = calcUnion(bStartIndex, UNION_B);

    auto [connectedCountA, sumPopulationA] = unionA;
    auto [connectedCoundB, sumPopulationB] = unionB;

    bool isGroupTwo = connectedCountA + connectedCoundB == blockSize;

    if (!isGroupTwo) {
      continue;
    }

    int currentDiffer = abs(sumPopulationA - sumPopulationB);

    minDiffer = min(minDiffer, currentDiffer);
  }
};

int main() {

  cin >> blockSize;

  readPopulations();
  readNeighbors();

  buildUnions();

  if (minDiffer == INT_MAX) {
    cout << OUT_OF_RESULT;
  } else {
    cout << minDiffer;
  }

  return 0;
}