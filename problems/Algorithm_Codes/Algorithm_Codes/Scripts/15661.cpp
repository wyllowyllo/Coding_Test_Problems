#include <bits/stdc++.h>
using namespace std;

int n;
int a[21][21];

const int INF = 987654321;
int ret = INF;


int Compare(vector<int>& t1, vector<int>& t2) {
	int t1_sum=0, t2_sum = 0;

	for (int i = 0; i < t1.size(); i++) {
		for (int j = 0; j < i; j++) {
			t1_sum += a[t1[i]][t1[j]];
			t1_sum += a[t1[j]][t1[i]];
		}
	}

	for (int i = 0; i < t2.size(); i++) {
		for (int j = 0; j < i; j++) {
			t2_sum += a[t2[i]][t2[j]];
			t2_sum += a[t2[j]][t2[i]];
		}
	}

	return abs(t1_sum - t2_sum);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i < (1 << n)-1; i++) {
		vector<int> t1, t2;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) t1.push_back(j);
			else t2.push_back(j);
		}

		ret = min(ret, Compare(t1, t2));
	}

	cout << ret << "\n";
}