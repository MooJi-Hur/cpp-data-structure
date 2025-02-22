/*
 * Problem: 1940
 * URL: https://www.acmicpc.net/problem/1940
 */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void combination(int startIndex,
                 vector<int> &tools,
                 vector<int> &units,
                 int &unitCount,
                 int &unitSum) {
  if (units.size() == 2) {
    int unitLocalSum = accumulate(units.begin(), units.end(), 0);
    if (unitLocalSum == unitSum) {
      unitCount++;
    }
    return;
  }

  for (size_t unitIndex = startIndex + 1; unitIndex < tools.size();
       ++unitIndex) {
    units.push_back(tools[unitIndex]);
    combination(unitIndex, tools, units, unitCount, unitSum);
    units.pop_back();
  }
}

int main() {

  int toolCount = 0;
  int unitSum = 0;

  cin >> toolCount >> unitSum;

  vector<int> tools(toolCount);

  for (int toolIndex = 0; toolIndex < toolCount; ++toolIndex) {
    cin >> tools[toolIndex];
  }

  int unitCount = 0;
  vector<int> units;
  combination(-1, tools, units, unitCount, unitSum);

  cout << unitCount;

  return 0;
}
