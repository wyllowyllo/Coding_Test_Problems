#include <bits/stdc++.h>
using namespace std;

namespace My {
	//메모리 제한 때문에 롤링 배열로 바꿔야 할듯 함

	//어렵지 않은 문제이고 어떻게 해결해야할지도 바로 떠올렸는데, 구현이 생각보다 오래 걸림;;
	// 이 문제를 풀기 위해 어떤 정보를 저장해야 하는지(어떤 정보가 필요한지) 에 집중해서, 거기에 맞게 풀어보자

	//문제 풀기 위해 필요한 것 : 입력값, 직전 행의 정보
	//따라서 직전 행의 정보만 저장하면 된다!
	//첫 행으로 초기화하고, 매 행은 읽자마자 새 값 계산 후 덮어쓰기
	int n;
	int a[100001][3];


	int dp_max[3];
	int dp_min[3];

	int prev_max[3];
	int prev_min[3];

	const int MAX = 1e9;
	const int MIN = -1e9;


	void Sol() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}



		prev_max[0] = dp_max[0] = a[n - 1][0];
		prev_max[1] = dp_max[1] = a[n - 1][1];
		prev_max[2] = dp_max[2] = a[n - 1][2];

		prev_min[0] = dp_min[0] = a[n - 1][0];
		prev_min[1] = dp_min[1] = a[n - 1][1];
		prev_min[2] = dp_min[2] = a[n - 1][2];

		for (int i = n - 2; i >= 0; i--) {

			fill(&dp_max[0], &dp_max[0] + 3, MIN);
			fill(&dp_min[0], &dp_min[0] + 3, MAX);

			for (int j = 0; j < 3; j++) {

				for (int k = j - 1; k <= j + 1; k++) {
					if (k < 0 || k >= 3) continue;

					dp_max[j] = max(dp_max[j], prev_max[k] + a[i][j]);
					dp_min[j] = min(dp_min[j], prev_min[k] + a[i][j]);
				}


			}
			memcpy(prev_max, dp_max, sizeof(prev_max));
			memcpy(prev_min, dp_min, sizeof(prev_min));
		}

		cout << max({ dp_max[0],dp_max[1] ,dp_max[2] }) << " ";
		cout << min({ dp_min[0],dp_min[1] ,dp_min[2] }) << "\n";
	}
}

namespace Sol {
	//매 행의 최대, 최소값을 구하기 위해 필요한 정보는, 그 행에서의 입력값과, 직전 행의 값이므로
	//전 행을 저장할 필요 없이, 직전 행만 저장하고, 매번 갱신하는 식으로 하면 된다!
	//직전 행만 기억하는 롤링 dp테이블 필요!

	void sol_1() {
		int n;
		int x0, x1, x2;

		cin >> n;
		cin >> x0 >> x1 >> x2;

		int maxPrev[3] = { x0,x1,x2 };
		int minPrev[3] = { x0,x1,x2 };

		for (int i = 1; i < n; i++) {
			cin >> x0 >> x1 >> x2;

			int maxCur0 = x0 + max(maxPrev[0], maxPrev[1]);
			int maxCur1 = x1 + max({ maxPrev[0], maxPrev[1], maxPrev[2]});
			int maxCur2 = x2 + max(maxPrev[1], maxPrev[2]);

			int minCur0 = x0 + min(minPrev[0], minPrev[1]);
			int minCur1 = x1 + min({ minPrev[0], minPrev[1], minPrev[2]});
			int minCur2 = x2 + min(minPrev[1], minPrev[2]);

			maxPrev[0] = maxCur0;
			maxPrev[1] = maxCur1;
			maxPrev[2] = maxCur2;

			minPrev[0] = minCur0;
			minPrev[1] = minCur1;
			minPrev[2] = minCur2;
		}

		cout << *max_element(maxPrev, maxPrev + 3) << ' '
			<< *min_element(minPrev, minPrev + 3) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Sol::sol_1();

}