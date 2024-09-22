#include <bits/stdc++.h>
using namespace std;

int N, M;
const int max_v = 101;
int m[max_v][max_v];
int visited[max_v][max_v];
pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} }; //위, 오른쪽, 아래, 왼쪽


void DFS(int y, int x) {
	cout << y << " : " << x << '\n';
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;

		if (ny < 0 || ny >= N || nx < 0 || nx >= M || !m[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main(){

	//----------------------My  Solution --------------------------------------------
	//그래프에서 Connected Component들을 찾는 문제는 DFS를 이용하여 해결할 수 있다!
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	int ret = 0;

	//전체 맵(그래프)의 각 vertex를 기점으로 DFS하여 connected graph를 찾는다!
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 1 && !visited[i][j]) {
				ret++; DFS(i, j);
			}
		}
	}
	cout << ret << '\n';


	//--------------------------------------------------------------------------------
}