#include <bits/stdc++.h>

using namespace std;

int main() {
  set<pair<string, int>> myFirstSet;

  myFirstSet.insert({"Hi", 1});
  myFirstSet.insert({"Hi", 1});
  myFirstSet.insert({"Hi", 1});

  cout << myFirstSet.size() << endl;

  set<int> mySecondSet;

  mySecondSet.insert(2);
  mySecondSet.insert(1);
  mySecondSet.insert(2);

  for (auto it : mySecondSet) {
    cout << it << endl;
  }

  return 0;
}