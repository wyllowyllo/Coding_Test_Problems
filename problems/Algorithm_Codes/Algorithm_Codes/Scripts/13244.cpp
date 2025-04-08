#include <bits/stdc++.h>
using namespace std;



int t, n, m;
int a, b;
int visited[1004];
int cnt;
vector<int> adj[1004];

#pragma region MySol

bool isConnected;




int dfs(int idx) {
	if (adj[idx].size() == 0) {

		return 1;
	}

	visited[idx] = 1;

	int ret = 1;

	for (int i : adj[idx]) {
		if (visited[i]) continue;


		ret += dfs(i);
	}


	return ret;
}

void MySol() {
	cin >> t;

	while (t--) {
		cin >> n;
		cin >> m;


		isConnected = false;
		

		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
		

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);

		}

		// 1. 사이클이 형성된 노드가 있는가 ? 
		//트리라면(모든 노드가 연결되어있고, 사이클이 없는 그래프) edge의 개수는 노드의 개수-1이어야 함
		if (n != m + 1) { cout << "graph\n"; continue; }




		// 2. 모든 그래프가 연결되어 있는가? (dfs시 탐색한 노드 개수 == n)
		int cnt = dfs(a);

		if (cnt == n) isConnected = true;




		if (isConnected) cout << "tree\n";
		else cout << "graph\n";
	}
}


#pragma endregion

#pragma region Sol_1

void dfs2(int here) {

}
void Sol_1() {
	scanf("%d\n", &t);
	while (t--) {
		for (int i = 0; i < 1004; i++) adj[i].clear();

		cnt = 0;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			adj[b].push_back(a);
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}

		if (m == n - 1 && cnt == 1) puts("tree");//한번만에 모든 노드 방문함
		else {
			puts("graph");
		}

	}
}

#pragma endregion




int main() {
	
}