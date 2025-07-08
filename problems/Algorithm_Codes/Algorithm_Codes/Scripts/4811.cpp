#include <bits/stdc++.h>
using namespace std;

namespace MySol {

	/*
	아 니 답변을 보고, 내가 왜 dp가 도움이 될지 확신이 없었는지 알았어.
	dp는 알약 한개의 개수, 알약 반개의 개수, 그리고 그때의 문자열 길이 라는 '상태'에서의 경우의 수를 저장하니, 당연히 나중에 저 '상태'에서의 경우의 수를 다시 쓰는 일이 생기는구나.
	나는 상태를 알약 한개의 개수, 알약 반개의 개수, 그리고 그때의 문자열 길이라고 정의하겐 했는데, 생각을 잘못해서 저 dp배열이 문자열 'HWWH...'에서의 경우의 수를 저장한다고 착각했네.
	문자열은 제각각이니 다시 쓰는 일이 없지만, 상태에서의 값을 저장하는거니 당연히 다시 쓰는구나
	*/
	typedef long long ll;
	int n;


	ll dp[31][31][61];

	ll go(int a, int b, int depth) {
		if (depth == 2 * n) {
			return 1;
		}

		ll& ret = dp[a][b][depth];
		if (ret != -1)return ret;

		ll cnt = 0;
		if (a > 0) cnt += go(a - 1, b + 1, depth + 1);
		if (b > 0) cnt += go(a, b - 1, depth + 1);


		return ret = cnt;
	}

	void Sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);


		while (true) {
			cin >> n;
			if (n == 0) break;

			memset(dp, -1, sizeof(dp));

			cout << go(n, 0, 0) << "\n";


		}
	}
}

namespace MySol_2 {
	//bottom up 방식으로 풀기

	typedef long long ll;
	int n;


	ll dp[31][31][61];

	void SOl_2() {

		
		while (true) {
			cin >> n;
			if (n == 0) break;

			memset(dp, 0, sizeof(dp));

			// 깊이가 2n까지 다 채워졌다면 경우의 수는 1
			for (int a = 0; a <= n; a++) {
				for (int b = 0; b <= n; b++) {
					dp[a][b][2 * n] = 1;
				}
			}

			for (int d = 2 * n - 1; d >= 0; d--) {
				for (int a = 0; a <= n; a++) {
					for (int b = 0; b <= n; b++) {


						if (2 * a + b + d != 2 * n) continue; //"남은 알 개수와 이미 쓴 길이를 합쳐서 전체 길이 2n” 여야 실제로 도달 가능한 상태라는 뜻
						//남은 통알(a)한 알당 2개의 반쪽을 준다는 뜻, b는 이미 반알 로 분리된 알약 수

						ll cnt = 0;

						if (a > 0) cnt += dp[a - 1][b + 1][d + 1];
						if (b > 0) cnt += dp[a][b - 1][d + 1];

						dp[a][b][d] = cnt;
					}
				}
			}


			cout << dp[n][0][0] << "\n";
		}

		
	}

}

namespace Sol {
	typedef long long ll;
	ll n, dp[31][31];

	ll go(int whole, int not_whole) {
		if (whole == 0 && not_whole == 0) return 1;
		ll& ret = dp[whole][not_whole];

		if (ret) return ret;

		if (whole > 0) ret += go(whole - 1, not_whole + 1);
		if (not_whole > 0) ret += go(whole , not_whole - 1);

		return ret;

	}

	void Sol() {
		while (true) {
			cin >> n;
			if (n == 0) break;

			cout << go(n, 0) << "\n";
		}
	}
}

int main() {
	MySol_2::SOl_2();
}