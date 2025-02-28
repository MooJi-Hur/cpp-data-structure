/*
 * Problem: 1436
 * URL: https://www.acmicpc.net/problem/1436
 */

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_ORDER = 10000;

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

int main() {

  int titleOrder = 0;
  cin >> titleOrder;

  vector<int> movieTitles;
  addMovieTitles(titleOrder, movieTitles);

  sort(movieTitles.begin(), movieTitles.end());

  int titleIndex = titleOrder - 1;
  cout << movieTitles[titleIndex];
  return 0;
}
