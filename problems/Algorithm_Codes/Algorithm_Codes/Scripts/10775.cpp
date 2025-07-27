#include <bits/stdc++.h>
using namespace std;


/*
1. 문제에서 DSU를 떠올려야 하는 이유
그리디 선택: “도착한 비행기는 가능한 가장 큰 번호의 빈 게이트에 주차”

빈 자리 관리의 핵심: 이미 사용된 게이트는 다시 돌아보지 않고 건너뛰어야 함

→ “어떤 게이트가 남아 있는지, 그리고 그 바로 앞의 남은 게이트는 무엇인지”를 빠르게 찾는 자료구조가 필요

DSU(서로소 집합)는

“어떤 요소 x가 속한 집합의 대표자(루트)를 찾는(find) 연산”
“두 집합을 합치는(union) 연산”
을 거의 상수 시간에 지원
→ 빈 게이트 집합을 “게이트 번호”별로 관리하기에 안성맞춤

-----------------------------------------------------------------

문제의 핵심은 ‘사용 가능한 게이트’를 하나의 집합으로 보고,
각 비행기가 올 때마다 그 집합에서 조건에 맞는 최대 번호를 빠르게 찾아 꺼내는 것에 있습니다.

DSU 방식: 빈 게이트 집합을 서로소 집합으로 관리해 find/union으로 바로바로 다음 후보를 가리키도록 하면

std::set 방식: 빈 게이트 번호를 set에 담고 upper_bound→erase로 관리해도

어떤 방식이든 “집합”에 대한 관점이 출발점이 돼야 합니다.
이 집합 관리 아이디어를 떠올리는 것이 문제 해결의 초석입니다.

*/
int g, p;
int gate[100001];

//어떤 게이트가 사용중이고, 어떤 게이트가 비어있는지 구분하기 위해,
//사용중인 게이트 집합과 빈 게이트 집합 총 2개의 트리 구조의 집합을 사용

int findP(int num) { //부모 찾기
	if (gate[num] == num) return num;

	return gate[num] = findP(gate[num]);
}
void unite(int a, int b) { //합치기
	int p1 = findP(a);
	int p2 = findP(b);

	if (p1 != p2)
		gate[p1] = p2;
}

vector<int> avail;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> g >> p;

	//첫번째 풀이(Union Find)
	
	/*
	//부모는 자기 자신으로 초기화
	for (int i = 0; i <= g; i++) {
		gate[i] = i;
	}

	vector<int> v(p);
	for (int i = 0; i < p; i++) {
		cin >> v[i];
	}

	int ret = 0;
	for (int i = 0; i < p; i++) {
		
		int parkingNum = findP(v[i]); //v[i]번 이하에서 가장 큰 빈 게이트 번호 찾기
		if (parkingNum == 0) break;

		ret++;
		unite(parkingNum, parkingNum - 1);
	}


	cout << ret << "\n";
	*/

	//두번째 풀이

	for (int i = 1; i <= g; i++) {
		avail.push_back(i);
	}
	vector<int> v(p);
	int ret = 0;

	for (int i = 0; i < p; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < p; i++) {
		auto it = upper_bound(avail.begin(), avail.end(), v[i]);

		if (it == avail.begin()) break;

		--it;
		ret++;
		avail.erase(it);
	}
	cout << ret << "\n";
	
}