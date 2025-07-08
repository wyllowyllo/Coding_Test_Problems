#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, k;
	int val;


	int dp[100001];
	const int INF = 1e9;

	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> k;

		fill(dp, dp + 100001, INF);

		for (int i = 0; i < n; i++) {
			cin >> val;
			dp[val] = 1;
		}

		for (int i = 1; i <= k; i++) {

			for (int j = 0; j < i; j++) {

				if (dp[j] != INF && dp[i - j] != INF) {
					dp[i] = min(dp[i], dp[j] + dp[i - j]);
				}

			}
		}

		if (dp[k] == INF) cout << -1 << "\n";
		else cout << dp[k] << "\n";
	}
}

namespace Sol {
	//팁 :dp문제에서,  n가지 종류를 무한히 쓸 수 는 문제라면 -> 왼쪽부터 dp를 만들어 간다
	// n가지 종류를 1개씩 쓸 수 있다면 -> 오른쪽부터 누적
	//최솟값을 구하는 dp문제라면, 초기화는 최댓값으로 하자!(최댓값을 구한다면 최솟값으로 초기화)
	int n, k, a[10001], temp, INF = 1e9;

	void sol() {
		cin >> n >> k;
		fill(a, a + 10001, INF);
		a[0] = 0;

		//이 문제에서는, n가지 종류의 동전을 무한히 쓸 수 있으므로, 왼쪽부터 dp!
		
		for (int i = 0; i < n; i++) {
			cin >> temp;

			//왼쪽부터, 값을 누적해 나감(각 동전을 무한히 쓸 수 있으므로)!
			for (int j = temp; j <= k; j++) {
				a[j] = min(a[j], a[j - temp] + 1); //ex) j가 3원이고, temp가 2원이라고 하면 j(3원)를 만들 수 있는 경우의 수는 j-temp원(1원)에서 temp(2원)를 추가하는 경우의 수이다.
			}
		}

		//만약 문제가 n가지 종류의 동전을 1개씩만 쓸 수 있는 문제라면, 오른쪽부터 dp!
		//왼쪽부터 진행할 때와 달리, 오른쪽에서부터 dp하면 누적이 안됨->따라서 1원,2원,3원 이라는 세 종류의 동전이 있다고 하면 각 동전 자체로는 누적이 안되므로, 1개씩만 쓰는 경우가 됨!
		/*
		for (int j = k; j >= temp; j--) {
				a[j] = min(a[j], a[j - temp] + 1); //ex) j가 3원이고, temp가 2원이라고 하면 j(3원)를 만들 수 있는 경우의 수는 j-temp원(1원)에서 temp(2원)를 추가하는 경우의 수이다.
			}
		
		*/

		if (a[k] == INF) cout << -1 << "\n";
		else cout << a[k] << "\n";


	}
}
int main() {
	
}