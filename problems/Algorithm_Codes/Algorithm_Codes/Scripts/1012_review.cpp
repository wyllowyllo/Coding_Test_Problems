#include <bits/stdc++.h>
using namespace std;

int t;
int m, n, k;
int y, x;
int a[51][51];
int visited[51][51];
int ret = 0;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void DFS(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[ny][nx] == 0 || visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main() {
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
					ret++;
				}
					
			}
		}

		cout << ret << "\n";
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		
		/*
		또는 이렇게 초기화
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51,
		*/
		ret = 0;
	}
}