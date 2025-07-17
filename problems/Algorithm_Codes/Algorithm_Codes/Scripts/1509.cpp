#include <bits/stdc++.h>
using namespace std;

namespace My {
	//문자열의 각 위치에서 팰린드롬을 생성할 때, 가능한 한 길게 생성하면 되지 않을까?
//문자열 처음부터 시작해서, 할 수 있는 한 가장 긴 팰린드롬 만드는 식으로 분리 -> 반례있음

//전체 문자열에서, 가장 긴 팰린드롬 찾아서, 그 부분 기준으로 문자열 분리하는거 반복하는 식으로 해야 할듯함
//이것도 아님...  ->가장 긴 팰린드롬부터 잘라나가는” 그리디 전략 자체가 최소 컷을 보장하지 않습니다.

//dp로 문자열 시작~끝에서 팰린드롬인지 아닌지 구했으니, 그냥 각 인덱스에서 가능한 사이즈 전부 체크해서, 그때의 분리 횟수 최소화되는걸 구하자
//dp배열을 2개 써야 함
	string s;

	int dp[2504][2504]; //start ~ end까지의 문자열이 팰린드롬인가?
	int dp2[2504];
	const int INF = 1e9;
	//pair<int,int> find_pal(int start, int end) { //가장 긴 팰린드롬 부분문자열 찾기
	//	int len = -1;
	//	int i, j;
	//	int ns, ne;
	//
	//	for (i = start; i <=end; i++) {
	//		for (j = end; j >= i; j--) {
	//			if (len >=j - i) break;
	//			if (dp[i][j]) {
	//				len = j - i;
	//				ns = i;
	//				ne = j;
	//				break;
	//			}
	//		}
	//	}
	//
	//	return { ns,ne };
	//}

	//int go(int start, int end) {
	//	int ns, ne;
	//	tie(ns, ne) = find_pal(start, end);
	//
	//	int ret = 1;
	//
	//	if (ns > start) ret += go(start, ns - 1);
	//	if(ne<end) ret += go(ne+1, end);
	//
	//	return ret;
	//}

	int go(int idx) {
		if (idx == s.size()) return 0;

		int& ret = dp2[idx];
		if (ret != INF) return dp2[idx];

		for (int _size = 0; idx + _size < s.size(); _size++) {
			if (dp[idx][idx + _size]) {
				ret = min(ret, go(idx + _size + 1) + 1);
			}
		}

		return ret;
	}

	void sol() {
		cin >> s;

		//start ~ end까지의 문자열이 팰린드롬인지, 아닌지 저장
		for (int i = 0; i < s.size(); i++) {
			dp[i][i] = 1;
		}
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = 1;
			}
		}

		for (int _size = 2; _size <= s.size(); _size++) {
			for (int i = 0; i < s.size(); i++) {

				if (i + _size >= s.size()) break;

				if (s[i] == s[i + _size] && dp[i + 1][i + _size - 1]) {
					dp[i][i + _size] = 1;
				}
			}

		}
		fill(&dp2[0], &dp2[0] + 2504, INF);

		cout << go(0) << "\n";

	}
}

namespace Sol {
	//DP배열을 2개 써야 하는 문제
	//팰린드롬 여부를 판단하는 2차원 배열 1개, 그리고 각 인덱스 부터 size만큼 분할 할 때의 분할 횟수 저장하는 1차원 배열 1개 

	//dp배열 2개 쓸 생각 못하고, 문제를 완탐으로 풀려는 생각을 먼저 하지 않고, 근거없이 그리디하게 풀려고 한게 패인인 듯함

	const int INF = 1e9;
	int dp[2504][2504]; //인덱스, 사이즈
	int dp2[2504]; //각 인덱스에서 size만큼 분할했을때(이때 팰린드롬이 되어야 함) 총 분할 횟수
	string s;

	int go(int here) {
		if (here == s.size()) return 0;
		if (dp2[here] != INF) return dp2[here];

		int& ret = dp2[here];
		for (int i = 1; here + i <= s.size(); i++) {
			if (dp[here][i]) ret = min(ret, go(here + i) + 1);
		}

		return ret;
	}

	void sol() {
		cin >> s;

		//팰린드롬이 되는 경우를 전처리
		for (int i = 0; i < s.size(); i++) dp[i][1] = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) dp[i][2] = 1;
		}

		for (int _size = 3; _size <= s.size(); _size++) {
			for (int j = 0; j + _size <= s.size(); j++) {
				if (s[j] == s[j + _size - 1] && dp[j + 1][_size - 2])
					dp[j][_size] = 1;
			}
		}

		fill(dp2, dp2 + 2504, INF);
		cout << go(0) << "\n";
	}
}

int main() {
	Sol::sol();
}