#include <bits/stdc++.h>
using namespace std;

//----------------------------------My Solution ---------------------------------------
/*int n, p, r;
int root;
vector<int> adjList[51];
map<int, int> m; //����ȣ-�θ����ȣ

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
		//r�� �ڽĳ�� ��� ����
		DFS(r);

		//r�� �θ����� �ڽĸ�Ͽ��� r ����
		auto idx = find(adjList[m[r]].begin(), adjList[m[r]].end(), r);
		adjList[m[r]].erase(idx);

		//������� ���� ����
		Traversal(root);
	}
	
	cout << cnt << "\n";
}*/

//------------------------------------------------------------------------------------

//-------------------------------Solution 1-------------------------------------------
/*�� �ڵ忡���� �Է��� r��带 ��Ʈ�� �ϴ� ����Ʈ���� ������ �� ������� ������ Ž���ϴ� ����̾�����
�� �ַ���� ������ �������� �ʰ�, ��Ʈ�κ��� Ʈ�� Ž���� �� �� r��� ����Ʈ���� �����ϴ� ������ Ž����*/

int n, r, temp, root;
vector<int> adj[54];


int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue; //r�� Ž������ ����
		ret += dfs(there);
		child++;
	}
	if (child == 0) return 1;//��������̸� 1��ȯ
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
	cout << dfs(root) << "\n"; //Ʈ������ Ư�� �κ��� Ž���ϴ� ���� -> �׻� ��Ʈ���� �����ϴ� ���� ����
}