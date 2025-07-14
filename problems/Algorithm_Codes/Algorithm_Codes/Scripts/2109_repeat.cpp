#include <bits/stdc++.h>
using namespace std;

int n, p, d;
vector<pair<int, int>> v;

priority_queue<int,vector<int>, greater<int>> pq;
int ret;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (pq.size() >= v[i].first) {
			pq.pop();
		}

		pq.push(v[i].second);
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";
}