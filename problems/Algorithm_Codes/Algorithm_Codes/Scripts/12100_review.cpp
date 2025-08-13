#include <bits/stdc++.h>
using namespace std;


namespace My {

	int n;

	int ret = 0;

	void shift(vector<vector<int>>& v) {
		for (int i = 0; i < n; i++) {
			vector<int> tmp;

			//0을 제외한 숫자만 일단 넣기
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == 0) continue;

				tmp.push_back(v[i][j]);
			}

			if (tmp.empty()) continue;


			v[i].clear();

			for (int j = 0; j < tmp.size(); j++) {
				if (j < tmp.size() - 1 && tmp[j] == tmp[j + 1]) {
					v[i].push_back(tmp[j] * 2);
					j++;
				}
				else v[i].push_back(tmp[j]);
			}

			while (v[i].size() < n) v[i].push_back(0);
		}
	}
	void RotateMat(vector<vector<int>>& v) {
		vector<vector<int>> tmp(n, vector<int>(n, 0));


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = v[n - j - 1][i];
			}
		}

		v = tmp;
		return;
	}
	void check(vector<vector<int>> v) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, v[i][j]);
			}
		}
	}

	void go(int here, vector<vector<int>> v) {
		if (here == 5) {
			check(v);
			return;
		}


		for (int i = 0; i < 4; i++) {
			// 0 ~ 270 도 회전
			auto tmp = v;

			for (int j = 0; j < i; j++) {
				RotateMat(tmp);
			}
			//왼쪽으로 밀기
			shift(tmp);

			go(here + 1, tmp);
		}
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);


		cin >> n;

		vector<vector<int>> a(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		go(0, a);
		cout << ret << "\n";
	}
}

int main() {
	


}