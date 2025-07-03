#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[40][40];

ll dp[40][40][3];


bool check(int y, int x, int d) {
	if (d == 0 || d==1) {
		return a[y][x] == 0;
	}
	else{
		return (a[y][x] == 0 && a[y][x-1] == 0 && a[y-1][x] == 0);
	}




	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		
			if (check(i, j, 0)) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			
			if (check(i, j, 1)) dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];

			if (check(i, j, 2)) dp[i][j][2] += dp[i - 1][j-1][0] + dp[i - 1][j-1][1]+ dp[i - 1][j - 1][2];
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";

}