#include <bits/stdc++.h>

using namespace std;

int twoD[10][10];

int main() {
  int *ptr = &twoD[0][0];
  int size = 10 * 10;

  for (int i = 0; i < size; ++i) {
    *(ptr + i) = 1;  // 배열을 1로 초기화
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << twoD[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}