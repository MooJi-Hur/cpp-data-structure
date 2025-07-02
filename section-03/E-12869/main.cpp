/*
 * Problem: 12869
 * URL: https://www.acmicpc.net/problem/12869
 */

#include <array>
#include <iostream>
#include <queue>

using namespace std;

// in
int svcSize = 0;

// logic
typedef struct Svc {
  int a, b, c;
} Svc;

array<int, 3> inSVC;

constexpr int DAMAGES[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                               {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int visited[64][64][64];

void readSVC() {
  for (int svcIndex = 0; svcIndex < svcSize; ++svcIndex) {
    cin >> inSVC[svcIndex];
  }
}

int solve() {
  queue<Svc> bfsQueue;

  auto [a, b, c] = inSVC;
  visited[a][b][c] = 1;
  bfsQueue.push(Svc{a, b, c});

  while (!bfsQueue.empty()) {
    Svc current = bfsQueue.front();
    bfsQueue.pop();

    if (current.a == 0 && current.b == 0 && current.c == 0) {
      break;
    }

    for (auto [damageA, damageB, damageC] : DAMAGES) {

      Svc next;
      next.a = max(0, current.a - damageA);
      next.b = max(0, current.b - damageB);
      next.c = max(0, current.c - damageC);

      if (visited[next.a][next.b][next.c]) {
        continue;
      }

      visited[next.a][next.b][next.c] =
          visited[current.a][current.b][current.c] + 1;

      bfsQueue.push(next);
    }
  }
  return visited[0][0][0] - 1;
}

int main() {

  cin >> svcSize;

  readSVC();

  cout << solve();

  return 0;
}