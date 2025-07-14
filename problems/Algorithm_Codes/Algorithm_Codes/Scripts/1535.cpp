#include <bits/stdc++.h>
using namespace std;

namespace My {
	//시간복잡도상 그냥 완탐으로도 풀리긴 함. 근데 걍 dp로 함 (dp로직 제거해도 가능!)
	int n;
	vector<int> v1, v2;
	int tmp;

	int dp[101][21]; //현재 체력,사람idx 를 인덱스로

	int go(int health, int idx) {
		if (idx == n || health <= 0) return 0;


		int& ret = dp[health][idx];
		if (ret != -1) return ret;



		if (health - v1[idx] > 0)
			ret = max(go(health - v1[idx], idx + 1) + v2[idx], go(health, idx + 1));
		else ret = go(health, idx + 1);



		return ret;
	}



	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v1.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v2.push_back(tmp);
		}

		fill(&dp[0][0], &dp[0][0] + (101 * 21), -1);

		cout << go(100, 0) << " ";
	}

}

namespace Sol {

	//각 사람을 1번만 만나서 인사할 수 있으므로, 오른쪽부터 dp!

	int n, dp[101], cost[101], happy[101];

	double temp;

	void sol() {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
		for (int i = 0; i < n; i++) scanf("%d", &happy[i]);

		for (int i = 0; i < n; i++) {
			for (int j = 100; j >= cost[i]; j--) {
				dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
			}
		}

		printf("%d\n", dp[100]);
	}
}



int main() {
	
	


}