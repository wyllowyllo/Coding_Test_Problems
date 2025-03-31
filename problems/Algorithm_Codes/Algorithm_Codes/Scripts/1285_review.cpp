#include <bits/stdc++.h>
using namespace std;

int n;
string s;


int a[45];
int ret = 500;

void go(int idx) {
	if (idx == n+1) {
		
		int sum = 0;

		for (int i = 1; i <= (1<<n-1); i *= 2) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] & i) cnt++;
			}

			sum += min(cnt, n - cnt);

		}

		ret = min(ret, sum);
		return;
	}

	go(idx + 1);
	a[idx+1] = ~a[idx+1];
	go(idx + 1);

}
int main() {
	cin >> n;

	for (int i = 1; i <=n; i++) {
		cin >> s;
		int value = 1;


		//입력 문자열을 숫자 하나로 표시
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') a[i] |= value;
			value *= 2;
		}
	}

	go(0);

	cout << ret << "\n";
}