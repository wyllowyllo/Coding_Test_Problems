#include <bits/stdc++.h>
using namespace std;


/*

처음에 나도 이 문제를 볼때 이중 반복문으로 각 칸에 도달할 수 있는 경우의 수를 구해보려 했거든?
인접한 노드의 경우의 수를 더하는 방식으로 말이야. 근데 그렇게 순차적으로 구해버리면 모든 경로를 구할 수 없을거라 생각해서(예를들어 굽이굽이 돌아오는 경로는 놓침)
dfs방식으로 완전탐색하는 걸로 처음에 방향을 정했는데, 높이 기준으로 내림차순 정렬하면 그런 경우를 놓치지 않고 모두 구할 수 있나?
어째서 그런지 설명해주고, 이 문제를 봤을때 아, 내림차순 정렬해야겠다! 라는 생각으로 이어져야 하는 이유를 설명해봐.
*/
namespace MySol {

	/*
	각 칸을 하나의 노드로 보고,
	어떤 노드로 올 수 있는 경우의 수는 상하좌우로 인접한 노드들의 경우의 수를 합한 값이다
	*/
	typedef long long ll;
	int m, n;

	int a[501][501];
	int dp[501][501];

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	int go(int y, int x) {
		if (y == 0 && x == 0)return dp[0][0];

		int& ret = dp[y][x];
		if (ret != -1) return ret;

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (a[ny][nx] <= a[y][x]) continue;

			cnt += go(ny, nx);
		}

		return ret = max(cnt, 0);
	}



	void Sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));
		dp[0][0] = 1;


		cout << go(m - 1, n - 1) << "\n";
	}
}


namespace Sol {

	//높이 기준으로 내림차순 정렬 후 높은 지점에서 낮은 지점으로만 DP 값을 전파.

	/*
	왜 이 문제를 보자마자 "높이로 내림차순 정렬해야겠다!"라고 떠올릴 수 있어야 할까?
이 문제를 봤을 때 다음 두 가지 포인트를 반드시 확인해야 해:

한 방향성만 존재

높은 곳 → 낮은 곳으로만 이동 가능 (낮은 곳에서 높은 곳으로 이동 X)

사이클 없음 (DAG)

높은 곳에서 낮은 곳으로만 이동하므로, 절대 다시 높은 곳으로 올라가지 않음.

이 두 가지가 확인되면 즉시 이런 사고가 따라와야 해:

→ DAG 형태로 이동 규칙이 명확하다
→ 그렇다면 위상 정렬을 활용해서 DP로 쉽게 풀 수 있다
→ 높이를 이용해 정렬하면 자연스러운 위상 정렬이 된다!

이 논리적인 흐름을 떠올릴 수 있어야 이 문제를 쉽게 해결할 수 있게 돼.
	*/

	/*
	 1. 위상 정렬이란?
**위상 정렬 (Topological Sort)**은 다음 조건을 만족하는 그래프에서만 가능한 정렬 방식이야:

방향 그래프 (Directed Graph)

사이클이 없는 그래프 (Acyclic)
→ 그래서 "DAG (Directed Acyclic Graph)"에서만 위상 정렬이 가능해.

💡 위상 정렬의 정의:
"모든 간선 (u → v)에 대해, 정렬된 결과에서 u는 반드시 v보다 앞에 위치하도록 정렬하는 것"
	*/


	int m, n;
	int a[501][501];
	int dp[501][501];

	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	struct cell {
		int height;
		int y, x;

		cell(int height,int y, int x) {
			this->height = height;
			this->y = y;
			this->x = x;
		}
	};
	vector<cell> cells;

	void Sol() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
	
				cells.push_back(cell(a[i][j], i, j));
			}

		}

		//높이 순으로 내림차순 정렬
		sort(cells.begin(), cells.end(), [](cell a, cell b) {
			return a.height > b.height;
			});

		dp[0][0] = 1; 

		for (auto c : cells) {
			for (int i = 0; i < 4; i++) {
				int ny = c.y + dy[i];
				int nx = c.x + dx[i];

				if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

				// 다음 칸이 더 낮다면, 현재 칸에서 다음 칸으로 경로를 전파
				if (a[ny][nx] < a[c.y][c.x])
					dp[ny][nx] += dp[c.y][c.x];
			}
		}

		cout << dp[m - 1][n - 1] << "\n";
	}
}

int main() {
	
	Sol::Sol();
}