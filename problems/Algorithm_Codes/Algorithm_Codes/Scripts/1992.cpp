#include <bits/stdc++.h>
using namespace std;



//--------------------------------------------My Solution 1------------------------------------------------------
//�־��� ������ ���� ��ü Ʈ���� �����, �ش� Ʈ���� DFS�ϸ鼭 ��� �����ϴ� ���
// int m[70][70];

//class node {
//private:
//	int n;
//	pair<int, int> LT;
//	pair<int, int> RB;
//
//public:
//	vector<node*> child;
//	node(int n,pair<int, int> leftTop, pair<int, int> rightBottom)
//	{
//		this->n = n;
//		this->LT = leftTop;
//		this->RB = rightBottom;
//
//		Divide();
//	};
//
//	void Divide()
//	{
//		if (n < 2) return;
//
//		//0 �Ǵ� 1���θ� �̷�����ִ��� �˻�, ���������� 4���� �и�
//		int sum = 0;
//		for (int i = LT.second; i < RB.second; i++) {
//			for (int j = LT.first; j < RB.first; j++) {
//				sum += m[i][j];
//			}
//		}
//
//		if (sum == 0 || sum == n * n) return;
//
//		//����
//		child.push_back(new node(n / 2, LT, { LT.first + n / 2, LT.second + n / 2 }));
//		child.push_back(new node(n / 2, { LT.first + n / 2, LT.second }, { RB.first, LT.second + n / 2 }));
//		child.push_back(new node(n / 2, { LT.first, LT.second + n / 2 }, { LT.first + n / 2, RB.second }));
//		child.push_back(new node(n / 2, { LT.first + n / 2, LT.second + n / 2 }, RB));
//	}
//
//	int GetV() {
//		return m[LT.second][LT.first];
//	}
//		
//
//};
//
//
//node* root = NULL;
//
//void DFS(node* n) {
//	
//
//	if (n->child.size()) {
//		cout << "(";
//		for (int i = 0; i < 4; i++) {
//			DFS(n->child[i]);
//		}
//		cout << ")";
//	}
//	else {
//		cout << n->GetV();
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	string inputLine;
//	for (int i = 0; i < n; i++) {
//		cin >> inputLine;
//
//		for (int j = 0; j < inputLine.size(); j++) {
//			m[i][j] = inputLine[j]-'0';
//		}
//	}
//
//	root = new node(n,{ 0,0 }, { n ,n});
//	DFS(root);
//}

//---------------------------------------------------------------------------------------------------

//-----------------------------------------My Solution 2--------------------------------------------
//Ʈ�� ������ ������ ����, Divide_and_Conquer ������� �ذ��غ���
//char m[70][70];
//int n;
//
//string Compression(pair<int, int> startXY,int size) {
//	string ret="";
//
//	//���ȣ���Ҷ� �������� ���� �����ϱ� !! (ó�� �ڵ� �ۼ��Ҷ� ������)
//	if (size == 1) {
//		ret += m[startXY.second][startXY.first];
//		return ret;
//	}
//	
//	char c = m[startXY.second][startXY.first];
//	//�� �˻�
//	for (int i = startXY.second; i < startXY.second+size; i++) {
//		for (int j = startXY.first; j < startXY.first+size; j++) {
//			//0�� 1�� �����ִ� ��� -> 4���� �����Ͽ�, ���ҵ� �ʿ��� ���� ���ప�� ��� ��ġ�� ���� ���� �����ڵ尡 �� -> Divide and Conquer!
//			if (c != m[i][j]) {
//				ret += '(';
//				ret += Compression(startXY, size / 2); //������
//				ret += Compression({startXY.first+(size/2), startXY.second}, size / 2); //������ ��
//				ret += Compression({ startXY.first , startXY.second+(size/2) }, size / 2); //���� �Ʒ�
//				ret += Compression({ startXY.first+(size/2), startXY.second+(size/2) }, size / 2); //������ �Ʒ�
//				ret += ')';
//				return ret;
//			}
//		}
//	}
//
//	//0�Ǵ� 1�θ� �̷���� ���
//	ret += c;
//	return ret;
//}
//int main() {
//	cin >> n;
//	string input;
//
//	//map �ʱ�ȭ
//	for (int i = 0; i < n; i++) {
//		
//		cin >> input;
//		for (int j = 0; j < n; j++) {
//			m[i][j] = input[j];
//		}
//	}
//
//	//recursion�� ���� �����ڵ� ����, ����� ���
//	cout << Compression({ 0,0 }, n) << "\n";
//
//}

//----------------------------------------------------------------------------------

int n;
string s;
char a[101][101];

string quard(int y, int x, int size) {
	if (size == 1) return string(1, a[y][x]); //string���� �Լ�(������, �ʱ�ȭ�� ��)

	char b = a[y][x];
	string ret = "";

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != a[i][j]) {
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y+size/2, x, size / 2);
				ret += quard(y+size/2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}

	return string(1, a[y][x]);
}

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	cout << quard(0, 0, n) << "\n";
}

