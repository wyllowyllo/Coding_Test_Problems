#include <bits/stdc++.h>
using namespace std;

int n,x;
int ret;
int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end());

	int left = 0; int right = n - 1;

	while (left < right) {
		if (v[left] + v[right] == x) {
			ret++;
			left++;
		}

		else if (v[left] + v[right] < x) left++;
		else right--;
	}
	cout << ret << "\n";
}