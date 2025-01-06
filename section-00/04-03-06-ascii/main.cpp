#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);

  cin.tie(NULL);

  string asciiSample = "123";

  asciiSample[0]++;  // 문자열의 +는 ASCII 코드 기반 수행

  // ASCII 0(0x00) ~ 127(0x7F), 7비트 부호 체계, 1비트는 에러 검출
  // 값이 범위를 넘지 않도록 유의

  cout << asciiSample << endl;

  return 0;
}