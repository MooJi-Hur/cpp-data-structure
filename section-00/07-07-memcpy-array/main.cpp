#include <bits/stdc++.h>

using namespace std;

int main() {
  int myArray[3] = {1, 2, 3};

  int ret[3];

  memcpy(ret, myArray, sizeof(myArray));

  cout << ret[1] << endl;

  ret[1] = 100;

  cout << ret[1] << endl;
  cout << myArray[1] << endl;

  return 0;
}