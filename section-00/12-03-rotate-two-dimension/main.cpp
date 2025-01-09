#include <bits/stdc++.h>

using namespace std;

void rotateLeft90(vector<vector<int>> &key) {
  int row = key.size();
  int column = key[0].size();

  // 크기 반전
  vector<vector<int>> rotated(column, vector<int>(row, 0));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      rotated[column - j - 1][i] = key[i][j];
    }
  }

  key = rotated;
}

void rotateRight90(vector<vector<int>> &key) {
  int row = key.size();
  int column = key[0].size();

  // 크기 반전
  vector<vector<int>> rotated(column, vector<int>(row, 0));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      rotated[j][row - i - 1] = key[i][j];
    }
  }

  key = rotated;
}

void show(const vector<vector<int>> &key) {
  int n = key.size();
  int m = key[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << key[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<vector<int>> myTwoD = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
  };

  cout << "Original Matrix:" << endl;
  show(myTwoD);

  rotateRight90(myTwoD);
  cout << "Rotated Right 90 degrees:" << endl;
  show(myTwoD);

  rotateLeft90(myTwoD);
  cout << "Rotated Left 90 degrees:" << endl;
  show(myTwoD);

  return 0;
}
