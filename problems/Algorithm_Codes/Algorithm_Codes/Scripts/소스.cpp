#include <bits/stdc++.h>
using namespace std;


int n;
int a[21];

string s;
const int MX = 987654321;
int ret = MX;

void go(int here) {

	int result = 0;
	if (here == n) {

		for (int j = 1; j <= (1 << n-1); j *= 2) { //열 검사
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (a[k] & j) cnt++;
			}

			result += min(cnt, n - cnt);
		}

		ret = min(ret, result);
		return;
	}

	go(here + 1);
	a[here] = ~a[here];
	go(here + 1);
}

int main() {
	cin >> n;

	for (int i = 0; i <n; i++) {
		cin >> s;

		int value = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'H') a[i] |= value;
			value *= 2;
		}
	}

	go(-1);

	cout << ret << '\n';


}