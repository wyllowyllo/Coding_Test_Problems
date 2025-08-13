#include <bits/stdc++.h>
using namespace std;

namespace My {
	int V, E, K;
	int u, v, w;
	int dist[20004];

	vector<pair<int, int>> adj[20004];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	const int INF = 1e9;

	void sol() {
		cin >> V >> E >> K;

		for (int i = 0; i < E; i++) {
			cin >> u >> v >> w;

			adj[u].push_back({ w,v });
		}

		fill(dist, dist + 20004, INF);
		dist[K] = 0;
		pq.push({ 0,K });

		while (pq.size()) {
			int cur_cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (dist[cur] != cur_cost) continue;

			for (auto there : adj[cur]) {

				if (dist[there.second] > cur_cost + there.first) {
					dist[there.second] = cur_cost + there.first;
					pq.push({ dist[there.second], there.second });
				}
			}
		}

		for (int i = 1; i <= V; i++) {
			if (dist[i] == INF) cout << "INF" << "\n";
			else cout << dist[i] << "\n";
		}
	}
}


namespace Sol {
	int V, E, K, u, v, w;
	vector<pair<int, int>> adj[20001];
	int dist[20001];


	const int INF = 987654321;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	void sol() {
		scanf("%d %d %d",& V, &E, &K);
		fill(dist, dist + 20001, INF);

		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(w, v));

		}

		pq.push(make_pair(0, K));
		dist[K] = 0;

		while (pq.size()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();

			if (dist[here] != here_dist) continue;

			for (pair<int, int> there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;

				if (dist[_there] > dist[here] + _dist) {
					dist[_there] = dist[here] + _dist;
					pq.push(make_pair(dist[_there], _there));
				}
			}

		}

		for (int i = 1; i <= V; i++) {
			if (dist[i] == INF) puts("INF");
			else printf("%d\n", dist[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	


}