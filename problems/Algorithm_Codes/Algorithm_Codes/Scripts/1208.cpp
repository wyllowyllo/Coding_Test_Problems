#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, s, tmp;

vector<int> v;
ll ret = 0;

void go(int idx, int end, ll sum, vector<ll> &vv) {
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

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<ll> A, B;
	go(0, n / 2, 0, A);
	go(n/2, n, 0, B);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (auto i : A) {
		int start = (int)(lower_bound(B.begin(), B.end(), s - i) - B.begin());
		int end = (int)(upper_bound(B.begin(), B.end(), s - i) - B.begin());

		if (end - start > 0) ret += end - start;
	}
	if (s == 0) ret--; //만들어야 하는 합이 0이라면, 아무것도 선택 안하는 경우는 제외

	cout << ret << "\n";
}