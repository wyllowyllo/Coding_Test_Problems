#include <bits/stdc++.h>
using namespace std;

int t, n;
map<string, int> m1;

string item;
string category;
int ret;

#pragma region MySol
//처음 문제를 봤을 때, n개중 r개를 선택하는 조합을 모두 구한 다음 해답을 구하는 방식으로 했었음
//모든 조합을 다 구하다 보니 시간 내 완료 x
//문제에서 요구하는 것은 조합을 구하는 것이 아니라, 단지 코디의 경우의 수를 구하는 것이므로 조합을 구하면 안됨
//키포인트 : 조합을 구하는 것이 아니라, 경우의 수를 구하는 것이다!
void MySol() {
	cin >> t;
	while (t--) {
		cin >> n;
		ret = 1;
		m1.clear();

		for (int i = 0; i < n; i++) {
			cin >> item >> category;
			m1[category]++;
		}

		for (auto v : m1) {
			ret *= (v.second + 1);
		}
		ret -= 1;

		cout << ret << "\n";
	}
}
#pragma endregion

#pragma region Sol_1
void Sol_1() {
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			m1[b]++;
		}

		long long ret = 1; //경우의 수는 그 크기가 매우 커질 수 있으므로, 경우의 수 문제는 그냥 long long으로 박아버리기!
		for (auto c : m1) {
			ret *= (long long)(c.second + 1);
		}

		ret--;
		cout << ret << "\n";
	}
	
}
#pragma endregion



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
}