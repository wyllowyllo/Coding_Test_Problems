#include <bits/stdc++.h>
using namespace std;


int m, x;

string o;
int s;


void cal(string order) {
	if (order == "add") {
		cin >> x;

		s |= (1 << x);
	}
	else if (order == "remove") {
		cin >> x;

		s &= ~(1 << x);
	}
	else if (order == "check") {
		cin >> x;

		cout << (s & (1 << x) ? 1 : 0)<<"\n";
		
	}
	else if (order == "toggle") {
		cin >> x;
		
		s ^= (1 << x);
	}
	else if (order == "all") {
		s = (1 << 21) - 1;
	}
	else if (order == "empty") {
		s = 0;
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> o;
		cal(o);
	}
}