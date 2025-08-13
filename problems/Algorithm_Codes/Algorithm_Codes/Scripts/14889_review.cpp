#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n;

	int m[21][21];

	int ret = 1e9;

	int visited[21];

	int getSum(vector<int> v) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < i; j++) {
				sum += m[v[i]][v[j]] + m[v[j]][v[i]];
			}
		}

		return sum;
	}
	void go(int idx, int s) {
		if (s == n / 2) {

			vector<int> A, B;

			for (int i = 0; i < n; i++) {
				if (visited[i]) A.push_back(i);
				else B.push_back(i);
			}

			int a = getSum(A);
			int b = getSum(B);

			ret = min(ret, abs(a - b));

			return;
		}

		for (int i = idx + 1; i < n; i++) {
			visited[i] = 1;
			go(i, s + 1);
			visited[i] = 0;
		}
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
			}
		}

		go(-1, 0);

		cout << ret << "\n";

	}
}

namespace Sol {
	const int INF = 987654321;
	int s[24][24], ret = INF, n;

	int go(vector<int>& a, vector<int>& b) {
		pair<int, int> ret;

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;

				ret.first += s[a[i]][b[j]];
				ret.second += s[a[i]][b[j]];
			}
		}

		return abs(ret.first - ret.second);
	}

	void sol() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}

		for (int i = 0; i < (1 << n); i++) {
			if (__builtin_popcount(i) != n / 2) continue;

			vector<int> start, link;

			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) start.push_back(j);
				else link.push_back(j);
			}

			ret = min(ret, go(start, link));
		}

		cout << ret << '\n';
	}
}

int main() {
	
}