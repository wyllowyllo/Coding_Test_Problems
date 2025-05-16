#include <bits/stdc++.h>
using namespace std;

#define y1 MINGWAN

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
char a[301][301];
int visited[301][301];

int n, m;
int x1, y1, x2, y2;
bool flag;

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];


			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			if (a[ny][nx] == '#') {
				flag = true;
				break;
			}
			else if (a[ny][nx] == '1') {
				a[ny][nx] = '0';
				continue;
			}

			q.push({ ny,nx });
		}
	}

}

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	while (true) {

		if (flag) break;
		memset(visited, 0, sizeof(visited));
		cnt++;
		bfs(y1-1, x1-1);
		//Print();
	}

	cout << cnt << "\n";

}