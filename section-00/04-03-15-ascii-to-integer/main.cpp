#include <bits/stdc++.h>

using namespace std;

int main() {
  string myNumber = "1";
  string myWord = "Hello";

  // 입력받은 값이 문자열이나 0이면 0, 숫자인 string이면 숫자로 바로 변환
  cout << atoi(myNumber.c_str()) << endl;
  cout << atoi(myWord.c_str()) << endl;

  return 0;
}