#include <bits/stdc++.h>
using namespace std;

int N, M;
const int max_v = 101;
int m[max_v][max_v];
int visited[max_v][max_v];
pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} }; //��, ������, �Ʒ�, ����


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
	//�׷������� Connected Component���� ã�� ������ DFS�� �̿��Ͽ� �ذ��� �� �ִ�!
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	int ret = 0;

	//��ü ��(�׷���)�� �� vertex�� �������� DFS�Ͽ� connected graph�� ã�´�!
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