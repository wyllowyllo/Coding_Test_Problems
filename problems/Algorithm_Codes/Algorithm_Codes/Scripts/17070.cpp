#include <bits/stdc++.h>
using namespace std;


namespace My {


	int n;
	int a[20][20];

	int dp[3][20][20]; //파이프가 해당 위치로 이동할 수 있는 모든 경우의 수(방향,y,x) 


	enum PIPEDIR { HORI = 0, VER = 1, DIAG = 2 };

	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);


		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		dp[HORI][0][1] = 1;

		//각 칸에 도달할 수 있는 모든 경우의 수를 구한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) continue;

				//현재위치로 올 수 있는 경우의 수
				if (j > 0) dp[HORI][i][j] += dp[HORI][i][j - 1] + dp[DIAG][i][j - 1];
				if (i > 0) dp[VER][i][j] += dp[VER][i - 1][j] + dp[DIAG][i - 1][j];
				if (i > 0 && j > 0 && a[i][j - 1] == 0 && a[i - 1][j] == 0) {

					dp[DIAG][i][j] += dp[HORI][i - 1][j - 1] + dp[VER][i - 1][j - 1] + dp[DIAG][i - 1][j - 1];
				}
			}
		}

		cout << dp[HORI][n - 1][n - 1] + dp[VER][n - 1][n - 1] + dp[DIAG][n - 1][n - 1] << "\n";

	}
}


namespace Sol {
	int n, a[24][24], dp[24][24][3];

	bool check(int y, int x,int d) {
		if (d == 0 || d == 2) {
			if (!a[y][x]) return true;
		}
		else if (d == 1) {
			if (!a[y][x]&& !a[y-1][x]&& !a[y][x-1]) return true;
		}


		return false;
	}
	void Sol() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		dp[1][2][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				//현재 가로 ->가로,대각선으로 이동
				if (check(i, j + 1, 0)) dp[i][j + 1][0] = dp[i][j][0];
				if(check(i+1,j+1,1)) dp[i+1][j + 1][1] = dp[i][j][0];

				//현재 세로-> 세로, 대각선으로 이동
				if (check(i+1, j, 2)) dp[i+1][j][2] = dp[i][j][2];
				if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] = dp[i][j][2];

				//현재 대각선-> 가로, 세로, 대각선으로 이동
				if (check(i, j + 1, 0)) dp[i][j + 1][0] = dp[i][j][1];
				if (check(i + 1, j, 2)) dp[i + 1][j][2] = dp[i][j][1];
				if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] = dp[i][j][1];

			}
		}

		int ret = dp[n][n][0];
		ret+= dp[n][n][1]; 	ret += dp[n][n][2];
		cout << ret << "\n";
	}
}



int main() {
	
}