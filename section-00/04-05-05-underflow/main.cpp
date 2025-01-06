#include <bits/stdc++.h>

using namespace std;

int main() {
  int intMin = -2147483648;
  cout << intMin << endl;

  intMin--;
  cout << intMin << endl;  // 언더플로우로 최댓값을 출력

  return 0;
}