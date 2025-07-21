#include <bits/stdc++.h>
using namespace std;

//로직 자체는 바로 떠올렸는데, 처음에 long long 타입 안쓰고, 또 mod연산을 매번 하지 않아서 오류남;;
//그냥 경우의 수 문제는 long long쓰고, mod을 해야 한다면 연산 할 떄마다 수행하자!
typedef long long ll;
int n;
ll dp[101][11]; //인덱스, 그 인덱스에 들어갈 수(0~9)

const int mod = 1000000000;

ll go(int here, int prev) {
	if (prev < 0 || prev>9) return 0;
	if (here == n) {
		return 1;
	}
	

	ll& ret = dp[here][prev];
	if (ret) return ret;

	ret = (ret+go(here + 1, prev + 1))%mod;
	ret = (ret+go(here + 1, prev - 1))%mod;

	return ret % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	
	/*
	top_down 방식
	ll ret = 0;
	for (int i = 1; i <= 9; i++) {
		ret += go(1, i);
		ret %= mod;
	}
	cout<<ret;*/

	
	//bottom_up 방식
	 for (int i = 1; i <= 9; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			if(j>0 && dp[i - 1][j - 1]) dp[i][j] = (dp[i][j]+dp[i - 1][j - 1])%mod;
			if (j < 9 && dp[i - 1][j + 1]) dp[i][j] = (dp[i][j]+dp[i - 1][j + 1])%mod;

			dp[i][j] %= mod;
		}
	}

	ll ret = 0;
	for (int i = 0; i <= 9; i++) {
		ret += dp[n - 1][i];
		ret %= mod;
	}
	cout << ret << "\n";
}