#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100001];
int path[100001];
int main() {
	cin >> n >> k;

	if (n == k) {
		cout << 0 << '\n' << n;
		return 0;
	}

	queue<int> q;
	visited[n] = 1;
	q.push(n);

	memset(path, -1, sizeof(path));
	
	while (q.size()) {
		int pos = q.front(); q.pop();
		
		if (pos == k) {
			cout << visited[k]-1 << "\n";
			vector<int> v;
			int n = path[k];
			v.push_back(k);

			while (n != -1) {
				v.push_back(n);
				n = path[n];
			}
			reverse(v.begin(), v.end());
			for (int i : v) cout << i << " ";

			return 0;
		}

		for (int next : {pos + 1, pos - 1, pos * 2}) {
			if (next < 0 || next >= 100001) continue;
			if (visited[next]) continue;


			visited[next] = visited[pos] + 1;
			path[next] = pos;
			q.push(next);
		}
	}
}