#include <bits/stdc++.h>
using namespace std;

int n;
int num, result, mem, exTime, lang, len;
string id;

map<string, int> m1; // {id, 틀린 횟수}
map<string, bool> m2; //문제를 푼 사람들
vector<string> solver; //문제 푼 사람들


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num >> id >> result >> mem >> exTime >> lang >> len;

		if (id == "megalusion") continue;
		if (result == 4 && !m2[id]) { m2[id] = true; solver.push_back(id); }
		else {
			if (!m2[id])
				m1[id]++;
		}
	}

	if (solver.size() == 0) cout << 0 << "\n";
	else {
		int cnt = 0;
		for (auto s : solver) {
			cnt += m1[s];
		}

		double ratio = ((double)(solver.size()) / (solver.size() + cnt)) * 100;


		//round(ratio) : 실수 ratio와 가장 가까운 정수
		//fabs(ratio - round(ratio)) < 1e-9) :실수 ratio와 그와 가장 가까운 정수의 차(절댓값)이 0.000000001이하인가
		if (fabs(ratio - round(ratio)) < 1e-9) {  // 정수 판별 (부동소수점 오차 고려)
			cout << fixed << setprecision(1) << ratio << "\n";
		}
		else {
			cout << fixed << setprecision(9) << ratio << "\n";
		}
	}

}