#include <bits/stdc++.h>

using namespace std;

int myArray[3] = {1, 2, 3};

int main() {
  int* myArrayPointer = myArray;  // 배열 이름을 할당했으나

  cout << myArrayPointer << endl;  // 첫 번재 요소의 주소와 같은 값이 나타남
                                   // 배열의 크기 정보 없음
  cout << &myArray[0] << endl;
  cout << myArrayPointer + 1 << endl;
  cout << &myArray[1] << endl;

  return 0;
}