#include <bits/stdc++.h>

using namespace std;

map<int, int> myIntMap;

int main() {
  if (myIntMap[1] == 0) {
    myIntMap[1] = 2;
  }

  for (auto it : myIntMap) cout << it.first << ' ' << it.second;

  return 0;
}