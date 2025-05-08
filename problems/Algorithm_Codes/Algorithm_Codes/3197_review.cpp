#include <bits/stdc++.h>
using namespace std;

//분리집합을 물에 대해서만 적용했는데, 백조의 탐색 위치에 대해서도 적용해야 함
//백조가 있는 L위치도 결국 물이다! 이점을 유의 
//위 두 부분 다 처음 이 문제 풀었을때도 실수했던점임..
int r, c;
char a[1501][1501];
int visited[1501][1501];
int melt_visited[1501][1501];

queue<pair<int, int>> water;
queue<pair<int, int>> swan_s;

pair<int, int> swan;

int day;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

bool flag;

void move() {
	//memset(visited, 0, sizeof(visited));
	visited[swan_s.front().first][swan_s.front().second] = 1;
	queue<pair<int, int>> temp;


	int y; int x;
	while (swan_s.size()) {
		tie(y, x) = swan_s.front(); swan_s.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			if (a[ny][nx] == 'L') {
				flag = true;
				return;
			}
			if (a[ny][nx] == 'X') {
				temp.push({ ny,nx });//탐색실패지점 저장
				continue;

			}
			swan_s.push({ ny,nx });
		}
	}

	swan_s = temp;
}
void melt() {
	//memset(visited, 0, sizeof(visited));
	melt_visited[water.front().first][water.front().second] = 1;
	queue<pair<int, int>> temp;

	int y; int x;
	while (water.size()) {
		tie(y, x) = water.front(); water.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (melt_visited[ny][nx]) continue;

			melt_visited[ny][nx] = 1;
			if (a[ny][nx] == 'X') {
				a[ny][nx] = '.';
				temp.push({ ny,nx });

				continue;
			}
			//else if (a[ny][nx] == 'L') continue;

			water.push({ ny,nx });
		}
	}

	water = temp;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.' || a[i][j] == 'L') water.push({ i,j });
			if (a[i][j] == 'L') swan = { i,j };

		}
	}
	swan_s.push(swan);


	while (true) {

		move();
		if (flag) {
			cout << day << "\n";
			break;
		}

		melt();
		day++;
	}


}