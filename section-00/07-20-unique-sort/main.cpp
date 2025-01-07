#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> first{4, 3, 3, 5, 1, 2, 3};

  first.erase(unique(first.begin(), first.end()), first.end());

  for (int i : first) cout << i << ' ';

  cout << endl;

  vector<int> second{4, 3, 3, 5, 1, 2, 3};

  sort(second.begin(), second.end());
  second.erase(unique(second.begin(), second.end()), second.end());

  for (int i : second) cout << i << ' ';

  cout << endl;

  return 0;
}