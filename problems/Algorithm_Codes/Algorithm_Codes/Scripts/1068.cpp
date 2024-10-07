#include <bits/stdc++.h>
using namespace std;

//----------------------------------My Solution ---------------------------------------
/*int n, p, r;
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

		//리프노드 개수 세기
		Traversal(root);
	}
	
	cout << cnt << "\n";
}*/

//------------------------------------------------------------------------------------

//-------------------------------Solution 1-------------------------------------------
/*내 코드에서는 입력한 r노드를 루트로 하는 서브트리를 삭제한 후 리프노드 개수를 탐색하는 방식이었으나
이 솔루션은 삭제를 수행하지 않고, 루트로부터 트리 탐색을 할 때 r노드 서브트리를 제외하는 식으로 탐색함*/

int n, r, temp, root;
vector<int> adj[54];


int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue; //r은 탐색에서 제외
		ret += dfs(there);
		child++;
	}
	if (child == 0) return 1;//리프노드이면 1반환
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	cin >> r;
	if (r == root) {
		cout << 0 << "\n";
		return 0;
	}
	cout << dfs(root) << "\n"; //트리에서 특정 부분을 탐색하는 문제 -> 항상 루트에서 시작하는 것이 좋다
}