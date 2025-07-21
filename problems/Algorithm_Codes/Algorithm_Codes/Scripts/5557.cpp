#include <bits/stdc++.h>
using namespace std;

namespace My {
	typedef long long ll;

	int n;
	ll dp[101][21]; //인덱스, 결과값
	int num[101];

	ll go(int idx, int ret) {
		if (idx == n - 1) {
			return ret == num[idx];
		}
		if (ret < 0 || ret>20) return 0;

		ll& cnt = dp[idx][ret]; //현재 인덱스에서 값 ret가 될 수 있는 수식의 개수
		if (cnt != -1)return cnt;

		cnt = 0;
		cnt += go(idx + 1, ret + num[idx]);
		cnt += go(idx + 1, ret - num[idx]);

		return cnt;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		fill(&dp[0][0], &dp[0][0] + 101 * 21, -1);


		//cout << go(1, num[0]) << "\n";



		//bottom up 방식으로 풀어보기//
		fill(&dp[0][0], &dp[0][0] + 101 * 21, 0);
		dp[0][num[0]] = 1;
		
		for (int i = 1; i <= n - 2; i++) {
			for (int ret = 0; ret <= 20; ret++) {
				ll ways = dp[i - 1][ret];
				if (ways == 0) continue;

				int plus = ret + num[i];
				if (plus >= 0 && plus <= 20)
					dp[i][plus] += ways;

				int minus = ret - num[i];
				if (minus >= 0 && minus <= 20)
					dp[i][minus] += ways;
			}
		}

		cout << dp[n - 2][num[n - 1]];
	}
}

namespace Sol {

	typedef long long ll;
	ll n, a[104], dp[104][21];

	ll go(int idx, int sum) {
		if (sum < 0 || sum>20) return 0;

		ll& ret = dp[idx][sum];
		if (ret) return ret;

		if (idx == n - 2) {
			if (sum == a[n - 1]) return 1;
			return 0;
		}

		ret += go(idx + 1, sum + a[idx + 1]);
		ret += go(idx + 1, sum - a[idx + 1]);
		return ret;
	}
	void sol() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << go(0, a[0]) << "\n";

	}
}


int main() {
	My::sol();
}