#include <bits/stdc++.h>
using namespace std;

int n;
int from, to;

vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;

		v.push_back({ to,from });

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (pq.empty() || pq.top() <=v[i].second) {
			pq.push(v[i].first);
		}
	}
	cout << pq.size() << "\n";
}