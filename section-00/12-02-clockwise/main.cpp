#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {1, 2, 3, 4, 5, 6};

  rotate(myVector.rbegin(), myVector.rbegin() + 1, myVector.rend());

  for (int i : myVector) cout << i << ' ';

  return 0;
}