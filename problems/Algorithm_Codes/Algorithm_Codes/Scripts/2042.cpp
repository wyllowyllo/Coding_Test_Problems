#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
using namespace std;

namespace My {
	typedef long long ll;

	int n, m, k;

	ll a, b, c;

	ll psum[1000004];
	vector<ll> v;

	void update(int idx, ll newValue) {

		ll diff = newValue - v[idx];
		v[idx] = newValue;
		while (idx <= n) {
			psum[idx] += diff;
			idx = idx + (idx & -idx);
		}
	}
	ll sum(int idx) {
		ll ret = 0;

		while (idx > 0) {
			ret += psum[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);


		cin >> n >> m >> k;
		v.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> v[i];

			psum[i] += v[i];
			int idx = i + (i & -i);
			while (idx <= n) {
				psum[idx] += v[i];
				idx = idx + (idx & -idx);
			}

		}


		for (int i = 0; i < m + k; i++) {
			cin >> a >> b >> c;

			if (a & 1) {
				update(b, c);
			}
			else {
				cout << sum(c) - sum(b - 1) << "\n";
			}
		}
	}
}

namespace Sol {

	int n, m, k, t1, t2, t3;
	long long t4;

	long long sum(vector<long long>& tree, int i) {
		long long ans = 0;

		while (i > 0) {
			ans += tree[i];
			i -= (i & -i);
		}
		return ans;
	}
	void update(vector<long long>& tree, int i, long long diff) {
		while (i < tree.size()) {
			tree[i] += diff;
			i += (i & -i);
		}
	}

	void sol() {
		scanf("%d %d %d", &n, &m, &k);
		vector<long long> a(n + 1);
		vector<long long> tree(n + 1);

		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			update(tree, i, a[i]);
		}

		m += k;
		while (m--) {
			scanf("%d", &t1);
			if (t1 == 1) {
				scanf("%d %lld", &t2, &t4);
				long long diff = t4 - a[t2];
				a[t2] = t4;

				update(tree, t2, diff);
			}
			else {
				int t2, t3;
				scanf("%d %d", &t2, &t3);
				printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1));
			}

		}
	}
}



int main() {
	Sol::sol();
}