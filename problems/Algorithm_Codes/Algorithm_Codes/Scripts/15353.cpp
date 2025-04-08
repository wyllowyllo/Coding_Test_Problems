#include <bits/stdc++.h>
using namespace std;

string a, b,ret;
int n1,n2,sum,carry;

#pragma region MySol

void MySol() {
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int s = min(a.size(), b.size());

	for (int i = 0; i < s; i++) {
		n1 = a[i] - '0';
		n2 = b[i] - '0';


		sum = (n1 + n2 + carry) % 10;
		carry = (n1 + n2 + carry) / 10;

		ret += sum + '0';

	}

	if (a.size() > s) {
		for (int i = s; i < a.size(); i++) {
			sum = ((a[i] - '0') + carry) % 10;
			carry = ((a[i] - '0') + carry) / 10;

			ret += sum + '0';
		}
	}
	else if (b.size() > s) {
		for (int i = s; i < b.size(); i++) {
			sum = ((b[i] - '0') + carry) % 10;
			carry = ((b[i] - '0') + carry) / 10;

			ret += sum + '0';
		}
	}

	if (carry) ret += "1";

	reverse(ret.begin(), ret.end());
	cout << ret << "\n";
}
#pragma endregion


#pragma region Sol_1

//나는 두 문자열을 reverse시켜, 가장 낮은 자리수부터 합산해가는 식으로 처리함
//여기서는 .back()을 사용하여 가장 뒤의 수(가장 낮은 자리수)끼리 합산하고, pop()하는 식으로 함


string string_add(string a, string b) {
	int sum = 0;
	string ret;

	while (a.size() || b.size() || sum) { //두 문자열 중 하나가 남아있거나, 올림수가 있다면 반복
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.size() - '0';
			b.pop_back();
		}
		ret += (sum % 10) + '0'; //숫자를 문자로 변환
		sum /= 10; //carry 만 남김

	}

	reverse(ret.begin(), ret.end());
	return ret;

}

void Sol_1() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	cout << string_add(a, b) << '\n';
}
#pragma endregion

int main() {
	
}