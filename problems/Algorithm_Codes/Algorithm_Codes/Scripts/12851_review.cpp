#include <bits/stdc++.h>
using namespace std;

int n,k;
int visited[100001];
int way[100001];


void bfs(int pos) {
	visited[pos] = 1;
	way[pos] = 1;
	
	queue<int> q;
	


	q.push(pos);
	

	while (q.size()) {
		pos = q.front(); q.pop();

		if (pos == k) {
		
			continue;
		}
		for (int np : {pos + 1, pos - 1, pos * 2}) {
			if (np < 0 || np>100000) continue;


			if (visited[np] && visited[np]<visited[pos]+1) continue;
			else if (visited[np] && visited[np] == visited[pos] + 1) {
				way[np]+=way[pos];
				continue;
			}

			visited[np] = visited[pos] + 1;
			way[np]=way[pos];
			
			q.push(np);
		}
	}
}
int main() {
	cin >> n >> k;

	bfs(n);

	cout << visited[k] - 1 << "\n";
	cout << way[k] << "\n";
}