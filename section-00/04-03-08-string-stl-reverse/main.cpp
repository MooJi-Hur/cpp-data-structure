#include <bits/stdc++.h>

using namespace std;

int main() {
  string full = "Hello, World!";

  reverse(full.begin(),
          full.end());  // reverse는 STL에서 지원하는 함수로 void, 원본이 바뀜
  cout << full << endl;

  reverse(full.begin(), full.end());
  cout << full << endl;

  reverse(full.begin() + 3, full.end());
  cout << full << endl;

  return 0;
}