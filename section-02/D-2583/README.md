### 지역별 넓이 구하기
- bfs로 탐색하여 열린 공간 확인
- 완전 탐색으로 새 출발지를 찾음

### 문제 풀 때 유의할 점
- 출력 시 조건 확인 -> 오름차순 정렬

```c++
#include <algorithm>

sort(openAreas.begin(), openAreas.end());
```