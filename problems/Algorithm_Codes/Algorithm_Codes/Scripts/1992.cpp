#include <bits/stdc++.h>
using namespace std;

int m[70][70];

class node {
private:
	int n;
	pair<int, int> LT;
	pair<int, int> RB;

public:
	vector<node*> child;
	node(int n,pair<int, int> leftTop, pair<int, int> rightBottom)
	{
		this->n = n;
		this->LT = leftTop;
		this->RB = rightBottom;

		Divide();
	};

	void Divide()
	{
		if (n < 2) return;

		//0 또는 1으로만 이루어져있는지 검사, 섞여있으면 4개로 분리
		int sum = 0;
		for (int i = LT.second; i < RB.second; i++) {
			for (int j = LT.first; j < RB.first; j++) {
				sum += m[i][j];
			}
		}

		if (sum == 0 || sum == n * n) return;

		//분할
		child.push_back(new node(n / 2, LT, { LT.first + n / 2, LT.second + n / 2 }));
		child.push_back(new node(n / 2, { LT.first + n / 2, LT.second }, { RB.first, LT.second + n / 2 }));
		child.push_back(new node(n / 2, { LT.first, LT.second + n / 2 }, { LT.first + n / 2, RB.second }));
		child.push_back(new node(n / 2, { LT.first + n / 2, LT.second + n / 2 }, RB));
	}

	int GetV() {
		return m[LT.second][LT.first];
	}
		

};


node* root = NULL;

void DFS(node* n) {
	

	if (n->child.size()) {
		cout << "(";
		for (int i = 0; i < 4; i++) {
			DFS(n->child[i]);
		}
		cout << ")";
	}
	else {
		cout << n->GetV();
	}
}

int main() {
	int n;
	cin >> n;
	string inputLine;
	for (int i = 0; i < n; i++) {
		cin >> inputLine;

		for (int j = 0; j < inputLine.size(); j++) {
			m[i][j] = inputLine[j]-'0';
		}
	}

	root = new node(n,{ 0,0 }, { n ,n});
	DFS(root);
}