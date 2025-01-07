#include <bits/stdc++.h>

using namespace std;

map<int, int> myIntMap;

int main() {
  if (myIntMap.find(1) == myIntMap.end()) {
    myIntMap[1] = 2;
  }

  for (auto it : myIntMap) cout << it.first << ' ' << it.second;

  return 0;
}