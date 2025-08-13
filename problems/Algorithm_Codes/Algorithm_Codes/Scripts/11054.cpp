#include <bits/stdc++.h>
using namespace std;


namespace My {
	int n;

	int cnt_ASC[1004];
	int cnt_DSC[1004];
	int len = 1;


	//경로 추적용
	//int prev_ASC[1004];
	//int prev_DSC[1004];

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;

		vector<int> a(n, 0);
		vector<int> b(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}

		fill(cnt_ASC, cnt_ASC + 1004, 1);
		fill(cnt_DSC, cnt_DSC + 1004, 1);

		/*fill(prev_ASC, prev_ASC + 1004, -1);
		fill(prev_DSC, prev_DSC + 1004, -1);*/

		//각 인덱스를 종점으로하는 증가하는 부분수열 최대길이
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && cnt_ASC[i] < cnt_ASC[j] + 1) {
					cnt_ASC[i] = cnt_ASC[j] + 1;
					//prev_ASC[i] = j;
				}
			}
		}



		//각 인덱스를 종점으로하는 감소 하는 부분수열 최대길이 -> 리버스 후 증가부분수열 그대로
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (b[j] < b[i] && cnt_DSC[i] < cnt_DSC[j] + 1) {
					cnt_DSC[i] = cnt_DSC[j] + 1;
					//prev_DSC[i] = j;
				}
			}
		}

		int pivotIdx;

		for (int i = 0; i < n; i++) {
			if (len < cnt_ASC[i] + cnt_DSC[n - i - 1] - 1) {
				len = cnt_ASC[i] + cnt_DSC[n - i - 1] - 1;
				pivotIdx = i;
			}


		}

		cout << len << "\n";


		//바이토닉 부분 수열 출력
	//int cur = pivotIdx;
	//	stack<int> tmp;
	//	while (true) {
	//		if (cur == -1) break;
	//		tmp.push(cur);
	//		cur = prev_ASC[cur];
	//	}
	//	while (tmp.size()) {
	//		cout << a[tmp.top()] << " ";
	//		tmp.pop();
	//	}
	//
	//	cur = prev_DSC[n - pivotIdx - 1];
	//	while (true) {
	//		if (cur == -1) break;
	//		cout << b[cur] << " ";
	//		cur = prev_DSC[cur];
	//	}
	}
}

namespace Sol {
	void sol() {
		int n;

		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> inc(n, 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i]) {
					inc[i] = max(inc[i], inc[j] + 1);
				}
			}
		}

		vector<int> dec(n, 1);

		for (int i = n-1; i >=0; i--) {
			for (int j = n-1; j > i; j--) {
				if (a[j] > a[i]) {
					dec[i] = max(dec[i], dec[j] + 1);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, inc[i] + dec[i] - 1);
		}

		cout << ans << "\n";
	}
}


int main() {
	
	


	
}