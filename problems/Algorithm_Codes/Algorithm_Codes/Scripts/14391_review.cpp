#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[5][5];


//int b[5][5]; //가로에 포함될지, 세로에 포함될지를 결정
int visited[5][5];


int ret;
string s;

void cal(int b[5][5]) {
	int sum = 0;
	
	//가로검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = 0;
			if (visited[i][j]) continue;
			if (b[i][j] == 0 && a[i][j]) {
				for (int k = j; k < m; k++) {
					if (b[i][k] == 1 || visited[i][k]) break;
					num *= 10;
					num += a[i][k];
					visited[i][k] = 1;
				}

				sum += num;
			}

			

		}
	}

	//세로검사
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = 0;
			if (visited[j][i]) continue;
			if (b[j][i] == 1 && a[j][i]) {
				for (int k = j; k < n; k++) {
					if (b[k][i] == 0 || visited[k][i]) break;
					num *= 10;
					num += a[k][i];
					visited[k][i] = 1;
				}

				sum += num;
			}


		}
	}

	ret = max(ret, sum);

}
void setMap(int r, int b[5][5]) {
	if (r == n) {
		memset(visited, 0, sizeof(visited));
		cal(b);

		return;
	}

	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			b[r][j] = ((i & (1 << j)) ? 1 : 0);
		}

		setMap(r + 1, b);
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j]=s[j]-'0';
		}
	}

	int b[5][5] = { 0, };
	setMap(0, b);
	

	cout << ret << "\n";


}