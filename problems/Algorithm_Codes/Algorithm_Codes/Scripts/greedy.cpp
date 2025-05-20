#include <bits/stdc++.h>
using namespace std;


#pragma region Chapter 1

namespace ch1 {
	int n;
	int from, to;

	vector<pair<int, int>> v;

	//시간복잡도가 2^10만이기 때문에 완탐은 불가함
	//greedy로 접근해보자 -> 정렬과 우선순위큐를 사용하는것을 고려
	//주어진 조건은 각 학생의 시작시간-떠나는 시간 이므로
	// 1. 시작시간을 기준으로 오름차순 정렬
	// 2. 끝나는 시간을 기준으로 오름차순 정렬
	// 3. 끝나는 시간 - 시작시간 을 기준으로 오름차순 정렬


	//위 명제들을 구현하는 로직을 짜 보고, 답이 아니라면 다른 명제를 선택하여 다시 구현 반복




	void Chapter_1() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> from >> to;
			//v.push_back({ from,to }); //1번 명제 적용시
			v.push_back({ to,from }); //2번 명제 적용시
		}


		//1번 명제 적용시
		/*
		//반례(예제2)가 있으므로 1번 명제는 틀림 --> 2번 명제로 태세전환하고 구현해보자!

		sort(v.begin(), v.end()); //v.first 기준 오름차순 정렬한 후, v.second기준 오름차순 정렬함
		from = v[0].first;
		to = v[0].second;

		int ret = 1;
		for (auto& s : v) {
			if (to > s.first) continue;
			from = s.first; to = s.second; ret++;
		}

		cout << ret;
		*/

		//2번 명제--> 빨리 끝나는 학생들을 우선적으로 먼저 포함시키면, 최적해(최대한 많은 학생 선택)에 도달하지 않을까?
		//2번 명제 적용 ---> 끝나는 시간 기준 오름차순 정렬

		//학생들을 떠나는 시간(to) 기준으로 정렬함
		//이렇게 하면 가장 빨리 자리를 비우는 학생을 우선적으로 선택할 수 있음
		//즉, 먼저 끝나는 활동을 선택해 나가는 방식
		sort(v.begin(), v.end());

		from = v[0].second;
		to = v[0].first;

		int ret = 1;
		for (auto& s : v) {
			if (to > s.second) continue;

			from = s.second; to = s.first; ret++;
		}

		cout << ret;

		

	}
}

#pragma endregion

#pragma region Chpater 2

//수집할 수 있는 골동품 가치의 합이 최대값이 되려면?
//시간복잡도 상 완탐은 x. 그리디로 접근 시... ->정렬 , 우선순위큐 활용!

//1. 가방의 크기를 내림차순으로 정렬하고 골동품의 가치가 높은 것부터 내림차순으로 담는다
//2. 가방의 크기를 오름차순으로 정렬하고 골동품의 가치가 작은것부터 담는다

//두 경우 모두 반례가 있음.

//가성비를 높이는 방법 ? 각 가방에 가능한 한 최대의 가치를 가진 골동품을 담는다
// 3. 무게를 적게 담을 수 있는 가방부터 골동품을 넣기 시작하고, 넣을수 있는 보석 중 가치가 최대인 보석만 하나 넣는다

namespace ch2 {



	int n, k;
	vector<pair<int, int>> v;
	vector<int> capacity;
	int m, p;
	int c;
	void Chapter_2() {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> m >> p;
			v.push_back({ m,p });
		}

		for (int i = 0; i < k; i++) {
			cin >>c;
			capacity.push_back(c);
		}

		sort(capacity.begin(), capacity.end()); //가방 크기 오름차순 정렬
		sort(v.begin(), v.end()); //보석 무게 오름차순 정렬, 두번째로 보석 가치 기준 오름차순 정렬

		priority_queue<int> pq;

		int j;
		int ret = 0;
		for (int i = 0; i < k; i++) {
			while (j < n && v[j].first <= capacity[i]) pq.push(v[j++].second); //가방에 넣을 수 있다면 일단 넣는다
			if (pq.size()) {// 만약 우선순위 큐에 선택 가능한 골동품이 있으면, 그 중에서가장가치가높은 골동품을선택하여ret에더합니다.그후우선순위큐에서그골동품을제거합니다.
				ret += pq.top(); pq.pop(); //second값이 가장 큰 것이 top에 온다.
			}
		}

