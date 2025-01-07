#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;
};

bool compare(const Point &a, const Point &b) { return a.x > b.x; }

vector<Point> pointVecter;
int main() {
  for (int i = 10; i >= 1; i--) {
    pointVecter.push_back({i, 10 - i});
  }

  sort(pointVecter.begin(), pointVecter.end(), compare);

  for (auto it : pointVecter) cout << it.x << " : " << it.y << endl;

  return 0;
}