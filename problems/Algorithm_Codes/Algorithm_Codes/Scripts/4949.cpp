#include <bits/stdc++.h>
using namespace std;


string input;

bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(' || c == '[') stk.push(c);
		else if (c == ')' || c == ']') {
			if (stk.empty()) return false;
			else {
				if (stk.top() == '(' && c == ')') stk.pop();
				else if (stk.top() == '[' && c == ']') stk.pop();
				else stk.push(c);
			}
		}
	}

	if (stk.empty()) return true;
	else return false;
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		getline(cin,input);

		if (input == ".") break;

		if (check(input)) cout << "yes\n";
		else cout << "no\n";
		
	}
	
	
}