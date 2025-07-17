#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, m;
	int s, e;
	int dp[2001][2001];
	vector<int> v;

	int go(int s, int e) {
		if (s >= e) {

			return 1;
		}

		int& ret = dp[s][e];
		if (ret != -1) return ret;

		ret = go(s + 1, e - 1) && (v[s] == v[e]);
		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		memset(dp, -1, sizeof(dp));
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> s >> e;
			s--; e--;

			cout << go(s, e) << "\n";
		}
	}
}

namespace Sol {
	int n, a[2004], dp[2004][2004], t, from, to;

	void sol() {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		//길이가 1이면 펠린드롬
		for (int i = 1; i <= n; i++) {
			dp[i][i] = 1;
		}

		//길이가 2일떄, 처음과 끝 같으면 펠린드롬
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
		}

		for (int _size = 2; _size <= n; _size++) {
			for (int i = 1; i <= n - _size; i++) {
				//처음과 끝이 같고, 그 사이 부분이 펠린드롬이면, 펠린드롬
				if (a[i] == a[i + _size] && dp[i + 1][i + _size - 1])
					dp[i][i + _size] = 1;
			}
		}
		cin >> t;
		while (t--) {
			cin >> from >> to;
			cout << dp[from][to] << "\n";
		}
	}
}

int main() {
	

}