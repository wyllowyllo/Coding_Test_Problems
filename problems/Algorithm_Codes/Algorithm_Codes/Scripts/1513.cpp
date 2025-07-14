#include <bits/stdc++.h>
using namespace std;

namespace My {
	//처음에 풀 때 3차원 dp로 했으나, 이전에 방문한 오락실의 상태(prev)도 고려해야 하기에 4차원 dp를 써야 함
	//엣지 케이스(n,m 위치에 오락실이 있는 경우) 를 처리하는 기저사례 작성을 잘못함 -> if (y == n && x == m) return c == 0;이렇게 수정


	/*
	prev는 “지금까지 마지막으로 들른 오락실 번호”라는 의미로, 이후에 어느 오락실을 방문할 수 있는지를 직접 좌우하는 값이어서 DP 상태에 반드시 포함돼야 합니다.

	지금 상태 정의인 dp[y][x][c]만으로는, 서로 다른 prev 값을 가진 호출들이 한 버킷에 섞여 버려요.
	예를 들어:

	어떤 경로 A에서 (y,x,c) 상태에 도착했을 때 prev=2였다면, 다음에 방문할 수 있는 오락실은 a[ny][nx]>2인 곳뿐이고

	경로 B에서 같은 (y,x,c)에 도착했지만 prev=5였다면, 방문 가능 범위가 a[ny][nx]>5로 달라집니다.

	그런데 DP 캐시가 dp[y][x][c] 하나뿐이면,

	“A 호출이 계산한 값”을 “B 호출도 그대로 재사용”
	해 버려서 당연히 잘못된 답이 나오게 되죠.

	---------------------------------------------------------------------------------------------------------------------------------------

	DP 상태에는 “현재 위치(y,x)”, “남은 방문 횟수(c)”, 그리고 “그때까지 마지막으로 들른 오락실 번호(prev)” 같이
	이후에 결정에 영향을 주는 모든 변수를 포함해야 합니다.

	이렇게 하면 서로 다른 prev 값이 섞이는 일이 없어서 올바르게 메모이제이션이 되고,

	베이스 케이스도 (n,m)에 도착했을 때 남은 c==0인지만 확인하면 깔끔히 처리됩니다.
	*/

	typedef long long ll;

	int n, m, c;
	int y, x;

	int a[51][51];
	ll dp[51][51][51][51]; //y,x,이전 오락실 번호, 남은 오락실 방문횟수 총 4개의 상태값

	int dy[] = { 1,0 };
	int dx[] = { 0,1 };

	ll go(int y, int x, int prev, int c) {//위치, 이전 방문한 오락실 번호, 방문해야 할 오락실 수
		if (c < 0) return 0;
		if (y == n && x == m) return c == 0;


		ll& ret = dp[y][x][prev][c];
		if (ret != -1) return ret;


		ret = 0;
		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<1 || ny>n || nx<1 || nx>m) continue;

			if (a[ny][nx]) {
				if (a[ny][nx] > prev) ret = (ret + go(ny, nx, a[ny][nx], c - 1)) % 1000007;
			}
			else ret = (ret + go(ny, nx, prev, c)) % 1000007;
		}


		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> m >> c;
		for (int i = 0; i < c; i++) {
			cin >> y >> x;

			a[y][x] = i + 1; //1번 ~ c번 오락실
		}

		memset(dp, -1, sizeof(dp));
		for (int i = 0; i <= c; i++) {
			
			if (a[1][1]) cout << go(1, 1, a[1][1], i - 1) << " ";
			else cout << go(1, 1, 0, i) << " ";
		}
	}
}

namespace Sol {
	//dp초기화는 답이 될수 없는 범위의 값으로 해야 한다. 이 문제는 0도 답이 될 수 있으므로, -1로 초기화
	//경우의 수를 재귀로 더해가는 과정에서 오버플로우가 날 수 있으므로, 경우의 수 합산 시마다 mod를 해주는 부분도 눈여겨 보자(나는 처음 풀 때 마지막 출력에서만 mod하려했음..)

	int n, m, c, y, x, a[51][51], dp[51][51][51][51];
	const int mod = 1000007;

	/// <summary>
	/// 경우의 수 반환 재귀함수
	/// </summary>
	/// <param name="y">y위치</param>
	/// <param name="x">x위치</param>
	/// <param name="cnt">방문해야 할 오락실 수</param>
	/// <param name="prev">이전에 방문한 오락실 번호</param>
	/// <returns></returns>
	int go(int y, int x, int cnt, int prev) {
		if (y > n || x > m) return 0;
		if (y == n && x == m) {
			if (cnt == 0 && a[y][x] == 0) return 1;
			if (cnt == 1 && a[y][x] > prev) return 1;
			return 0;
		}

		int& ret = dp[y][x][cnt][prev];
		if (ret != -1) return ret;

		ret = 0;

		if (a[y][x] == 0) {
			ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
		}
		else if (a[y][x] > prev) {
			ret = (go(y + 1, x, cnt-1, a[y][x]) + go(y, x + 1, cnt-1, a[y][x])) % mod;
		}

		return ret;


	}
	void sol() {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m >> c;

		for (int i = 1; i <= c; i++) {
			cin >> y >> x;
			a[y][x] = i;

		}

		for (int i = 0; i <= c; i++) {
			cout << go(1, 1, i, 0) << " ";
		}
	}
}

int main() {
	Sol::sol();


}