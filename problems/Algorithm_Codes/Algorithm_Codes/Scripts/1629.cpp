#include <bits/stdc++.h>
using namespace std;

//--------------------------------My Solution ------------------------------------------//

// 개념 : 2의 64승은, 2의 32승 * 2의 32승 과 같다는 점을 이용함. ->단순 반복문으로 제곱할 때보다 시간복잡도 줄어듦!(logN)
// 개념 : (a*b)%c == ((a%c)*(b%c))%c 와 같다.
long long multi(int a, int b, int c)
{
	if (b == 1) {
		return a % c;
	}


	long long ret;
	if (b & 1) { //b가 홀수
		ret = (multi(a, b / 2, c) * multi(a, b / 2, c))%c;
		ret = (ret * a) % c;

		return ret;
	}
	else { //b가 짝수
		ret= (multi(a, b / 2, c) * multi(a, b / 2, c))%c;

		return ret;
	}
}

//--------------------------------------------------------------------------------------//

//----------------------------Solution 1 ------------------------------------------------//
typedef long long ll;
ll go(ll a, ll b, ll c) {
	if (b == 1) return a % c;

	ll ret = go(a, b / 2, c);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret * a%c) % c; //b가 홀수인 경우
	return ret;
}
//--------------------------------------------------------------------------------------//
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << multi(A, B, C) << "\n"; //My Solution
	//cout << go(A, B, C) << "\n"; // Solution 1
	return 0;
}