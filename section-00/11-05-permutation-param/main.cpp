#include <bits/stdc++.h>

using namespace std;

int main() {
  const int SIZE = 3;
  int myArray[SIZE] = {1, 2, 3};

  do {
    for (int i : myArray) cout << i << ' ';

    cout << endl;
  } while (next_permutation(&myArray[0], &myArray[SIZE]));

  cout << endl;

  do {
    for (int i : myArray) cout << i << ' ';

    cout << endl;
  } while (next_permutation(&myArray[0], &myArray[0] + 3));

  cout << endl;

  do {
    for (int i : myArray) cout << i << ' ';

    cout << endl;
  } while (next_permutation(myArray, myArray + 3));

  return 0;
}