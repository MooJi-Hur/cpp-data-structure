/*
 * Problem: 1062
 * URL: https://www.acmicpc.net/problem/1062
 */

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

// in
int wordSize = 0, learnLetterSize = 0;

constexpr int ALPHABET_SIZE = 26;

vector<bitset<ALPHABET_SIZE>> words;

// logic
constexpr int SMALL_A = 'a' - 'a';
constexpr int SMALL_N = 'n' - 'a';
constexpr int SMALL_T = 't' - 'a';
constexpr int SMALL_I = 'i' - 'a';
constexpr int SMALL_C = 'c' - 'a';

void readWords() {
  words.resize(wordSize, 0);

  for (int rowIndex = 0; rowIndex < wordSize; ++rowIndex) {
    string row;
    getline(cin >> ws, row);
    for (int colIndex = 0; colIndex < (int)row.size(); ++colIndex) {
      words[rowIndex] |= (1 << (row[colIndex] - 'a'));
    }
  }
};

int countReadableWords(bitset<ALPHABET_SIZE> mask) {
  int wordCount = 0;

  for (auto word : words) {
    bool hasLetter = word != 0;
    bool isMaskedWord = hasLetter && (word & mask) == word;

    if (isMaskedWord) {
      wordCount++;
    }
  }

  return wordCount;
};

int findAlphabetCombi(int alphabetIndex,
                      int unknownCount,
                      bitset<ALPHABET_SIZE> mask) {

  if (unknownCount < 0) {
    return 0;
  }

  if (alphabetIndex == ALPHABET_SIZE) {
    return countReadableWords(mask);
  }

  bitset<ALPHABET_SIZE> nextMask = mask;
  nextMask |= (1 << alphabetIndex);

  int wordCounts =
      findAlphabetCombi(alphabetIndex + 1, unknownCount - 1, nextMask);

  bool isAFFIX = alphabetIndex == SMALL_A || alphabetIndex == SMALL_C ||
                 alphabetIndex == SMALL_I || alphabetIndex == SMALL_N ||
                 alphabetIndex == SMALL_T;

  if (!isAFFIX) {
    wordCounts = max(wordCounts,
                     findAlphabetCombi(alphabetIndex + 1, unknownCount, mask));
  }

  return wordCounts;
};

int main() {

  cin >> wordSize >> learnLetterSize;

  readWords();

  int initAlphabetIndex = 0;
  int initMask = 0;
  cout << findAlphabetCombi(initAlphabetIndex, learnLetterSize, initMask);

  return 0;
}