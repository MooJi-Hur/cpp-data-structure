#include <bits/stdc++.h>

using namespace std;

queue<int> myQueue;

int main() {
  for (int i = 1; i <= 10; i++) myQueue.push(i);

  while (myQueue.size()) {
    cout << myQueue.front() << ' ';

    myQueue.pop();
  }

  return 0;
}