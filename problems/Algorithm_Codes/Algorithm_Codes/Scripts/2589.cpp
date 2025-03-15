#include <bits/stdc++.h>
using namespace std;

int h, w;
char a[51][51];

#pragma region MySol
vector<pair<int, int>> lands;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[51][51];

int ret = 0, result = 0;

//아시발 생각해보니까 이거 DFS잖아 병신아
//BFS로 하려면 큐로 해야지 재귀로 해버리면 DFS잖아
//최단거리 구하려면 인접한 노드 모두 방문하고 다음으로 넘어가는 식으로 해서 거리 갱신해야 한느데
//이렇게 하면 그냥 최대깊이까지 들어간다음 다음으로 넘어가잖아



void BFS(int y, int x) {

	visited[y][x] = 0; //시작위치

	queue<pair<int, int>> q;
	q.push({ y,x });
	int cy, cx;

	while (q.size()) {
		tie(cy, cx) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i]; int nx = cx + dx[i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (a[ny][nx] == 'W' || visited[ny][nx] != -1) continue;

			visited[ny][nx] = visited[cy][cx] + 1;
			ret = max(ret, visited[ny][nx]);
			q.push({ ny,nx });

		}
	}



}

void MySol() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];

			if (a[i][j] == 'L') lands.push_back({ i,j });
		}
	}

	for (auto pos : lands) {
		memset(visited, -1, sizeof(visited));
		ret = 0;

		BFS(pos.first, pos.second);

		result = max(result, ret);
	}

	cout << result << "\n";
}

#pragma endregion

#pragma region Sol_1

int mx;

void bfs2(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop(); //새로 y,x변수 만들지 않고 기존 매개변수 활용했네

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 'W')continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
			mx = max(mx, visited[ny][nx]);
		}
	}
}

void Sol_1() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 'L') bfs2(i, j);
		}
	}

	cout << mx - 1 << "\n";
}
#pragma endregion


int main() {

}