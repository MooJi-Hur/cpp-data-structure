#include <bits/stdc++.h>

using namespace std;

int myArray[3] = {1, 2, 3};

int n = 3, r = 3;

void show() {
  for (int i = 0; i < r; i++) {
    cout << myArray[i] << ' ';
  }

  cout << endl;
}

void recursivePermutation(int n, int r, int depth) {
  if (r == depth) {
    show();
    return;
  }

  for (int i = depth; i < n; i++) {
    cout << "Change : " << n << " : " << r << " : " << depth << endl;
    swap(myArray[i], myArray[depth]);
    recursivePermutation(n, r, depth + 1);
    cout << "Rechange : " << n << " : " << r << " : " << depth << endl;
    swap(myArray[i], myArray[depth]);

    cout << endl;
  }
  return;
}

int main() {
  recursivePermutation(n, r, 0);

  return 0;
}