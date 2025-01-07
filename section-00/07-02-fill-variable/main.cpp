#include <bits/stdc++.h>

using namespace std;

int oneD[10];
int twoD[10][10];

int main() {
  fill(oneD, oneD + 10, 100);

  for (int i = 0; i < 10; i++) {
    cout << oneD[i] << " ";
  }
  cout << endl;

  fill(&twoD[0][0], &twoD[0][0] + 10 * 10, 2);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << twoD[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}