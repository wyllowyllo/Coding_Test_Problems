#include <bits/stdc++.h>
using namespace std;


string s;
bool flag;

#pragma region MySol

void MySol() {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p') {
			if (i < s.size() - 1 && s[i + 1] == 'i') { i = i + 1; }
			else { flag = true; break; }
		}
		else if (s[i] == 'k') {
			if (i < s.size() - 1 && s[i + 1] == 'a') { i = i + 1; }
			else { flag = true; break; }
		}
		else if (s[i] == 'c') {
			if (i < s.size() - 2 && s[i + 1] == 'h' && s[i + 2] == 'u') { i = i + 2; }
			else { flag = true; break; }
		}
		else {
			flag = true;
			break;
		}
	}

	if (flag) cout << "NO\n";
	else cout << "YES\n";
}
#pragma endregion

#pragma region Sol_1

//여기서는 substr활용하여 문제 해결함

void Sol_1() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i < s.size() - 1 && (s.substr(i, 2) == "pi") || (s.substr(i, 2) == "ka")) i += 1;
		else if (i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
		else flag = 1;

	}

	if (flag) cout << "NO\n";
	else cout << "YES\n";
}
#pragma endregion



int main() {
	
}