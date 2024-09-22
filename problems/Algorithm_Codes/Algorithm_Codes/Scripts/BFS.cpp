#include <bits/stdc++.h>
using namespace std;

//--------------My Solution------------------
int inputMap[101][101];
queue<pair<int,int>> q;
int visited[101][101];

//-------------------------------------------

//--------------Solution 1------------------
const int max_n = 4;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m, a[max_n][max_n], visit[max_n][max_n], y, x, sy, sx, ey, ex;

//-------------------------------------------

int main() {

	//BFS 는 노드 간 가중치가 동일한 그래프에서 최단거리를 탐색할 때 많이 사용된다!(미로 최단경로 등)
	//-----------------------------------My Solution ----------------------------------------------------//
	pair<int, int> dir[4] = { {1,0},{0,1}, {-1,0}, {0,-1} }; //(y,x) 차례대로 위, 오른쪽, 아래, 왼쪽 방향

	int N, M;
	pair<int, int> startPos;
	pair<int, int> dstPos;
	cin >> N >> M;
	cin >> startPos.first >> startPos.second;
	cin >> dstPos.first >> dstPos.second;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> inputMap[i][j];
		}
	}

	q.push(startPos);
	visited[startPos.first][startPos.second] = 1;

	int nextX, nextY;
	while (q.size()) {
		auto prePos = q.front();
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			nextX = prePos.second + dir[i].second;
			nextY = prePos.first + dir[i].first;

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (visited[nextY][nextX] == 0 && inputMap[nextY][nextX] == 1) {
				q.push({ nextY, nextX });
				visited[nextY][nextX] = visited[prePos.first][prePos.second]+1;
			}
				
		}
	}

	cout << visited[dstPos.first][dstPos.second] << "\n";

	//-------------------------------------------------------------------------------------------------------//

	//-------------------------------------Solution 1---------------------------------------------------------
	cin >> n >> m;
	cin >> sy >> sx;
	cin >> ey >> ex;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	queue<pair<int, int>> q2;
	visit[sy][sx] = 1;
	q2.push({ sy,sx });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop(); //tie를 쓰면 pair나 tuple의 값을 한번에 끄집어 낼 수 있다!
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = visit[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	printf("%d\n", visit[ey][ex]);

	//------------------------------------------------------------------------------------------
}