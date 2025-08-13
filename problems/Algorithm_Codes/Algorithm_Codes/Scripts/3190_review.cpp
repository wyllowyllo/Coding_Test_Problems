#include <bits/stdc++.h>
using namespace std;

int n, k;

int a[101][101];
int r, c, l;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> r >> c;

		a[r][c] = 1;
	}
	
	cin >> l;
	vector<pair<int, char>> v(l);

	for (int i = 0; i < l; i++) {
		cin >> v[i].first >> v[i].second;

	}

	deque<pair<int, int>> snake;

	int _t = 1;
	int dir = 0;
	snake.push_front({ 1,1 });
	a[1][1] = 2;
	int idx = 0;
	while (true) {

		int ny = snake.front().first + dy[dir];
		int nx = snake.front().second + dx[dir];

		if (ny <= 0 || ny > n || nx <= 0 || nx > n || a[ny][nx] == 2) break;

		snake.push_front({ ny, nx });
		if (a[ny][nx] != 1) {
			a[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		a[ny][nx] = 2;

		if (idx<v.size() && v[idx].first == _t) {
			if (v[idx].second == 'L') dir = ((dir - 1>=0)?dir-1:3);
			else dir = ((dir + 1 <= 3) ? dir + 1 : 0);

			idx++;
		}

		_t++;
	}

	cout << _t << "\n";
}