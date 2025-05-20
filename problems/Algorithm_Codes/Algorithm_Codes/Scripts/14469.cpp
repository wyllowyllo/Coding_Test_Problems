#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int n;
int a, t;
vector<pair<int, int>> v;

ll ret;

#pragma region MySol

//FIFO로 처리하기

void MySol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> t;
		v.push_back({ a,t });
	}

	sort(v.begin(), v.end());

	for (auto& i : v) {
		if (ret <= i.first) {
			ret = i.first + i.second;
		}
		else {
			ret += i.second;
		}
	}

	cout << ret << "\n";
}

#pragma endregion


#pragma region Sol_1

//라인스위핑 문제
//1번 소의 검사 끝난 시간< 2번 소의 도착시간 이면 realTime을 2번 소 도착시간으로 update
//1번 소의 검사 끝난 시간> 2번 소의 도착시간 이면 realTime을 1번 소 검사 끝 시간+2번 소 검사 끝 시간 으로 update

void Sol_1() {
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	int realtime = a[0].first + a[0].second;
	for (int i = 1; i < a.size(); i++) {
		realtime = max(realtime, a[i].first);
		realtime += a[i].second;
	}

	cout << realtime << "\n";
}


#pragma endregion


 
int main() {
	

}