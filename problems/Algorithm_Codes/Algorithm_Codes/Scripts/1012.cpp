#include <bits/stdc++.h>
#include "string"
using namespace std;

const int max_v=50;
int inputM[max_v][max_v];
int visited[max_v][max_v];
pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} };
int t,n,m,k;
int y, x;


//------------------------My Solution ----------------------------------------
void DFS(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visited[ny][nx] || !inputM[ny][nx]) continue;
		DFS(ny, nx);
	}
}
int main() {
	cin >> t;
	while (t--) {
		int ret = 0;
		memset(inputM, 0, sizeof(inputM));
		memset(visited, 0, sizeof(visited));
		cin >> m >> n >> k;

		
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			inputM[y][x] = 1;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && inputM[i][j]) {
					ret++; DFS(i, j);
				}
					
			}
		}

		cout << ret << "\n";
	}

//---------------------------------------------------------------------

//------------------------Solution 1----------------------------------
	cin >> t;
	int ret;
	while (t--) {
		fill(&inputM[0][0], &inputM[0][0] + 51 * 51, 0); //초기화(첫째주소, 마지막주소+1, 초기화할 값)
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			inputM[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (inputM[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
					ret++;
				}
			}
		}
		cout << ret << "\n";
	}

}