## 정규 표현식
### 특수 기호 사용법
- `*`, `n` 등 정규 표현식에서 활용되는 문자를 사용하기 위해서는 백슬래시 `\`를 두 번 붙임
```c++
string affix_pattern_text = "[\\*]";
```

### 문자, 숫자 관련 정규 표현식
- 범위, 포함 여부
    - `*` : 포함하지 않거나, 하나 이상의 수
    - `+` : 한 개 이상

- 문자 집합과 패턴
    - `[^a-zA-Z]`: 대괄호에서 `^`로 시작할 경우 부정을 의미. 알파벳 소문자와 대문자가 포함되지 않은 문자열
    - `[aeiou]` : 모음이 하나 이상 포함된 문자열, `[]`는 문자 집합에서 하나의 문자만 선택
    - `(ab)+`: 그룹을 정의, 괄호 안의 문자를 묶어서 취급. `ab`가 하나 이상 포함된 문자열
        

- 반복 `{}`
    - `\\d{4}` : 네 자리 숫자, 숫자 하나만 있을 때는 정확한 반복 수를 의미
        - `(\\d{4}-\\d{4}-\\d{4})` : `YYYY-MM-DD`
    - `a{1, 3}`: `{n, m}`은 최소 `n`회 ~ 최대 `m`회
    - `a{0, 3}` : `a`가 최대 세 번 반복된 경우 
    - `a{3,}`: 최소 `n`번 반복

- 매칭
    - 숫자 : `\\d`
        - `\\d+`: 한 개 이상의 숫자
    - 공백 : `\\s`, 공백 아닌 곳에서 매칭 : `\\S`
        - 공백, 탭, 개행 포함
        - `[^\\s]+` : 공백이 아닌 문자 하나 이상을 연속적으로 찾음
        - 공백을 만나면 단어 단위로 맵핑
    - 단어 경계 : `\\b`, 단어 경계가 아닌 곳에서 매칭 : `\\B`

- 문자열의 시작과 끝
    - `^abc` : abc로 시작하는 문자열
    - `abc$`: abc로 끝나는 문자열
    - `^abc$`: 정확히 `abc`인 문자열, `abcabc`는 해당되지 않음
    - `^ab[a-z]*c`: `ab`로 시작하고, `c`로 끝나는 소문자로 이루어진 문자열
    - `^ab[a-z]+c`: `ab`로 시작하고, `c`로 끝나며 하나 이상의 소문자가 중간에 들어간 문자열


- [정규 표현식 설명](https://en.cppreference.com/w/cpp/regex/basic_regex/basic_regex)