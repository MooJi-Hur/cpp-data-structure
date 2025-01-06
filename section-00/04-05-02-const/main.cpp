#include <bits/stdc++.h>

using namespace std;

void printConstRef(const int& x) {
  // x = 100; // const는 수정할 수 없으므로 에러
  cout << x;
}

int main() {
  int x = 10;

  printConstRef(x);
  return 0;
}