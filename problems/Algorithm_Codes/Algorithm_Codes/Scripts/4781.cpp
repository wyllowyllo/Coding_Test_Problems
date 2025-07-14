#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, c;
	double m, p;

	int dp[10001]; //가격을 인덱스로, 각 가격에서 구매할 수 있는 가장 높은 칼로리 저장

	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


		while (true) {
			cin >> n;
			cin >> m;

			int money = (int)round((m * 100));

			if (n == 0 && money == 0) break;

			memset(dp, 0, sizeof(dp));

			for (int i = 0; i < n; i++) {
				cin >> c;
				cin >> p;

				int cost = (int)round((p * 100));

				for (int j = cost; j <= money; j++) {
					dp[j] = max(dp[j], dp[j - cost] + c);
				}
			}

			cout << dp[money] << "\n";
		}
	}
}

namespace Sol {
	int cost, n, m1, m2, c;
	int dp[100004];

	void sol() {
		while (1) {
			scanf("%d %d.%d", &n, &m1, &m2);

			if (n == 0) break;

			int cost = m1 * 100 + m2;
			memset(dp, 0, sizeof(dp));

			for (int i = 0; i < n; i++) {
				scanf("%d %d.%d", &c, &m1, &m2);
				int p = m1 * 100 + m2;
				for (int j = p; j <= cost; j++) {
					dp[j] = max(dp[j], dp[j - p] + c);
				}
			}
			printf("%d\n", dp[cost]);
		}
	}
}

int main() {
	
	Sol::sol();
	
}