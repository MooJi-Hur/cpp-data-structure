#include <bits/stdc++.h>

using namespace std;

const int maxN = 10;

int oneD[maxN];
int twoD[maxN][maxN];

int main() {
  memset(oneD, -1, sizeof(oneD));
  memset(twoD, 0, sizeof(twoD));

  for (int i = 0; i < maxN; i++) cout << oneD[i] << " ";

  cout << endl;

  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < maxN; j++) {
      cout << twoD[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}