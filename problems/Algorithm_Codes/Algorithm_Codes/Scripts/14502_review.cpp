#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

//bruteForce 방식으로 풀었음
//벽을 세우는 3개의 위치를 조합으로 구해 벽을 세운다음, 바이러스 dfs로 전파 -> 남은 위치 크기계산
int n, m;
int a[8][8];
vector<pair<int, int>> emptyPos;
int max_size = -1;

int dy[4] = { -1,0,1,0 }; int dx[4] = { 0,1,0,-1 };
int visited[8][8];
int wallCnt = 0;

void DFS(int y, int x, int& area) {
	visited[y][x] = 1;
	area++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (a[ny][nx] == 1 || visited[ny][nx]) continue;


		DFS(ny, nx, area);
	}
}

int Spread() {
	int area = 0;
	//바이러스 전파
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {


			if (a[i][j] == 2 && !visited[i][j]) {
				DFS(i, j, area);
			}
		}
	}

	return area;
}

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			//빈 공간은 따로 저장해둠
			if (a[i][j] == 0) emptyPos.push_back({ i,j });

			//벽 개수 저장
			if (a[i][j] == 1) wallCnt++;
		}
	}

	//3개의 벽을 먼저 세우고 (조합)

	for (int i = 0; i < emptyPos.size(); i++) {
		for (int j = i + 1; j < emptyPos.size(); j++) {
			for (int k = j + 1; k < emptyPos.size(); k++) {

				//3개의 벽 좌표
				pair<int, int> w1 = emptyPos[i];
				pair<int, int> w2 = emptyPos[j];
				pair<int, int> w3 = emptyPos[k];

				//벽 세우기
				a[w1.first][w1.second] = 1;
				a[w2.first][w2.second] = 1;
				a[w3.first][w3.second] = 1;

				//바이러스 전파
				int virusArea = Spread();


				//나머지 크기 구함
				int safeZone = (n * m) - virusArea - wallCnt - 3;
				max_size = max(safeZone, max_size);

				//맵 복구
				a[w1.first][w1.second] = 0;
				a[w2.first][w2.second] = 0;
				a[w3.first][w3.second] = 0;

				//초기화
				memset(visited, 0, sizeof(visited));
			}
		}
	}


	cout << max_size << "\n";

}
#pragma endregion




int main() {


	

	





}