/*
 * Problem: 1285
 * URL: https://www.acmicpc.net/problem/1285
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr bool T = true;
constexpr bool H = false;
constexpr char LARGE_T = 'T';
constexpr char LARGE_H = 'H';

void readCoins(vector<vector<bool>> &coinGrid) {
  int sideLength = coinGrid.size();

  for (int rowIndex = 0; rowIndex < sideLength; ++rowIndex) {
    string rowCoin;
    getline(cin >> ws, rowCoin);
    for (int colIndex = 0; colIndex < sideLength; ++colIndex) {
      coinGrid[rowIndex][colIndex] = (rowCoin[colIndex] == LARGE_T);
    }
  }
};

void addReverseCandidates(vector<vector<pair<int, int>>> &reverseCandidates) {
  int sideLength = reverseCandidates.size() >> 1;

  for (int sideIndex = 0; sideIndex < sideLength; ++sideIndex) {
    int rowCandidate = sideIndex * 2;
    int colCandidate = rowCandidate + 1;

    for (int index = 0; index < sideLength; ++index) {
      reverseCandidates[rowCandidate][index] = {sideIndex, index};
      reverseCandidates[colCandidate][index] = {index, sideIndex};
    }
  }
}

void addCombinations(int &candidateSize, vector<vector<int>> &combinations) {
  int combinationSize = combinations.size();

  for (int combiIndex = 0; combiIndex < combinationSize; ++combiIndex) {
    vector<int> combination;
    for (int candidateIndex = 0; candidateIndex < candidateSize;
         ++candidateIndex) {

      if (combiIndex & (1 << candidateIndex)) {
        combination.push_back(candidateIndex);
      }
    }
    combinations[combiIndex] = combination;
  }
}

void getPermutations(vector<vector<int>> &combinations,
                     vector<vector<int>> &permuations) {
  for (size_t combiIndex = 0; combiIndex < combinations.size(); ++combiIndex) {
    vector<int> permutation;
    permutation = combinations[combiIndex];
    do {
      permuations.push_back(permutation);
    } while (next_permutation(permutation.begin(), permutation.end()));
  }
}

void getMinTCount(int &minTCount,
                  vector<vector<int>> &permutations,
                  vector<vector<pair<int, int>>> &reverseCandidates,
                  vector<vector<bool>> &coinGrid) {

  for (vector<int> &permutation : permutations) {
    vector<vector<bool>> initCoinGrid = coinGrid;
    for (int &positionIndex : permutation) {
      vector<pair<int, int>> changePositions = reverseCandidates[positionIndex];
      for (auto [row, col] : changePositions) {
        initCoinGrid[row][col] = !initCoinGrid[row][col];
      }
    }

    int tCount = 0;
    for (size_t rowIndex = 0; rowIndex < initCoinGrid.size(); ++rowIndex) {
      tCount += accumulate(initCoinGrid[rowIndex].begin(),
                           initCoinGrid[rowIndex].end(), 0);
    }

    if (tCount < minTCount) {
      minTCount = tCount;
    }
  }
}

int main() {

  int sideLength = 0;
  cin >> sideLength;

  vector<vector<bool>> coinGrid(sideLength, vector<bool>(sideLength, H));
  readCoins(coinGrid);

  int candidateSize = sideLength * 2;
  vector<vector<pair<int, int>>> reverseCandidates(
      candidateSize, vector<pair<int, int>>(sideLength, {0, 0}));
  addReverseCandidates(reverseCandidates);

  vector<vector<int>> combinations(1 << candidateSize);
  addCombinations(candidateSize, combinations);

  vector<vector<int>> permutations;
  getPermutations(combinations, permutations);

  int minTCount = sideLength * sideLength;
  getMinTCount(minTCount, permutations, reverseCandidates, coinGrid);

  cout << minTCount;

  return 0;
}