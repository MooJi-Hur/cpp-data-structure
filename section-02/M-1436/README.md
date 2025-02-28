- 정규표현식으로 푼 경우 시간 초과 발생
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