#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {1, 2, 3, 4, 5, 6};
  rotate(myVector.begin() + 1, myVector.begin() + 2, myVector.begin() + 5);

  for (int i : myVector) cout << i << ' ';

  return 0;
}