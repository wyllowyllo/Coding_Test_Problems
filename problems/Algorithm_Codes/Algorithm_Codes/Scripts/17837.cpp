#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, k;
	int r, c, d;
	struct horse {
		int y, x;
		int dir;
	};
	pair<int, vector<horse*>> a[13][13];

	horse h[11];

	int dy[] = { 0,0,-1,1 };
	int dx[] = { 1,-1,0,0 };
	bool flag;

	void cellUpdate(int oy, int ox, int ny, int nx, horse* cur, bool doReverse) {


		auto& prevCell = a[oy][ox];
		auto start = find(prevCell.second.begin(), prevCell.second.end(), cur);

		vector<horse*> tmp(start, prevCell.second.end());
		if (doReverse) reverse(tmp.begin(), tmp.end());

		prevCell.second.erase(start, prevCell.second.end());

		for (auto i : tmp) {
			i->y = ny;
			i->x = nx;
			a[ny][nx].second.push_back(i);
		}
	}
	void move(int idx) {
		horse* cur = &h[idx];

		int oy = cur->y;
		int ox = cur->x;
		int dir = cur->dir;

		int ny = oy + dy[dir];
		int nx = ox + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx].first == 2) {
			dir ^= 1;
			ny = oy + dy[dir];
			nx = ox + dx[dir];

			cur->dir = dir;

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx].first == 2)
				return;

			bool f = (a[ny][nx].first == 0) ? false : true;
			cellUpdate(oy, ox, ny, nx, cur, f);



		}

		else if (a[ny][nx].first == 0) {
			cellUpdate(oy, ox, ny, nx, cur, false);
		}
		else if (a[ny][nx].first == 1) {
			cellUpdate(oy, ox, ny, nx, cur, true);
		}

		if (a[ny][nx].second.size() >= 4) flag = true;

	}

	void sol() {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j].first;
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> r >> c >> d;

			h[i].y = r - 1;
			h[i].x = c - 1;
			h[i].dir = d - 1;

			a[r - 1][c - 1].second.push_back(&h[i]);
		}

		int round = 1;
		while (true) {
			if (round > 1000) break;

			for (int i = 0; i < k; i++) {
				move(i);
				if (flag) break;
			}
			if (flag) break;
			round++;
		}

		if (flag) cout << round << "\n";
		else cout << -1 << "\n";
	}
}

namespace Sol {
	int n, k, a[14][14], y, x, dir;
	struct Point {
		int y, x, dir;
	};
	vector<int> v[14][14];
	vector<Point> status;
	const int dy[] = { 0, 0, -1, 1 };
	const int dx[] = { 1, -1, 0, 0 };

	void move(int y, int x, int dir, int i) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) {
		
			status[i].dir ^= 1;
			ny = y + dy[dir];
			nx = x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return;
		}

		vector<int>& here_v = v[y][x];
		vector<int>& next_v = v[ny][nx];

		auto pos = find(here_v.begin(), here_v.end(), i);

		if (a[ny][nx] == 1) reverse(pos, here_v.end());
		for (auto it = pos; it != here_v.end(); it++) {
			next_v.push_back(*it);
			status[*it].y = ny;
			status[*it].x = nx;
		}
		here_v.erase(pos, here_v.end());
		return;

	}
	bool isOver() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j].size() >= 4) {
					return 1;
				}
			}
		}
		return 0;
	}
	bool simul() {
		for (int i = 0; i < status.size(); i++) {
			int y = status[i].y;
			int x = status[i].x;
			int dir = status[i].dir;

			move(y, x, dir,i);
			if (isOver()) return 1;
		}
	}
	void sol() {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> y >> x >> dir;
			y--; x--; dir--;

			status.push_back({ y,x,dir });

		}

		int cnt = 0;
		bool flag = 0;
		while (cnt <= 1000) {
			cnt++;
			if (simul()) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << cnt << "\n";
		else cout << -1 << "\n";
	}
}
int main() {
	
}