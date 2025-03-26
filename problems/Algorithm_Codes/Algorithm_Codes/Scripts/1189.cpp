#include <bits/stdc++.h>
using namespace std;


int r,  c,  k;

char a[6][6];
int visited[6][6];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int cnt = 0;

#pragma region MySol
void go(int y, int x, int dist) {

	if (dist > k) return;

	if (y == 0 && x == c - 1) {
		if (dist == k) {
			cnt++;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx] == 'T') continue;

		visited[ny][nx] = 1;
		go(ny, nx, dist + 1);
		visited[ny][nx] = 0;
	}
}

void MySol() {
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	visited[r - 1][0] = 1;
	go(r - 1, 0, 1);

	cout << cnt << "\n";
}

#pragma endregion

#pragma region Sol_1

//경우의 수는? '더하는'것이다
//이 풀이에서는 집으로 갈 수 있는 경우의 수를 구할 때, 재귀함수의 리턴값을 합산해서 총 경우의 수를 구함
//k거리로 목적지 도착할 수 있으면 1 반환, 없으면 0 반환
//최종적인 재귀함수의 반환값은 이들의 합이 되고, 이것이 곧 경우의 수가 된다

int go_2(int y, int x) {
	if (y == 0 && x == c - 1) {
		if (k == visited[y][x]) return 1;
		return 0;
	}

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T')continue;
		
		visited[ny][nx] = visited[y][x] + 1;
		ret += go_2(ny, nx);
		visited[ny][nx] = 0;
	}

	return ret;
}
void Sol_1() {
	string s;
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			a[i][j] = s[j];
		}
	}

	visited[r - 1][0] = 1;
	cout << go_2(r - 1, 0) << "\n";
}
#pragma endregion


int main() {
	

}