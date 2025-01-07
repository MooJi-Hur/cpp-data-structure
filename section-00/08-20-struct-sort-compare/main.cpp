#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  string myIntStrings[3] = {"111", "222", "33"};

  sort(myIntStrings, myIntStrings + 3, compare);

  for (string myIntString : myIntStrings) cout << myIntString << ' ';

  return 0;
}