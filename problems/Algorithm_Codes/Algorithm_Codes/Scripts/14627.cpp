#include <bits/stdc++.h>
using namespace std;

namespace my {
	typedef long long ll;

	ll s, c;
	ll a[1000001];

	ll lo, hi;

	ll ret = 1e18;
	ll total = 0;

	ll check(ll mid) {

		ll cnt = 0;


		for (int i = 0; i < s; i++) {
			cnt += a[i] / mid;

		}

		return cnt;
	}

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> s >> c;

		for (int i = 0; i < s; i++) {
			cin >> a[i];
			total += a[i];
		}


		lo = 1; hi = 1e18 + 4;

		while (lo <= hi) {
			ll mid = (lo + hi) / 2;


			if (check(mid) >= c) {
				ret = total - mid * c;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}

		cout << ret << "\n";
	}
}

namespace sol {
	typedef long long ll;
	ll s, c, a[1000004], ret, sum, ret_cnt;

	bool check(ll mid) {
		ll cnt = 0;
		for (int i = 0; i < s; i++)cnt += a[i] / mid;
		return cnt >= c;
	}

	void Sol() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> s >> c;
		for (int i = 0; i < s; i++)cin >> a[i], sum += a[i];

		ll lo = 1, hi = 1e9;

		while (lo <= hi) {
			ll mid = (lo + hi) / (1LL * 2); //int 형인 2를 long long으로 타입캐스팅
			if (check(mid)) {
				lo = mid + 1;
				ret = mid;
			}
			else hi = mid - 1;
		}

		cout << sum - ret * c << "\n";
	}
}

int main() {
	
}