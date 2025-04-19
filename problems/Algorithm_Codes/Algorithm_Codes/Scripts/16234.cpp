#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[51][51];
int visited[51][51];

int dy[4] = { -1,0,1,0 }; int dx[4] = { 0,1,0,-1 };



#pragma region MySol

// connected Grapgh를 찾는 방식을 활용하여 연합을 생성할 국가들을 연결하고, 인원 재분배함
//탐색했을 때 connected graph가 생성되지 않을 때(모든 국가간 상호 인원차가 l 이상 r 이하가 아닐때) 반복문 탈출

int day = 0;
bool isMoveHappen = false;
vector<pair<int, int>>v;

void Move() {
	if (!isMoveHappen) isMoveHappen = true;

	int sum = 0;

	for (auto c : v) {
		sum += a[c.first][c.second];
	}
	int num = sum / v.size();

	for (auto c : v) {
		a[c.first][c.second] = num;
	}


}
void open(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;

		int people = abs(a[y][x] - a[ny][nx]);
		if (l <= people && people <= r) {
			v.push_back({ ny,nx }); //국경 오픈할 나라들을 push
			open(ny, nx);
		}
	}
}

void MySol() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {

		memset(visited, 0, sizeof(visited));
		v.clear();
		isMoveHappen = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i,j }); //국경 오픈할 나라들을 push

					open(i, j); //dfs로 connectedGraph 탐색하며 국경 오픈
					if (v.size() > 1) Move(); //인구 이동

				}
			}
		}

		if (!isMoveHappen) break;
		day++; //인구이동 발생 일수 증가
	}

	cout << day << "\n";
}
#pragma endregion


#pragma region Sol_1

int sum = 0;
int cnt = 0;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])continue;
		if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {

			visited[ny][nx] = 1;
			v.push_back({ ny,nx });
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
}

void Sol_1() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		bool flag = 0; //인구이동 발생 플래그 변수
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });

					sum = a[i][j];
					dfs(i, j);
					if (v.size() == 1) continue;

					for (pair<int, int> b : v) {
						a[b.first][b.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}

		if (!flag) break;
		cnt++;
	}

	cout << cnt << "\n";
}

#pragma endregion

int main() {
	

}