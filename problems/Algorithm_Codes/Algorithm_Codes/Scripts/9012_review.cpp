#include <bits/stdc++.h>
using namespace std;


int t;
string input;

#pragma region MySol

void MySol() {
	cin >> t;

	while (t--) {
		cin >> input;

		stack<char> s;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				s.push(input[i]);
			}
			else if (input[i] == ')') {
				if (s.size() && s.top() == '(') s.pop();
				else s.push(input[i]);
			}
		}

		if (s.size()) cout << "NO\n";
		else cout << "YES\n";


	}
}
#pragma endregion

#pragma region Sol_1
//나는 일단 괄호의 종류에 상관없이 입력시 스택에 push하고, 최종적으로 스택의 사이즈가 0이 아니라면 NO를 출력하는 식으로 함
//여기서는, ')'입력이 들어올 때 스택이 비어있다면 무조건 "NO"를 출력하고 종료하는 식임.

int n;
bool check(string s) {
	stack<char> stk;

	for (char c : s) {
		if (c == '(') stk.push(c);
		else {
			if (!stk.empty()) stk.pop();
			else return false;
		}
	}

	return stk.empty();
}

void Sol_1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (check(input)) cout << "YES\n";
		else cout << "NO\n";
	}
}

#pragma endregion

int main() {
	
	
}