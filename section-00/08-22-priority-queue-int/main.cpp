#include <bits/stdc++.h>

using namespace std;

struct Point {
  int y, x;
  Point(int y, int x) : y(y), x(x) {}
  Point() {
    y = -1;
    x = -1;
  }
  bool operator<(const Point &a) const { return x < a.x; }
};

priority_queue<Point> myPoints;

int main() {
  myPoints.push({1, 1});
  myPoints.push({2, 2});
  myPoints.push({3, 3});
  myPoints.push({4, 4});
  myPoints.push({5, 5});

  cout << myPoints.top().x << endl;

  return 0;
}