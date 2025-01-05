#include <bits/stdc++.h>

using namespace std;

int main() {
  string ko = "나는";

  cout << ko[0] << endl;  // 한글은 3byte가 한 글자, '나'로 출력되지 않음
  cout << ko[0] << ko[1] << ko[2] << endl;

  cout << ko << endl;

  string en = "abc";

  cout << en[0] << endl;
  cout << en << endl;

  return 0;
}