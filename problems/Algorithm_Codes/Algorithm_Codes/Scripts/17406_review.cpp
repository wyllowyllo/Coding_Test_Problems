#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int a[51][51];
int origin[51][51];


int r, c, s;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ret = 1e9;
struct rot {
	int r, c, s;

} v[7];

void Print() {
	cout << "\n";
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			cout<< a[i][j]<<" ";
		}
		cout << "\n";
	}
}
void go(vector<int> &vv) {


	for (int i = 0; i < k; i++) {

		r = v[vv[i]].r;
		c = v[vv[i]].c;
		s = v[vv[i]].s;

		int ly = r - s;
		int lx = c - s;

		int ry = r + s;
		int rx = c + s;

		int _size = rx - lx + 1;

		while (_size > 1) {
			vector<int> tmp;
			vector<pair<int, int>> pos;

			int idx = 0;
			int y = ly; int x = lx;
			tmp.push_back(a[y][x]);
			pos.push_back({ y,x });

			while (true) {
				int ny = y + dy[idx]; int nx = x + dx[idx];
				if (ny == ly && nx == lx) break;

				if (ny<ly || ny>ry || nx<lx || nx>rx) {
					idx++;
					continue;
				}

				tmp.push_back(a[ny][nx]);
				pos.push_back({ ny,nx });
				y = ny;
				x = nx;
			}

			rotate(tmp.rbegin(), tmp.rbegin() + 1, tmp.rend());

			for (int p = 0; p < tmp.size(); p++) {
				a[pos[p].first][pos[p].second] = tmp[p];
			}

			ly += 1; lx += 1;
			ry -= 1; rx -= 1;
			_size = rx - lx + 1;


		}

		//Print();

	}

	
	int sum = 0;
	int r = 1e9;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += a[i][j];
		}
		r = min(r, sum);
	}

	ret = min(ret, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			cin >> a[i][j];
		}
	}

	memcpy(origin, a, sizeof(a));

	vector<int> vv;
	for (int i = 0; i < k; i++) {
		cin >> v[i].r >> v[i].c >> v[i].s;
		vv.push_back(i);
	}

	
	do {
		go(vv);
		memcpy(a, origin, sizeof(origin));
	} while (next_permutation(vv.begin(), vv.end()));
	

	cout << ret << "\n";
}