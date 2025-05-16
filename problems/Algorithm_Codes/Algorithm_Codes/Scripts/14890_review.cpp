#include <bits/stdc++.h>
using namespace std;

int n, l;
int a[101][101];
int b[101][101];

#pragma region MySol
int go(int m[101][101]) {
	int cnt = 0;
	int lCnt = 0, hCnt = 1;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (m[i][j] == m[i][j - 1]) {
				hCnt++;
			}
			else if (m[i][j] == m[i][j - 1] + 1) {
				if (hCnt >= l) {
					hCnt = 1;
				}
				else { flag = true; break; }
			}
			else if (m[i][j] == m[i][j - 1] - 1) {

				int k;
				for (k = j; k < n; k++) {
					if (m[i][j] != m[i][k]) break;
					lCnt++;
					if (lCnt == l) break;
				}

				if (lCnt >= l) {
					lCnt = 0;
					hCnt = 0;
					j = k;
				}
				else { flag = true; break; }
			}
			else {
				flag = true;
				break;
			}
		}

		if (!flag) cnt++;
		lCnt = 0; hCnt = 1;
		flag = false;
	}

	return cnt;
}


void MySol() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][i];
		}

	}
	int ret = 0;
	ret += go(a);
	ret += go(b);

	cout << ret << "\n";

}

#pragma endregion

#pragma region Sol_1
int rt;

void Solve(int m[101][101]) {
	for (int i = 0; i < n; i++) {
		int cnt = 1;

		int j;

		for (j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) cnt++;
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= l) cnt = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}

		if (j == n - 1 && cnt >= 0) rt++;
	}
}
void Sol_1() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j];
		}
	}
	Solve(a); Solve(b);
	printf("%d\n", rt);
	
}

#pragma endregion

int main() {
	

}