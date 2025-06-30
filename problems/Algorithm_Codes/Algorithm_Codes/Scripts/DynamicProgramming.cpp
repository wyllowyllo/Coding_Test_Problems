#include <bits/stdc++.h>
using namespace std;




namespace ex1 {
	//이 문제를 완전탐색으로 푼다면? 시간복잡도는 2^30
	//이럴 땐, DP로 해결할 수 있을까 생각해보자 -> 즉, 메모이제이션이 가능한지를 봐야 한다
	//메모이제이션을 위한 배열은 어떻게 정의? -> 문제에서 어떤 상태값이 중요한지를 생각해서, 그것을 기반으로 배열 생성

	/*  ● 사과는 최대 100초동안 떨어진다고 하니 매초를 담을 100개짜리 배열이 필요합니다.
		● 지금 내가 있는 상태가 1인지 2인지가 중요합니다. 2개짜리 배열이 필요합니다.
		● 그리고 움직일 수 있는 카운트가 제한되어있네요.그걸 담을 30개짜리 배열이 필요합니다.*/



	int s, m;
	int a[101];
	int dp[101][2][31];


	int go(int idx, int pos, int turn) {
		if (turn < 0) return -1e9;
		if (idx == s) return 0;

		//이미 계산된 값이면 반환
		int& ret = dp[idx][pos][turn];
		if (ret != -1) return ret;

		//현재 나무에 머무르거나 다른 나무로 이동하는 경우 중 최대값 선택
		return ret=max(go(idx + 1, pos ^ 1, turn - 1), go(idx + 1, pos, turn)) + (pos == a[idx]-1);
	}

	void MySol() {
		cin >> s >> m;

		
		for (int i = 0; i < s; i++) {
			cin >> a[i];
		}
		memset(dp, -1, sizeof(dp));

		// 두 가지 초기 상태(1번 나무에 시작, 2번 나무에 시작) 중 최대 값 출력
		cout << max(go(0, 0, m), go(0, 1, m - 1)) << "\n";
	}

}

namespace ex2 {
	//피보나치 수열 : 탑다운 방식
	//재귀적인 구조, 큰 N에서 시작하여 1또는 0 등의 작은 숫자로 향하게 함수가 호출됨
	//DP에 필요한 배열만을 만들며, 코드가 직관적. 재귀호출에 대한 오버헤드가 있는 것이 단점


	int dp[1004];
	int fibo(int n) {
		if (n <= 1) return n;

		int& ret = dp[n];
		if (ret != -1) return ret;

		return ret = fibo(n - 1) + fibo(n - 2);
	}
	void Sol() {
		int n = 10;
		memset(dp, -1, sizeof(dp));

		int ret = fibo(n);
		cout << ret << "\n";
	}

}
namespace ex3 {
	//피보나치 수열 : 바텀업 방식
	//0이나 1등 작은 숫자에서 N까지 반복문을 통해 DP를 만듦.
	//재귀호출에 대한 오브헤드가 없는 장점이 있으나, 문제에 필요한 배열 뿐 아니라 모든 배열을 다 만든다는 단점이 있음
	//보통 탑다운 DP보다 더 빠름.

	int dp[1004];
	
	void Sol() {
		memset(dp, -1, sizeof(dp));

		int n = 10;
		dp[0] = 0;
		dp[0] = 1;

		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		cout << dp[n] << '\n';
	}
}


namespace ex4 {
	//경우의 수를 푸는 DP

	//경우의 수를 풀 때 DP를 사용하는 경우가 있는데, 이때는 그냥 '다 더한다'고 생각하면 됨.


	int t, n;
	int dp[10001];

	void MySol() {
		cin >> t;

		dp[0] = 1;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 10000; j++) {
				if(j-i>=0) dp[j] += dp[j - i];
			}
		}

		while (t--) {
			cin >> n;
			cout << dp[n] << "\n";
		}
	}

}
int main() {
	ex1::MySol();
}