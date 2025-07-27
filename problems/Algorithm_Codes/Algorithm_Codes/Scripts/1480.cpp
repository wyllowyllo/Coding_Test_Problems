#include <bits/stdc++.h>
using namespace std;

namespace My {
	//각 보석이 어느 가방에 포함될지 그 경우의 수는 최대 11 
//즉 시간복잡도는 11^13?

//각 보석이 몇 번 가방에 포함되어있는지를 저장하는 배열을 만들기엔 공간복잡도가 너무 큰데..

// int dp[11][14]; //가방인덱스, 보석 포함 유무를 나타내는 비트마스킹 -> 역시 실패..
//뭔가 각 단계에서, 현재 어떤 보석들이 어디에 담겨있는지를 알 수 있어야 할 거 같은데...

//보석을 기준으로 가방을 선택하는 방향으로 가지 말고, 각 가방이 보석 조합을 선택하는 방향으로 가보자
//보석 조합을 일단 모두 구한 뒤,
//재귀 형식을 통해, 각 가방이 보석 조합 중 하나를 선택
//dp를 사용하여 최대 개수 구하기

//두번째 방법을 생각은 했는데, 어떻게 구현할지를 몰랐음..

	int n, m, c;
	int v[15]; //보석 무게
	//int bag[11];// 각 가방의 남은 용량

	int dp[11][1 << 14]; //가방인덱스, 보석 포함 유무를 나타내는 비트마스킹


	//첫번째 시도 ------------------------
	//int go(int here) { //각 보석이 몇 번 가방에 담길지에 대한 경우의 수 탐색
	//	if (here == n) {
	//		return 0;
	//	}
	//	
	//	/*int& ret = dp[here][visited];
	//	if (ret != -1) return ret;*/
	//	int ret = 0;
	//
	//	ret = max(ret, go(here + 1)); //현재 보석이 어느 가방에도 담기지 않음
	//
	//	for (int i = 0; i < m; i++) { 
	//		if (bag[i] - v[here] < 0) continue;
	//
	//		bag[i] -= v[here];
	//		ret=max(ret,go(here + 1)+1);
	//		bag[i] += v[here];
	//	}
	//
	//	return ret;
	//}

	//두번째 시도 ---------------------------

	vector<pair<int, int>> combi[14]; //각 가방이 고를 수 있는 보석 집합

	//현재 남아있는 보석으로 만들 수 있는 조합 모두 구하기
	void dfs(int idx, int weight, int count, int used, vector<pair<int, int>>& list) {
		if (weight > c) return;
		if (idx == n) {
			if (count > 0)
				list.push_back({ count,used });

			return;
		}

		//선택안함
		dfs(idx + 1, weight, count, used, list);

		//선택함
		if (!(used & (1 << idx)))
			dfs(idx + 1, weight + v[idx], count + 1, used | (1 << idx), list);
	}

	int go(int idx, int select) {
		if (idx == m) {

			return 0;
		}

		int& ret = dp[idx][select];
		if (ret != -1) return ret;

		ret = 0;
		for (auto i : combi[idx]) { //현재 가방이 선택할 수 있는 보석 조합
			if (select & i.second) continue;

			ret = max(ret, go(idx + 1, select | i.second) + i.first);

		}

		ret = max(ret, go(idx + 1, select)); //현재 가방을 안쓰는 경우

		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		//fill(&bag[0], &bag[0] + 11, c);
		fill(&dp[0][0], &dp[0][0] + 11 * (1 << 14), -1);


		//각 가방 당 선택할 수 있는 모든 보석 조합 구하기
		for (int i = 0; i < m; i++) {
			dfs(0, 0, 0, 0, combi[i]);
		}


		cout << go(0, 0) << "\n";

	}
}

namespace Sol {
	//시간복잡도 상 브루트포스는 안됨...
	//그럼 dp로 일단은 시도
	//구하고자 하는것 : 담을 수 있는 최대 보석 개수 
	// 어떤 상태값을 정의할 수 있을까 고민해보면...
	//가방의 인덱스, 그리고 그 인덱스(그 시점)의 가방의 남은 용량
	//또한, 한번 담은 보석을 다른 가방에 또 담을수는 없으므로, 보석에 대한 상태값이 필요할 것이다
	//따라서 현재 시점(인덱스)에서 어떤 보석을 담았는지를 비트마스킹을 통해 상태값으로 정해보자

	//현재 인덱스에서, capacity가 이정도고, 보석을 mask처럼 담았을 때의 최댓값을 쌓다 보면, 글로벌한 최댓값이 되지 않을까? 하고 시도해보자!
	typedef long long ll;
	int n, m, c, a[24], backpack[24], dp[24][1 << 14][24];

	int go(int here, int yamyam, int capacity) {
		if (here == m) return 0;
		
		int& ret = dp[here][yamyam][capacity];
		if (ret) return ret;

		ret = max(ret, go(here + 1, yamyam, c)); //현재 가방에  담지 않음

		for (int i = 0; i < n; i++) {
			bool isbeforeYam = (1 << i) & yamyam;
			bool isYamCan = (capacity - a[i]) >= 0;

			if (!isbeforeYam && isYamCan) ret = max(ret, go(here, yamyam | (1 << i), capacity - a[i]) + 1);

		}

		return ret;
	}
	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) cin >> a[i];

		cout << go(0, 0, c) << "\n";
	}
}
int main() {
	
	Sol::sol();
	
}