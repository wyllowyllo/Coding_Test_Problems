#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace	std;

#pragma region MySol

namespace My {
	//전체 누적합에서 suffix 누적합을 빼는 방식으로 부분합 구함
//이때 부분합이 최대가 되기 위해선, 최소가 되는 suffix(0이하의 값을 가지게 됨)를 구한 다음 그 부분을 제거하면, 전체 부분합에서 -로 작용하는 부분을 제거하는 것이므로, 자연스레 최대의 누적합을 구할 수 있을 것이라 생각함
	const int MAX = 987654321;
	const int MIN = -987654321;

	int cnt[100001];

	int n, tmp;
	int ret = MIN;

	int suffix = MAX;

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			cnt[i + 1] = cnt[i] + tmp;

			suffix = min(suffix, cnt[i]);

			ret = max(ret, max(cnt[i + 1], cnt[i + 1] - suffix));
		}

		cout << ret << "\n";
	}
}

#pragma endregion

#pragma region Sol

namespace Sol {
	//누적된 합 자체가 음수라면 버리고, 양수라면 계속 더하면서, 각 구간마다 max값을 구해서 값을 갱신해 나가며 최댓값을 구함
	const int MAX = 987654321;
	const int MIN = -987654321;

	int cnt[100001];

	int n, tmp;
	int ret = MIN;

	int suffix = MAX;
	int sum; int a;

	void Sol() {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			sum += a;
			ret = max(ret, sum);

			if (sum < 0) sum = 0; //만약 계속 누적하다 구간 합이 음수가 되는 경우면, 구간에 포함시키지 않고 다시 처음부터 시작

		}

		printf("%d\n", ret);
	}
}

#pragma endregion

#pragma region MySol_2

namespace MySol_2 {

	typedef long long ll;

	ll dp[100004]; //마지막 원소(idx)에서 끝나는 연속합 중 최대

	int n;
	
	ll ret;//전체 수열에서 가능한 연속합 중 최대값
	void sol() {

		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;
		vector<ll> input(n);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		//fill(&dp[0], &dp[0] + 100004, MIN);
		dp[0] = input[0];
		ret = dp[0];

		for (int i = 1; i < n; i++) {
			dp[i] = max(input[i], dp[i - 1] + input[i]);
			ret = max(ret, dp[i]);
			
		}

		cout << ret << "\n";
	}
}
#pragma endregion


int main() {
	
	//Sol();
	MySol_2::sol();
}