		//가방의 크기는 오름차순 정렬되어있고, 골동품의 무게도 오름차순 정렬되어 있다.
		//따라서 1번 가방에 골동품을 넣고 이후 2번 가방에 넣을 골동품을 고르는 경우, 처음부터 다시 검사할 필요없이(j=0 갱신 없이) 그 위치부터 바로 탐색하면 된다(1번 가방에 들어가는 골동품이라면 2번 가방에도 당연히 들어갈 수 있으므로)


		cout << ret << '\n';

	}
}

#pragma endregion

#pragma region Chapter 3

namespace ch3 {

	

	//단순히 오름차순 정렬하면 되는 문제지만, 공간복잡도 상 불가능
	//우선순위 큐 사용하기
	int n;
	double score;

	priority_queue<double> pq;
	vector<double> v;

	void ch_3() {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> score;
			
			if (pq.size() == 5) {
				pq.push(score); pq.pop(); //5명 중 가장 점수가 높은 학생을 제거해 나감
			}
			else pq.push(score);
		}

		//최종적으로 pq엔 가장 점수가 낮은 5명만 존재함
		while (pq.size()) {
			v.push_back(pq.top()); pq.pop();
		}

		reverse(v.begin(), v.end());
		for (double i : v) printf("%.2lf\n", i);

	}
}
#pragma endregion

#pragma region Chapter 4

//이 문제는 visited배열을 사용하여 선이 그려진 구간을 표시하고, 카운트를 통해 각 선의 길이를 구하는 식으로 해결할 수 있다
//그러나 점의 범위가 -10억~10억 까지이므로, 공간 복잡도 상 배열로 이를 표현할 수 없다(보통은 3000만 정도까지면 가능)
//따라서 라인스위핑 방식을 사용한다

//선의 왼쪽 점(L), 오른쪽 점(R)을 정의한다.
// 만약 다음 선의 왼쪽 점<현재 선 오른쪽 점 && 다음 선 오른쪽 점>현재 선 오른쪽 선 이라면 두 선은 겹쳐진 구간이 있는 것임
//이 경우에 R=다음 선의 오른쪽 점으로 갱신하여 하나의 선으로 처리한다.

//만약 다음 선의 왼쪽 점 > 현재 선의 오른쪽 점 이라면 겹치지 않는 별개의 선이므로
//이때 L과 R을 다음 선의 왼,오른쪽 점으로 변경한다.

/* 주의 : 라인스위핑을 할 때는 반드시 정렬을 해야 한다! */


namespace ch4 {

	typedef pair<int, int> P;
	P L[1000004];

	int n;
	int a, b;
	int l, r, ret;

	void ch_4() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			L[i] = P(a, b);
		}

		sort(L, L + n); //a(시작점)기준 오름차순 정렬
		l = L[0].first; r = L[0].second;
		for (int i = 1; i < n; i++) {
			if (r < L[i].first) {
				ret += r - l;
				l = L[i].first;
				r = L[i].second;
			}
			else if (L[i].first <= r && L[i].second >= r) {
				r = L[i].second;
			}
		}

		cout << ret << "\n";
	}
}
#pragma endregion

#pragma region Chapter 5

namespace ch5 {
	int n;
	int x;
	
	//시간복잡도는 NlogN이 된다.(while반복문의 시간복잡도=N, sort시간복잡도 logN)
	void ch_5(){
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cin >> x;

		sort(v.begin(), v.end()); //투포인터 사용시에는 먼저 정렬을 해야한다!

		int l = 0; int r = n - 1;
		int ret = 0;
		while (l < r) {
			if (v[l] + v[r] == x) {
				ret++;
				r--;
			}
			else if (v[l] + v[r] > x) r--;
			else if (v[l] + v[r] < x) l++;
		}

		cout << ret << "\n";

	}
}
#pragma endregion


int main() {
	//ch1::Chapter_1();
	//ch2::Chapter_2();
	//ch3::ch_3();
}