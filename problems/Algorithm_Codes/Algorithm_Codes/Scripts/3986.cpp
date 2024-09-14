#include <bits/stdc++.h>
using namespace std;

int N;
string word;

int cnt = 0;

int main() {
	cin >> N;

	//-------------------------My Solution ----------------------------------------------
	for (int i = 0; i < N; i++) {
		cin >> word;

		stack<char> s;
		for (char c : word) {
			if (s.empty() || s.top() != c)
				s.push(c);
			else {
				s.pop();
			}
		}

		if (s.empty()) cnt++;
		
	}

	cout << cnt << "\n";

	//-------------------------------------------------------------------------------------

	//---------------------Solution 1------------------------------------------------------
	string s;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		stack<char> stk;
		for (char a : s) {
			if (stk.size() && stk.top() == a)stk.pop();
			else stk.push(a);
		}
		if (stk.size() == 0) ret++;
	}

	cout << ret << "\n";
	//-------------------------------------------------------------------------------------
	return 0;
}