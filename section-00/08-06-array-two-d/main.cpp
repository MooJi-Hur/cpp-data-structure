#include <bits/stdc++.h>

using namespace std;

const int mxy = 3;
const int mxx = 4;

int towD[mxy][mxx];

int main() {
  for (int i = 0; i < mxy; i++) {
    for (int j = 0; j < mxx; j++) {
      towD[i][j] = (i + j);
    }
  }

  for (int i = 0; i < mxy; i++) {
    for (int j = 0; j < mxx; j++) {
      cout << towD[i][j] << ' ';
    }

    cout << endl;
  }

  return 0;
}