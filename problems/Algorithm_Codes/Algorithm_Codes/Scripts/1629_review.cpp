
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

#pragma region Sol_1
//입력값 범위가 약 21억까지 이므로, 시간상 반복문으로 a의 거듭제곱을 구할 수 없다는 생각을 해야 함
//반복문 없이, a의 거듭제곱 값을 어떻게 구할 수 있을까? 에서 출발
//a의 4승 == a의 2승 * a의 2승 -> 이 아이디어 활용
//곱한 것들을 변수에다가 담아놓고, 그 변수를 활용하는 방법!

//두번째 제한사항 : 값의 범위
//a를 b번 곱할 경우, 값의 범위가 너무 커져서 오버플로우 남
//(a+b)%c == a%c + a%b, (a*b)%c == (a%c * b%c)%c 해당 아이디어 활용!

ll go(ll n, ll r) {
	if (r==1) {
		return n ;
	}

	if (r & 1) return ((go(n, r / 2) * go(n, r / 2))%c * go(n, 1))%c;
	else return (go(n, r / 2) * go(n, r / 2))%c;
}
void MySol() {
	long long v1 = a % c;

	cout<<go(v1, b)%c<<"\n";
	
}

#pragma endregion

#pragma region Sol_1



ll go_2(ll a, ll b) {
	if (b == 1) return a % c;

	ll ret = go_2(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret * a) % c;
	return ret;
}
void Sol_1() {
	
	cout << go_2(a, b) << "\n";
	
}
#pragma endregion


int main() {
	cin >> a >> b >> c;

	MySol();
	//Sol_1();
}