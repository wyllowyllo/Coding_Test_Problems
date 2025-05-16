#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
int a, b;

vector<int> adj[1001];
int visited[1001];
int start;

int go(int node) {
	int cnt = 1;
	for (int n : adj[node]) {
		if (visited[n]) continue;

		visited[n] = 1;
		cnt += go(n);
	}

	return cnt;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> m;

		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			start = a;
		}

		if (n - 1 != m) {
			cout << "graph\n";
			continue;
		}
		
	


		visited[start] = 1;
		int cnt=go(start);
		if (cnt == n) cout << "tree\n";
		else cout << "graph\n";

		
	}
}