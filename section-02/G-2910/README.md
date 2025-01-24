### `sort`
- 구조체에서 연산자를 오버로딩 한 것은 벡터 자료구조를 해당 구조체로만 사용했을 때 가능
- `vector<int,Order>`에서는 sort에 사용자가 정의한 함수를 넣어야 함
    - return 값은 `bool` 타입
    - destructing은 C++17부터 지원함
        - ` auto [keyA, orderA] = a;`
    - 선순위 조건을 if문에 넣음

### `unordered_map`
-  `map`은 key 기준으로 정렬, 탐색/삽입 속도 O(logN)
- `unordered_map`은 탐색/삽입 속도 O(1)
- 다만, 정렬이 필요할 경우 별도의 처리가 필요하여 vector로 변환하여 사용
    - `vector<int,Order> frequencyVector(frequencyMap.begin(), frequencyMap.end());`
- key가 있는지 찾을 때에는 `find`와 `end`를 활용
    ```c++
            auto hasKey = frequencyMap.find(messageKey);

        if (hasKey != frequencyMap.end())
    ```

