#include <bits/stdc++.h>
using namespace std;


namespace BinarySearch {
	int binarySearch(const vector<int>& arr, int target) {
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return -1;
	}
	void BS() {
		vector<int> arr = { 1,3,6,9,10,21,22,30 };
		int target = 6;
		int result = binarySearch(arr, target);

		if (result != -1) {
			cout << "Target found at index: " << result << "\n";
		}
		else {
			cout << "Target not found in the array\n";
		}

	}
}

namespace Q1 {

	int t;
	int n, m;

	vector<int> v1, v2;
	int tmp;

	string check(int num) {

		int left = 0;
		int right = v1.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (v1[mid] == num)
				return "I remember!";
			else if (v1[mid] < num)
				left = mid + 1;
			else
				right = mid - 1;
		}


		return "I forgot!";
	}

	void Q1() {
		cin >> t;

		while (t--) {
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> tmp;
				v1.push_back(tmp);
			}

			sort(v1.begin(), v1.end());

			cin >> m;
			for (int i = 0; i < m; i++) {
				cin >> tmp;
				v2.push_back(tmp);
			}

			for (int i = 0; i < m; i++) {
				cout << check(v2[i]) << "\n";
			}
		}
		
	}
}

namespace Q2 {
	int n, m;
	int pen[300001];
	int maxCnt;
	int ret;

	bool check(int unit) {
		int cnt = 0; //묶음 개수

		for (int i = 0; i < m; i++) {
			cnt += pen[i] / cnt;
			if (pen[i] % cnt) cnt++;
		}


		return cnt <= n;
	}
	void Q2() {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> pen[i];
			maxCnt = max(maxCnt, pen[i]);
		}

		int left = 1;
		int right = maxCnt;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (check(mid)) {
				ret = min(mid, ret);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
}

namespace Q3 {

	int n;
	int a[1001];
	int cnt[1001];
	int prev[1001];

	int ret;
	int idx;
	void sol_1() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			int maxV = 0;

			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && maxV < cnt[j]) maxV = cnt[j];
			}

			cnt[i] = maxV + 1;
			ret = max(ret, cnt[i]);
		}
	}

	vector<int> v;
	void go(int idx) {
		if (idx == -1) return;

		v.push_back(a[idx]);
		go(prev[idx]);

		return;
	}
	void sol_2() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		fill(prev, prev + 1001, -1);
		fill(cnt, cnt + 1001,1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
					cnt[i] = cnt[j] + 1;
					prev[i] = j;
					if (ret < cnt[i]) {
						ret = cnt[i];
						idx = i;
					}
				}
			}
		}
		go(idx);
		for (int i = v.size() - 1; i >= 0; i--) {
			printf("%d ", v[i]);
		}
		
	}

	int lis[1001], len, num;

	void sol_3() {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);

			auto lowerPos = lower_bound(lis, lis + len, num);
			if (*lowerPos == 0) len++;
			*lowerPos = num;

		}

		printf("%d", len);
	}
}

int main() {

}