#include <bits/stdc++.h>
using namespace std;


int r, c;
char a[21][21];
int b[26];


int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int ret = 1;

void go(int y, int x, int cnt) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		
		if (b[a[ny][nx] - 'A']) continue;

		b[a[ny][nx]-'A'] = 1;
		go(ny, nx,cnt+1);
		b[a[ny][nx]-'A'] = 0;
	}

	ret=max(ret,cnt);
}
int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	b[a[0][0] - 'A'] = 1;
	go(0, 0,1);
	
	cout << ret << '\n';
}