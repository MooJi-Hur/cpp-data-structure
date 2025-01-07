#include <bits/stdc++.h>

using namespace std;

struct World {
  int w, o;
  double r, l, d;
};

void print(World inWorld) {
  cout << inWorld.w << ' ' << inWorld.o << ' ' << inWorld.r << ' ' << inWorld.l
       << ' ' << inWorld.d << ' ' << endl;
}

int main() {
  World myWorld = {1, 1, 1, 1, 1};

  print(myWorld);

  vector<World> ret;

  ret.push_back({1, 2, 3, 4, 5});
  ret.push_back({1, 2, 3, 4, 6});

  ret.push_back({});
  ret.push_back({1, 3});

  for (World world : ret) {
    print(world);
  }

  return 0;
}