#include <bits/stdc++.h>

using namespace std;

int main() {
  string myString = "123456";

  vector<int> digits;

  for (int i = 0; i < myString.length(); i++) {
    // 문자 타입에서 '0'을 빼 정수 값으로 변환
    // '0' = 48, '1' = 49
    int digit = myString[i] - '0';

    digits.push_back(digit);
  }

  for (int i = 0; i < digits.size(); i++) {
    cout << digits[i] << " ";
  }

  return 0;
}