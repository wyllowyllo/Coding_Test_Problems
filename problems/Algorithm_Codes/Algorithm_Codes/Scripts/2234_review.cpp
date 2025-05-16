#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[51][51];
int b[51][51];
int visited[51][51];

int cnt = 0;
int mx = 0;
int l = 0;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

vector<int> roomSize;

void check(int y,int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (b[y][x] == b[ny][nx]) continue;

		int s = roomSize[b[y][x]] + roomSize[b[ny][nx]];
		l = max(l, s);
	}
}
int go(int y, int x, int color) {
	int size = 1;
	


	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;

		if(i==0 && (a[y][x]&2)) continue;
		else if (i == 1 && (a[y][x] & 4)) continue;
		else if (i == 2 && (a[y][x] & 8)) continue;
		else if (i == 3 && (a[y][x] & 1)) continue;

		visited[ny][nx] = 1;
		b[ny][nx] = color;

		size += go(ny, nx, color);
	}

	return size;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int color = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			visited[i][j] = 1;
			b[i][j] = color;

			int width = go(i, j, color++);
			roomSize.push_back(width);

			mx=max(mx, width);
			cnt++; //방의 개수
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check(i, j);
		}
	}


	cout << cnt << "\n";
	cout << mx << "\n";
	cout << l << "\n";



}