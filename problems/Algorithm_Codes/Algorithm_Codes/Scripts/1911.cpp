#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

//처음에 '최소 개수'에만 집착해서 그리디적으로 문제를 풀어보려 했음
//그러나 구현 아이디어가 떠오르지 않음... 배열로 그 위치에 널판지가 설치되었는지 아닌지 확인하는 식으로밖에 생각이 안남..

//'최소개수'구하는것에 집착하기 보단, 일단 어떻게 널판지를 설치해나갈지를 생각해보자
//웅덩이 위치를 정렬해서, 라인스위핑하며 널판지를 설치해나간다.
//널판지의 끝을 가르키는 포인터를 두고, 이를 각 구덩이의 시작 및 끝 점과 비교해나가며 어디서부터 널판지를 몇 개 설치할지를 결정할 수 있다.

//한가지 방법(그리디 등) 에 매몰되어 문제를 풀려하지 말고, 그냥 방법론보다는 우선적으로 문제 도식화해보고, 문제를 해결할 로직을 다양하게 생각해보기!

int n, l;
vector<pair<int, int>> v;
int s, e;

int p;
int ret;

void MySol(){
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;

		v.push_back({ s,e - 1 });
	}

	sort(v.begin(), v.end());

	for (auto i : v) {
		if (i.second < p) continue; //웅덩이의 끝 위치 < 현재 설치된 널판지의 끝 위치

		int startPoint = max(p, i.first); //널판지 설치 위치 정하기(웅덩이 시작점부터 새로 설치하냐, 아니면 널판지 끝에서부터 이어서 설치하냐)

		int cnt = (int)ceil((double)(i.second - startPoint + 1) / l); //필요한 널판지 개수 = (덮어야 될 길이)/널판지 길이
		ret += cnt;

		p = startPoint + (l * cnt);//널판지 끝 포인터 갱신


	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1

int idx;
int b;
void Sol_1() {
	cin >> n >> l;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (a[i].second < idx) continue;
		if (idx < a[i].first) { //널판지 이어서 설치하지 않고, 구덩이 시작부터 새로 설치하는 경우
			b = (a[i].second - a[i].first) / l + ((a[i].second - a[i].first) % l ? 1 : 0);
			idx = a[i].first + (b * l);
		}
		else {
			b = (a[i].second - idx) / l + ((a[i].second - idx) % l ? 1 : 0);
			idx = idx + (b * l);
		}

		ret += b;
	}

	cout << ret << "\n";
}
#pragma endregion


int main() {
	

}