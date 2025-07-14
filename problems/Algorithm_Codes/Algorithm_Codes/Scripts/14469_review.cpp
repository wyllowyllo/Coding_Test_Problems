#include <bits/stdc++.h>
using namespace std;

int n;

int from, t,to;
vector<pair<int, int>> v;
//int ret;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> from >> t;
		//to = from + t;

		v.push_back({ from,t });

	}

	sort(v.begin(), v.end());

	int start = v[0].first;
	int end = start + v[0].second;

	for (int i = 1; i < n; i++) {
		if (v[i].first < end) end = end + v[i].second;
		else {
			start = v[i].first;
			end = start + v[i].second;
		}
	}

	cout << end << "\n";
	
}