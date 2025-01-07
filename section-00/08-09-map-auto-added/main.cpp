#include <bits/stdc++.h>

using namespace std;

map<int, int> myIntMap;
map<string, string> myStringMap;

int main() {
  cout << myIntMap[1] << endl;         // 0을 할당
  cout << myStringMap["aaa"] << endl;  // 빈 문자열 할당

  for (auto it : myIntMap) cout << it.first << ' ' << it.second << endl;

  for (auto it : myStringMap) cout << it.first << ' ' << it.second << endl;

  return 0;
}