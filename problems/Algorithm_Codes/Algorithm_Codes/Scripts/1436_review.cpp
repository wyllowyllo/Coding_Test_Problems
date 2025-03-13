#include <bits/stdc++.h>
using namespace std;

int n;
#pragma region MySol

//처음에 나는 숫자간의 규칙성을 발견하려 애쓰면서, 풀 방법을 찾고자 했음
//그러나 처음엔, 가능하다면 무식하게 풀 수 있는지 먼저 확인해봐야함
//이 문제의 경우 무식하게 풀 수 있는 문제임.



int cnt = 0;
string ret = "666";

void MySol() {
	cin >> n;


	for (int i = 666;; i++) {
		//int형을 string으로 변환하고, find로 문자열 666 찾기
		if (to_string(i).find("666") != string::npos) {
			//666이 포함되어 있다면
			cnt++;
			if (cnt == n) {
				cout << i << "\n";
				break;
			}
		}

	}

	return;
}

#pragma endregion




int main() {
	
	MySol();
}