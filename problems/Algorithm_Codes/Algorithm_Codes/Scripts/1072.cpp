#include <bits/stdc++.h>
using namespace std;

namespace My {
	//실수 연산 오차 떄문에 좀 애먹음..
	//되도록이면 정수 연산하도록 변경하자

	typedef long long ll;
	ll x, y, z;
	ll lo, hi;

	ll ret = -1;
	bool check(ll mid) {

		// floor( (y+mid)/(x+mid)*100 ) > z
		//위를 소숫값 없이 판정 (부동소숫점 연산 오류 피하기 위함) 
		// ⇔ (y+mid)*100/(x+mid) ≥ z+1
		// ⇔ (y+mid)*100 >= (z+1)*(x+mid)

		return (y + mid) * 100 >= (z + 1) * (x + mid);
	}

	void MySol() {
		cin >> x >> y;


		z = (y * 100) / x;

		lo = 1;
		hi = 2 * x;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;

			if (check(mid)) {
				ret = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		cout << ret << "\n";
	}
}
namespace Sol {
	//나는 비율 계산할때 double 캐스팅을 사용하여 실수 연산을 했는데, 이게 실패 요인으로 작용
	//실수연산은 정확하지 않으니, 최대한 사용하지 말자!
	typedef long long ll;
	ll a, b, mid, ret = -1;

	void Sol() {
		cin >> a >> b;
		ll z = b * 100 / a;
		ll lo = 1, hi = 1e9;

		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if ((b + mid) * 100 / (a + mid) > z) {
				ret = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		cout << ret << "\n";
	}
}
int main() {
	
}