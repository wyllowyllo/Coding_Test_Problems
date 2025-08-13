#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int dp[21][21][21];

const int INF = 1e9;

int W(int _a, int _b, int _c) {
	if (_a <= 0 || _b <= 0 || _c <= 0) return 1;
	if (_a > 20 || _b > 20 || _c > 20) return W(20, 20, 20);

	int& ret = dp[_a][_b][_c];
	if (ret != INF) return ret;

	if (_a < _b && _b < _c)
		return ret=W(_a, _b, _c - 1) + W(_a, _b - 1, _c - 1) - W(_a, _b - 1, _c);

	
	return ret=W(_a-1, _b, _c) + W(_a-1, _b - 1, _c) + W(_a-1, _b, _c-1)-W(_a - 1, _b-1, _c - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	fill(&dp[0][0][0], &dp[0][0][0] + 21 * 21 * 21, INF);
	while (true) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}



}