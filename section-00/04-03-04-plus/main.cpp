#include <bits/stdc++.h>

using namespace std;

int main() {
  string init = "abc";

  // good
  init += "d";

  // bad
  init = init + "d";  // 문자열을 만들어 재할당, 시간이 걸림
}