#include <bits/stdc++.h>
using namespace std;

namespace My {
	//자릿수 늘려 가며 뒤 숫자를 남아있는 성냥개비로 만들어 감
//각 자릿수에서 가능한 한 큰(또는 작은)수를 만들면 최대(또는 최소)를 구할 수 있지 않을까 잠깐 생각했으나,
//이게 숫자마다 필요한 성냥개비 개수가 각각 다르고, 그렇기 때문에 그리디하게 해버리면 남은 성냥개비 때문에 최적해보다 자리수가 늘어나거나 줄어드는 상황이 생길수도 있을거 같음.. 
// 따라서 그리디는 안될거 같고.. dp로 해야 할듯

//long long으로도 커버가 안되는 답의 범위가 문제인 듯.. string으로 해야할 듯

//현재 dp 테이블은, string dp_max[55][101]; // idx, cnt → 값 저장 이런 식을 되어 있음.
//하지만 go_max(idx, cnt, num)은 num에 따라 다른 경로를 만들 수 있음.
//즉, dp_max[idx][cnt]에 단 하나의 값만 저장해두면 안 됨.
// 왜냐하면 다른 num과 함께 같은 idx, cnt로 들어왔을 때 다른 결과가 될 수도 있는데 이미 저장된 하나의 결과만 써버리기 때문

//두번째 시도 : '남은 성냥 개수' 만 상태값으로 한다.


	int t, n;
	string dp_max[55][101]; //인덱스, 남은 성냥 수를 상태값으로
	string dp_min[55][101]; //인덱스, 남은 성냥 수를 상태값으로

	vector<int> v[8]; //성냥개비 개수(2~7)에 따라 만들 수 있는 숫자

	bool cmp_max(string a, string b) {
		if (a.size() == b.size()) return a > b;
		return a.size() > b.size();
	}

	bool cmp_min(string a, string b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	}
	void init() {
		v[2].push_back(1);
		v[3].push_back(7);

		v[4].push_back(4);

		v[5].push_back(2);
		v[5].push_back(3);
		v[5].push_back(5);

		v[6].push_back(0);
		v[6].push_back(6);
		v[6].push_back(9);

		v[7].push_back(8);

		
	}

	string go_max(int idx, int cnt, string num) {
		if (cnt == 0) return num;
		if (cnt < 2) return "-1";

		string& ret = dp_max[idx][cnt];
		if (ret != "-1") return ret;

		for (int i = 2; i <= 7; i++) {
			if (cnt < i) break;

			for (int j : v[i]) {
				ret = max(ret, go_max(idx + 1, cnt - i, num + to_string(j)), cmp_max);
			}
		}

		return ret;
	}

	string go_min(int idx, int cnt, string num) {
		if (cnt == 0) return num;
		if (cnt < 2) return "987654321";

		string& ret = dp_min[idx][cnt];
		if (ret != "987654321") return ret;

		for (int i = 2; i <= 7; i++) {
			if (cnt < i) break;

			for (int j : v[i]) {
				if (idx == 0 && j == 0) continue;
				ret = min(ret, go_min(idx + 1, cnt - i, num + to_string(j)), cmp_min);
			}
		}

		return ret;
	}

	string Mindp[101];
	string Maxdp[101];

	void sol() {
		init();

		//fill(&dp_max[0][0], &dp_max[0][0] + 55 * 101, "-1");
		//fill(&dp_min[0][0], &dp_min[0][0] + 55 * 101, "987654321");

		//두번째 시도
		fill(Maxdp, Maxdp + 101, "#");
		fill(Mindp, Mindp + 101, string(101, '9'));

		Maxdp[0] = Mindp[0] = "";

		//Mindp 
		for (int i = 2; i <= 100; i++) {
			for (int j = 2; j <= 7; j++) {
				for (int k : v[j]) {

					if (i - j >= 0 && Mindp[i - j] != string(101, '9')) {
						string tmp = Mindp[i - j] + to_string(k);
						if (tmp[0] == '0') continue;
						Mindp[i] = min(Mindp[i], tmp, cmp_min);
					}
				}
			}
		}

		//Maxdp 
		for (int i = 2; i <= 100; i++) {
			for (int j = 2; j <= 7; j++) {
				for (int k : v[j]) {

					if (i - j >= 0 && Maxdp[i - j] != "#") {
						string tmp = to_string(k) + Maxdp[i - j];
						//if (tmp[0] == '0' && tmp.size() > 1) continue;
						if (Maxdp[i] == "#" || cmp_max(tmp, Maxdp[i])) {
							Maxdp[i] = tmp;
						}
					}
				}
			}
		}

		cin >> t;


		while (t--) {
			cin >> n;

			//첫번째 시도
			//cout << go_min(0, n, "") << " "<< go_max(0, n,"") << "\n";

			//두번째 시도
			cout << Mindp[n] << " " << Maxdp[n] << "\n";
		}
	}
}

