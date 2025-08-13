#include <bits/stdc++.h>
using namespace std;

int t, n;

typedef long long ll;

ll dp[101];

ll go(int N) {
	if (N <= 3) return 1;

	ll& ret = dp[N];
	if (ret) return ret;

	return ret= go(N - 2) + go(N - 3);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		cout << go(n)<<"\n";

	}
}