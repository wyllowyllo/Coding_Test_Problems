#include <bits/stdc++.h>
using namespace std;

int r, c;

char a[21][21];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int ret = -1;

void go(int y, int x, int visited, int cnt) {

	visited |= (1 << (a[y][x] - 'A'));
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if(visited & (1 << (a[ny][nx] - 'A'))) continue;

		go(ny, nx, visited, cnt);
	}

	ret = max(ret, cnt);
}

string s;

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = s[j];
		}
	}

	go(0, 0, 0, 0);
	cout << ret << '\n';


}