- 정규 표현식으로 푼 경우 시간 초과 발생
    ```c++
    void addMovieTitles(int titleOrder, vector<int> &movieTitles) {

      int movieIndex = 0;
      while (movieTitles.size() < titleOrder) {

        string movieTitle = to_string(movieIndex);

        regex title_regex("6{3,}");
        if (regex_search(movieTitle, title_regex)) {
          movieTitles.push_back(movieIndex);
        }
        ++movieIndex;
      }
    }
    ```
    - 반면 to_string(num).find는 문자열을 한 번만 탐색하여 더 빠르게 찾아냄
    - 666이 포함된 숫자를 먼저 모으는 방법으로 접근할 수 있음

- BFS
  - 재귀로 풀 수 있는 것은 BFS로도 풀 수 있음
  - 재귀는 함수 호출을 이용하고, BFS는 명시적인 스택을 사용
  - 10^6 이상으로 깊어질 경우, 스택 오버 플로우의 위험이 있으므로 BFS를 사용
  - dfs stack을 구조체로 만들면 visited를 따로 만들지 않아도 됨

- String and Char
  - '-1'은 Char가 아님

- Set 
  - set에서 요소를 탐색할 때는 advance를 사용함
