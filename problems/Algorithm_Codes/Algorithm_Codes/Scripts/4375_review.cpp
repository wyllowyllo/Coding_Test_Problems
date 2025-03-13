#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

#pragma region MySol

// long long으로도 커버할 수 없는 수가 생김 -> fail
void MySol() {
	while (true) {
		cin >> n;
		string num = "1";

		if (cin.eof() == true)
			break;

		while (stoll(num) % n != 0) {
			num += "1";
		}

		cout << num.size() << "\n";
	}
}
#pragma endregion

#pragma region Sol_1
//(a+b)%n == (a%n + b % n) % n;
//(a*b)%n == (a%n * b%n)%n;

void Sol_1() {
	while (scanf("%d", &n) != EOF) {
		ll cnt = 1, ret = 1;
		while (true) {
			if (cnt % n == 0) {
				printf("%lld\n", ret);
				break;
			}
			else {
				cnt = (cnt * 10) + 1; //1씩 늘리는 방법
				cnt %= n; //마지막에 mod하는게 아니라, 더할 때마다 mod연산 한다!
				ret++;
			}
		}
	}
}

#pragma endregion


int main() {
	Sol_1();
}