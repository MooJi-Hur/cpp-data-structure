#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pairs;

bool cmp(pair<int, int> prev, pair<int, int> next) {
  return prev.first > next.first;
}

int main() {
  for (int i = 10; i >= 1; i--) {
    pairs.push_back({i, 10 - i});
  }

  sort(pairs.begin(), pairs.end(), cmp);

  for (auto it : pairs) {
    cout << it.first << " : " << it.second << endl;
  }

  return 0;
}