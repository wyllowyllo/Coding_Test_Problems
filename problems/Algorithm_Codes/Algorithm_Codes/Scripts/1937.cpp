#include <bits/stdc++.h>
using namespace std;


int n;
typedef long long ll;

int a[501][501];
ll dp[501][501]; //각 위치에서 시작했을 때 움직일 수 있는 최대 칸의 수

ll result=-1;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


ll go(int y, int x) {
	

	ll& ret = dp[y][x];
	if (ret!=0) return ret;

	ll cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || ny>n || nx<1 || nx>n) continue;
		if (a[y][x] >= a[ny][nx]) continue;

		cnt = max(cnt, go(ny, nx) + 1);
	}

	cnt = max(cnt, (ll)1);

	return ret = cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result =max(result,go(i, j));
		}
	}

	cout << result << "\n";
}