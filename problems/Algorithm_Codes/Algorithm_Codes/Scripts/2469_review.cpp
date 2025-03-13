#include <bits/stdc++.h>
using namespace std;

int n;
int a[101][101];
int visited[101][101];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int maxHeight = 0;
int maxCount = 0;

void DFS(int y, int x, int h) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || ny>n || nx<0 || nx>n) continue;
		if (h >= a[ny][nx] || visited[ny][nx]) continue;
		DFS(ny, nx, h);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			maxHeight = max(a[i][j], maxHeight);
		}
	}

	for (int h = 0; h <= maxHeight; h++) {
		memset(visited, 0, sizeof(visited));
		
		int count = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > h && !visited[i][j]) {
					DFS(i,j,h);
					count++;
				}
			}
		}

		maxCount = max(count, maxCount);
	}
	cout << maxCount << "\n";
}