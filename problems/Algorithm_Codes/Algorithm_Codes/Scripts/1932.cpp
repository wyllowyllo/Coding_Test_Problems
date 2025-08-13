#include <bits/stdc++.h>
using namespace std;

int n;
int a[504][504];

int dp[504][504];

int go(int depth, int idx) {
	if (depth == n) {

		return 0;
	}

	int& ret = dp[depth][idx];
	if (ret!=-1) return ret;

	return ret = max(go(depth + 1, idx), go(depth + 1, idx+1))+a[depth][idx];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <=i; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";
}