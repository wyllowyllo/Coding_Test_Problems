#include <bits/stdc++.h>
using namespace std;


namespace My {

	//이분 탐색을 해야 함을 알아챘지만, 무엇을 left,right,mid로 잡아야 할지 꽤 고민했음
	//left는 블루레이 하나에 담을 최소 시간(분)이므로 1로 설정하고, right는 강의 전체 시간의 합으로 설정함(전체강의를 하나의 블루레이로 담을 수 있는 크기)
	//최적화하려면, left는 가장 짧은 강의의 시간으로 설정해도 될 것 같음.

	//블루레이 하나의 시간을 mid라고 정했을 때, 전체 강의를 m개의 블루레이로 담아 나눌 수 있는지 검사
	//만약 할 수 있다면, right를 mid-1로 갱신해 더 작은 범위로도 가능한지 다시 검사
	//만약 할 수 없다면, left이하부분 또한 모두 될 가능성이 없으므로, 범위를 더 크게 하기 위해 left를 mid+1로 갱신함
	int n, m;

	int lecture[100001];
	int total;


	const int MAX = 987654321;
	int ret = MAX;

	bool check(int len) {
		int bundle = 1;
		int remain = len;

		for (int i = 0; i < n; i++) {

			if (lecture[i] > len) return false;

			if (remain < lecture[i]) {
				bundle++;
				remain = len;
			}

			remain -= lecture[i];
		}


		return bundle <= m;
	}


	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);


		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> lecture[i];
			total += lecture[i];
		}
		int left = 1;
		int right = total;


		while (left <= right) {
			int mid = (left + right) / 2;
			if (check(mid)) {
				ret = min(ret, mid);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	//hi의 최댓값을 생각해 보면, 강의 전체를 담을 수 있는, 즉 강의 전체를 합친 값이 되어야 함을 알 수 있다.


	typedef long long ll;
	int n, m, lo, hi, ret, a[100004], sum, mx;

	bool check(int mid) {
		if (mx > mid) return false; //단위가 가장 긴 강의길이보다 작을 경우, 담기가 불가능함

		int temp = mid;
		int cnt = 0;
		for(int i=0;i<n;i++){
			if (mid - a[i] < 0) {
				cnt++;
				mid = temp;
			}

			mid -= a[i];
		}

		if (mid != temp) cnt++;
		return cnt <= m;
	}
	void Sol() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			mx = max(mx, a[i]);

		}

		lo = 0; hi = sum;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (check(mid)) {
				hi = mid - 1;
				ret = mid; //굳이 min()쓸필요 없이, 갱신되는 mid가 최소인 것이 확실하기 때문에 그냥 대입해도 됨.
			}
			else lo = mid + 1;
		}
	}
}

int main() {

	

}