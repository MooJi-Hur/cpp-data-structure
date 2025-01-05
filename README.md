# cpp-data-structure
- CMake 빌드를 이용한 IO 파일 관리

### sh 파일 권한 부여
```bash
chmod +x setup-vscode.sh \
    && chmod +x setup-problems.sh \
    && chmod +x setup-chapter.sh
```

### 단원 폴더 만들기
- `setup-chapter` 파일 실행
- 섹션, 단원 이름 입력
- 폴더 내 `main.cpp`, `input.txt`, `output.txt` 생성 확인

- 예
```bash
./setup-chapter.sh section-00 02-01-main-basic
```

- 오류가 생길 경우, sh 파일 권한 확인