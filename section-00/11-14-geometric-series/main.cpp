#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 1, r = 2, n = 4;

  vector<int> myVector;

  cout << a * ((int)pow(2, n) - 1) / (r - 1) << endl;

  for (int i = 0; i < n; i++) {
    myVector.push_back(a);
    a *= r;
  }

  for (int i : myVector) cout << i << endl;

  return 0;
}