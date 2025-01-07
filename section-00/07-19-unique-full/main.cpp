#include <bits/stdc++.h>

using namespace std;

vector<int> myVector{1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};

int main() {
  auto it = unique(myVector.begin(), myVector.end());

  for (int i : myVector) cout << i << ' ';
  cout << endl;

  return 0;
}