#include <bits/stdc++.h>
using namespace std;

string s, t;

string ret;

stack<char> stk;

void sol_1() {
	for (int i = 0; i < s.size(); i++) {
		ret += s[i];

		if (ret.size() >= t.size() && ret.substr(ret.size() - t.size(), t.size()) == t) {
			ret.erase(ret.end() - t.size(), ret.end());
		}
	}

	cout << ret << "\n";
}

void sol_2() {
	for (int i = 0; i < s.size(); i++) {
		stk.push(s[i]);

		if (stk.size() >= t.size() && stk.top() == t.back()) {
			string tmp = "";
			for (int i = 0; i < t.size(); i++) {
				tmp += stk.top();
				stk.pop();
			}

			reverse(tmp.begin(), tmp.end());

			if (tmp != t) {
				for (char c : tmp)
					stk.push(c);
			}
		}
	}

	string ret = "";
	while (stk.size()) {
		ret += stk.top();
		stk.pop();
	}

	reverse(ret.begin(), ret.end());
	cout << ret << "\n";
		
}
int main() {
	cin >> s >> t;

	//sol_1();
	sol_2();
}