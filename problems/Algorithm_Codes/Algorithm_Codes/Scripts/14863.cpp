#include <bits/stdc++.h>
using namespace std;

namespace My {
	//첫번째 시도 : DP로 함. 뭔가 공간복잡도 1억 정도 나오길래 안되겠다 싶긴 했음..
//아니... 조건 잘못봤네 공간복잡도 1억 아니고 천만이구나
//틀린 이유 : 문제 조건 잘못봄... 로직 다 짜놓고 조건 잘못봐서 배열 크기 너무 크게 잡아서 메모리초과남...
//틀린 이유 2 : 초기화 
//메모라이징 된 값 체크 이후에는, ret=-1e9를 추가해야 한다. (그대로 두거나, -1등의 값으로 초기화해버리면 오답임!)
// ->이거 안하면, 만약에 저 밑에 조건문 2개에 걸리지 않을 경우 그대로 0을 리턴해버림
	//즉, 조건문 2개에 걸리지 않는다는 건 답이 될 수 없는 경우라는 것인데, 0또는 너무작은 음수값을 리턴해버리면, 이후에 재귀에서 돌아오는 과정에서 +가 되어 양수로 바뀌어, 그게 답이 되어버리는 경우가 생김

	//따라서 초기화는 절대 답이 될수 없는 범위의 값으로 하자!


/*
예시, ret=-1;로 한 경우

이부분은 답이 될 수 없는 경우의 수를 없애는 역할을 합니다. 단순이 한 정점의 값이 -1이라면 누적해서 0이상의 값이 되어서 -> 답이 될 수 있는 범위가 되어 -> 노이즈가 되버립니다.

근데 -1e6을 하게 되면 해당 경우의 수가 제거되는 효과를 지니게 됩니다.



예를 들어,

a -> b -> c -> d라는 경우의 수랑

a -> b -> e -> f라는 경우의 수가 있습니다.

전자의 경우 c에서 안되는 경우가 발생해서 이 경우의 수를 제거해야 한다면 어떻게 해야할까요?



이 때 해당 정점에서 매우 큰 음수를 주어서 -> 답이 절대 될 수 없는 범위로 만들어 해당 경우의 수를 제거하는 기법이라고 보시면 됩니다.


*/

	int n, k;
	int a, b, c, d;

	typedef long long ll;

	struct sector {
		int time[2];
		int money[2];
	} s[101];

	ll dp[101][100001];


	ll go(int here, int period) {
		if (here == 0) return 0;

		ll& ret = dp[here][period];
		if (ret) return ret;

		ret = -1e9;
		if (period - s[here].time[0] >= 0) ret = max(ret, go(here - 1, period - s[here].time[0]) + s[here].money[0]); //걷기
		if (period - s[here].time[1] >= 0) ret = max(ret, go(here - 1, period - s[here].time[1]) + s[here].money[1]); //자전거
		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c >> d;
			s[i].time[0] = a;
			s[i].money[0] = b;
			s[i].time[1] = c;
			s[i].money[1] = d;

		}

		cout << go(n, k) << "\n";
	}
}

namespace Sol {
	typedef long long ll;
	int n, k, dp[101][100001];

	struct B {
		int _time, pay;
	};

	B a[101], b[101];

	int go(int here, int _time) {
		if (here == n) return 0;
	

		int& ret = dp[here][_time];
		if (ret) return ret;

		ret = -1e9;
		if (_time - a[here]._time >= 0) ret = max(ret, go(here + 1, _time - a[here]._time) + a[here].pay);
		if (_time - b[here]._time >= 0) ret = max(ret, go(here + 1, _time - b[here]._time) + b[here].pay);

		return ret;
	}
	void sol() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i]._time >> a[i].pay >> b[i]._time >> b[i].pay;
		}

		cout << go(0, k) << "\n";
	}
}

namespace Sol_2 {
	//남은 시간 만 상태값으로 정의해서, 1차원 dp로 푸는 풀이
	//도시별로 한 번의 선택만 가능한 냅색 문제에서,
    //이전 상태를 한 번 쓰고 지워버리는 방식


	/*도시마다 두 가지 선택지가 있고, 그중 하나만 선택해야 하므로,
		현재 상태 dp[j]를 기반으로 한 번 두 가지 갱신을 한 뒤 dp[j] = 0으로 만들어서
		같은 도시에서 다시 중복으로 갱신되는 것을 막습니다.

		이건 마치 "현재 도시의 선택이 끝났으니 이 시간 상태는 폐기"하는 느낌입니다.

		일반 냅색처럼 위에서 아래로 순회하는 게 아니라 뒤에서부터 내려오면서 처리합니다.이는 갱신 충돌 방지를 위한 전형적인 냅색 테크닉입니다.*/


	int n, k, dp[100001], t1, t2, p1, p2;

	void sol() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> k;

		dp[0] = 1; //시간 0일때의 모금액은 0이지만, 시작이라는 것을 표시하기 위해 1로 설정

		for (int i = 0; i < n; i++) {
			cin >> t1 >> p1 >> t2 >> p2;

			for (int j = k; j >= 0; j--) {
				if (dp[j]) {
					if (j + t1 <= k) dp[j + t1] = max(dp[j + t1], dp[j] + p1);
					if (j + t2 <= k) dp[j + t2] = max(dp[j + t2], dp[j] + p2);


				// 모금액을 순차적으로 모집하는 것이기 때문에 
				// 이번에 모금액을 갱신했다면 해당 인덱스의 모금액은 초기화를 둬서
				// 현재 인덱스에서의 선택지를 처리한 후에는 해당 상태를 더 이상 사용하지 않도록 합니다.
				// 즉, 중복 갱신을 막습니다.
					dp[j] = 0;
				}
			}
		}

		// 최댓값 - 처음 시작한 1
		cout << *max_element(dp, dp + k + 1) - 1;
	}
}

int main() {
	
	Sol::sol();
	
}