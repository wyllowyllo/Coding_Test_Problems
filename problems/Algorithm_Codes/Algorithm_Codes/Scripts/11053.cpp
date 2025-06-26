#include <bits/stdc++.h>
using namespace std;


int n;
int a[1001];
int cnt[1001];


const int MAX = 1001;
int lis[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(cnt, cnt + 1001, 1);

	/*
	* int len=1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				len = max(len,cnt[i]);
			}
		}
	}*/

	int len = 0;
	fill(lis, lis + 1001, MAX);

	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(lis, lis + len, a[i]);
		if (*pos == MAX) len++;

		*pos = a[i];
	}

	cout << len << "\n";
}