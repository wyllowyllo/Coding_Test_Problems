#include <bits/stdc++.h>

using namespace std;

int n;
int p, d;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int ret;
int mx;
#pragma region  MySol

//시간복잡도상 완탐은 안될듯
//방법 1 : 마감날이 짧은 기간 강연부터 처리하되, 같은 마감날이면 강연료가 큰 것을 선택한다면, 최대한 많은 강연을 참여하며 최대 수익을 얻을 수 있을 것이다

//따라서 1순위로 마감날 기준 오름차순 정렬하고, 마감날이 같다면 강의료가 높은 순으로 내림차순 정렬하여 이를 순회하며 강의를 선택함
//틀림


//방법 2 : 기간 당 수익(기간/마감일) 을 계산하여 내림차순 정렬?


//방법 3 : 기간이 가장 긴 것부터 포함시키고, 기간 같은 것 중 가장 수익 큰거 포함시키기 -> 마감일 기준 내림차순 정렬하되, 같은 마감일에 대해선 높은 강의료 순 정렬

//방법 4 : 일정 안에 최대한 많은 강의를 참여하면서도 가장 수익이 큰 조합 만들기
//  강연을 마감일 오름차순으로 정렬하고, priority queue에 push
//우선순위 큐의 top은 수익이 가장 작은 강의
//큐의 사이즈가 곧 참여하는 강의의 수가 됨
//만약 큐의 크기 > 강연의 마감일 이 되면 마감일을 초과하는 것이므로, 큐에서 가장 작은 수익을 뺌
//최종적으로 힙 안에 남는 것은 "일정 안에 최대한 많이 들어가면서도 가장 수익이 큰 조합".



void MySol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		//v.push_back({ d,p });

		/*period[i] = d;
		pay[i] = p;
		vv.push_back({ ((double)p / d) ,i});*/

		/*v.push_back({ d,p });
		mx = max(mx, d);*/
		v.push_back({ d,p });
	}

	/* 방법 1
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int>b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
});

int day = 0;
for (auto& i : v) {
	if (i.first <day) continue;
	ret += i.second;
	day++;
}
	*/

	/*방법 3*/
	/*sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int>b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;

});

	int day = 0;
	int remain = mx - day;
	for (auto& i : v) {
		if (i.first < remain) continue;
		ret += i.second;
		day++;
		remain=mx-day;
	}
	*/

	//방법 4
	sort(v.begin(), v.end());

	for (auto& i : v) {
		pq.push(i.second);
		if ((int)pq.size() > i.first) {
			pq.pop();      // 가장 작은 수익 제거
		}
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}


	cout << ret << "\n";
}
#pragma endregion

#pragma region MySol_2

//방법 3 리뉴얼 : 마감일 가장 긴 것부터 검사해나가며 우선순위 큐 사용
//그날 들을 수 있는 가장 큰 수익을 확보해나가는 방식

vector<int> a[10001];
priority_queue<int> pq_2;
void MySol_2() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		mx = max(mx, d);

		a[d].push_back(p);
	}

	for (int i = mx; i >= 1; i--) {
		for (int j : a[i]) {
			pq_2.push(j);
		}

		if (pq_2.size()) {
			ret += pq_2.top();
			pq_2.pop();
		}
	}

	cout << ret << "\n";
}
#pragma endregion


#pragma region Sol_1


/*아이디어 접근 과정*/
//마감일 1일인  강의 중 가장 수익이 큰 것 선택, 2일인 강의 중 가장 큰것 선택.... 이런식으로 하면 되지 않을까?
//그러나 반례 : 3개의 강의 중 1일짜리 강의 수익이 50이고, 2일짜리 강의 수익이 90,100 이라면 1일차 강의 안하고 2일짜리 강의 2개 하는게 더 수익이 큼
//즉 1일차,2일차... 이런식으로 강의 선택하다 만약 마감일 초과할 때 가장 수익 작은거 취소해버리기



//아이디어 1 : 위 과정에 근거하여, 일단 마감일 기준으로 오름차순 정렬 (마감일이 촉박한 강연부터 처리해야 많이 강의참여할수 있으므로)
//우리는 강의를 참여했을 때의 수익의 합이 최대가 되게 해야 한다
//이때 최대라는 것은, 최소를 작게 만들거나, 최대를 크게 만드는 것이다
//최소를 작게 만드는 방향으로 최대를 구해 보자
//-> 마감일 오름차순 정렬된 상태에서 pq에 수익을 push할때, 만약 제약을 어기는 경우(마감일 초과)최소는 빼버리는 방식으로  그떄그때 가장 덜 중요한(수익이 작은) 강연을 제거하는 기법
//이 과정을 반복했을때, 최종적으로 최소를 가장 작게 만든(즉 참여한 강의 수익의 하방을 최대한 높임) 조합이 pq에 남는다

/*중요*/
//이때 최대라는 것은, 최소를 작게 만들거나, 최대를 크게 만드는 것이다
//최소를 작게 만드는 방향으로 최대를 구해 보자



void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) { //pq의 사이즈는 곧 참여한 강의 수이고, 1강의당 1일이므로 몇일차인지를 나타냄

			//만약 마감일이 지난 경우, 가장 수익이 작은 강의를 하나 제거해서 마감일을 맞춤
			pq.pop();
		}
	}

	while (pq.size()) {
		ret += pq.top(); pq.pop();
	}
	cout << ret << "\n";
}

#pragma endregion

int main() {
	//MySol();
	//Sol_1();
	MySol_2();
}

/*
이 알고리즘이 그리디 인 이유

“매 강연마다 지금까지의 수익 합을 최대화하되, 제약을 어길 땐 가장 작은 수익을 버린다”

→ 매 단계에 가장 좋아 보이는(=로컬 최적의) 선택만 함

→ 이것이 전형적인 그리디 전략이고, 이 문제에서는 올바른 최적해로 귀결됩니다.



*/