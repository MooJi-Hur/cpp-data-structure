#include <bits/stdc++.h>

using namespace std;

int main() {
  string hello = "Hello";

  hello.push_back(' ');  // string의 push_back()은 하나의 문자만 넣을 수 있음
                         // cf. vector push_back()
  hello.push_back('W');
  hello.push_back('o');
  hello.push_back('r');
  hello.push_back('l');
  hello.push_back('d');

  cout << hello;

  return 0;
}