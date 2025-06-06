/*
 * Problem: 11723
 * URL: https://www.acmicpc.net/problem/11723
 */

#include <iostream>
#include <string>

using namespace std;

// in
string CHECK = "check";

string ALL = "all";
string EMPTY = "empty";

string ADD = "add";
string REMOVE = "remove";

string TOGGLE = "toggle";

int calcCount = 0;
int S = 0;

int main() {

  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> calcCount;

  for (int calcIndex = 0; calcIndex < calcCount; ++calcIndex) {

    string operatorName;
    int targetIndex = 0;
    cin >> operatorName;

    if (operatorName != ALL && operatorName != EMPTY) {
      cin >> targetIndex;
    }

    if (operatorName == CHECK) {
      bool isOn = S & (1 << targetIndex);
      cout << isOn << '\n';
    } else if (operatorName == ALL) {
      S = ~0;
    } else if (operatorName == EMPTY) {
      S = 0;
    } else if (operatorName == ADD) {
      S |= (1 << targetIndex);
    } else if (operatorName == REMOVE) {
      S &= ~(1 << targetIndex);
    } else if (operatorName == TOGGLE) {
      S ^= (1 << targetIndex);
    }
  }
  return 0;
}
