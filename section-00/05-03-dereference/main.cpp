#include <bits/stdc++.h>

using namespace std;

int main() {
  string myWord = "Hello";

  string* myWordPointer = &myWord;

  cout << myWordPointer << endl;
  cout << *myWordPointer << endl;

  return 0;
}