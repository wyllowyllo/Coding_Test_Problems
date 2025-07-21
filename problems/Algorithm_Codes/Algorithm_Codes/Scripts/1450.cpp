#include <bits/stdc++.h>
using namespace std;

namespace My {
	//경우의 수를 묻는 문제. 따라서 각 경우를 하나의 노드라고 생각했을 때, 그 노드의 개수가 곧 경우의 수가 될 거라고 생각함.
//따라서, 일단 재귀를 통한 완탐으로 노드 개수 세는 로직 작성(생각보다 오래걸림;; 재귀 완탐으로 노드 개수세는 로직 기억해 놓자! )
// 그러나 시간복잡도 상 완탐으로는 안되는 걸 앎 -> dp써야겠다고 생각
// 현재 인덱스와, 그때의 가방 남은 용량을 상태값으로 정의해서 그때의 경우의 수를 저장할 수 있겠다고 생각
// 공간복잡도 상 용량은 1e9로 불가능하지만, 사실 아이템 개수가 최대 30개라 실질적인 용량 상태 개수는 한정적일 거라 생각해서, 맵을 씀!
//메모리 초과 뜸;;
//생각해보니 아이템 개수가 30개라도 각 아이템을 포함하거나 포함하지 않는 경우의 수는 2^30이니, 용량 상태 개수도 그만큼 나올수 있음. 한정적이지 않겠구나..

/*
메모리 초과가 나는 건 weight 상태가 너무 많아서인데, n이 30개 정도라는 점을 활용해 보세요.
즉, 아이템을 반으로 나눠 각 절반의 모든 부분집합 합을 구한 뒤 두 리스트를 투포인터나 이분 탐색으로 결합하는 meet‑in‑the‑middle 기법을 사용해 보시면
메모리·시간 모두 크게 줄일 수 있습니다.

아이템 30개를 한꺼번에 처리하려 하니 2³⁰가지 상태가 나와 버려요. 대신 이걸 15개씩 둘로 나눠보세요.
앞쪽 15개의 부분집합 합을 모두 구해 리스트 A에,
나머지 15개의 부분집합 합을 모두 구해 리스트 B에 담고,
A와 B를 정렬한 뒤 투포인터(or 이분탐색)로 합이 ≤C인 쌍의 개수를 세는 방식입니다.
이렇게 하면 메모리·시간 복잡도가 2·2^(n/2) 수준으로 줄어듭니다.

경우의 수 문제는 그냥 long long 써라 제발!!!
*/

	int n, c;

	vector<int> v(31);
	//map<pair<int,int>, int> m;
	//
	////첫번째 시도
	//
	//int go(int idx,int weight) {
	//	if (weight==0 || idx==n) {
	//		return 1;
	//	}
	//
	//	int& ret = m[{idx,weight}];
	//	if (ret) return ret;
	//
	//	ret = 0;
	//	if(weight - v[idx] >=0) ret += go(idx + 1, weight - v[idx]);
	//	ret += go(idx + 1, weight);
	//
	//	return ret;
	//}


	typedef long long ll;

	void go(int idx, int end, ll sum, vector<ll>& vv) {
		if (idx == end) {
			vv.push_back(sum);
			return;
		}


		go(idx + 1, end, sum + v[idx], vv);
		go(idx + 1, end, sum, vv);

	}
	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> c;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		//cout << go(0, c); 

		vector<ll> A, B;
		go(0, n / 2, 0, A);
		go(n / 2, n, 0, B);

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int j = B.size() - 1;
		ll ret = 0;
		for (int i = 0; i < A.size(); i++) {
			while (j >= 0 && A[i] + B[j] > c)j--;
			ret += (j + 1);
		}
		cout << ret << "\n";
	}
}

namespace Sol {
	//Meet In The Middle 알고리즘
	//범위 N짜리 완전탐색을 하는게 아니라, 범위 N/2짜리 완전탐색을 두번 실행 -> 시간 줄일 수 있다!
	typedef long long ll;
	ll n, c, a[31], ret;
	vector<int> v, v2;

	//용량 c를 초과하지 않는 아이템 조합을 찾아, 그 조합의 총 무게 v에 추가
	void go(int here, int _n, vector<int>& v, int sum) {
		if (sum > c) return;
		if (here > _n) {
			v.push_back(sum);
			return;
		}

		go(here + 1, _n, v, sum + a[here]);
		go(here + 1, _n, v, sum);
		return;
	}
	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);


		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		go(0, n / 2 - 1, v, 0);
		go(n / 2, n - 1, v2, 0);

		sort(v.begin(), v.end());
		sort(v2.begin(), v2.end());

		for (int b : v) {
			if (c - b >= 0) ret += (int)((upper_bound(v2.begin(), v2.end(), c - b))-v2.begin());
		}
		cout << ret << "\n";
	}

}
int main() {
	Sol::sol();
}
