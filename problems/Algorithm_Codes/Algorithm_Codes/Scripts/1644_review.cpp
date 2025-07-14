#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n;
	int a[4000001];
	int ret;
	vector<int> era() {
		vector<int> v;

		for (int i = 2; i <= n; i++) {
			if (a[i] == 1) continue;
			for (int j = i * 2; j <= n; j += i) {
				a[j] = 1;
			}
		}

		for (int i = 2; i <= n; i++)
			if (a[i] == 0)
				v.push_back(i);

		return v;
	}


	void sol() {
		cin >> n;
		vector<int> v = era();

		if (v.empty()) {
			cout << 0 << "\n";
			return;
		}

		int sum = 0;
		int j = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
			if (sum == n) {
				ret++;
			}
			else if (sum < n) continue;
			else {
				while (sum > n) {
					sum -= v[j];
					j++;
				}

				if (sum == n) ret++;
			}
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	bool che[4000001];
	int n, a[2000001], p, lo, hi, ret, sum;

	void sol() {
		scanf("%d", &n);

		for (int i = 2; i <= n; i++) {
			if (che[i]) continue;
			for (int j = i * 2; j <= n; j += i)
				che[j] = 1;
		}

		for (int i = 2; i <= n; i++) {
			if (!che[i]) a[p++] = i;
		}

		while (1) {
			if (sum >= n) sum -= a[lo++];
			else if (hi == p) break;
			else sum += a[hi++];
			if (sum == n) ret++;
		}

		printf("%d\n", ret);
	}
}

int main() {

}

