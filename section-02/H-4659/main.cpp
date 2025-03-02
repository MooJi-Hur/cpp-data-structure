/*
 * Problem: 4659
 * URL: https://www.acmicpc.net/problem/4659
 */

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

const string END_INPUT = "end";

int main() {

  vector<string> userPasswords;

  while (true) {
    string userPassword;

    cin >> userPassword;

    if (userPassword == END_INPUT) {
      break;
    }

    userPasswords.push_back(userPassword);
  }

  vector<bool> goodPasswords(userPasswords.size(), false);

  for (size_t passwordIndex = 0; passwordIndex < userPasswords.size();
       ++passwordIndex) {
    string userPassword = userPasswords[passwordIndex];

    regex vowels_match("[aeiou]+");
    regex phoneme_repeat_match("([aeiou]{3}|[^aeiou]{3})");
    regex char_repeat_match("([^eo])\\1");

    goodPasswords[passwordIndex] =
        (regex_search(userPassword, vowels_match) &&
         !regex_search(userPassword, phoneme_repeat_match) &&
         !regex_search(userPassword, char_repeat_match));
  }

  for (size_t passwordIndex = 0; passwordIndex < userPasswords.size();
       ++passwordIndex) {
    string userPassword = userPasswords[passwordIndex];
    string validatedPassword = goodPasswords[passwordIndex] ? "" : "not ";

    cout << '<' << userPassword << '>' << " is " << validatedPassword
         << "acceptable." << '\n';
  }

  return 0;
}