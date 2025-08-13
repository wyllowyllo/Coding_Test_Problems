#include <bits/stdc++.h>
using namespace std;

int n, p;
int sum;
int ret = -1004;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;

		sum += p;
		ret = max(ret, sum);
		if (sum < 0) sum = 0;

	}

	cout << ret << "\n";
}