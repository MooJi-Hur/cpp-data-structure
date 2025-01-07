#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector{1, 2, 3};
  vector<int> ret(3);

  copy(myVector.begin(), myVector.end(), ret.begin());

  cout << ret[1] << endl;

  ret[1] = 100;

  cout << ret[1] << endl;
  cout << myVector[1] << endl;

  return 0;
}