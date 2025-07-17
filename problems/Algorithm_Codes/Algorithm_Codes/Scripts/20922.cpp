#include <bits/stdc++.h>
using namespace std;

int n,k;
int cnt[100001];


int ret = -1;

int main() {
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l = 0, r = 0;

	while (l <= r) {
		if (r == n) {
			ret = max(ret, r - l);
			break;
		}

		if (!cnt[v[r]]) {
			cnt[v[r]]++;
			r++;
		}
		else {
			if (cnt[v[r]] < k) {
				cnt[v[r]]++;
				r++;
			}
			else {
				ret = max(ret, r - l);

				while (cnt[v[r]] == k && l <=r) {
					cnt[v[l]]--;
					l++;
				}
			}
		}
	}


	cout << ret << "\n";
}