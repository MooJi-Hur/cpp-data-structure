# 2309

## 상수
```c++
constexpr int SIZE_CANDIDATE = 9;
constexpr int SIZE_MY_FRIEND = 7;
constexpr int THRESHOLD = 100;
```

- constexpr 
	- 컴파일 타임 상수 
	- 컴파일 시간에 값을 결정
	- C++11 이후 지원되는 키워드

## 주요 함수
### `getInput()`
```c++
array<int, SIZE_CANDIDATE> getInput()
{
	array<int, SIZE_CANDIDATE> elements;

	for (int i = 0; i < elements.size(); ++i)
	{
		cin >> elements[i];
	}

	return elements;
}
```

- 입력 배열은 아홉 명으로 고정되어 있어 array를 사용
- array는 vector와 달리 미리 크기를 결정
- index를 기반으로 ([] operator) 값을 할당 
- 여러 값을 동시에 입력할 경우, `fill`을 사용

### `getOutput()``
```c++
void printOutput(const vector<int> &elements)
{
	for (const int element : elements)
	{
		cout << element << '\n';
	}
}
```

- `const` 넘겨받은 값의 수정 방지
- `&elements`참조에 의한 복사

### 재귀로 구현한 조합
```c++
void combine(const array<int, SIZE_CANDIDATE> &allElements, vector<int> subComb, int startIndex, int remaining)
{

	// 기저 조건
	if (remaining == 0)
	{
		// 조합의 합 계산
		int sum = accumulate(subComb.begin(), subComb.end(), 0);

		// 조합의 합이 100이면 종료
		if (THRESHOLD == sum)
		{
			printOutput(subComb);
			exit(0);
		}

		return;
	}

	// 백트랙킹
	for (int i = startIndex; i < allElements.size(); ++i)
	{
		// 부분 조합에 시작 원소 삽입
		subComb.push_back(allElements[i]);

		// 재귀
		combine(allElements, subComb, i + 1, remaining - 1);

		// 부분 조합 복원
		subComb.pop_back();
	}
}
```

- 재귀와 표현만 일단 공부
- 직접 디버깅 해보기



---

### Set 마지막 두 개의 요소 제거
```c++
// set<int>& 매개 변수를 참조자로 사용하여 원본을 직접 수정
void removeLastTwo(set<int> &elements)
{
	if (elements.size() < 2)
		return;

	// prev는 새로운 반복자를 생성, 읽기 전용으로 만듦
	// advance는 원본 반복자를 수정
	auto secondToLast = prev(elements.end(), 2);

	elements.erase(secondToLast, elements.end());
}
```