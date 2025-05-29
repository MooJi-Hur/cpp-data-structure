/*
 * Problem: 1062
 * URL: https://www.acmicpc.net/problem/1062
 */

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// in
int wordCount = 0, alphabetCount = 0;
constexpr int MAX_WORD = 50;
constexpr int MAX_ALPHABET = 26;

constexpr int MAX_INNER_LETTER = 15 - 8;

// out
int maxReadableWord = 0;

constexpr char SMALL_A = 'a';

// logic
string PREFIX = "anta";
string SUFFIX = "tica";

int affixCount = 0;

bitset<MAX_ALPHABET> affixAlphabets;
vector<int> letterCombiCandidates;

void presetAffix() {
  string affix = PREFIX + SUFFIX;

  for (size_t affixIndex = 0; affixIndex < affix.size(); ++affixIndex) {
    char affixLetter = affix[affixIndex];
    int letterIndex = affixLetter - SMALL_A;

    affixAlphabets |= (1 << letterIndex);

    affixCount = affixAlphabets.count();
  }
};

void readWords() {
  for (int wordIndex = 0; wordIndex < wordCount; ++wordIndex) {
    string word;
    getline(cin >> ws, word);

    word.erase(0, PREFIX.size());
    word.erase(word.size() - SUFFIX.size(), SUFFIX.size());

    cout << word << '\n';

    for (int letterIndex = 0; letterIndex < word.size(); ++letterIndex) {
      cout << word[letterIndex] << ' ';
      int alphabetIndex = word[letterIndex] - SMALL_A;
    }
  }
};

void combiAlphabets() {

};

int main() {
  cin >> wordCount >> alphabetCount;

  presetAffix();

  if (affixCount > alphabetCount) {
    maxReadableWord = 0;
    cout << maxReadableWord;
    return 0;
  }

  readWords();

  // 알파벳 조합마다 읽을 수 있는 단어의 갯수가 다름, 무슨 알파벳인지는 관심 x
  // 기본적으로 5개는 알아야함,

  combiAlphabets();

  cout << maxReadableWord;
  return 0;
}