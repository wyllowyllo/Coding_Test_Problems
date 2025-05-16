#include <bits/stdc++.h>
using namespace std;

int n;
int a[21][21];

int ret = 0;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int visited[21][21];

#pragma region  MySol
void move(int row, int col, pair<int, int> dir) {
	if (a[row][col] == 0) return;
	int y = row; int x = col;
	while (true) {
		int ny = y + dir.first;
		int nx = x + dir.second;

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
		if (!a[ny][nx]) {
			a[ny][nx] = a[y][x];
			a[y][x] = 0;
		}
		else {
			if (a[ny][nx] != a[y][x]) break;
			else if (a[ny][nx] == a[y][x] && visited[ny][nx]) break;
			else {
				a[ny][nx] *= 2;
				a[y][x] = 0;
				visited[ny][nx] = 1;
				ret = max(ret, a[ny][nx]);
				break;
			}
		}

		y = ny;
		x = nx;
	}
}
void scan(pair<int, int> dir) {
	memset(visited, 0, sizeof(visited));

	if (dir.first == -1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				move(i, j, dir);
			}
		}
	}
	else if (dir.first == 1) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				move(i, j, dir);
			}
		}
	}
	else if (dir.second == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				move(i, j, dir);
			}
		}
	}
	else if (dir.second == -1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				move(i, j, dir);
			}
		}
	}


}

void go(int cnt) {

	if (cnt == 5) {
		//Print(dirV);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int dirY = dy[i]; 	int dirX = dx[i];
		int b[21][21];
		copy(&a[0][0], &a[0][0] + 21 * 21, &b[0][0]);
		scan({ dirY,dirX });


		go(cnt + 1);


		copy(&b[0][0], &b[0][0] + 21 * 21, &a[0][0]);
	}
}
void MySol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			ret = max(ret, a[i][j]);
		}
	}


	go(0);
	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1




void Rotate90(vector<vector<int>>& key) {
	
	vector<vector<int>> tmp(n, vector<int>(n,0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = key[n - j - 1][i];
		}
	}

	key = tmp;

}

void moveLeft(vector<vector<int>> &board) {
	for (int i = 0; i < n; i++) {
		vector<int> line;

		for (int j = 0; j < n; j++) {
			if (board[i][j]) line.push_back(board[i][j]);//0이 아닌 블록만 추출
		}

		//연속된 같은 값끼리 한번만 합치기
		vector<int> merged;
		for (int j = 0; j < line.size(); j++) {
			if (j+1<line.size() && line[j] == line[j + 1]) {
				merged.push_back(line[j] * 2);
				ret = max(ret, line[j] * 2);
				j++; //다음 값은 스킵
			}
			else {
				merged.push_back(line[j]);
				ret = max(ret, line[j]);
			}
		}

		//합쳐진 값들로 다시 왼쪽 채우고, 나머지 0으로

		for (int j = 0; j < n; j++) {
			board[i][j] = (j < merged.size() ? merged[j] : 0);
		}
	}
}
void dfs(int depth, vector<vector<int>> board) {
	if (depth == 5) return;

	for (int i = 0; i < 4; i++) {

		auto tmpBoard = board;

		//필요한 만큼 회전
		for (int r = 0; r < i; r++) {
			Rotate90(tmpBoard);
		}

		//좌측으로 밀기
		moveLeft(tmpBoard);


		dfs(depth + 1, tmpBoard);
	}
}
void Sol_1() {
	cin >> n;
	
	vector<vector<int>>board(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			ret = max(ret, board[i][j]);
		}
	}

	dfs(0, board);
	cout << ret << "\n";


}
#pragma endregion


int main() {
	Sol_1();
}