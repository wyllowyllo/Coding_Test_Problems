#include <bits/stdc++.h>
#define co(a) cout<<a<<"\n";
using  namespace std;


namespace MySol {
	//1번 : mid<a[i]인 경우를 처리하는 if문을 check함수에 추가하거나
	//2번 : 그것이 아니라면 lo=max[a[i]]로 하여, mid<a[i]인 경우가 발생하지 않도록 하기!
	// hi는 모든 금액의 합으로 설정함(한 번의 인출로 쭉 생활할수 있도록)
	int n, m;
	int a[100001];

	int ret = 10001;
	int mx = -1;

	bool check(int draw) {

		//if (mx > draw) return false;
		int cnt = 1;
		int remain = draw;
		for (int i = 0; i < n; i++) {
			if (remain < a[i]) {
				cnt++;
				remain = draw;
			}

			remain -= a[i];
		}


		return cnt <= m;
	}

	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> m;

		int lo = -1, hi = -1;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			lo = max(lo, a[i]);
			//mx = max(mx, a[i]);

			sum += a[i];
		}
		hi = sum;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (check(mid)) {
				hi = mid - 1;
				ret = mid;
			}
			else lo = mid + 1;
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	//팁 : 이분 탐색을 활용하는 문제는 long long을 써야하는 문제가 매우 많으므로, 일단 long long박고 시작하자!
	

	typedef long long ll;
	int n, m, a[100005], mx, ret, lo, hi;


	bool check(int mid) {
		int cnt = 1, temp = mid;
		for (int i = 0; i < n; i++) {
			if (mid - a[i] < 0) {
				mid = temp;
				cnt++;
			}
			mid -= a[i];
		}

		return cnt <= m;
	}
	void Sol() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(a[i], mx);

		}


		lo=mx, hi= 1000000004;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (check(mid)) {
				hi = mid - 1;
				ret = mid;
			}
			else lo = mid + 1;
		}

		co(ret);
	}
}

int main() {

}