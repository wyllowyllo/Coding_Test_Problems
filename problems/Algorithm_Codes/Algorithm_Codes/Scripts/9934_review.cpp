#include <bits/stdc++.h>
using namespace std;

int k, temp;

vector<int> t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> temp;
		t.push_back(temp);
	}

	int left, right, mid;

	left = 0; right = pow(2, k) - 2;
	queue<pair<int, int>>q;
	q.push({ left,right });
	int level = 1;
	int cnt = 0;

	while (q.size()) {
		tie(left, right) = q.front(); q.pop();


		if (left == right) { cout << t[left] << " "; continue; }

		mid = (left + right) / 2;
		cout << t[mid] << " ";
		cnt++;
		
		if (cnt == level) {
			cout << "\n";
			level = level * 2;
			cnt = 0;
		}
		q.push({ left,mid - 1 });
		q.push({ mid + 1,right });
	}
	


}