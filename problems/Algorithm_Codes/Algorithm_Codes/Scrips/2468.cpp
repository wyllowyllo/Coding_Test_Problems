#include <bits/stdc++.h>
using namespace std;

const int max_v = 100;
int m[max_v][max_v];
int visited[max_v][max_v];
int n;
int max_height = -1;
int num = 0;
int ret = 0;

pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} };

//---------------------------My Solution --------------------------------
void DFS(int y, int x, const int height) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;
		if (height >=m[ny][nx]) continue;
		DFS(ny, nx,height);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (max_height < m[i][j]) max_height = m[i][j];
		}
	}

	//height별 connected graph 검사
	//반례 생각하기! : 아무곳도 물에 잠기지 않는 경우 (height=0인 경우) 고려하여 코드 재작성함
	for (int height = 0; height <= max_height; height++) {
		num = 0;
		fill(&visited[0][0], &visited[0][0] + max_v * max_v, 0);

		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && m[i][j]>height) {
					num++;
					DFS(i, j,height);
				}
					
			}
		}

		ret = max(ret, num);
	}

	cout << ret << "\n";

	//--------------------------------------------------------------
}