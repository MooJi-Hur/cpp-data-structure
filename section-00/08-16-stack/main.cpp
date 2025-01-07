#include <bits/stdc++.h>

using namespace std;

stack<string> myStack;

int main() {
  myStack.push("H");
  myStack.push("e");
  myStack.push("l");
  myStack.push("l");
  myStack.push("o");

  while (myStack.size()) {
    cout << myStack.top() << endl;

    myStack.pop();
  }

  return 0;
}