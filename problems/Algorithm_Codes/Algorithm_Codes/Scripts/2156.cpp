#include <bits/stdc++.h>
using namespace std;

int n;
int a[10004];
int dp[10004][4];

int go(int idx, int cnt) {
	if (cnt == 3) return -1e9;
	if (idx == n) {
		return 0;
	}

	int& ret = dp[idx][cnt];
	if (ret!=-1) return ret;

	return ret = max(go(idx + 1, cnt + 1) + a[idx], go(idx + 1, 0));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";


	//1차원 dp로 풀기
	/*
	int n;
	long long a[10004], dp[10004];
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max({ dp[i - 1], //현재 idx의 포도주 안먹음
		dp[i - 2] + a[i],  // i-1번째 포도주 안먹음
		dp[i - 3] + a[i - 1] + a[i] //i-2번째 포도주 안먹음
		});
	}
	cout << dp[n] << "\n";

	*/

}