#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<pair<int, int>> myVector;

  for (int i = 1; i <= 5; i++) {
    myVector.push_back({i, i});
  }

  for (auto it : myVector) {
    cout << it.first << " : " << it.second << endl;
  }

  for (pair<int, int> it : myVector) {
    cout << it.first << " : " << it.second << endl;
  }

  return 0;
}