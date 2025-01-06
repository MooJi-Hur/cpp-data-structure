#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
  cin >> n;

  int variableLengthArray[n];  // Array는 런타임 시 크기 결정

  memset(variableLengthArray, 0, sizeof(variableLengthArray));

  for (int i : variableLengthArray) {  // 컴파일 시 범위 결정
    cout << i << " ";  // clang에서는 출력됨, C++ 표준에서는 지원하지 않음
  }

  return 0;
}