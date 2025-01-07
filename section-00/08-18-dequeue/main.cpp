#include <bits/stdc++.h>

using namespace std;

int main() {
  deque<int> myDeque;

  myDeque.push_front(1);
  myDeque.push_back(2);
  myDeque.push_back(3);

  cout << myDeque.front() << endl;
  cout << myDeque.back() << endl;

  cout << myDeque.size() << endl;

  myDeque.pop_back();
  myDeque.pop_front();

  cout << myDeque.size() << endl;

  return 0;
}