/*
 * Problem: 11655
 * URL: https://www.acmicpc.net/problem/11655
 */

#include <iostream>
#include <string>

using namespace std;

constexpr int NUM_OF_ALPHABET = 26;
constexpr int HALF_OF_ALPHABET = 26 >> 1;
constexpr int ENCODE_KEY = 13;

constexpr char LARGE_FIRST = 'A';
constexpr char SMALL_FIRST = 'a';
constexpr char LARGE_LAST = LARGE_FIRST + NUM_OF_ALPHABET;
constexpr char SMALL_LAST = SMALL_FIRST + NUM_OF_ALPHABET;

constexpr char BLANK = ' ';
constexpr char NUMBER_START = '0';
constexpr char NUMBER_LAST = NUMBER_START + 9;

int main() {

  string inSentence;
  getline(cin, inSentence);

  string outSentence;
  for (size_t letterIndex = 0; letterIndex < inSentence.size(); ++letterIndex) {
    char currentLetter = inSentence[letterIndex];

    bool isNumber =
        (currentLetter >= NUMBER_START && currentLetter <= NUMBER_LAST);
    bool isNotAlphabet = isNumber || (currentLetter == BLANK);

    if (isNotAlphabet) {
      outSentence += currentLetter;
      continue;
    }

    bool inLargeEncodeBound = (currentLetter >= LARGE_FIRST) &&
                              (currentLetter < LARGE_FIRST + HALF_OF_ALPHABET);
    bool inSmallEncodeBound = (currentLetter >= SMALL_FIRST) &&
                              (currentLetter < SMALL_FIRST + HALF_OF_ALPHABET);

    bool inEncodeBound = inLargeEncodeBound || inSmallEncodeBound;

    char encodedLetter;

    if (inEncodeBound) {
      encodedLetter = currentLetter + ENCODE_KEY;
    } else {
      encodedLetter = currentLetter - ENCODE_KEY;
    }

    outSentence += encodedLetter;
  }

  cout << outSentence;
  return 0;
}