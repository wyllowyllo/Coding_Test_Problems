#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, k;
	int tmp;

	typedef long long ll;
	ll dp[10001];

	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

		cin >> n >> k;


		dp[0] = 1; //0원을 만드는 경우의 수는 1가지
		for (int i = 0; i < n; i++) {
			cin >> tmp;

			for (int j = tmp; j <= k; j++) {
				dp[j] += dp[j - tmp];
			}
		}

		cout << dp[k] << "\n";
	}
}

namespace Sol {
	int dp[10001];
	int n, k, temp;

	void sol() {

		scanf("%d %d", &n, &k);
		dp[0] = 1;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);

			if (temp >= 10001) continue;
			for (int j = temp; j <= k; j++) {
				dp[j] += dp[j - temp]; //j가 되는 경우의 수는, j 이전 값들의 경우의 수의 합
			}
		}

		printf("%d\n", dp[k]);
	}
}

int main() {
	
}