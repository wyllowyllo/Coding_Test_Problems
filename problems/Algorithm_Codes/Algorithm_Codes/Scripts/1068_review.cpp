#include <bits/stdc++.h>
using namespace std;

int parent;
int del;
int cnt = 0;

vector<int> l[50];


map<int, int> m; //노드,부모노드

vector<int> deletedNodes;


int n, r, temp, root;
vector<int> adj[54];

#pragma region MySol

//문제 실패 이유 : 트리의 루트가 항상 0번이라고 가정해버림..
//첫번째 입력이 -1이 아닐수도 있다(첫번째 노드가 루트노드가 아닐수도있다). 탐색은 루트노드부터 시작해야하므로, 어느노드가 루트노드인지를 알아야한다.
// 위 이유로 실패함 하... 예제만 보고 섣부른 판단 하지말라 
//더빡치는건 옛날에도 똑같은 이유로 실패함...(다 잘해 놓고 마지막에 리프노드 탐색할 때 그냥 Tranvel(0)이런식으로 시작을 0번부터 시작함...0번이 루트라는 보장이 없는데)




void Travel(int startNode) {
	for (int v : l[startNode]) {
		deletedNodes.push_back(v);
		Travel(v);
	}
}



void findLeaf(int startNode) {

	if (l[startNode].size() == 0) {
		cnt++;
		return;
	}

	for (int v : l[startNode]) {
		findLeaf(v);
	}

}



void MySol() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent != -1) l[parent].push_back(i);
		else root = i; //루트노드 설정

		m[i] = parent;
	}

	cin >> del;

	if (del==root) cout << 0 << "\n"; //0번째 노드의 부모 노드가 -1이 아닐수도 있다.
	else {



		temp = m[del]; //지울 노드의 부모노드


		deletedNodes.push_back(del);
		Travel(del); //삭제할 노드 하위의 모든 노드 삭제

		for (int node : deletedNodes)
			l[node].clear();

		for (int i = 0; i < l[temp].size(); i++)
			if (l[temp][i] == del)
				l[temp].erase(l[temp].begin() + i);





		//리프 노드는 어떻게 구함?
		//리스트를 쭉 따라갔을 때 자식이 없으면 리프 노드이다
		findLeaf(root);

		cout << cnt << "\n";

	}
}
#pragma endregion

#pragma region Sol_1

//트리를 탐색할 때는, 항상 루트 노드부터 시작해서 탐색해야 한다.
//나는 첫번째로 입력받는 값이 -1이라 가정해버림(예시에서 그렇게 나와서..) -> 그러나 -1이 언제 입력될지는 알수 없다
//따라서 0번째 노드를 루트노드로 가정하면 안된다.
//-1이 입력될 때, 그 노드가 루트노드가 된다




int dfs(int here) {
	int ret = 0;
	int child = 0;

	for (int there : adj[here]) {
		if (there == r) continue; //지운 노드인 경우 pass
		ret += dfs(there);
		child++;
	}

	if (child == 0) return 1; //하위 노드가 없는 경우임. 자신이 리프인 경우
	return ret;
}

void Sol_1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}

	cin >> r;
	if (r == root) {
		cout << 0 << "\n"; return;
	}
	
	cout << dfs(root) << "\n"; //탐색 시 반드시 루트부터 시작!!
	return;
}

#pragma endregion



int main() {
	//Sol_1();
	
	MySol();
}