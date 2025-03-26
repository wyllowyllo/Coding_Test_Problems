#include <bits/stdc++.h>
using namespace std;

const int INF = 3000000;
int n;
int a[11][11];

int visited[11][11];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int ret=INF;

#pragma region MySol

bool check(int y, int x) {
	//y,x중심으로 4방향 검사
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
		if (visited[ny][nx]) return false;
	}

	return true;
}

int Cal() {
	int cost = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				cost += a[i][j];
			}
		}
	}

	return cost;
}
void plant(int cnt, int here) { //위치 3개 정하여 꽃 심기

	if (cnt == 3) {

		//비용 계산
		int cost = Cal();
		ret = min(ret, cost);
		return;
	}

	for (int i = here; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				visited[i][j] = 1;
				visited[i - 1][j] = 1;
				visited[i][j + 1] = 1;
				visited[i + 1][j] = 1;
				visited[i][j - 1] = 1;

				plant(cnt + 1, i);

				visited[i][j] = 0;
				visited[i - 1][j] = 0;
				visited[i][j + 1] = 0;
				visited[i + 1][j] = 0;
				visited[i][j - 1] = 0;
			}
		}
	}



}


void MySol() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}


	plant(0, 0);

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1
bool check_2(int y, int x) {
	if (visited[y][x]) return 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
			return 0;
		}
	}
		return 1;
}

int setFlower(int y, int x) {
	visited[y][x] = 1;
	int s = a[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		s += a[ny][nx];
	}

	return s;
}
void eraseFlower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}
void flower(int cnt, int hap) {
	if (cnt == 3) {
		ret = min(ret, hap);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check_2(i, j)) {
				flower(cnt + 1, hap + setFlower(i, j));

			}
		}
	}
}
void Sol_1() {
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	flower(0, 0);
	cout << ret;
}
#pragma endregion


int main() {
	
}