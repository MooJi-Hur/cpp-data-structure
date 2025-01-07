#include <bits/stdc++.h>

using namespace std;

const int n = 3;
int main() {
  int myVector[n] = {1, 2, 3};
  int ret[n];

  copy(myVector, myVector + n, ret);

  cout << ret[1] << endl;

  ret[1] = 100;

  cout << ret[1] << endl;
  cout << myVector[1] << endl;

  return 0;
}