#include <bits/stdc++.h>
using namespace std;

int m;
int group = 0;

string s; int num;

#pragma region MyRegion

//처음에 Fast IO 안하니 시간초과났음

void Cal() {

	if (s == "add") {
		if (!(group & (1 << num - 1))) {
			group |= (1 << num - 1);
		}
	}
	else if (s == "remove") {
		if ((group & (1 << num - 1))) {
			group &= ~(1 << num - 1);
		}
	}
	else if (s == "check") {
		if (group & (1 << num - 1))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else if (s == "toggle") {
		group ^= (1 << num - 1);
	}
	else if (s == "all") {
		group = (1 << 20) - 1;
	}
	else if (s == "empty") {
		group = 0;
	}
}


void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;

	while (m--) {
		cin >> s;
		if (s != "all" && s != "empty") cin >> num;
		Cal();
	}
}
#pragma endregion



#pragma region Sol_1

char _s[11];
int n, x;


void Sol_1() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s %d", &_s, &x);

		if (_s[0] == 'a' && _s[1] == 'd') n |= (1 << x);
		else if (_s[0] == 'r') n &= ~(1 << x);
		else if (_s[0] == 'c') printf("%d\n", (n & (1 << x)) == 0 ? 0 : 1);
		else if (_s[0] == 't') n ^= (1 << x);
		else if (_s[0] == 'a' && _s[1] == 'l') n = (1 << 21) - 1;
		else n = 0;
	}
}
#pragma endregion

int main() {
	Sol_1();
}