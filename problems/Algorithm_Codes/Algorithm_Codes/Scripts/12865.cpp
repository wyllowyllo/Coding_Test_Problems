#include <bits/stdc++.h>
using namespace std;


namespace My {

	int n, k;
	int w, v;

	int dp[100001]; //배낭 용량 k일때의 최대 가치


	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

		cin >> n >> k;


		for (int i = 0; i < n; i++) {
			cin >> w >> v;

			for (int j = k; j >= w; j--) {
				dp[j] = max(dp[j], dp[j - w] + v);
			}
		}

		cout << dp[k] << "\n";
	}
}

namespace Sol {
	//재귀를 이용한 풀이

	int n, k;
	int w, vv;
	vector<pair<int, int>> v;

	int dp[100004][104]; //현재 남은 가방의 무게와 아이템 인덱스를 인덱스로 하여, 그때의 최대 가치 저장


	int go(int weight, int idx) {
		if (idx == n || weight == 0) return 0;

		int& ret = dp[weight][idx];
		if (ret != -1) return ret;

		//현재 idx의 아이템을 가방에 포함하지 않는 경우
		ret = go(weight, idx + 1);

		//현재 idx의 아이템을 가방에 포함하는 경우
		if (weight - v[idx].first >= 0) {
			ret = max(ret, go(weight - v[idx].first, idx + 1) + v[idx].second);

		}


		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> w >> vv;
			v.push_back({ w,vv });

		}

		fill(&dp[0][0], &dp[0][0] + 100004 * 104, -1);


		cout << go(k, 0);
	}
}

int main() {

	Sol::sol();

	
}