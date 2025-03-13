#include <bits/stdc++.h>
using namespace std;

int w, h;
int a[100][100];
int visited[100][100];



int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

#pragma region MySol

int totalCheese = 0;
int hour = 0;

void DFS(int y, int x, int& cheeseSize) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (a[ny][nx] == 0 && !visited[ny][nx]) {
			DFS(ny, nx, cheeseSize);
		}
		else if (a[ny][nx]) {
			totalCheese--;
			cheeseSize++;
			a[ny][nx] = 0;
			visited[ny][nx] = 1;
		}
	}
}

void MySol() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];

			if (a[i][j]) totalCheese++;
		}
	}

	int cheeseCnt = 0;


	while (totalCheese > 0) {
		hour++;
		cheeseCnt = 0;

		memset(visited, 0, sizeof(visited));
		DFS(0, 0, cheeseCnt);




	}
	cout << hour << "\n" << cheeseCnt << "\n";
}
#pragma endregion

#pragma region Sol_1

vector<pair<int, int>> v;
int n, m, cnt, cnt2;

void go(int y, int x) {
	visited[y][x] = 1;
	if (a[y][x] == 1) { //dfs탐색 중 치즈 발견하면 위치 저장하고 탐색종료
		v.push_back({ y,x });
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
		go(ny, nx);
	}
}
void Sol_1() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
		v.clear();

		go(0, 0);
		cnt2 = v.size(); //녹는 치즈의 개수

		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0;
		}

		bool flag = 0; //치즈 남았는가?
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) flag = 1;
			}
		}

		cnt++;
		if (!flag) break;
	}

	cout << cnt << '\n' << cnt2 << '\n';
}
#pragma endregion


int main() {

	
}