#include <bits/stdc++.h>

using namespace std;

int main() {
  int myArray[] = {1, 2, 3};

  bool flag = 1;

  do {
    flag = next_permutation(myArray, myArray + 3);
    cout << "Flag : " << flag << endl;

    for (int i : myArray) cout << i << ' ';
    cout << endl;

  } while (flag);

  return 0;
}