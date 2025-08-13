#include <bits/stdc++.h>
using namespace std;

namespace My {
	//구간쿼리 문제라 누적합으로 풀었음.
//누적합 구해서 매번 최대값 갱신하는데, 이때 누적합이 음수가 되는 순간에는 그 구간을 빼버리고 새로 누적하는게 결과가 더 클 것임이 자명하므로(음수구간 더해봤자 더 작아지므로)
//누적합이 음수가 될 때는, 누적값 초기화(0)하고 그 인덱스부터 다시 누적 시작함

//누적된 합 자체가 음수라면 버리고, 양수라면 계속 누적하며, 최댓값을 계속 갱신함

//구간 쿼리 문제는, 누적합을 활용할 생각을 하자!
	int n;
	int cnt[100004];
	int ret = -1e9;
	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;

		int v;
		for (int i = 1; i <= n; i++) {
			cin >> v;

			cnt[i] = cnt[i - 1] + v;
			ret = max(ret, cnt[i]);

			if (cnt[i] < 0) {

				cnt[i] = 0;
				continue;
			}


		}
		cout << ret << "\n";
	}
}

namespace Sol {
	int n, sum, a, ret = -1001;

	void sol() {
		scanf("%d", & n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);

			sum += a;
			ret = max(ret, sum);
			if (sum < 0) sum = 0;
		}

		printf("%d\n", ret);
	}
}

int main() {
	
}