#include <bits/stdc++.h>
using namespace std;

//--------------------------------My Solution ------------------------------------------//

// ���� : 2�� 64����, 2�� 32�� * 2�� 32�� �� ���ٴ� ���� �̿���. ->�ܼ� �ݺ������� ������ ������ �ð����⵵ �پ��!(logN)
// ���� : (a*b)%c == ((a%c)*(b%c))%c �� ����.
long long multi(int a, int b, int c)
{
	if (b == 1) {
		return a % c;
	}


	long long ret;
	if (b & 1) { //b�� Ȧ��
		ret = (multi(a, b / 2, c) * multi(a, b / 2, c))%c;
		ret = (ret * a) % c;

		return ret;
	}
	else { //b�� ¦��
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
	if (b % 2) ret = (ret * a%c) % c; //b�� Ȧ���� ���
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