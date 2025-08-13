#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int a[54][54];

vector<pair<int, int>> v;
map<pair<int, int>, int> m;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };




void spread() {
	m.clear();
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) {
				int tmp = a[i][j] / 5;
				int cnt = 0;

				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;

					cnt++;
					m[{ny, nx}] += tmp;
				}

				a[i][j] -= tmp*cnt;
			}

		}
	}

	for (auto i : m) {
		auto pos = i.first;
		a[pos.first][pos.second] += i.second;
	}


}

void operate(pair<int,int> pos, int _dy[],int _dx[]) {
	vector<int> vv;
	vector<pair<int, int>> nodes;

	int y = pos.first; int x = pos.second+1;
	int idx = 0;
	vv.push_back(a[y][x]);
	nodes.push_back({ y,x });

	while (true) {
		
		int ny = y + _dy[idx]; int nx = x + _dx[idx];
		if (ny == pos.first && nx == pos.second) break;

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) { idx++; continue; }

		vv.push_back(a[ny][nx]);
		nodes.push_back({ ny,nx });

		y = ny; x = nx;
	}

	vv[vv.size() - 1] = 0;
	rotate(vv.rbegin(), vv.rbegin() + 1, vv.rend());

	idx = 0;
	for (auto i : nodes) {
		a[i.first][i.second] = vv[idx++];
	}
}
int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			if (a[i][j] == -1)
				v.push_back({ i,j });
		}
	}

	while (t--) {
		//미세먼지 확산
		spread();

		//공기청정기 (위)
		int wind_dy[] = { 0,-1,0,1 };
		int wind_dx[] = { 1,0,-1,0 };
		operate(v[0], wind_dy,wind_dx);

		//공기청정기 (아래)
		int wind_dy_below[] = { 0,1,0,-1 };
		int wind_dx_below[] = { 1,0,-1,0 };
		operate(v[1], wind_dy_below, wind_dx_below);
	}

	//남아있는 미세먼지 양
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) {

				sum += a[i][j];
			}
		}
	}

	cout << sum << "\n";
}