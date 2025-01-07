#include <bits/stdc++.h>

using namespace std;

map<string, int> nameId;
string names[] = {"kim", "lee", "ha"};

int main() {
  for (int i = 0; i < 3; i++) {
    nameId.insert({names[i], i + 1});
    nameId[names[i]] = i + 1;
  }

  cout << nameId["na"] << endl;

  nameId["na"] = 4;

  cout << nameId.size() << endl;

  nameId.erase("na");

  auto it = nameId.find("na");

  if (it == nameId.end()) {
    cout << "Not Found." << endl;
  }

  nameId["na"] = 10;

  it = nameId.find("na");

  if (it != nameId.end()) {
    cout << (*it).first << " : " << (*it).second << endl;
  }

  cout << endl;

  for (auto it : nameId) {
    cout << (it).first << " : " << (it).second << endl;
  }

  cout << endl;

  for (auto it = nameId.begin(); it != nameId.end(); it++) {
    cout << (*it).first << " : " << (*it).second << endl;
  }

  nameId.clear();

  return 0;
}