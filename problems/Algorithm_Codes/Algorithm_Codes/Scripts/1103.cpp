#include <bits/stdc++.h>


using namespace std;


//vector<pair<int,int>> adj[51*51];


int n, m;
int a[51][51];
string s;

pair<int, int> dir[4] = { {-1,0}, {0,1},{1,0},{0,-1} };


int visited[51][51];
int dp[51][51];

int result = 0;
bool cycle;



namespace MySol {
	//입력받은 보드로부터, 보드의 각 칸을 하나의 노드라고 가정해서, 인접 그래프를 생성한다
	//인접 그래프의 각 노드를 시작점으로 하여 dfs 시 가장 depth가 깊은 것이 최대로 동전을 움직이는 횟수가 된다.
	//만약 dfs시 사이클을 발견한다면, 동전을 무한번 움직일 수 있는 경우일 것이다.

	//위 생각에 따라 로직 작성해봤는데, 미리 인접 그래프를 작성해서 거기서 dfs해버리면,
	//한 칸도 못가고 게임이 끝나는 경우(한 번만 움직여서 구멍에 빠지거나 판에 벗어나는 경우) 를 못 셈
	// 즉,  adjacency-list 생성부에서 “구멍이거나 범위를 벗어나면 무조건 무시”해 버리기 때문에, 그 끝내는(move) 동작이 아예 카운트에 포함되지 않음.

	//adj를 미리 뽑지 말고, dfs안에서 '구멍이거나 범위를 벗어나는 경우'에도 이동 횟수를 계산하는 식으로 고치면 됨
	//근데, 결국 이 방법 자체가 모든 경우의 수를 탐색하는 방법이고, 시간복잡도상 지수시간이라 불가능함(4^이동횟수)



	//void dfs(int y, int x, int cnt) {
//	
//	
//	ret = max(ret, cnt);
//
//	for (auto i : adj[y*m+x]) {
//		if (visited[i.first][i.second]) {
//			cout << -1 << "\n";
//			exit(0);
//		}
//
//		visited[i.first][i.second] = 1;
//		dfs(i.first, i.second, cnt+1);
//		visited[i.first][i.second] = 0;
//	}
//
//	return;
//}



	bool check(int y, int x) {
		if (y < 0 || y >= n || x < 0 || x >= m) return false;
		if (a[y][x] == -1) return false;

		return true;
	}


	void Try_1() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j] - '0';

			}
		}

		memset(dp, -1, sizeof(dp));
		////인접 그래프 생성
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {

		//		if (a[i][j] > 9) continue;

		//		int dist = a[i][j];

		//		for (auto d : dir) {
		//			int ny = i + d.first * dist;
		//			int nx = j + d.second * dist;

		//			if (check(ny, nx)) {
		//				adj[i * m + j].push_back({ny,nx});
		//			}
		//		}
		//	}
		//}

		////각 지점을 시작점으로 하여, dfs
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		if (a[i][j] > 9) continue;
		//		
		//		visited[i][j] = 1;
		//		dfs(i, j, 0);
		//		visited[i][j] = 0;
		//	}
		//}

		//
		//cout << ret << "\n";
	}



	//------------------------------------------------------------------------

	//dp[y][x] : (y,x)에서 출발했을 때 최대로 움직일 수 있는 횟수
	int go(int y, int x) {
		if (cycle) return 0;

		int& ret = dp[y][x];
		if (ret != -1) return ret;

		visited[y][x] = 1;
		int cnt = 0;

		int dist = a[y][x];

		for (auto d : dir) {
			int ny = y + d.first * dist;
			int nx = x + d.second * dist;

			if (!check(ny, nx)) {
				//구멍이거나 범위 벗어남
				cnt = max(cnt, 1);
				continue;
			}
			if (visited[ny][nx]) { //사이클 발견
				cycle = true;
				break;
			}


			cnt = max(cnt, go(ny, nx) + 1);

		}

		visited[y][x] = 0;

		return ret = cnt;
	}


	void Try_2() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'H')      a[i][j] = -1;
				else               a[i][j] = s[j] - '0';

			}
		}

		memset(dp, -1, sizeof(dp));
		
		result = go(0, 0);

		if (cycle) cout << -1 << "\n";
		else cout << result << "\n";
	}
}

namespace Sol {
	int t, a, d[54][54];
	string s;
	char b[54][54];
	bool check[54][54];
	const int dy[4] = { -1, 0, 1, 0 };
	const int dx[4] = { 0, 1, 0, -1 };

	bool in(int aa, int bb) {
		return (1 <= aa && aa <= t && 1 <= bb && bb <= a);
	}

	int down(int y, int x) {
		if (!in(y, x) || b[y][x] == 'H') return 0;
		if (check[y][x]) {
			cout << -1 << "\n";
			exit(0);
		}

		int& ret = d[y][x];
		if (ret) return ret;

		check[y][x] = 1;

		int value = (int)b[y][x] - '0';
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i] * value;
			int nx = x + dx[i] * value;

			ret = max(ret, down(ny, nx) + 1);
		}

		check[y][x] = 0;

		return ret;
	}


	void sol() {
		cin >> t >> a;
		for (int i = 1; i <= t; i++) {
			cin >> s;
			for (int j = 1; j <= a; j++) {
				b[i][j] = s[j - 1];
			}
		}

		cout << down(1, 1) << "\n";
	}
}






int main() {
	Sol::sol();
}