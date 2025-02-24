/*
 * Problem: 1159
 * URL: https://www.acmicpc.net/problem/1159
 */

#include <array>
#include <iostream>
#include <string>

using namespace std;

constexpr int ALPHABET_SIZE = 26;
constexpr char smallA = 'a';

int main() {
  int numOfPlayer = 0;
  cin >> numOfPlayer;

  array<int, ALPHABET_SIZE> alphabetCounts;
  alphabetCounts.fill(0);

  string resultNames;

  for (int playerIndex = 0; playerIndex < numOfPlayer; ++playerIndex) {
    string playerName;
    cin >> playerName;

    char firstNameChar = playerName[0];
    alphabetCounts[firstNameChar - smallA]++;
  }

  bool canPlay = false;

  for (int countIndex = 0; countIndex < ALPHABET_SIZE; ++countIndex) {
    if (alphabetCounts[countIndex] >= 5) {
      canPlay = true;
      char firstChar = countIndex + smallA;
      resultNames += firstChar;
    }
  }

  if (canPlay) {
    cout << resultNames;
  } else {
    cout << "PREDAJA";
  }

  return 0;
}