#include <bits/stdc++.h>

using namespace std;

//------------------------------My Solution-------------------------------------
//우선 문제조건과 예상범위를 생각해서, 무식하게 풀 수 있을 것 같으면 무식하게 풀어보기!
//(값 범위가 대략 1000만 이하라면 무식하게 풀 수 있는 경우인 경우가 많다)
// 이 문제의 주요사항 : 어떤 문제든 일단 bruteforce로 풀어보기!!
int n;
int cnt = 0;
string title = "666";

int main() {
	cin >> n;

	while (cnt < n) {
		if (title.find("666")!=title.npos) cnt++;
		if (cnt == n) break;
		title = to_string(stoll(title) + 1);
	}

	cout << title << "\n";
}

//------------------------------------------------------------------------------