#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int main() {
  vector<pair<int, int>> pairs = {{5, 1}, {2, 2}, {5, 3}, {3, 4}, {2, 5}};

  cout << "Original : " << endl;

  for (const auto& p : pairs) {
    cout << p.first << ' ' << p.second << endl;
  }

  cout << endl;

  cout << "Sorted with sort : " << endl;

  sort(pairs.begin(), pairs.end(), cmp);

  for (const auto& p : pairs) {
    cout << p.first << ' ' << p.second << endl;
  }

  cout << endl;

  cout << "Sorted with stable_sort : " << endl;

  pairs = {{5, 1}, {2, 2}, {5, 3}, {3, 4}, {2, 5}};

  stable_sort(pairs.begin(), pairs.end(), cmp);

  for (const auto& p : pairs) {
    cout << p.first << ' ' << p.second << endl;
  }

  cout << endl;

  return 0;
}