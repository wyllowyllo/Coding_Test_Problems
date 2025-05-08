#include <bits/stdc++.h>
using namespace std;


int r, c, k;

char a[6][6];
int visited[6][6];


int ret;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void go(int y, int x,int depth) {
	if (depth == k + 1) return;
	if (y == 0 && x == c - 1) {
		if(depth == k)ret++;
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx] || a[ny][nx]=='T') continue;

		visited[ny][nx] = 1;
		go(ny, nx, depth + 1);
		visited[ny][nx] = 0;
	}

}

int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	visited[r - 1][0] = 1;
	go(r - 1, 0, 1);
	cout << ret << '\n';
}