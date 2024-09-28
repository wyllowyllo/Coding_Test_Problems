#include <bits/stdc++.h>
using namespace std;



//--------------------------------------------My Solution 1------------------------------------------------------
//주어진 문제에 대한 전체 트리를 만들고, 해당 트리를 DFS하면서 답안 도출하는 방식
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
//		//0 또는 1으로만 이루어져있는지 검사, 섞여있으면 4개로 분리
//		int sum = 0;
//		for (int i = LT.second; i < RB.second; i++) {
//			for (int j = LT.first; j < RB.first; j++) {
//				sum += m[i][j];
//			}
//		}
//
//		if (sum == 0 || sum == n * n) return;
//
//		//분할
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
//트리 일일히 만들지 말고, Divide_and_Conquer 방식으로 해결해보기
//char m[70][70];
//int n;
//
//string Compression(pair<int, int> startXY,int size) {
//	string ret="";
//
//	//재귀호출할땐 기저조건 먼저 설정하기 !! (처음 코드 작성할때 빼먹음)
//	if (size == 1) {
//		ret += m[startXY.second][startXY.first];
//		return ret;
//	}
//	
//	char c = m[startXY.second][startXY.first];
//	//맵 검사
//	for (int i = startXY.second; i < startXY.second+size; i++) {
//		for (int j = startXY.first; j < startXY.first+size; j++) {
//			//0과 1이 섞여있는 경우 -> 4개로 분할하여, 분할된 맵에서 각각 압축값을 얻어 합치면 본래 맵의 압축코드가 됨 -> Divide and Conquer!
//			if (c != m[i][j]) {
//				ret += '(';
//				ret += Compression(startXY, size / 2); //왼쪽위
//				ret += Compression({startXY.first+(size/2), startXY.second}, size / 2); //오른쪽 위
//				ret += Compression({ startXY.first , startXY.second+(size/2) }, size / 2); //왼쪽 아래
//				ret += Compression({ startXY.first+(size/2), startXY.second+(size/2) }, size / 2); //오른쪽 아래
//				ret += ')';
//				return ret;
//			}
//		}
//	}
//
//	//0또는 1로만 이루어진 경우
//	ret += c;
//	return ret;
//}
//int main() {
//	cin >> n;
//	string input;
//
//	//map 초기화
//	for (int i = 0; i < n; i++) {
//		
//		cin >> input;
//		for (int j = 0; j < n; j++) {
//			m[i][j] = input[j];
//		}
//	}
//
//	//recursion을 통해 압축코드 생성, 결과값 출력
//	cout << Compression({ 0,0 }, n) << "\n";
//
//}

//----------------------------------------------------------------------------------

int n;
string s;
char a[101][101];

string quard(int y, int x, int size) {
	if (size == 1) return string(1, a[y][x]); //string생성 함수(사이즈, 초기화할 값)

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

