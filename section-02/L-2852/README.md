- 여러 개의 상황과 조건을 구현할 수 있는지 보는 문제. 
    1) 득점과 승자가 다를 수 있음
    2) 이전 상황의 값을 비교할 수 있어야 함
    -> 챗지피티는 isFirstGoal을 조건으로 넣지 않고, 이전 시간과 득점을 for문 밖으로 빼냄 
    ```c++
    void calcGoalInfos(const vector<pair<int, int>> &goalInfos,
                map<int, int> &sumGoals,
                map<int, int> &sumSeconds) {
    
        int previousTime = 0;
        int previousLeadingTeam = 0;
        
        for (int i = 0; i <= goalInfos.size(); ++i) {
            int currentTime = (i == goalInfos.size()) ? MAX_TIME : goalInfos[i].second;
            
            int firstTeamScore = sumGoals[FIRST_TEAM];
            int secondTeamScore = sumGoals[SECOND_TEAM];
            int currentLeadingTeam = (firstTeamScore > secondTeamScore) ? FIRST_TEAM : 
                                    (firstTeamScore < secondTeamScore) ? SECOND_TEAM : 0;
            
            if (previousLeadingTeam != 0 && previousLeadingTeam == currentLeadingTeam) {
                sumSeconds[previousLeadingTeam] += (currentTime - previousTime);
            }
            
            if (i < goalInfos.size()) {
                sumGoals[goalInfos[i].first]++;
            }
            
            previousTime = currentTime;
            previousLeadingTeam = currentLeadingTeam;
        }
    }
    ```

- 스트링 패딩 처리
    - ss 참고
    ```c++
    string formatTime(int totalSeconds) {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;
        stringstream ss;
        ss << setw(2) << setfill('0') << minutes << ":" 
        << setw(2) << setfill('0') << seconds;
        return ss.str();
    }
    ```