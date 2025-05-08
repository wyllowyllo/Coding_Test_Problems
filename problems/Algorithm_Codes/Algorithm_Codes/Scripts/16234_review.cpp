#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[51][51];
int visited[51][51];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int day = 0;
bool flag = false;

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	int sum = a[y][x];
	vector<pair<int, int>> uni;
	uni.push_back({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			
			int diff =abs(a[ny][nx] - a[y][x]);
			if (diff<l || diff>r) continue;

			flag = true;
			sum += a[ny][nx];
			uni.push_back({ ny,nx });

			visited[ny][nx] = 1;
			q.push({ ny,nx });

		}
	}
	
	int v = sum / uni.size();

	//인구이동
	for (auto n : uni) {
		a[n.first][n.second] = v;
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {


		flag = false;
		memset(visited, 0, sizeof(visited));

		//시작지점 정하여 연합 생성
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j])
					bfs(i, j);
			}
		}

		if (!flag) break;

		day++;
	}

	cout << day << "\n";
}