#include <bits/stdc++.h>

using namespace std;

int twoD[10][10];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&twoD[0][0], &twoD[0][0] + 8 * 8,
       7);  // 행 단위로 순차적으로 실행하므로, 정사각이 만들어지지 않음

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << twoD[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}