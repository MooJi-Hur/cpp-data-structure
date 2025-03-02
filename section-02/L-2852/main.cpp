/*
 * Problem: 2852
 * URL: https://www.acmicpc.net/problem/2852
 */

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

constexpr int FIRST_TEAM = 1;
constexpr int SECOND_TEAM = 2;

constexpr int MIN_TIME = 0;
constexpr int MAX_TIME = 48 * 60;

void readGoalInfos(int goalCount, vector<pair<int, int>> &goalInfos) {

  for (int goalIndex = 0; goalIndex < goalCount; ++goalIndex) {
    int teamOrder;
    string goalTime;
    cin >> teamOrder >> goalTime;

    int minutes = stoi(goalTime.substr(0, 2));
    int seconds = stoi(goalTime.substr(goalTime.size() - 2, 2));
    int totalSeconds = minutes * 60 + seconds;

    goalInfos.push_back({teamOrder, totalSeconds});
  }
}

void calcGoalInfos(vector<pair<int, int>> &goalInfos,
                   map<int, int> &sumGoals,
                   map<int, int> &sumSeconds) {

  int recordTime = goalInfos.size() + 1;
  for (int goalIndex = 0; goalIndex < recordTime; ++goalIndex) {

    bool isFirstGoal = (goalIndex == 0);
    bool isFinalTime = (goalIndex == goalInfos.size());

    bool isWinning = sumGoals[SECOND_TEAM] != sumGoals[FIRST_TEAM];
    bool canSumSeconds = !isFirstGoal && isWinning;

    if (canSumSeconds) {

      bool isFirstTeamWin = sumGoals[FIRST_TEAM] > sumGoals[SECOND_TEAM];

      int currentTime = isFinalTime ? MAX_TIME : goalInfos[goalIndex].second;
      int prevTime = goalInfos[goalIndex - 1].second;
      int timeGap = currentTime - prevTime;

      sumSeconds[isFirstTeamWin ? FIRST_TEAM : SECOND_TEAM] += timeGap;
    }

    bool hasGoal = !isFinalTime;
    if (hasGoal) {
      int goalTeam = goalInfos[goalIndex].first;
      sumGoals[goalTeam]++;
    }
  }
}

void printWinnerTimes(map<int, int> &sumSeconds) {
  int firstTeamMinutes = sumSeconds[FIRST_TEAM] / 60;
  int firstTeamSeconds = sumSeconds[FIRST_TEAM] % 60;

  int secondTeamMinutes = sumSeconds[SECOND_TEAM] / 60;
  int secondTeamSeconds = sumSeconds[SECOND_TEAM] % 60;

  cout << setw(2) << setfill('0') << firstTeamMinutes;
  cout << ':';
  cout << setw(2) << setfill('0') << firstTeamSeconds;
  cout << '\n';
  cout << setw(2) << setfill('0') << secondTeamMinutes;
  cout << ':';
  cout << setw(2) << setfill('0') << secondTeamSeconds;
}

int main() {

  int goalCount = 0;
  cin >> goalCount;

  vector<pair<int, int>> goalInfos;
  readGoalInfos(goalCount, goalInfos);

  map<int, int> sumGoals;
  map<int, int> sumSeconds;
  calcGoalInfos(goalInfos, sumGoals, sumSeconds);

  printWinnerTimes(sumSeconds);

  return 0;
}