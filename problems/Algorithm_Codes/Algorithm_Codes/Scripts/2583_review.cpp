#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int a[101][101];
int visited[101][101];

int lx, ly, rx, ry;
int cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

#pragma region MySol
//범위 정하는 것이 헷갈려서 오래걸림
//왼쪽아래 좌표는 포함, 오른쪽 위 좌표는 미포함

vector<int> sizes;

void DFS(int y, int x, int* size) {
	visited[y][x] = 1;
	*(size) += 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (a[ny][nx] == 1 || visited[ny][nx]) continue;
		DFS(ny, nx, size);
	}
}

void MySol() {
	cin >> m >> n >> k;


	for (int i = 0; i < k; i++) {
		cin >> lx >> ly >> rx >> ry;

		for (int j = ly; j < ry; j++) {
			for (int k = lx; k < rx; k++) {
				a[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				int size = 0;
				DFS(i, j, &size);
				cnt++;
				sizes.push_back(size);
			}

		}
	}

	sort(sizes.begin(), sizes.end());

	cout << cnt << "\n";
	for (auto v : sizes)
		cout << v << " ";
	cout << "\n";
}

#pragma endregion

#pragma region Sol_1
vector<int >ret;

int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (a[ny][nx] == 1 || visited[ny][nx]) continue;
		ret += dfs(ny, nx);
	}

	return ret;
}

void Sol_1() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> lx >> ly >> rx >> ry;
		for (int x = lx; x < rx; x++) {
			for (int y = ly; y < ry; y++) {
				a[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1 && visited[i][j] == 0) {
				ret.push_back(dfs(i, j));
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int a : ret) cout << a << " ";
	
}
#pragma endregion




int  main() {
	

}