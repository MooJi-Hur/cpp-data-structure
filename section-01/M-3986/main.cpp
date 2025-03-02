/*
 * Problem: 3986
 * URL: https://www.acmicpc.net/problem/3986
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

  int wordCount = 0;
  cin >> wordCount;

  int goodWordCount = 0;
  for (int wordIndex = 0; wordIndex < wordCount; ++wordIndex) {
    string inWord;
    getline(cin >> ws, inWord);

    stack<char> letters;

    for (char inChar : inWord) {
      if (!letters.empty() && letters.top() == inChar) {
        letters.pop();
      } else {
        letters.push(inChar);
      }
    }

    if (letters.empty()) {
      goodWordCount++;
    }
  }

  cout << goodWordCount;

  return 0;
}