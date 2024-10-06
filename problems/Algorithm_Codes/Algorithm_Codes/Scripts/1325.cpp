#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
vector<int> adjList[100001];
int visited[100001];

int DFS(int node) {
	visited[node] = 1;
	if (adjList[node].size() == 0) return 1;


	int ret = 1;
	for (int i : adjList[node]) {
		if(!visited[i])
			ret += DFS(i);
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[b].push_back(a);
	}

	int max_num = 0;
	map<int, int> comNumMap; //컴퓨터번호-해킹가능 컴퓨터수

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 100001, 0);
		int comNum = DFS(i);
		comNumMap[i] = comNum;
		max_num = max(max_num, comNum);
	}

	for (auto i : comNumMap) {
		if (i.second == max_num)
			cout << i.first << " ";
	}


}