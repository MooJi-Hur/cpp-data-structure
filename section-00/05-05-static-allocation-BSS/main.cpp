#include <bits/stdc++.h>

using namespace std;

// BSS Segment
// 전역 변수, static, const 초기화가 되지 않거나 0으로 초기화 된 값 할당
int withoutInit;
int initZero = 0;
const int initConstInt = 0;

int main() {
  static int localWithoutInit;
  static int localInit = 0;
  return 0;
}