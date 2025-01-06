#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {10, 20, 30};

  for (const int& value : myVector) {
    cout << value << " ";

    // value = 100; // value는 const를 참조하므로 에러 발생
  }
  return 0;
}