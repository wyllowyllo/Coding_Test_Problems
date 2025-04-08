#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[21][21];

int ret = 1;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int visited[27];

#pragma region MySol

//첫번째 시도로 DFS, 두번째 시도로 BFS -> 모두 시간초과

//두번째 시도 : DFS로 하되, 알파벳 검사할 때 기존에는 인자로 vector넘겨줘서 반복문 돌려 비교했지만, 이번에는 하나의 visited 배열을 놓고 각 알파벳을 인덱스로 하여 검사
//성공!

void DFS(int y, int x, int depth) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[a[ny][nx] - 'A']) continue;

		visited[a[ny][nx] - 'A'] = 1;
		DFS(ny, nx, depth + 1);
		visited[a[ny][nx] - 'A'] = 0;
	}

	ret = max(ret, depth);
	return;
}

void MySol() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	DFS(0, 0, 1);


	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1

//이 문제의 시간복잡도? 2^26 ~ 3^ 26 
//각 위치에서 4방향으로 움직일 수 있지만, 이전 위치의 문자는 제외되므로, 대략 각 위치에서 2~3가지의 이동 선택지를 가질 것임
//알파벳 개수가 26개므로, 최대로 움직인다면 26칸을 움직임 -> 따라서 시간복잡도는 위와 같음

//그럼 시간복잡도가 너무 큰데.. 근데 문제를 보면 이건 완전탐색으로 풀어야 하는데...?
//그러나 완전탐색으로 풀어야 하므로, 완전탐색으로 푼다! (실제로 돌려보면 시간복잡도 위처럼 크진 않음)


void go(int y, int x, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		int next = (int)(a[ny][nx] - 'A');

		if (visited[next] == 0) {
			visited[next] = 1;
			go(ny, nx, cnt + 1);
			visited[next] = 0;
		}
	}
	return;
}
void Sol_1() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	visited[(int)a[0][0] - 'A'] = 1;
	go(0, 0, 1);
	cout << ret << '\n';
	return;
}


#pragma endregion

#pragma region MySol_2

//비트마스킹 활용하여 풀어보기

int b[21][21];
string s;

void go_2(int visited, int y, int x, int cnt) {

	if (visited & (1 << b[y][x] - 'A')) {
		ret = max(ret, cnt);
		return;
	}

	visited |= (1 << b[y][x] - 'A');
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];


		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		

		go_2(visited, ny, nx,cnt);
	}

}
void MySol_2() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++)
			b[i][j] = s[j];
	}


	go_2(0,0,0,0);
	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_2

void go_3(int y, int x, int num, int cnt) {
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		int _next = (1 << (int)(a[ny][nx] - 'A'));
		if ((num & _next) == 0) go_3(ny, nx, num | _next, cnt + 1);
	}

}
void Sol_2() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	go_3(0, 0, 1 << (int)a[0][0] - 'A', 1);
}

#pragma endregion




int main() {
	
	
}