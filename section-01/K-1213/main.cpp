/*
 * Problem: 1213
 * URL: https://www.acmicpc.net/problem/1213
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int alphabetSize = 26;
constexpr char alphabetLargeStart = 'A';

int main() {

  string initName;
  cin >> initName;

  string forwardName;
  string middleName;
  string backwardName;

  sort(initName.begin(), initName.end());

  vector<int> alphabetCounts(alphabetSize, 0);

  for (int i = 0; i < initName.size(); ++i) {
    int alphabetIndex = initName[i] - alphabetLargeStart;
    alphabetCounts[alphabetIndex]++;
  }

  for (int i = 0; i < alphabetSize; ++i) {
    bool isOdd = (alphabetCounts[i] % 2 != 0);

    if (isOdd) {
      middleName += i + alphabetLargeStart;
      alphabetCounts[i]--;
    }
  }

  if (middleName.size() > 1) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }

  for (int alphabetIndex = 0; alphabetIndex < alphabetSize; ++alphabetIndex) {
    char alphabet = alphabetIndex + alphabetLargeStart;

    for (int alphabetCount = 0; alphabetCount < alphabetCounts[alphabetIndex];
         ++alphabetCount) {
      bool isOdd = (alphabetCount % 2 != 0);
      if (isOdd) {
        forwardName += alphabet;
      } else {
        backwardName += alphabet;
      }
    }
  }

  reverse(backwardName.begin(), backwardName.end());

  cout << forwardName << middleName << backwardName;

  return 0;
}