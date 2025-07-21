#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, tmp;
vector<ll> v;

void go(int idx, int end, ll sum,vector<ll>& vv) {
	if (sum > m) return;
	if (idx == end) {
		vv.push_back(sum);
		return;
	}

	go(idx + 1, end, sum + v[idx], vv);
	go(idx + 1, end, sum, vv);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<ll> A, B;
	go(0, n / 2,0, A);
	go(n/2, n, 0, B);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll ret = 0;
	for (auto i : A) {
		ret += (int)(upper_bound(B.begin(), B.end(), m - i) - B.begin());
	}
	cout << ret << "\n";
}