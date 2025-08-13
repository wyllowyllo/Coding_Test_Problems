#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll dp[104][10];
ll ret;

const int MOD = 1000000000;
ll go(int here,int num) {
	if (num < 0 || num>9) return 0;
	if (here == n-1) {

		return 1;
	}

	ll& ret = dp[here][num];
	if (ret) return ret;

	/*if (num > 0) ret += go(here + 1, num - 1)%MOD;
	if (num < 9) ret += go(here + 1, num + 1)%MOD;*/

	ret = max(ret, go(here + 1, num - 1)%MOD + go(here + 1, num + 1)%MOD);

	return ret%MOD;
}

int main() {
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		ret += go(0, i)%MOD;
	}

	cout << ret%MOD << "\n";
}