#include <bits/stdc++.h>
using namespace std;

int n;

int ret=-1;
int main() {
	cin >> n;

	int a = n / 5;
	int remain = n -(5*a);

	while (a>=0) {

		if (remain % 3 == 0) {

			ret = a + (remain / 3);
			break;
		}

		a--;
		remain=n - (5 * a);
	}

	cout << ret << "\n";
}