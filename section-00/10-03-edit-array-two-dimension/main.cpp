#include <bits/stdc++.h>

using namespace std;

int myArray[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

void anyRowSizePram(int inArray[][3]) { inArray[2][2] = 100; }

void threeRowSizePram(int inArray[3][3]) { inArray[2][2] = 1000; }

int main() {
  anyRowSizePram(myArray);
  cout << myArray[2][2] << endl;

  threeRowSizePram(myArray);
  cout << myArray[2][2] << endl;

  return 0;
}