#include <bits/stdc++.h>
using namespace std;

int n, g;
int a[11][11];
int visited[11][11];
int ret=2000001;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int cal(pair<int,int> p) {
	int cost = a[p.first][p.second];

	for (int k = 0; k < 4; k++) {
		int y = p.first + dy[k];
		int x = p.second + dx[k];
		cost += a[y][x];
	}

	return cost;
}
void combi(int idxY, int idxX, vector<pair<int,int>> v) {
	if (v.size() == 3) {
		int sum = 0;
		for (auto p : v) {
			sum += cal(p);
		}
		ret = min(ret, sum);

		return;
	}

	for (int i = idxY; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
			if (visited[i][j]) continue;

			bool flag = false;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (visited[y][x]) { flag = true; break; }
			}

			if (flag) continue;
			else {
				visited[i][j] = 1;
				visited[i-1][j] = 1;
				visited[i][j+1] = 1;
				visited[i+1][j] = 1;
				visited[i][j-1] = 1;
				v.push_back({ i,j });

				combi(i, j, v);

				visited[i][j] = 0;
				visited[i - 1][j] = 0;
				visited[i][j + 1] = 0;
				visited[i + 1][j] = 0;
				visited[i][j - 1] = 0;
				v.pop_back();
			}
		}
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g;
			a[i][j] = g;
		}
	}

	vector<pair<int, int>> v;
	combi(0, 0, v);
	cout << ret << "\n";
}