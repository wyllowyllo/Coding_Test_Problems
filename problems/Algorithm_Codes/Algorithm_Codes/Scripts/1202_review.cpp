#include <bits/stdc++.h>
using namespace std;

int n, k;
int m, v, c;

vector<pair<int, int>> jems;
vector<int> bags;

priority_queue<int> pq;

typedef long long ll;
ll ret;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jems.push_back({ m,v });
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bags.push_back(c);
	}

	sort(jems.begin(), jems.end());
	sort(bags.begin(), bags.end());


	int j=0;
	for (int i = 0; i < bags.size(); i++) {

		int capacity = bags[i];

		for (j; j < jems.size(); j++) {
			if (capacity >=jems[j].first) {
				pq.push(jems[j].second);
			}
			else break;
		}

		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}

	}
	cout << ret << "\n";

}