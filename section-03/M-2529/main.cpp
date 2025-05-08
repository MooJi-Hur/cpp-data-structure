/*
 * Problem: 2529
 * URL: https://www.acmicpc.net/problem/2529
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr char GREATER_THAN = '>';
constexpr char LESS_THAN = '<';

constexpr int MAX_DIGIT = 9;

void readSigns(vector<char> &signs) {
  for (auto &sign : signs) {
    cin >> sign;
  }
};

bool isMatchedSign(int prevNumber, int currentNumber, char currentSign) {
  if (prevNumber > currentNumber && currentSign == GREATER_THAN)
    return true;
  if (prevNumber < currentNumber && currentSign == LESS_THAN)
    return true;

  return false;
};

void buildNumbers(int currentPlace,
                  string result,
                  vector<char> &signs,
                  vector<bool> &visited,
                  vector<string> &results) {
  int placeSize = (int)visited.size();

  if (currentPlace == placeSize) {
    results.push_back(result);
    return;
  }

  for (int currentNumber = 0; currentNumber <= MAX_DIGIT; ++currentNumber) {
    if (visited[currentNumber]) {
      continue;
    }

    bool canAdded = false;
    bool isFirstPlace = currentPlace == 0;

    if (isFirstPlace) {
      canAdded = true;
    } else {
      int prevNumber = result[currentPlace - 1] - '0';
      char currentSign = signs[currentPlace - 1];

      canAdded = isMatchedSign(prevNumber, currentNumber, currentSign);
    }

    if (canAdded) {
      visited[currentNumber] = true;
      result += (currentNumber + '0');
      buildNumbers(currentPlace + 1, result, signs, visited, results);
      result.pop_back();
      visited[currentNumber] = false;
    }
  }
};

int main() {

  int signCount = 0;
  cin >> signCount;

  vector<char> signs(signCount);
  readSigns(signs);

  int placeCount = signCount + 1;
  vector<bool> visited(placeCount);

  vector<string> results;

  int initPlace = 0;
  string initResult = "";
  buildNumbers(initPlace, initResult, signs, visited, results);

  sort(results.begin(), results.end());

  cout << results.back() << '\n' << results.front();
  return 0;
}