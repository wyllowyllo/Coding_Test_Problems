#include <bits/stdc++.h>
using namespace std;

int n, p, r;
int root;
vector<int> adjList[51];
map<int, int> m; //노드번호-부모노드번호

int cnt = 0;
void DFS(int node) {
	
	for (auto child : adjList[node]) {
		DFS(child);
	}
	adjList[node].clear();

	
}
void Traversal(int node) {
	if (adjList[node].size() == 0) {
		cnt++;
		return;
	}
	for (auto i : adjList[node])
		Traversal(i);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == -1) root = i;
		if (p != -1)
			adjList[p].push_back(i);
		m.insert({ i,p });
	}

	cin >> r;
	if (m[r] == -1) cnt = 0;
	else {
		//r의 자식노드 모두 제거
		DFS(r);

		//r의 부모노드의 자식목록에서 r 제거
		auto idx = find(adjList[m[r]].begin(), adjList[m[r]].end(), r);
		adjList[m[r]].erase(idx);

		Traversal(root);
	}
	
	cout << cnt << "\n";
}