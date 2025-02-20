/*
 * Problem: 10988
 * URL: https://www.acmicpc.net/problem/10988
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string inWord;
  getline(cin >> ws, inWord);

  bool isPalindrom = true;

  if (inWord.size() == 1) {
    cout << isPalindrom;
    return 0;
  }

  size_t halfInWordSize = inWord.size() >> 1;

  string forwardHalfWord = inWord.substr(0, halfInWordSize);

  reverse(inWord.begin(), inWord.end());
  string backwardHalfWord = inWord.substr(0, halfInWordSize);

  for (int i = 0; i < halfInWordSize; ++i) {
    bool isSameChar = (forwardHalfWord[i] == backwardHalfWord[i]);
    if (!isSameChar) {
      isPalindrom = false;
      break;
    }
  }

  cout << isPalindrom;

  return 0;
}