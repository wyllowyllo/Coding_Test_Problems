#include <bits/stdc++.h>
using namespace std;

namespace My {
	//투포인터를 활용하여 풀었음
	int t;
	int n, m;
	int ret;


	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> t;

		while (t--) {
			ret = 0;
			cin >> n >> m;
			vector<int> A(n);
			vector<int> B(m);

			for (int i = 0; i < n; i++) {
				cin >> A[i];
			}
			for (int i = 0; i < m; i++) {
				cin >> B[i];
			}

			sort(A.begin(), A.end());
			sort(B.begin(), B.end());

			int j = 0;

			for (int i = 0; i < n; i++) {


				for (j; j < m;) {
					if (A[i] > B[j]) {
						j++;
					}
					else break;
				}

				ret += j;
			}

			cout << ret << "\n";
		}
	}
}

namespace Sol {
	//여기서는 이분 탐색 개념을 활용하여 문제를 해결함
	//직접 이분 탐색 구현하여 풀어도 되지만, lower_bound or upper_bound함수 써서 해도 됨
	//주의 : lower_bound와 upper_bound는 반드시 정렬된 배열에서 써야 함!

	//lower_bound : 특정 값 '이상'인 첫번째 위치 반환
	//upper_bound : 특정 값 '초과'인 첫번째 위치 반환
	int t, n, m;

	void Sol() {
		cin >> t;

		while (t--) {
			int ret = 0;
			cin >> n >> m;

			vector<int> a(n), b(m);

			for (int i = 0; i < n; i++) cin >> a[i];
			for (int i = 0; i < m; i++) cin >> b[i];

			sort(b.begin(), b.end());
			sort(a.begin(), a.end());

			for (int i = 0; i < n; i++) {
				//b 요소 중 a[i] 미만(<) 의 개수 세기
				auto pos = lower_bound(b.begin(), b.end(), a[i]); //a[i]이상인 첫번째 원소 위치 반환함 -> a[i] 이상인 첫 번째 값을 찾아 위치 반환
				ret += (int)(pos - b.begin()); //iterator -> int
			}

			cout << ret << "\n";
		}

	}
}
int main() {

	
}