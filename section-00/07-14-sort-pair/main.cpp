#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pairs;
int main() {
  for (int i = 10; i >= 1; i--) {
    pairs.push_back({i, 10 - i});
  }

  sort(pairs.begin(), pairs.end());

  for (auto pairIt : pairs) {
    cout << pairIt.first << " : " << pairIt.second << endl;
  }

  return 0;
}