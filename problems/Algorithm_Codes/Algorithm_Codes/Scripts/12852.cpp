#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

namespace My {

	//dp를 활용해서, 현재상태에서 1이 될 수 있는 최소 연산횟수를 구함
	//역추적하는 로직을 떠올리기가 힘들었음
	//현재값 a의 최소 연산횟수를 구하고, 그때 _next배열에 현재 값의 다음 값을 저장시켜놓는다. 이걸 따라가면서 trace하는 방식

	int n;


	const int MAX = 1e6 + 4;
	int dp[MAX];
	//int val[MAX]; //연산횟수를 인덱스로, 각 연산횟수에서의 값을 저장
	int _next[MAX]; //현 상태값 다음 값

	int go(int a) {
		if (a == 1) {

			return 0;
		}


		int& ret = dp[a];
		if (ret != -1) return ret;

		ret = MAX;

		if (a % 3 == 0) {
			int tmp = go(a / 3) + 1;
			if (ret > tmp) {
				ret = tmp;
				_next[a] = a / 3;
			}
		}

		if (a % 2 == 0) {
			int tmp = go(a / 2) + 1;
			if (ret > tmp) {
				ret = tmp;
				_next[a] = a / 2;
			}
		}

		int tmp = go(a - 1) + 1;
		if (ret > tmp) {
			ret = tmp;
			_next[a] = a - 1;
		}


		return ret;
	}



	void sol() {
		cin >> n;

		memset(dp, -1, sizeof(dp));


		int result = go(n);
		cout << result << "\n";



		int cur = n;
		cout << n << " ";
		while (true) {
			if (cur == 1) break;

			cout << _next[cur] << " ";
			cur = _next[cur];
		}
	}
}

namespace Sol {
	int dp[1000004], n;
	const int INF = 987654321;

	void go(int here) {
		if (here == 0) return;
		printf("%d ", here);

		//현재 값의 연산 횟수와, 그 다음 가능한 값들의 연산 횟수 비교 시 딱 1차이가 난다면 현재 값 다음은 그 값임
		if (here % 3 == 0 && (dp[here] == (dp[here / 3] + 1))) go(here / 3); 
		else if (here % 2 == 0 && (dp[here] == (dp[here / 2] + 1))) go(here / 2);
		else if (here-1>=0 && (dp[here] == (dp[here - 1] + 1))) go(here - 1);
	}

	void sol() {
		scanf("%d", &n);
		fill(dp, dp + 1000004, INF);

		dp[1] = 0; //1에서 1로 갈때의 최소 연산횟수는 0

		//i에서 1로 갈 때의 최소 연산횟수를 구함
		for (int i = 1; i <= n; i++) {
			if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
			if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}

		printf("%d\n", dp[n]);
		go(n); //경로 추적

	}
}


int main() {
	Sol::sol();
}