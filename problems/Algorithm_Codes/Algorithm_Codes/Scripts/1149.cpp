#include <bits/stdc++.h>
using namespace std;

namespace MySol {

	/*
	 “인접한 집끼리 색이 다르다” 제약만 있으니, here번째 집의 최소비용을 결정할 때 바로 직전 집의 색만 알면 충분합니다.
	 더 이전의 색 선택들은 “here-1번째 집을 특정 색으로 칠했을 때의 최소비용”에 이미 압축돼 있죠(최적 부분 구조 + 무기억성).

	 시그니처를 “이전색” 기준 대신 “현재색” 기준으로 바꿔도 됩니다.
	 본질은 동일하지만, 직관은 현재색이 더 좋다는 사람이 많습니다
	*/
	int n;
	int cost[1004][3];


	int dp[1004][3];
	const int MAX = 1e9;

	int paint(int here, int prevColor) {
		if (here == n) {

			return 0;
		}

		int& ret = dp[here][prevColor];
		if (ret != MAX) return ret;

		for (int i = 0; i < 3; i++) {
			if (prevColor == i) continue;

			ret = min(ret, paint(here + 1, i) + cost[here][i]);
		}

		return ret;
	}

	//top-down 풀이
	void sol_1() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}
		fill(&dp[0][0], &dp[0][0] + 1004 * 3, MAX);

		int ret = MAX;
		for (int i = 0; i < 3; i++) {
			ret = min(ret, paint(1, i) + cost[0][i]);
		}

		cout << ret << "\n";
	}

	//bottom-up 풀이
	//상태값을 현재 인덱스와 현재 인덱스에 칠할 컬러 로 정함
	void sol_2() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}
		fill(&dp[0][0], &dp[0][0] + 1004 * 3, MAX);

		dp[0][0] = cost[0][0];
		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][2];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k == j) continue;
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);
				}
			}
		}

		cout << min({ dp[n - 1][0],dp[n - 1][1] ,dp[n - 1][2] })<<"\n";

	}
}

namespace Sol {
	


	void sol() {
		int n;
		cin >> n;
		vector<vector<int>> cost(n, vector<int>(3));
		for (int i = 0; i < n; ++i) {
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}

		// dp[i][c] = i번째 집을 색 c로 칠했을 때, 0..i까지의 최소비용
		vector<vector<int>> dp(n, vector<int>(3));
		dp[0][0] = cost[0][0];
		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][2];

		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << "\n";
	}

	//롤링 배열로 메모리 최적화
	void sol_2() {
		int n; cin >> n;
		int r, g, b;
		int pr, pg, pb; // 이전 집까지의 최소비용(마지막 색이 R/G/B)
		cin >> r >> g >> b;
		pr = r; pg = g; pb = b;

		for (int i = 1; i < n; ++i) {
			cin >> r >> g >> b;
			int nr = min(pg, pb) + r;
			int ng = min(pr, pb) + g;
			int nb = min(pr, pg) + b;
			pr = nr; pg = ng; pb = nb;
		}
		cout << min({ pr, pg, pb }) << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	MySol::sol_2();

}