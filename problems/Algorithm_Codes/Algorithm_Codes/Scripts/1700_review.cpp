#include <bits/stdc++.h>
using namespace std;

namespace My {

	//멀티탭에 남은 구멍이 없을 때, 미래에 사용될 시점이 가장 나중인 것을 멀티탭에서 뽑는다!

	int n, k;
	vector<int> v;


	int tmp;
	int cnt;

	queue<int> use[101]; //전기용품 사용 시점
	int pluged[101];// 어느 전기용품이 현재 멀티탭에 연결되어 있는가

	vector<int> multi;

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n >> k;

		for (int i = 0; i < k; i++) {
			cin >> tmp;
			v.push_back(tmp);
			use[tmp].push(i); //각 전기용품 사용시점 기록
		}

		for (int i = 0; i < k; i++) {

			if (pluged[v[i]]) {
				use[v[i]].pop();
				continue;
			}



			if (multi.size() == n) {

				int max = 0;
				int pos = 0;
				for (int j = 0; j < multi.size(); j++) {
					int num = multi[j];
					if (use[num].empty()) {
						pos = j;
						break;
					}
					if (max < use[num].front()) {
						max = use[num].front();
						pos = j;
					}
				}

				pluged[multi[pos]] = 0;
				multi.erase(multi.begin() + pos);
				cnt++;
			}

			multi.push_back(v[i]);
			use[v[i]].pop();
			pluged[v[i]] = 1;
		}

		cout << cnt << "\n";
	}
}

namespace Sol {
	//Memory Paging Optimal Algorithm
	//알고리즘은 바로 떠올렸는데, 그걸 구현하는게 오래 걸림..
	//멀티탭에 꽂혀있지 않은 전자기기를 쓰려 할 때, 멀티탭이 가득 차있다면,
	//멀티탭에 있는 전자기기 중 미래에 사용되는 시점이 언제인지 각각 알아내서
	//가장 나중에 쓰이는(또는 더 이상 쓰이지 않음) 전자기기를 멀티탭에서 제거한다(find,erase사용)

	int k, n, a[104], visited[104], cnt;
	const int INF = 987654321;
	vector<int> v;

	void sol() {
		cin >> k >> n;

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				if (v.size() == k) {
					int last_idx = 0, pos;

					for (int _a : v) {
						int here_pick = INF;
						for (int j = i + 1; j < n; j++) {
							if (_a == a[j]) {
								here_pick = j; break;
							}
						}

						if (last_idx < here_pick) {
							last_idx = here_pick;
							pos = _a;
						}
					}
					visited[pos] = 0;
					cnt++;
					v.erase(find(v.begin(), v.end(), pos));
				}
				v.push_back(a[i]); visited[a[i]] = 1;
			}
		}
		cout << cnt << "\n";
	}

	
}
int main() {
	

}