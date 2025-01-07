#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> myUnorderedMap;
int main() {
  myUnorderedMap["Hello,"] = 0;
  myUnorderedMap["World!"] = 1;

  for (auto it : myUnorderedMap) {
    cout << it.first << " : " << it.second << endl;
  }

  return 0;
}