/*
 * Problem: 1436
 * URL: https://www.acmicpc.net/problem/1436
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_ORDER = 10000;
constexpr int SIX_PLACEHOLDER = -1;
constexpr int MAX_DIGIT_PLACE = 5;

typedef struct State {
  int index;
  vector<int> path;
} State;

void fillRemainChars(int digitSize, vector<vector<int>> &titleCandidates) {
  vector<int> titleLetters(10);
  iota(titleLetters.begin(), titleLetters.end(), 0);

  stack<State> dfsStack;
  dfsStack.push({0, {}});

  while (!dfsStack.empty()) {
    State currentState = dfsStack.top();
    dfsStack.pop();

    if (currentState.path.size() == digitSize) {
      titleCandidates.push_back(currentState.path);
      continue;
    }

    for (size_t numberIndex = 0; numberIndex < titleLetters.size();
         ++numberIndex) {
      State nextState = currentState;
      nextState.index = numberIndex + 1;
      nextState.path.push_back(titleLetters[numberIndex]);
      dfsStack.push(nextState);
    }
  }
}

void addFixedLetter(vector<vector<int>> &titleCandidates,
                    set<int> &movieTitles) {
  for (vector<int> &titleCandidate : titleCandidates) {
    string remainTitle;
    for (int &titleLetter : titleCandidate) {
      remainTitle += to_string(titleLetter);
    }
    for (size_t letterIndex = 0; letterIndex < titleCandidate.size() + 1;
         ++letterIndex) {
      string fullTitle = remainTitle;

      fullTitle.insert(letterIndex, "666");

      int movieTitle = stoi(fullTitle);
      movieTitles.insert(movieTitle);
    }
  }
}

void addMovieTitles(int titleOrder, set<int> &movieTitles) {
  vector<vector<int>> titleCandidates;

  for (int digitSize = 1; digitSize < MAX_DIGIT_PLACE; ++digitSize) {
    fillRemainChars(digitSize, titleCandidates);
  }

  addFixedLetter(titleCandidates, movieTitles);
}

void printMovieTitle(int titleOrder, set<int> &movieTitles) {
  auto titleItor = movieTitles.begin();
  int movieTitleIndex = titleOrder - 1;
  advance(titleItor, movieTitleIndex);
  cout << *titleItor;
}

int main() {

  int titleOrder = 0;
  cin >> titleOrder;

  set<int> movieTitles;
  addMovieTitles(titleOrder, movieTitles);

  printMovieTitle(titleOrder, movieTitles);

  return 0;
}
