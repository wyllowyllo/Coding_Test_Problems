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

int main() {
	
	Sol::sol();
	
}