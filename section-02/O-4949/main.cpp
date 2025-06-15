/*
 * Problem: 4949
 * URL: https://www.acmicpc.net/problem/4949
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 각 문자열은 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호("( )"),
// 대괄호("[ ]")로 이루어져 있으며, 온점(".")으로 끝나고, 길이는 100글자보다
// 작거나 같다.

// in
string EOL = ".";
string inSentence;

// out
string BALANCE = "yes";
string UNBALANCE = "no";

// logic
char LEFT_PARENTHESES = '(';
char RIGHT_PARENTHESES = ')';
string FULL_PARENTHESES = "()";

char LEFT_BRACKETS = '[';
char RIGHT_BRACKETS = ']';
string FULL_BRACKETS = "[]";

int main() {

  while (getline(cin, inSentence)) {

    if (inSentence == EOL) {
      break;
    }

    stack<char> balanceStack;

    for (char inLetter : inSentence) {

      bool needInspect =
          inLetter == LEFT_BRACKETS || inLetter == LEFT_PARENTHESES ||
          inLetter == RIGHT_BRACKETS || inLetter == RIGHT_PARENTHESES;

      if (!needInspect) {
        continue;
      }

      if (balanceStack.empty()) {
        balanceStack.push(inLetter);
        continue;
      }

      char topLetter = balanceStack.top();

      string lastPair = string() + topLetter + inLetter;

      bool isPair = lastPair == FULL_BRACKETS || lastPair == FULL_PARENTHESES;

      if (isPair) {
        balanceStack.pop();
      } else {
        balanceStack.push(inLetter);
      }
    }

    bool isBalance = balanceStack.empty();

    string result = isBalance ? BALANCE : UNBALANCE;
    cout << result << '\n';
  }
  return 0;
}