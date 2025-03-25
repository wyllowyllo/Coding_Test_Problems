#include <bits/stdc++.h>
using namespace std;

int k, n;


vector<int> v;

vector<int> ret[11];

int a[1030];

#pragma region MySol

//완전 이진 트리인 입력만 들어오므로, 재귀를 통해 절반씩 쪼개어 나간다
//각 단계에서의 mid 인덱스가 서브트리의 루트가 된다
//mid기준 왼쪽, 오른쪽에 대해 다시 탐색



void Print() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
}

void BS(int left, int right, int level) {

	if (left == right) {
		ret[level].push_back(v[left]);
		return;
	}

	int mid = (left + right) / 2;
	ret[level].push_back(v[mid]);

	//mid 중심 좌우로 분할
	BS(left, mid - 1, level + 1);
	BS(mid + 1, right, level + 1);

}

void MySol() {
	cin >> k;
	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> n;
		v.push_back(n);
	}
	BS(0, pow(2, k) - 2, 1);
	Print();
}
#pragma endregion


#pragma region Sol_1

//나와 방법 같음


void go(int s, int e, int level) {
	if (s > e) return; //혹시라도 왼쪽 인덱스>오른쪽 인덱스 일 경우 대비
	if (s == e) {
		ret[level].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	ret[level].push_back(a[mid]);
	go(s, mid - 1, level + 1);
	go(mid + 1, e, level + 1);
	return;

}
void Sol_1() {
	cin >> n;
	int _end = (int)pow(2, n) - 1;
	for (int i = 0; i < _end; i++) {
		cin >> a[i];
	}

	go(0, _end,1);
}

#pragma endregion

int main() {
	
}