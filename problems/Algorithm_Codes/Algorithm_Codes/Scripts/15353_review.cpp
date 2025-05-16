#include <bits/stdc++.h>
using namespace std;


string a, b;
string ret;

int main() {
	cin >> a >> b;

	int len = min(a.size(), b.size());

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());


	int sum = 0;
	int carry = 0;
	int n1, n2;

	
	for (int i = 0; i < len; i++) {
		n1 = a[i] - '0';
		n2 = b[i] - '0';

		sum = (n1 + n2+carry) % 10;
		carry = (n1 + n2 + carry) / 10;
		ret += (char)(sum + '0');
	}

	for (int i = len; i < a.size(); i++) {
		n1 = a[i] - '0';
		sum=(n1+carry) % 10;
		carry = (n1 + carry) / 10;
		ret += (char)(sum + '0');
	}

	for (int i = len; i < b.size(); i++) {
		n1 = b[i] - '0';
		sum = (n1 + carry) % 10;
		carry = (n1 + carry) / 10;
		ret += (char)(sum + '0');
	}

	if (carry > 0) ret += "1";

	reverse(ret.begin(), ret.end());
	cout << ret << "\n";


}