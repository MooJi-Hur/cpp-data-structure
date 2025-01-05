#ifndef ONLINE_JUDGE
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

#endif

/** === Timing ===
Insert the following timer functions
at the beginning and end of the code block.
auto start = startTimer();
stopTimer(start);
*/

high_resolution_clock::time_point startTimer() {
#ifndef ONLINE_JUDGE
  return high_resolution_clock::now();  // 로컬 환경: 시간 측정 활성화
#else
  return high_resolution_clock::time_point();  // 온라인 저지: 더미 반환
#endif
}

void stopTimer(const high_resolution_clock::time_point &start) {
#ifndef ONLINE_JUDGE
  auto end = high_resolution_clock::now();
  clog << "Time: " << duration_cast<milliseconds>(end - start).count() << "ms"
       << endl;
#endif
}