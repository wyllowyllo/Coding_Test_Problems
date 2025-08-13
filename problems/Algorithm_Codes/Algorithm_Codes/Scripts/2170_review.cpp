#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;
typedef long long ll;
ll ret;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	int s = v[0].first; int e = v[0].second;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first > e) {
			ret += e - s;
			s = v[i].first;
			e = v[i].second;
		}

		else if (v[i].second > e) {
			e = v[i].second;
		}
	}

	ret += e - s ;
	cout << ret << "\n";
}