#include <bits/stdc++.h>
using namespace std;

int n;
int d, w;
vector<pair<int, int>> v;
priority_queue<int,vector<int>, greater<int>> pq;

int ret;

#pragma region Sol_1

void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back({ d,w });
	}

	sort(v.begin(), v.end());

	for (auto& i : v) {
		pq.push(i.second);
		if (pq.size() > i.first) {
			pq.pop();
		}
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_2

vector<int> a[1001];
int mx;
priority_queue<int> max_heap;
#pragma endregion

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		a[d].push_back(w);
		mx = max(mx, d);
	}

	for (int i = mx; i >= 1;i--) {
		for (int j : a[i]) {
			max_heap.push(j);
		}

		if (!max_heap.empty()) {
			ret += max_heap.top();
			max_heap.pop();
		}
		
	}

	cout << ret << "\n";
}