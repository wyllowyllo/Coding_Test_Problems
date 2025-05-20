#include <bits/stdc++.h>
using namespace std;

int n;
int d, c;
vector<pair<int, int>> v;

int ret;

#pragma region MySol

	priority_queue<int, vector<int>, greater<int>> pq;

	void MySol() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d >> c;

			v.push_back({ d,c });
		}


		sort(v.begin(), v.end());

		for (auto& i : v) {
			pq.push(i.second);

			if (pq.size() > i.first) {
				pq.pop();
			}
		}

		while (pq.size()) {
			ret += pq.top();
			pq.pop();
		}

		cout << ret << "\n";
	}

#pragma endregion

#pragma region Sol_1

//5일치, 1일치, 1일치, 1일치 총 4개의 문제가 있다고 하면
//5일치짜리 문제를 어느 시점에 풀 것인가에 따라 나머지 1일치 문제들을 풀수 있느냐 없느냐가 정해짐
// 즉 각 문제의 푸는 순서 배치를 생각해야 함
//그러나 deaeline을 오름차순 정렬하게 되면, 기간이 짧은 문제푸터 풀어나가므로 배치에 관한 로직 자체를 작성하지 않아도 됨.
//따라서 문제의 deadline 기준 오름차순 정렬함

//어떤 가방 안에다가 deadline짧은 거부터 순서대로 들어온다고 했을 때, 최대 컵라면 합을 달성하기 위해선
//최대를 많게 하거나, 최소를 적게 해야 한다.
//최소를 적게 하는 방향으로 한다면, 가방이 꽉 찰 때 마다 가방 안에 있는 것 중 최소치를 빼버리면 된다.
//즉 minHeap사용
//최종적으로 가방에 남는 과제는 컵라면의 양이 최대가 되는 조합이 된다.

void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> c;
		v.push_back({ d,c });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		ret += v[i].second;
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			ret -= pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n";

}
#pragma endregion








int main() {

}