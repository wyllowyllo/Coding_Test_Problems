#include <bits/stdc++.h>
using namespace std;

namespace My {

	//길이 n을 만드는 방법의 수를 구할때,
	//마지막에 1을 붙이는 경우의 수는 -> go(n-1)이 전이됨
	//마지막에 00을 붙이는 경우의 수는 -> go(n-2)이 전이됨
	//따라서 점화식은 go(n)= go(n-1)+go(n-2)
	int n;
	typedef long long ll;

	ll dp[1000001];

	ll go(int idx) {
		if (idx == 1 || idx == 2) return idx;

		ll& ret = dp[idx];
		if (ret) return ret;

		return ret = (go(idx - 1) % 15746 + go(idx - 2) % 15746) % 15746; //현재 idx에 1을 넣는 경우의 수와 00을 넣는 경우의 수 합
	}
	void sol() {
		cin >> n;
		cout << go(n) << "\n";
	}
}

namespace Sol {
	const int MOD = 15746;
	void sol() {
		int n;
		cin >> n;

		vector<int> dp(n + 2);

		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		}

		cout << dp[n] << "\n";
	}
}

int main() {

}