#include <bits/stdc++.h>
using namespace std;

namespace mysol {
	//브루트포스로도 되긴하는데, 카데인알고리즘 씀

	int n;
	double tmp;

	double a = 1.0f;
	double ret = -1.0f;

	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a *= tmp;
			ret = max(ret, a);
			if (a < 1.0f) {
				a = 1.0f;
			}
		}

		cout << fixed << setprecision(3) << ret << "\n";
	}
}

namespace Sol {
	//그리디한 접근법
	//배열을 앞쪽에서부터 순회를 하면서, 각 인덱스에서 어떤 행동을 해야할까 를 기반으로 코드를 만들고, 답을 산출
	// 
	//가설 : 현재 인덱스의 값(현재값)이, 이전의 값(누적한 곱)과 현재값을 곱한 것보다
	// 더 작으면 -> 곱한다!(더 커지므로)
	// 더 크면(즉 누적곱에 현재값 곱한것보다 그냥 현재값이 더 큼) -> 곱하지 않는다(현재값 유지)


	int n;
	double psum[10001], a[10001], ret, b;

	void Sol() {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		double b = a[0]; //b는 누적값

		ret = b;

		for (int i = 1; i < n; i++) {
			if (a[i] > b * a[i]) b = a[i]; //현재값>누적값*현재값 이 될 경우, 곱하지 않고 새로 시작!
			else b *= a[i]; //현재값<누적값*현재값 일 경우 곱하기
			ret = max(b, ret);
		}


		printf("%.3lf", ret + 0.00001);
		/*
		실수연산은 제한된 정확도 때문에 부정확할 수 있음
		팁 : 실수형을 출력하는 문제는, ret + 0.00001이런식으로 작은 값을 더해서 출력하게끔 하면 정답이 되는 경우가 있음
		*/
		
	}
}

int main() {
	Sol::Sol();
}