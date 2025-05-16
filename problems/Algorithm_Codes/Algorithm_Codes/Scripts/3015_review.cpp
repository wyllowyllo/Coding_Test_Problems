#include <bits/stdc++.h>
using namespace std;

int n;
int h[500001];




typedef long long ll;
stack<pair<int, ll>> stk;
ll ret;
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	
	for (int i = 0; i < n; i++) {
		int cnt = 1;

		while (stk.size() && h[stk.top().first] <=h[i]) {
			ret+= stk.top().second;

			if (h[stk.top().first] == h[i]) { //같은 키끼리 그룹 크기를 누적
				cnt= stk.top().second+1; //이전 그룹의 크기 + 나 자신
			}
			else {
				cnt = 1; //다른 키면 새 그룹(1명)으로 시작
			}

			stk.pop();
		}

		if (stk.size()) ret++;
		stk.push({ i,cnt });
	}

	cout << ret << "\n";
}

