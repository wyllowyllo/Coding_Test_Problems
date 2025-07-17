#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
using namespace std;


namespace My {

	//18이하의 소수는? 2,3,5,7,11,13,17
	double dp[20][20][20];//라운드, A팀 score, B팀 score

	bool isPrime(int score) {
		if (score < 2) return false;
		if (score == 2) return true;
		if (score % 2 == 0) return false;

		for (int i = 3; i <= sqrt(score); i++) {
			if (score % i == 0) return false;
		}

		return true;
	}
	int a, b;
	double p_a, p_b;
	//double ret;


	double go(int A_score, int B_score, int round) {
		if (round == 18) {

			//1 - 두 팀 모두 소수로 득점하지 않은 확률 == 적어도 한 팀이 골을 소수로 득점할 확률
			if (!isPrime(A_score) && !isPrime(B_score))
			{
				return 1.0f;
			}

			return 0.0f;
		}

		double& ret = dp[round][A_score][B_score];
		if (ret != 0.0f) return ret;

		//A팀만 득점
		if (a > 0 && b < 100) ret += (double)(go(A_score + 1, B_score, round + 1) * p_a * (1 - p_b));

		//B팀만 득점
		if (b > 0 && a < 100) ret += (double)(go(A_score, B_score + 1, round + 1) * p_b * (1 - p_a));

		//A,B모두 득점 실패
		if (a < 100 && b < 100) ret += (double)(go(A_score, B_score, round + 1) * (1 - p_a) * (1 - p_b));

		//A,B모두 득점 성공
		if (a > 0 && b > 0) ret += (double)(go(A_score + 1, B_score + 1, round + 1) * p_a * p_b);


		return ret;
	}
	void sol() {
		cin >> a >> b;
		p_a = (double)a / 100;
		p_b = (double)b / 100;

		fill(&dp[0][0][0], &dp[0][0][0] + 20 * 20 * 20, 0.0f);

		double result = go(0, 0, 0);
		result = (double)(1 - result);
		cout << setprecision(16) << result << "\n";


		/* bottom up 방식*/
		/*dp[0][0][0] = 1.0;
		for (int r = 0; r < 18; r++) {
			for (int i = 0; i <= r; i++) {
				for (int j = 0; j <= r; j++) {
					double cur = dp[r][i][j];
					if (cur == 0) continue;

					dp[r + 1][i + 1][j] += cur * p_a * (1 - p_b);
					dp[r + 1][i][j + 1] += cur * (1 - p_a) * p_b;
					dp[r + 1][i + 1][j + 1] += cur * p_a * p_b;
					dp[r + 1][i][j] += cur * (1 - p_a) * (1 - p_b);
				}
			}
		}*/
		
	}
}

namespace Sol {
	//나는 dp초기화를 0.0f으로 했는데, 확률이 0이 될 가능성이 있으므로 사실 0으로 하면 안됨
	//또한, double형이므로, ==를 쓸 수 없다 -> 대소(>,<)를 대신 써야 함!
	//여기서는 dp를 -1로 초기화하고, 대소 관계를 활용하여 메모라이제이션 된 확률값을 가져온다
	
	//사실 나도 문제 풀때 -1로 초기화하는 것을 생각했으나, 이 문제는 각 경우의 수의 확률을 다 더해야 하므로 -1로 초기화시키면 문제가 된다 생각했음
	//여기서는 -1로 초기화하되, ret에 누적(+=)하기 전 ret=0.0으로 다시 초기화함
	//로직을 보면, 굳이 나처럼 조건분기 달 필요 없다는 걸 알수 있다


	const int n = 18;
	bool isP[20];

	double a, b, dp[20][20][20];

	double go(int idx, int x, int y) {
		if (idx == n) return isP[x] || isP[y] ? 1.0 : 0.0;

		double& ret = dp[idx][x][y];
		if (ret > -0.5) return ret;

		ret = 0.0;
		ret += go(idx + 1, x + 1, y) * a * (1 - b);
		ret += go(idx + 1, x + 1, y + 1) * a * b;
		ret += go(idx + 1, x, y + 1) * (1 - a) * b;
		ret += go(idx + 1, x, y) * (1 - a) * (1 - b);
		return ret;
	}
	void era() {
		fill(isP, isP + 20, 1);
		isP[0] = 0; isP[1] = 0;

		for (int i = 2; i <= 20; i++) {
			for (int j = i + i; j <= 20; j += i) {
				isP[j] = 0;
			}
		}
	}
	void sol() {
		scanf("%lf %lf", &a, &b);
		a /= 100; b /= 100;
		era();

		memset(dp, -1, sizeof(dp));
		printf("%.6lf", go(0, 0, 0));
	}
}

int main() {
	Sol::sol();
	
}