#include <bits/stdc++.h>

using namespace std;

int first = 1;
char second = 'a';
string third = "가";
double fourth = 1.123123;

int main() {
  printf("1 : %d\n", first);
  printf("2 : %c\n", second);
  printf("3 : %s\n",
         third.c_str());  // string은 포인터 타입 char *로 변경 후 출력
  printf("4 : %lf\n", fourth);

  return 0;
}