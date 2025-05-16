#include <bits/stdc++.h>
using namespace std;

string s;
bool flag;
int main() {
	cin >> s;

	for (int i = 0; i < s.size();) {
		if (s[i] == 'p') {
			if (s.substr(i, 2) != "pi") { flag = true; break; }
			else i += 2;
		}
		else if (s[i] == 'k') {
			if (s.substr(i, 2) != "ka") { flag = true; break; }
			else i += 2;
		}
		else if (s[i] == 'c') {
			if (s.substr(i, 3) != "chu") { flag = true; break; }
			else i += 3;
		}
		else { flag = true; break; }
	
	}

	if (!flag) cout << "YES";
	else cout << "NO";
}