/*
 * Problem: 10808
 * URL: https://www.acmicpc.net/problem/10808
 */

#include <array>
#include <iostream>
#include <string>

using namespace std;

constexpr char SMALL_A = 'a';
constexpr int ALPHABET_SIZE = 26;

int main() {
  string inWord;
  getline(cin >> ws, inWord);

  array<int, ALPHABET_SIZE> letterCounts;

  letterCounts.fill(0);

  for (char letter : inWord) {
    int alphabetIndex = letter - SMALL_A;

    letterCounts[alphabetIndex]++;
  }

  for (int letterCount : letterCounts) {
    cout << letterCount << ' ';
  }

  return 0;
}
