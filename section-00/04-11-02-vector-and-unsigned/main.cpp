#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {1, 2, 3};

  // bad    // vector의 size는 unsigned int를 반환
  // int와 계산 시  음수가 나와야할 결과임에도 아주 큰 양수가
  // 나올 수 있음
  cout << myVector.size() - 10 << endl;

  // good
  cout << (int)myVector.size() - 10 << endl;

  return 0;
}