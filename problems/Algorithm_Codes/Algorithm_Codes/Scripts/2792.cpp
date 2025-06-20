#include <bits/stdc++.h>
using namespace std;

int n, m;
int jew[300001];

int ret = 987654321;

bool check(int unit) {
	int bundle = 0;
	for (int i = 0; i < m; i++) {
		bundle += jew[i] / unit;
		if (jew[i] % unit) bundle++;
	}

	return bundle <= n;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	int left, right=0;
	left = 1;

	for (int i = 0; i < m; i++) {
		cin >> jew[i];
		right = max(right, jew[i]);
	}

	while (left <= right) {
		int mid = (left + right)/2;

		if (check(mid)) {
			ret = min(mid, ret);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << ret << "\n";
}