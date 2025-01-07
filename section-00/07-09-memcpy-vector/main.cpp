#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector{1, 2, 3};
  vector<int> ret(
      3);  // vector는 단순 복사가 가능한 (Trivially Copyable) 타입이 아님

  memcpy(&ret, &myVector, 3 * sizeof(int));

  cout << ret[1] << endl;

  ret[1] = 100;

  cout << ret[1] << endl;
  cout << myVector[1] << endl;

  return 0;
}