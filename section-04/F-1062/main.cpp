/*
 * Problem: 1062
 * URL: https://www.acmicpc.net/problem/1062
 */

#include <bitset>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
constexpr int MAX_ALPHABET_SIZE = 26;

constexpr int AFFIX_SIZE = 4;
constexpr int MUST_LEARN_CHAR = 5;

string WORD_PREFIX = "anta";
string WORD_SUFFIX = "tica";

int wordSize = 0, alphabetSize = 0;

// out
int maxTeachableWord = 0;

// logic
constexpr char START_CHAR = 'a';

bitset<MAX_ALPHABET_SIZE> alphabetState = 0;

vector<string> words;

bitset<MAX_ALPHABET_SIZE> onAphabets(string word) {
  bitset<MAX_ALPHABET_SIZE> alphabetBitset = 0;
  for (char letter : word) {

    int letterIndex = letter - START_CHAR;

    alphabetBitset |= (1 << letterIndex);
  }

  return alphabetBitset;
};

void prepareWords() {

  for (int wordIndex = 0; wordIndex < wordSize; ++wordIndex) {
    string inWord;
    cin >> inWord;

    inWord.erase(0, AFFIX_SIZE);
    inWord.erase(inWord.size() - AFFIX_SIZE, inWord.size());

    words.push_back(inWord);
  }
};

void countMaxWord() {
  for (int combiIndex = 0; combiIndex < (1 << wordSize); ++combiIndex) {
    int wordCount = 0;
    int charCount = 0;
    bitset<MAX_ALPHABET_SIZE> combiBit = alphabetState;

    for (int wordIndex = 0; wordIndex < wordSize; ++wordIndex) {
      if (combiIndex & (1 << wordIndex)) {
        wordCount++;
        combiBit |= onAphabets(words[wordIndex]);
      }
    }

    for (char currentBit : combiBit.to_string()) {
      if (currentBit == '1') {
        charCount++;
      }
    }

    if (charCount <= alphabetSize) {
      maxTeachableWord = max(maxTeachableWord, wordCount);
    }
  }
};

int main() {

  cin >> wordSize >> alphabetSize;

  if (alphabetSize < MUST_LEARN_CHAR) {
    cout << maxTeachableWord;
    return 0;
  }

  alphabetState |= onAphabets(WORD_PREFIX);
  alphabetState |= onAphabets(WORD_SUFFIX);

  prepareWords();

  countMaxWord();

  cout << maxTeachableWord;

  return 0;
}
