/*
 * Problem: 19942
 * URL: https://www.acmicpc.net/problem/19942
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int MAX_COST = 15 * 500 + 1;
constexpr int NO_CANDIDATES = -1;
constexpr int NUTRIENT_COUNT = 4;
constexpr int COST_INDEX = NUTRIENT_COUNT + 1;

void readCandidates(vector<vector<int>> &candidates) {
  for (size_t foodIndex = 1; foodIndex < candidates.size(); ++foodIndex) {

    candidates[foodIndex][0] = foodIndex;
    for (int nutrientIndex = 1; nutrientIndex <= NUTRIENT_COUNT;
         ++nutrientIndex) {
      cin >> candidates[foodIndex][nutrientIndex];
    }
    cin >> candidates[foodIndex][NUTRIENT_COUNT + 1];
  }
}

void printMinCostInfos(int minCost, vector<int> &minFoodIndexes) {
  if (minCost == MAX_COST) {
    minCost = NO_CANDIDATES;
  }

  cout << minCost << '\n';

  if (minCost != NO_CANDIDATES) {
    sort(minFoodIndexes.begin(), minFoodIndexes.end());
    for (int index : minFoodIndexes) {
      cout << index << ' ';
    }
  }
}

void getCombination(int foodCount, vector<vector<int>> &combinationIndexes) {
  vector<int> candidateIndexes(foodCount);
  iota(candidateIndexes.begin(), candidateIndexes.end(), 1);

  int combinationCount = 1 << foodCount;
  for (int combinationIndex = 0; combinationIndex < combinationCount;
       ++combinationIndex) {
    vector<int> localCandidates;
    for (int candidateIndex = 0; candidateIndex < foodCount; ++candidateIndex) {
      if (combinationIndex & (1 << (candidateIndex))) {
        localCandidates.push_back(candidateIndexes[candidateIndex]);
      }
    }

    if (localCandidates.size()) {
      combinationIndexes.push_back(localCandidates);
    }
  }
}

void computeMinCost(int &minCost,
                    vector<int> &minFoodIndexes,
                    vector<vector<int>> &combinationIndexes,
                    vector<vector<int>> &candidates,
                    vector<int> &minNutrient) {

  sort(combinationIndexes.begin(), combinationIndexes.end());

  for (vector<int> combi : combinationIndexes) {

    int localCost = 0;
    vector<int> sumNutrient(NUTRIENT_COUNT, 0);

    for (int index : combi) {
      vector<int> currentFood = candidates[index];

      localCost += currentFood[COST_INDEX];

      for (int nutrientIndex = 0; nutrientIndex < NUTRIENT_COUNT;
           ++nutrientIndex) {
        sumNutrient[nutrientIndex] += currentFood[nutrientIndex + 1];
      }
    }

    bool isLowCost = localCost < minCost;
    bool isEnoughNutrient = false;

    if (isLowCost) {
      isEnoughNutrient = true;
      for (int nutrientIndex = 0; nutrientIndex < NUTRIENT_COUNT;
           ++nutrientIndex) {
        if (minNutrient[nutrientIndex] > sumNutrient[nutrientIndex]) {
          isEnoughNutrient = false;
          break;
        }
      }
    }

    if (isLowCost && isEnoughNutrient) {
      minCost = localCost;
      minFoodIndexes = combi;
    }
  }
}

int main() {

  int foodCount = 0;
  cin >> foodCount;

  vector<int> minNutrient(NUTRIENT_COUNT);
  for (int nutrientIndex = 0; nutrientIndex < NUTRIENT_COUNT; ++nutrientIndex) {
    cin >> minNutrient[nutrientIndex];
  }

  vector<vector<int>> candidates(foodCount + 1,
                                 vector<int>(1 + NUTRIENT_COUNT + 1, 0));
  readCandidates(candidates);

  vector<vector<int>> combinationIndexes;
  getCombination(foodCount, combinationIndexes);

  int minCost = MAX_COST;
  vector<int> minFoodIndexes;
  computeMinCost(minCost, minFoodIndexes, combinationIndexes, candidates,
                 minNutrient);

  printMinCostInfos(minCost, minFoodIndexes);

  return 0;
}