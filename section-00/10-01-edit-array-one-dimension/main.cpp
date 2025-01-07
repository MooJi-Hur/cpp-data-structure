#include <bits/stdc++.h>

using namespace std;

int myArray[3] = {1, 2, 3};

void ten(int inArray[]) { inArray[1] = 10; }

void hundred(int inArray[3]) { inArray[2] = 100; }

void thousand(int *inArray) { inArray[3] = 1000; }

int main() {
  ten(myArray);

  cout << myArray[0] << endl;

  hundred(myArray);

  cout << myArray[1] << endl;

  thousand(myArray);

  cout << myArray[2] << endl;

  return 0;
}