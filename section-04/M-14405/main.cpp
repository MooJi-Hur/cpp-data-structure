/*
 * Problem: 14405
 * URL: https://www.acmicpc.net/problem/14405
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

  string inLetters;
  cin >> inLetters;

  size_t letterIndex = 0;
  bool canSpeak = true;
  while (letterIndex < inLetters.size()) {
    string subLetter = inLetters.substr(letterIndex, 2);
    if (subLetter == "pi" || subLetter == "ka") {
      letterIndex += 2;
    } else if (subLetter == "ch") {
      string nextLetter = inLetters.substr(letterIndex + 2, 1);
      if (nextLetter == "u") {
        letterIndex += 3;
      } else {
        canSpeak = false;
        break;
      }
    } else {
      canSpeak = false;
      break;
    }
  }

  if (canSpeak) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
