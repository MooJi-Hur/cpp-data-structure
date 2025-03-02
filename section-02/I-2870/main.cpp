/*
 * Problem: 2870
 * URL: https://www.acmicpc.net/problem/2870
 */

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool compareNumbers(const string &a, const string &b) {
  if (a.size() != b.size()) {
    return a.size() < b.size();
  }

  return a < b;
}

int main() {
  int inLineSize = 0;
  cin >> inLineSize;
  vector<string> inLines(inLineSize);

  for (int lineIndex = 0; lineIndex < inLineSize; ++lineIndex) {
    cin >> inLines[lineIndex];
  }

  vector<string> outNumbers;
  regex number_regex("\\d+");
  for (const string line : inLines) {

    auto numbers_begin =
        sregex_iterator(line.begin(), line.end(), number_regex);
    auto numbers_end = sregex_iterator();

    for (sregex_iterator i = numbers_begin; i != numbers_end; ++i) {
      smatch match = *i;
      string match_str = match.str();

      while (match_str.size() > 1 && (match_str[0] == '0')) {
        match_str.erase(0, 1);
      }
      outNumbers.push_back(match_str);
    }
  }

  sort(outNumbers.begin(), outNumbers.end(), compareNumbers);

  for (string outNumber : outNumbers) {
    cout << outNumber << '\n';
  }

  return 0;
}