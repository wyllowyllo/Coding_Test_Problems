#include <bits/stdc++.h>
#define MAX_N 100001 
using namespace std;


namespace My {
	//dp 배열 초기화 시 0이 “미방문”이자 “정답이 0”을 동시에 의미하니, 경우에 따라 -1로 초기화하고 “ret != -1이면 메모된 값 반환” 패턴을 쓰면 더 명확합니다.

	vector<int> v;
	int input;

	int dp[100001][5][5];

	int energy(int prevPos, int newPos) {
		if (prevPos == 0) return 2;
		if (prevPos == newPos) return 1;
		if (abs(prevPos - newPos) % 2 == 1) return 3;
		if (abs(prevPos - newPos) == 2) return 4;
	}
	int go(int idx, int lf, int rf) {
		if (idx == v.size()) {

			return 0;
		}


		int& ret = dp[idx][lf][rf];
		if (ret) return ret;

		int pos = v[idx];
		ret = min(go(idx + 1, pos, rf) + energy(lf, pos), go(idx + 1, lf, pos) + energy(rf, pos));

		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		while (true) {
			cin >> input;
			if (input == 0) break;

			v.push_back(input);
		}

		cout << go(0, 0, 0) << "\n";
	}

	const int INF = 1e9;
	int dp2[2][5][5];

	void sol2() {

		
		
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		while (true) {
			cin >> input;
			if (input == 0) break;

			v.push_back(input);
		}

		int n = v.size() - 1;
		// 1) 기저: i == n 일 때 모든 상태는 0
		for (int lf = 0; lf < 5; lf++)
			for (int rf = 0; rf < 5; rf++)
				dp2[n % 2][lf][rf] = 0;

		for (int i = n - 1; i >= 0; i--) {
			int cur = i % 2;
			int next = (i + 1) % 2;
			int pos = v[i];

			for (int lf = 0; lf < 5; lf++) {
				for (int rf = 0; rf < 5; rf++) {
					int best = INF;

					if (pos != rf)
						best = min(best, dp2[next][pos][rf] + energy(lf, pos));
					if (pos != lf)
						best = min(best, dp[next][lf][pos] + energy(rf, pos));
					dp[cur][lf][rf] = best;
				}
			}
		}

		cout << dp[0][0][0] << "\n";
	}

}

namespace Sol {
	int dp[5][5][MAX_N], n;
	vector<int> v;
	int check(int from, int to) {
		if (from == 0) return 2;
		if (from == to) return 1;
		if (abs(from - to) == 2) return 4;
		
		return 3;
	}
	int solve(int y, int x, int target) {
		if (target == n) return 0;
		if (dp[y][x][target] != -1) return dp[y][x][target];

		int left = solve(v[target], x, target + 1) + check(y, v[target]);
		int right = solve(y, v[target], target + 1) + check(x, v[target]);

		return dp[y][x][target] = min(left, right);

	}

	void sol() {
		while (true) {
			int num;
			cin >> num;

			if (num == 0) break;
			v.push_back(num);
		}

		memset(dp, -1, sizeof(dp));
		n = v.size();
		cout << solve(0, 0, 0) << '\n';
	}
}


int main() {
	
}