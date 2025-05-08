/*
 * Problem: 2529
 * URL: https://www.acmicpc.net/problem/2529
 */

#include <climits>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

constexpr char GREATER_THAN = '>';
constexpr char LESS_THAN = '<';

void findMaxInt(int currentIndex,
                queue<char> &signs,
                queue<int> &candidates,
                vector<bool> &maxVisited,
                string &maxResult) {

  for (int candidate = (int)signs.size(); candidate >= 0; --candidate) {
    candidates.push(candidate);
  }

  int prevCandidate = candidates.front();
  candidates.pop();

  while (!candidates.empty()) {
    int currentNumber = candidates.front();
    candidates.pop();

    char currentSign = signs.front();
    signs.pop();

    if (currentSign == LESS_THAN) {
      cout << currentSign;

      char asciiNumber = prevCandidate + '0';
      maxResult += asciiNumber;
      prevCandidate = currentNumber;
    } else if (currentSign == GREATER_THAN) {
      char asciiNumber = currentNumber + '0';
      maxResult += asciiNumber;
    }

    cout << maxResult << ' ' << prevCandidate << ' ' << currentSign << ' '
         << currentNumber << '\n';
  }
};

int main() {

  int signCount = 0;
  cin >> signCount;

  queue<char> signs;
  for (int signIndex = 0; signIndex < signCount; ++signIndex) {
    char inSign;
    cin >> inSign;

    signs.push(inSign);
  }

  queue<int> candidates;

  vector<bool> minVisited(signCount + 1, false);
  vector<bool> maxVisited(signCount + 1, false);

  string minResult;
  string maxResult;
  findMaxInt(0, signs, candidates, maxVisited, maxResult);

  cout << minResult << '\n' << maxResult;

  return 0;
}