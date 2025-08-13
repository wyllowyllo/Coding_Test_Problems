#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, l;
	int s, e;
	vector<pair<int, int>> v;

	int ret = 0;
	int idx = -1;//설치된 널판지 끝 인덱스


	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n >> l;

		for (int i = 0; i < n; i++) {

			cin >> s >> e;
			v.push_back({ s,e });
		}

		sort(v.begin(), v.end());

		for (auto i : v) {
			if (i.first > idx) { //새로 설치 시작
				int cnt = (i.second - i.first) / l; //필요한 널판지 개수
				if (((i.second - i.first) % l)) cnt++;

				ret += cnt;
				idx = i.first + cnt * l; //널판지 끝점 갱신
			}
			else {
				if (i.second <= idx) continue;

				int cnt = (i.second - idx) / l; //필요한 널판지 개수
				if (((i.second - idx) % l)) cnt++;

				ret += cnt;
				idx = idx + cnt * l; //널판지 끝점 갱신
			}
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	int n, m, idx, ret, b;

	void sol() {
		cin >> n >> m;
		vector<pair<int, int>> a(n);

		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

		sort(a.begin(), a.end());

		for (int i = 0; i < n; i++) {
			if (a[i].second <= idx) continue;
			if (idx < a[i].first) {
				b = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
				idx = a[i].first + b * m;
			}
			else {
				b = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
				idx = idx + b * m;
			}
			ret += b;
		}
	}
}
int main() {

	
}