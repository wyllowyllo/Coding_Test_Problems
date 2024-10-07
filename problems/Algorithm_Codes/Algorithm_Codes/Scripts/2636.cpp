#include <bits/stdc++.h>
using namespace std;

//----------------------------------My Solution ----------------------------------//
/*int m[100][100];
int visited[100][100];
pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} };
int w, h;
int t = 0;
int remainCheese=0; //전부 녹기 1시간전 치즈 개수 저장
vector<pair<int, int>> emptyPos;

void DFS(int y, int x, vector<pair<int,int>>* v,bool* isAir) {

	visited[y][x] = 1;
	v->push_back({ y,x });

	//이 connected graph가 바깥(맵 테두리)와 맞닿아있는지 체크
	if (!(*isAir) && (y == 0 || y == h - 1 || x == 0 || x == w - 1)) *isAir = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (m[ny][nx] != 0 || visited[ny][nx]) continue;
		DFS(ny, nx, v,isAir);
	}
}

void removeCheese(int y,int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (m[ny][nx] == 1) {
			m[ny][nx] = 0;
			emptyPos.push_back({ ny,nx });
		}
			
	}
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) emptyPos.push_back({ i,j });
			
		}
	}

	while (1) {
		if (emptyPos.size() == h * w) break;

		fill(&visited[0][0], &visited[0][0] + (100 * 100), 0);

		remainCheese = (w * h) - emptyPos.size();

		//0에 대해 conneted graph 찾고, 만약 그 0의 connected graph가 바깥과 맞닿아 있고 c와 맞닿아 있을 때 그 맞닿아있는 c를 제거
		vector<pair<int, int>> connectedGraph[10000];
		bool isGraphOutside[10000];
		int cnt = 0;
		for (auto pos : emptyPos) {
			bool isAir = false;
			if (!visited[pos.first][pos.second]) {
				DFS(pos.first, pos.second, &connectedGraph[cnt],&isAir);
				isGraphOutside[cnt]=isAir;
				cnt++;
			}
				
		}

		for (int i = 0; i < cnt; i++) {
			//0의 connected graph가 외부와 맞닿아있는 경우, 해당 connected graph와 접촉한 치즈를 제거
			if (isGraphOutside[i]) {
				for (auto node : connectedGraph[i])
					removeCheese(node.first, node.second);
			}
		}

		t++; //다 녹을 때까지 걸리는 시간 기록
	}

	cout << t << "\n";
	cout << remainCheese << "\n";
}*/

//------------------------------------------------------------------------------------

//----------------------------Solution 1----------------------------------------------
/*내 코드의 경우 맵의 0인 위치 전부들 대상으로  해당 지점에서 시작해서 connected graph 생성
 만약 그 connectedgraph가 외곽과 맞닿아 있는 경우에, 그 그래프의 노드 전부들 다시 탐색해서
 그 노드 상하좌우로 치즈가 있을경우 그 치즈를 지우는 식으로 함.
 그러나 이 코드에서는 애초에 최외곽지점 하나에서 dfs 시작하므로 connected graph를 찾는 dfs도 한번만 수행 -> 훨씬 효율적!*/
int a[104][104], visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int n, m, cnt, cnt2;
vector <pair<int, int>>v;

void go(int y, int x) {
	visited[y][x] = 1;

	//탐색 중 치즈 만났다면 -> 공기에 접촉된 치즈이므로 지워야 함 -> v에 추가
	if (a[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
		go(ny, nx);
	}
}
int main() {
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();

		go(0, 0);
		cnt2 = v.size(); //남아있는 치즈개수
		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0; //치즈 녹이기
		}

		bool flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) flag = 1;
			}
		}
		cnt++;
		if (!flag) break; //전부 다 0이면 탈출
	}

	cout << cnt << '\n' << cnt2 << '\n';

}



