#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << "Not sorted" << endl;

  int notSorted[] = {1, 3, 2};

  do {
    for (int i : notSorted) cout << i << ' ';

    cout << endl;
  } while (next_permutation(notSorted, notSorted + 3));

  cout << "Sorted" << endl;

  int sorted[] = {1, 2, 3};

  do {
    for (int i : sorted) cout << i << ' ';

    cout << endl;
  } while (next_permutation(sorted, sorted + 3));

  return 0;
}