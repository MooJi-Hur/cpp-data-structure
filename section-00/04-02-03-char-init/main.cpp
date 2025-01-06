#include <bits/stdc++.h>

using namespace std;

int main() {
  char nullAscii = '\0';
  char zero = 0;
  char null = NULL;

  string emptyString = "";

  if (nullAscii == zero) cout << "nullAscii == zero : " << 1 << endl;
  if (zero == null) cout << "zero == null : " << 1 << endl;

  if (string(1, nullAscii) == emptyString)
    cout << "string(1, nullAscii) == emptyString : " << 1 << endl;

  return 0;
}