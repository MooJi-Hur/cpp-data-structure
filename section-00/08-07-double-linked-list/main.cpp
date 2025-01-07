#include <bits/stdc++.h>

using namespace std;

list<int> myList;

void print(list<int> inList) {
  for (auto it : inList) cout << it << ' ';
  cout << endl;
}

int main() {
  for (int i = 1; i <= 3; i++) myList.push_back(i);
  for (int i = 1; i <= 3; i++) myList.push_front(i);

  auto it = myList.begin();
  it++;

  myList.insert(it, 1000);

  print(myList);

  it = myList.begin();
  it++;

  myList.erase(it);

  print(myList);

  myList.pop_front();
  myList.pop_back();

  print(myList);

  cout << myList.front() << " : " << myList.back() << endl;
  myList.clear();

  return 0;
}