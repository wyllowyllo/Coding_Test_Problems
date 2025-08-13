#include <bits/stdc++.h>
using namespace std;

namespace My {

	//문제를 보면, 처음에 1번 영화 위에 놓인 영화 수는 0, 2번 영화 위에 놓인 영화수는 1.... n번 영화 위에 놓인 영화 수는 n-1개가 된다.
	//또한, 어떤 영화를 볼 때, 그 위에 쌓인 영화 수를 출력 후 0으로 업데이트하고, 그 영화를 맨 위에 올림으로써 다른 영화들 또한 위에 쌓인 수 값을 업데이트해야한다.

	//즉, 누적합을 구하되, 값이 업데이트되는 상황이 있으므로 -> 펜윅트리를 써보자

	//펜윅트리는, n개의 원소가 있을때 그 모든 원소에 대해 세그먼트를 가지지는 않지만, n번째 세그먼트가 n의 이진수 값의 마지막 1의 개수만큼의  요소를 가지게 되는 세그먼트 트리이다.



	int t, n, m;
	int a[200004]; //최대 10만개의 영화가 주어지므로, 두 배에 해당하는 범위의 배열을 준비하고, [100002,200002] 에는 처음에 주어지는
				   // 1번~n번 영화를 보관하고, 여기에서 특정 영화를 보고 난 후 [1,100001] 이 범위에다 보고 난 영화를 넣는다. (문제에서 다 본 영화는 맨 위에 쌓는다는 점을 구현)

	int tree[200004]; //펜윅트리 : n번째 영화의 위에 있는 영화 개수를 저장(누적합)


	map<int, int> v; //n번 영화가 현재 어느 인덱스에 놓여있는지 저장

	void update(int idx, int value) {

		while (idx < 200004) {
			tree[idx] += value;
			idx += (idx & -idx);
		}

	}
	int sum(int idx) {
		int ret = 0;
		while (idx > 0) {
			ret += tree[idx];
			idx -= (idx & -idx);
		}

		return ret;
	}


	void sol() {
		cin >> t;
		while (t--) {
			cin >> n >> m;

			memset(tree, 0, sizeof(tree));
			v.clear();
			int offset = 100001;

			for (int i = 1; i <= n; i++) {
				update(i + offset, 1);
				v[i] = i + offset;
			}

			int tmp;
			for (int i = 1; i <= m; i++) {
				cin >> tmp;
				int idx = v[tmp];

				cout << sum(idx) - 1 << " ";

				update(idx, -1);
				update(--offset, 1);
				v[tmp] = offset;
			}
			cout << "\n";
		}
	}
}

namespace Sol {
	/*
	이 문제(BOJ 3653 ‘영화 수집’)는
	“현재 위치 기반 개수 질의(위에 몇 개?) + 위치 변경(맨 위로 이동)”을 반복하므로,
	구간 누적값(프리픽스 합) 을 빠르게 질의하고 점 단위 갱신을 하는 펜윅 트리(BIT) 가
	가장 자연스러운 선택
	*/

	/*
		왜 펜윅 트리를 떠올려야 하나 (사고 과정)
		상태 모델링

		선반을 1차원 선형 배열의 “위치” 로 모델링합니다.

		어떤 영화가 그 위치에 “있으면 1, 없으면 0” 을 두면, “어떤 영화 위에 있는 개수” = 해당 위치의 왼쪽(작은 인덱스) 합 으로 환원됩니다.

		문제의 출력은 “해당 영화 위에 쌓인 수”이니, sum(pos) - 1 로 계산(자기 자신을 포함하므로 -1).

		연산 형태 파악

		질의: sum(pos) (프리픽스 합)

		갱신: 그 영화가 있던 자리 pos를 0으로 만들고(top으로 옮김), 새 top 자리에 1을 놓기 → 점 갱신 2회
		⇒ “프리픽스 합 질의 + 점 갱신” = Fenwick Tree 표준 케이스 (각 연산 O(log N)).

		top을 어떻게 구현? (오프셋 트릭)

		초기엔 [BASE+1 … BASE+n] 구간에 1을 채우고(영화 1~n 배치), top 포인터를 BASE로 둡니다.

		영화를 볼 때마다

		그 영화의 현재 위치 pos를 0으로 갱신

		top-- 한 자리에 1을 넣고, 그 영화의 위치를 top으로 갱신
		→ “맨 위로 쌓기”가 배열의 왼쪽으로 확장되며 깔끔히 표현됩니다.

		이렇게 하면 전체 사용 좌표 범위는 최대 n + m만큼이므로 트리 크기를 n+m+α로 잡으면 충분합니다.
	*/
	int t, n, m, tree[200004], temp;
	map<int, int> mp;

	void update(int idx, int value) {
		while (idx < 200004) {
			tree[idx] += value;
			idx += (idx & -idx);
		}
	}

	int sum(int idx) {
		int ret = 0;

		while (idx > 0) {
			ret += tree[idx];
			idx -= (idx & -idx);
		}

		return ret;
	}

	void sol() {
		cin >> t;
		while (t--) {
			cin >> n >> m;
			memset(tree, 0, sizeof(tree));
			mp.clear();

			int update_idx = 100001;
			for (int i = 1; i <= n; i++) {
				update(i + update_idx, 1);
				mp[i] = i + update_idx;
			}

			for (int i = 0; i < m; i++) {
				cin >> temp;

				int idx = mp[temp];
				cout << sum(idx) - 1 << " ";

				update(idx, -1);
				update(--update_idx, 1);
				mp[temp] = update_idx;

			}
			cout << "\n";
		}
	}
}

namespace Sol_2 {
	int n, m;

	struct Fenwick {
		int N;

		vector<int> bit;
		Fenwick(int n = 0) { init(n); }
		void init(int n) { N = n; bit.assign(n + 1, 0); }

		void add(int idx, int val) {
			for (; idx <= N; idx += idx & -idx) bit[idx] += val;
		}
		int sum(int idx) const {
			int ret = 0;
			for (; idx > 0; idx -= idx & -idx) ret += bit[idx];
			return ret;
		}

	};

	void sol() {
		int T;
		cin >> T;
		while (T--) {
			cin >> n >> m;

			// 좌표 범위: 최대 n+m까지 필요
			Fenwick fw(n + m + 2);
			vector<int> pos(n + 1);

			// 앞쪽 m칸은 '맨 위로 올릴' 버퍼로 예약
			int base = m; // top은 base, 실제 새 위치는 --base로 채움

			for (int i = 1; i <= n; i++) {
				pos[i] = i + base;
				fw.add(pos[i], 1);
			}

			for (int i = 0; i < m; i++) {
				int x; cin >> x;
				int p = pos[x];

				int above = fw.sum(p) - 1;
				cout << above << (i + 1 == m ? '\n' : ' ');


				// 기존 자리 비우고, 맨 위로 올림
				fw.add(p, -1);
				fw.add(base, 1);
				pos[x] = base;
				--base;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	//My::sol();
	//Sol::sol();
	Sol_2::sol();

}