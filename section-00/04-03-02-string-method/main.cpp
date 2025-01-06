#include <bits/stdc++.h>

using namespace std;

int main() {
  string init = "love is";
  init += " pain!";  // init = init + "d";은 재할당으로 시간이 걸림
                     // push_back()은 한 문자씩 넣을 수 있음
  init.pop_back();   // 마지막 문자 제거 O(1)의 시간복잡도

  cout << init << " : " << init.size() << endl;

  cout << char(*init.begin())
       << endl;  // 문자열이 첫 요소를 가리키는 이터레이터 begin()
  cout << char(*(init.end() - 1)) << endl;  // end() 문자열의 마지막 요소 다음

  // string& insert (size_t pos, const string& str);
  init.insert(0, "test ");  // O(N)의 시간복잡도

  cout << init << " : " << init.size() << endl;  // size O(1)의 시간복잡도

  // string& erase (size_t pos = 0, size_t len = npos);
  init.erase(0, 5);  // O(N)의 시간복잡도

  cout << init << " : " << init.size() << endl;

  // size_t find (const string& str, size_t pos = 0);

  auto it = init.find("love");

  if (it != string::npos) {  // size_t 타입의 최댓값, 부호가 없는 최대 정수값
                             // O(N) ~ O(N*M)
    cout << "포함되어 있다." << endl;
  }

  cout << it << endl;
  cout << string::npos << endl;

  // string substr (size_t pos = 0, size_t len = npos) const;
  cout << init.substr(5, 2) << endl;  // O(N) substr(크기, 위치), substr(위치)

  return 0;
}