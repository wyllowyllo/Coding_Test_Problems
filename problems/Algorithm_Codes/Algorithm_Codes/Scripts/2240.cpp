#include <bits/stdc++.h>
using namespace std;


namespace My {
	int t, w;

	int dp[1001][31][3]; //(시간,이동횟수,위치) 일 때 받을 수 있는 자두 최대개수

	int v[1001];



	int go(int t, int move, int idx) {
		if (t <= 0) return 0;

		int& ret = dp[t][move][idx];
		if (ret != -1) return ret;


		int cnt = 0;
		if (v[t] == idx) cnt++;

		if (move) {
			cnt += max(go(t - 1, move, idx), go(t - 1, move - 1, (idx == 1) ? 2 : 1));

		}
		else {
			cnt += go(t - 1, move, idx);
		}

		return ret = max(ret, cnt);
	}

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> t >> w;


		for (int i = 1; i <= t; i++) {
			cin >> v[i];
		}
		memset(dp, -1, sizeof(dp));

		cout << max(go(t, w, 1), go(t, w - 1, 2)) << "\n";
	}
}


namespace Sol {
	int dp[1004][2][34], n, m, b[1004];

	int go(int idx, int tree, int cnt) {
		if (cnt < 0) return -1e9; //이동횟수 cnt가 음수가 되는 경우는 있어선 안되는 일이므로, 절대 답이 될 수 없게 -1e9반환
		if (idx == n) return 0;

		int& ret = dp[idx][tree][cnt];
		if (~ret) return ret;

		return ret = max(go(idx + 1, tree, cnt), go(idx + 1, 1 ^ tree, cnt - 1)) + (tree == b[idx] - 1);
	}

	void sol() {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;

		for (int i = 0; i < n; i++) cin >> b[i];

		cout << max(go(0, 1, m - 1), go(0, 0, m)) << "\n";
	}
}
int main() {

	
	Sol::sol();

}

