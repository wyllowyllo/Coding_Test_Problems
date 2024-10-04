#include <bits/stdc++.h>
using namespace std;

//---------------------------------My Solution------------------------------------------------
/*
int inputMap[8][8];
int copyMap[8][8];
int visited[8][8];
pair<int, int> wallList[64]; int idx = 0;
pair<int, int> dist[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} };

int n, m;

void DFS(int y, int x) {
	visited[y][x] = 1;
	copyMap[y][x] = 2;

	for (int i = 0; i < 4; i++) {
		int ny = y + dist[i].first;
		int nx = x + dist[i].second;

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (copyMap[ny][nx] != 0 || visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> inputMap[i][j];
			if (inputMap[i][j] == 0) wallList[idx++] = { i,j };
		}
	}

		

		vector<tuple<int,int,int>> list;
		//벽 3개 세우기
		for (int i = 0; i < idx-2; i++) {
			for (int j = i + 1; j < idx - 1; j++) {
				for (int k = j + 1; k < idx; k++) {
					list.push_back({ i,j,k });
				}
			}
		}

		int max_size = 0;
		for (auto pos : list) {

			copy(&inputMap[0][0], &inputMap[0][0] + 8 * 8, &copyMap[0][0]);

			int idx1, idx2, idx3;
			tie(idx1, idx2, idx3) = pos;
			copyMap[wallList[idx1].first][wallList[idx1].second] = 1;
			copyMap[wallList[idx2].first][wallList[idx2].second] = 1;
			copyMap[wallList[idx3].first][wallList[idx3].second] = 1;

			fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);

			//바이러스 전파
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (copyMap[i][j] == 2 && !visited[i][j])
						DFS(i, j);
				}
			}

			//안전구역 크기 계산
			int size = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (copyMap[i][j] == 0)
						size++;
				}
			}
			max_size = max(max_size, size);
		}
		
		
		cout << max_size << "\n";

}*/
//-------------------------------------------------------------------------------------

//-------------------------------Solution 1-----------------------------------------
int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> virusList, wallList;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx]==1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}
int solve() {
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (pair<int, int> b : virusList) {
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			//바이러스, 벽 위치 좌표 각각 기록
			if (a[i][j]==2) virusList.push_back({ i,j }); 
			if (a[i][j] == 1) wallList.push_back({ i,j });
		}
	}

	//벽 설치 가능한 위치 중 3개 뽑음(조합) -> 해당 위치에 벽 설치
	for (int i = 0; i < wallList.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[wallList[i].first][wallList[i].second] = 1;
				a[wallList[j].first][wallList[j].second] = 1;
				a[wallList[k].first][wallList[k].second] = 1;
				ret = max(ret, solve());

				//다시 원상복구
				a[wallList[i].first][wallList[i].second] = 0;
				a[wallList[j].first][wallList[j].second] = 0;
				a[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}

	cout << ret << "\n";
}