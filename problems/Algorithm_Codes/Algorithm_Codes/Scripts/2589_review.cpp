#include <bits/stdc++.h>
using namespace std;

char a[51][51];
int visited[51][51];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


vector<pair<int,int>> lands;

int w, h;
int ret;

void BFS(int y, int x) {

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;

	int ny; int nx;
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		ret = max(ret, visited[y][x] - 1);

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (visited[ny][nx]||a[ny][nx]=='W') continue;

			visited[ny][nx] = visited[y][x] + 1;
			
			q.push({ ny,nx });
		}
	}

	

}
int main() {

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') lands.push_back({ i,j });
		}
	}

	for (auto pos : lands) {
		memset(visited, 0, sizeof(visited));
		BFS(pos.first, pos.second);
	}

	cout << ret << "\n";

}