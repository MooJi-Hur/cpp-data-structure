/*
 * Problem: 1620
 * URL: https://www.acmicpc.net/problem/1620
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  int monsterCount = 0;
  int problemCount = 0;

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> monsterCount >> problemCount;

  monsterCount++;
  vector<string> monstersKeyIndex(monsterCount);
  unordered_map<string, int> monstersKeyName;

  for (int i = 1; i < monsterCount; ++i) {
    cin >> monstersKeyIndex[i];
    monstersKeyName.insert({monstersKeyIndex[i], i});
  }

  for (int i = 0; i < problemCount; ++i) {
    string problem;
    cin >> problem;

    if (isdigit(problem[0])) {
      cout << monstersKeyIndex[stoi(problem)] << '\n';
    } else {
      cout << monstersKeyName[problem] << '\n';
    }
  }
  return 0;
}