#include <bits/stdc++.h>
using namespace std;

const int MAX=200004;
int n, k;

int visited[MAX];

int val;

void go(int idx) {
	visited[idx] = 1;
	queue<int> q;
	q.push(idx);

	while (q.size()) {
		idx = q.front(); q.pop();

		if (idx == k) {

			return;
		}

		for (int next : {idx + 1, idx - 1, idx * 2}) {
			if (next < 0 || next >= MAX) continue;

			
			if (next == idx * 2) val = visited[idx];
			else val = visited[idx] + 1;

			if (!visited[next] || visited[next] > val) {
				visited[next] = val;
				q.push(next);
			}
			
			

			
		}
	}
}

int main() {
	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		return 0;
	}

	go(n);
	cout << visited[k]-1 << "\n";

}