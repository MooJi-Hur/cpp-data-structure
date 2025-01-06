#include <bits/stdc++.h>

using namespace std;

int myCount;
string myLine;

int main() {
  cin >> myCount;
  string bufferflush;

  getline(cin,
          bufferflush);  // bufferflash가 없을 경우, 첫 줄은 개행문자가 출력됨

  for (int i = 0; i < myCount; i++) {
    getline(cin, myLine);
    cout << myLine << endl;
  }

  return 0;
}