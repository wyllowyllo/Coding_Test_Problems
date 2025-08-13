#include <bits/stdc++.h>
using namespace std;
int n;

namespace My {
	const int MOD = 1000000007;

	map<pair<int, int>, int> mp;

	int go(int num, int idx) {
		if (idx == n) {
			if (num % 15 == 0) return 1;
			return 0;
		}

		int& ret = mp[{num, idx}];
		if (ret) return ret % MOD;

		num *= 10;
		ret += go((num + 1) % 15, idx + 1);
		ret += go((num + 5) % 15, idx + 1);
		ret %= MOD;

		return ret;
	}
	void sol() {
		cin >> n;
		cout << (go(1, 1) + go(5, 1)) % MOD << "\n";
	}
}

namespace Sol {
	const int MOD = 1000000007;

	void sol() {
		long long n;

		cin >> n;

		if (n == 1) {
			cout << 0 << "\n";
			return;
		}

		//합이 0인 경우의 수 1개, 합이 1,2인 경우의 수는 0개
		long long dp0=1, dp1 = 0, dp2 = 0;

		//마지막 자리는 언제나 5이고(5의 배수 만족하기 위해),
		//이것이 되기 위해서는 앞자리의 합 + 5 가 3으로 나누어 떨어져야 함.
		//즉 ((앞자리 숫자들의 총합)+마지막 자리 5) % 3==0,
		// -> (앞자리 숫자들의 총합)%3 + 마지막 자리 5 %3 
		//-> (0또는 1 또는 2) + 2 ==0 이 되어야 한다!


		for (long long i = 1; i <= n-1; i++) {
			long long ndp0 = (dp2 + dp1) % MOD; //현재 길이에서 합이 0이 되는 경우는, 이전 길이의 합이 1인 경우와 2인 경우임.

		}
	}
}

int main() {
	
	
	
	
}