namespace Sol {
	//이 문제의 최대범위는? 최대 100개의 성냥개비가 있을 때 50자리 수까지 가능
	//따라서 int(10자리까지 가능), long long (20자리까지 가능) 으로도 커버할 수 없다
	//string을 기반으로 문제를 풀어야 함!



	
	//최대값 구하기
	//최대값을 구할 땐, 그리디하게 풀어야 함!
	//왜냐하면, 자리수를 크게 만들면 그게 최대치가 되기 떄문!
	//따라서, 최대한 자리수를 크게 만들기 위해서는, 가장 성냥을 적게 소모하는 1을 최대한 길게 붙여야 함!
	//그러나 모두 1로만 해버리면 성냥이 나누어 떨어지지 않을 수 있음
	//2가 짝수 개의 성냥을 소모하므로, 홀수 개의 성냥을 소모하는 숫자가 필요! ->그래야 나누어떨어지니까
	//가장 성냥을 적게 소모하면서, 홀수 개의 성냥을 소모하는 숫자는 7이다(3개 소모)
	//정리하자면, 남은 성냥 개수가 홀수라면, 짝수개로 만들기 위해  7을 하나 생성.
	//남은 성냥 개수가 짝수개가 되면, 그걸 모두 소모하여 1을 계속 생성하여 최대 자릿수의 숫자를 생성한다!
	//이 수가 가능한 수 중 가장 긴 수가 되므로, 최대값이 된다!


	//최소값 구하기
	//최대값은, 사이즈를 크게 하면 그게 최대가 되는 것이 자명하므로 그리디로 풀 수 있으나, 최소값은 그렇게 할 수 없다..
	//어떻게 하면, 최소가 될까?
	//따라서, 모든 경우의 수를 생각하되, 시간복잡도를 고려하면 dp로 접근해야 한다
	//상태값은 어떻게? -> 성냥개수 n일떄의 최솟값을 쌓아, 글로벌한 최소값을 만들자! (성냥 개수를 상태값으로!)
	//초기화는 어떻게? 최소값을 구하는 것이므로, 초기화는 최댓값으로 해야 한다!
	//이때 가능한 답의 최대 자리수는 50자리이므로, 51자리가 최대값이 될 것이다!



	int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, t, n;
	string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";
	
	string get_min_str(string a, string b) {
		if (a.size() == b.size()) return (a < b ? a : b);
		if (a.size() < b.size()) return a;
		return b;
	}
	string findMax(int here) {
		string ret = "";
		if (here & 1) { ret += '7'; here -= 3; }
		while (here) {
			ret += '1';
			here -= 2;

		}
		return ret;
	}


	
	void sol_1() { //그리디와 dp(바텀업)
		cin >> t;

		fill(dp, dp + 104, MAX_STR);
		dp[0] = "";

		for (int i = 2; i < 104; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i - a[j] < 0) continue;
				if (j == 0 && dp[i - a[j]] == "") continue;
				dp[i] = get_min_str(dp[i], dp[i - a[j]] + to_string(j));
			}
		}

		while (t--) {
			cin >> n;
			cout << dp[n] << " " << findMax(n) << "\n";
		}
		
		
		
	}


	string findMin(int here) {
		if (here == 0) return "";
		string& ret = dp[here];
		if (ret != MAX_STR) return ret;

		for (int i = 0; i <= 9; i++) {
			if (here - a[i] < 0) continue;
			if (here == n && i == 0) continue;

			ret = get_min_str(ret, to_string(i) + findMin(here - a[i]));
			return ret;
		}
	}
	void sol_2() { //탑다운 방식으로 풀기

		cin >> t;
		while (t--) {
			cin >> n;
			fill(dp, dp + 104, MAX_STR);
			cout << findMin(n) << " " << findMax(n) << "\n";
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//My::sol();
	//Sol::sol_1();
	Sol::sol_2();
}