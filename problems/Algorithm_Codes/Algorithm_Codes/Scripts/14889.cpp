#include <bits/stdc++.h>
using namespace std;

int n;
int a[21][21];

int team[21];

const int INF = 987654321;
int ret= INF;

#pragma region MySol

int GetDiff() {
	int ret = 0;

	vector<int> t1, t2;
	for (int i = 0; i < n; i++) {
		if (team[i] == 0) t1.push_back(i);
		else t2.push_back(i);
	}

	int t1_sum = 0, t2_sum = 0;
	for (int i = 0; i < t1.size(); i++) {
		for (int j = 0; j < i; j++) {
			t1_sum += a[t1[i]][t1[j]];
			t1_sum += a[t1[j]][t1[i]];
		}
	}

	for (int i = 0; i < t2.size(); i++) {
		for (int j = 0; j < i; j++) {
			t2_sum += a[t2[i]][t2[j]];
			t2_sum += a[t2[j]][t2[i]];
		}
	}


	return abs(t2_sum - t1_sum);
}
void MakeTeam(int idx, int num) {
	if (num == n / 2) {
		ret = min(ret, GetDiff());
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		team[i] = 1;

		MakeTeam(i, num + 1);

		team[i] = 0;
	}

}

void MySol() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	MakeTeam(-1, 0);
	cout << ret << "\n";
}
#pragma endregion


int s[21][21];
#pragma region Sol_1

//비트마스킹 사용한 풀이

int go(vector<int>& a, vector<int>& b) {
	pair<int, int> ret;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) continue;

			ret.first += s[a[i]][a[j]];
			ret.second += s[b[i]][b[j]];
		}
	}

	return abs(ret.first - ret.second);
}
void Sol_1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++) { //모든 경우의 수 탐색
		if (__builtin_popcount(i) != n / 2) continue; //정확히 1의 개수가 절반이 되는 경우에만 

		vector<int> start, link;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) start.push_back(j);
			else link.push_back(j);
		}

		ret = min(ret, go(start, link));

	}

	cout << ret << "\n";
}

#pragma endregion


int main() {
	Sol_1();
}