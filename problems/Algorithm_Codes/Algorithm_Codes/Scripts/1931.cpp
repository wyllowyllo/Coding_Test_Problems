#include <bits/stdc++.h>
using namespace std;

int n;
int s, e;

vector<pair<int, int>> v;
priority_queue<int> pq;

int ret;

#pragma region MySol

//일단 회의 빨리 시작하는거부터 고려하도록, 회의 시작시간 기준 오름차순 정렬
//pq에 있는 것이 가능한 회의들이 됨.

//답은 맞았는데...
// 만약에 top이외에 pq에 있는 원소 중 회의 끝나는 시간이 현재 회의 시작보다 늦다면
// 결국 현재회의 못하는건데 그런 경우는 처리 못함..


void MySol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;

		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());


	for (auto& i : v) {
		if (pq.size() && pq.top() > i.first) { //만약 현재 회의시작시간이 pq안의 회의 중 가장 늦게 끝나는 회의보다 이전일 경우
			if (pq.top() > i.second) { //만약 그 회의 끝나는 시잔보다 현재 회의가 더 빨리 끝난다면 이걸로 교체
				pq.pop();
				pq.push(i.second);
			}

		}
		else pq.push(i.second);
	}

	cout << pq.size() << "\n";
}
#pragma endregion

#pragma region Sol_1
//겹치지 않게 했을때 회의 최대 갯수 구하기
//라인스위핑 문제

//구간 관련된 문제(구간을 기반으로 해서 최대치를 잡는 등..) ->정렬을 생각해보기!
//끝나는 시간 기준으로 오름차순 정렬
//빨리 끝나는 시간 기준 정렬해야 회의가 겹치지 않는 빈 공간이 최대한 많이 생길 테니까


/*
생각해보니, 이게 e가 기간의 길이가 아니고 회의가 끝나는 절대적인 '시간'이니까,
e를 오름차순해서 빨리 끝나는 순으로 해야하는게 합리적이겠네.
e가 작다는건 시작시간 s가 빠르고 회의시간이 짧다는 것을 내포하니까.
나는 처음 생각할 때 s오름차순 정렬해야 한다 생각했는데(왜나면 s가 빠른걸 먼저 해야 오전회의~오후회의까지 차례대로 처리하므로 최대한 많이 처리한다 생각했음)
e로 정렬해버리면 s가 빠르면서 e-s가 작은 회의부터 먼저 처리하게 될 테니까 최대한 많은 회의를 배정한다고 생각할 수 있겠네

*/
void Sol_1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e,s });
	}
	

	sort(v.begin(), v.end());

	s = v[0].second;
	e = v[0].first;
	ret++;

	for (int i = 1; i < n; i++) {
		if (v[i].second < e) continue;
		s = v[i].second; e = v[i].first; ret++;
	}

	cout << ret << "\n";

}



#pragma endregion

int main() {
	Sol_1();
}



