#include <bits/stdc++.h>
using namespace std;


namespace My {

	int a, b;

	bool find(vector<int>& v, int target) {
		int left = 0;
		int right = v.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] == target)return true;
			else if (v[mid] < target) left = mid + 1;
			else right = mid - 1;
		}


		return false;
	}

	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> a >> b;
		vector<int> A(a);
		vector<int> B(b);

		for (int i = 0; i < a; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < b; i++) {
			cin >> B[i];
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int a_size = A.size();
		int b_size = B.size();

		for (int i = 0; i < a; i++) {
			if (find(B, A[i])) {
				a_size--;
			}
		}
		for (int i = 0; i < b; i++) {
			if (find(A, B[i])) {
				b_size--;
			}
		}

		cout << a_size + b_size << "\n";
	}
}

namespace Sol {
	int n, m, cnt, temp;
	map<int, int> _map;

	void Sol() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp; _map[temp]++;
		}

		for (int i = 0; i < m; i++) {
			cin >> temp; _map[temp]++;
		}

		//맵 순환하는 방법
		for (auto it : _map) {
			if (it.second == 1) cnt++;
		}

		cout << cnt << "\n";
	}


}

int main() {
	Sol::Sol();
}