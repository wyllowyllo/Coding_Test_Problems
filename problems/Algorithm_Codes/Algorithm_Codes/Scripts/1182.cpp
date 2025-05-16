#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, s;
//ll cnt[30];
int ret = 0;
ll a[30];

//int t;

void go(int idx,int sum) {
	if (idx == n) {
		if (sum == s) ret++;
		return;
	}

	go(idx + 1, sum); //포함하지 않음
	go(idx + 1, sum+a[idx]);//포함
}
int main() {

	cin >> n >> s;

	//첫번째 시도 방법 : 실패 -> 부분수열이래서 연속되는 부분만을 고르는 건줄 알았는데 비연속적인 경우도 고려해서 수열만드는거인듯
	/*for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j <=i; j++) {
			cnt[j] += t;
			if (cnt[j] == s) ret++;
		}
	}

	cout << ret << '\n';*/

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	/* 1. 비트마스킹으로 구현
	//모든 조합에 대해 검사하기
	for (int i = 1; i < (1<<n); i++) {
		ll sum = 0;
		for (int j = 0; j <n; j++) {
			if (i & (1<<j)) sum += a[j];
		}
		if (sum == s) ret++;
	}

	*/

	//2. dfs로 구현
	go(0, 0);
	if (s == 0) ret--;

	cout << ret << '\n';

}