#include <bits/stdc++.h>
using namespace std;

namespace My {

	/*
	매 순간 “어느 칸에, 어떤 크기(1×1·2×2·…·5×5)로 색종이를 붙일지”에 따라 격자의 전체 상태가 바뀌는데,

	격자 상태를 그대로 DP 상태로 잡으려면 10×10 비트맵(2^100개!)를 모두 다뤄야 하고,

	“남은 칸 수 + 남은 종이 수” 같은 단순한 변수만으로는 서로 다른 배치들을 구분할 수 없습니다.

	그래서 실질적인 중복 부분 문제(overlapping subproblems)도 거의 없고,
	상태 공간도 전혀 압축되지 않아 메모이제이션 이득이 사라집니다.

	반면에

	“맨 위·맨 왼쪽의 첫 1” 하나만 처리 → 분기 폭을 극단적으로 줄이고,

	“지금까지 사용한 종이 수 ≥ 최적해” 가지치기 → 탐색을 빠르게 단축

	시키는 백트래킹＋가지치기(Branch & Bound) 방식이 이 문제엔 훨씬 더 잘 맞습니다.

	이게 바로 DP 대신 백트래킹으로 들어가야 했던 이유입니다.

	dp[cnt][a][b][c][d][e]처럼 “남은 1의 개수와 남은 색종이 수”만으로는, 어떤 칸들이 남았는지를 전혀 구분할 수 없어서 상태 정의가 틀렸어요.

	예를 들어 “남은 4개의 1” 상태는

	네 칸이 모두 붙어 있어 한 장의 2×2 색종이로 덮을 수 있는 경우도 있고,

	네 칸이 사방으로 흩어져 있어서 전부 1×1 색종이 네 장을 써야 하는 경우도 있는데,
	둘을 같은 dp[4][…]에 묶어 버리면 최적 부분 구조가 깨집니다.
	*/

	int _a[10][10];
	int total;

	int ret = 1e9;
	//int dp[101][6][6][6][6][6]; //남은 점 개수, 1~5크기의 색종이 수 _>이때의 사용한 최소 색종이 수



	int attach(int y, int x, int size) {
		int cnt = 0;
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (_a[i][j] == 1) {
					cnt++;
					_a[i][j] = -1;
				}
			}
		}

		return cnt;
	}
	void detach(int y, int x, int size) {
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (_a[i][j] == -1) {
					_a[i][j] = 1;
				}
			}
		}
	}
	bool isPossible(int y, int x, int size) {

		if (y + size - 1 >= 10 || x + size - 1 >= 10) return false;
		int cnt = 0;

		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {

				if (_a[i][j] != 1) return false;
				if (_a[i][j] == 1) cnt++;
			}
		}

		if (cnt == 0) return false; //구역 안에 1이 없다면 색종이 붙일 필요 없으므로 false;

		return true;
	}



	void go(int cnt, int a, int b, int c, int d, int e, int cur) {

		if (cur >= ret) return;
		if (cnt == 0) {
			ret = min(ret, cur);
			return;
		}


		bool flag = false;
		int ny, nx;
		for (int i = 0; i < 10 && !flag; i++) {
			for (int j = 0; j < 10; j++) {
				if (_a[i][j] == 1) {
					flag = true;
					ny = i; nx = j;
					break;
				}
			}
		}

		if (!flag)return;

		if (e > 0 && isPossible(ny, nx, 5)) {
			int t = attach(ny, nx, 5);
			go(cnt - t, a, b, c, d, e - 1, cur + 1);
			detach(ny, nx, 5);
		}
		if (d > 0 && isPossible(ny, nx, 4)) {
			int t = attach(ny, nx, 4);
			go(cnt - t, a, b, c, d - 1, e, cur + 1);
			detach(ny, nx, 4);
		}
		if (c > 0 && isPossible(ny, nx, 3)) {
			int t = attach(ny, nx, 3);
			go(cnt - t, a, b, c - 1, d, e, cur + 1);
			detach(ny, nx, 3);
		}
		if (b > 0 && isPossible(ny, nx, 2)) {
			int t = attach(ny, nx, 2);
			go(cnt - t, a, b - 1, c, d, e, cur + 1);
			detach(ny, nx, 2);
		}
		if (a > 0 && isPossible(ny, nx, 1)) {
			int t = attach(ny, nx, 1);
			go(cnt - t, a - 1, b, c, d, e, cur + 1);
			detach(ny, nx, 1);
		}

		return;
	}

	void Sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> _a[i][j];
				if (_a[i][j]) total++;
			}
		}

		if (total == 0) {
			cout << 0 << "\n";
			return;
		}


		go(total, 5, 5, 5, 5, 5, 0);
		if (ret == 1e9) cout << -1 << "\n";
		else cout << ret << "\n";
	}
}

namespace Sol {
	//경험적으로, 큰 색종이를 우선 붙이는 경우일 때, 색종이가 최소로 쓰이게 될 것임을 알 수 있다.
	//휴리스틱(heuristic)!

	/*
	휴리스틱(Heuristic) 은 완벽한 해법을 보장하지는 않지만, “어떤 기준으로 먼저 시도해 보면 좋겠다”는 경험적·문제 특화된 규칙(rule-of-thumb)을 말합니다.
	여기서는 더 큰 색종이가 한 번에 더 많은 칸을 덮기 때문에,
	전체 색종이 수를 줄이는 데 유리하고
	탐색 깊이를 빠르게 낮출 수 있어서
	branch-and-bound(백트래킹+가지치기)의 성능을 크게 끌어올려 줍니다.
	이처럼 “최적해를 빨리 찾도록 선택지 순서를 정하는” 방식을 탐색 휴리스틱 혹은 순서 결정 휴리스틱(move-ordering heuristic) 이라고 부릅니다.
	휴리스틱 덕분에 최악의 경우에도 탐색 폭이 훨씬 줄어들지만,
	만약 큰 색종이를 붙였을 때 해가 나쁘다면(드물긴 해도) 다른 크기도 결국 시도해 보되,
	큰 것부터 시도하니 빠르게 좋은 해를 찾아 강력하게 가지치기할 수 있다는 장점이 있죠.
	*/

	const int INF = 987654321;
	int a[104][104], ret = INF, n = 10;

	map<int, int> mp;


	bool check(int y, int x, int cnt) {
		if (y + cnt > n || x + cnt > n) return false;
		for (int i = y; i < y + cnt; i++) {
			for (int j = x; j < x + cnt; j++) {
				if (a[i][j] == 0) return false;
			}
		}

		return true;
	}
	void draw(int y, int x, int cnt, int value) {
		for (int i = y; i < y + cnt; i++) {
			for (int j = x; j < x + cnt; j++) {
				a[i][j] = value;
			}
		}
	}
	void dfs(int y, int x, int cnt) {
		if (cnt >= ret) return;
		if (x == n) {
			dfs(y + 1, 0, cnt);
			return;
		}

		if (y == n) {
			ret = min(ret, cnt);
			return;
		}

		if (a[y][x] == 0) {
			dfs(y, x + 1, cnt);
			return;
		}

		for (int _size = 5; _size >= 1; _size--) {
			if (mp[_size] == 5) continue;

			if (check(y, x, _size)) {
				mp[_size]++;
				draw(y, x, _size, 0);
				dfs(y, x + _size, cnt + 1);
				draw(y, x, _size, 1);
				mp[_size]--;
			}
		}

		return;
	}
	void sol() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		dfs(0, 0, 0);
		cout << (ret == INF ? -1 : ret) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Sol::sol();
}