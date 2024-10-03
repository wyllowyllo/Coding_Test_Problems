#include <bits/stdc++.h>
using namespace std;

int t;
string input;

bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(') stk.push(c); //여는 괄호면 push
		else {
			if (!stk.empty()) stk.pop(); 
			else return false; //빈 스택에 닫힌 괄호가 입력되는 경우임 -> 이 경우 더 입력받을 필요도 없이 무조건 false임. (소거될 가능성이 없으므로)
		}
	}

	return true;
}
int main() {

	//-----------------------------My Solution -----------------------------//
	/*cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;
		stack<char> s;
		for (int j = 0; j < input.size(); j++) {
			if (s.size() && s.top()=='(' &&input[j]==')')
				s.pop();
			else s.push(input[j]);
		}

		if (s.size()) cout << "NO\n";
		else cout << "YES\n";
	}*/

	//------------------------------------------------------------------------

	//----------------------------Solution 1 ---------------------------------
	//빈 스택에 ')'입력되는 경우에 더이상 연산하지 않고 바로 false출력하므로 내 코드보다 조금 더 효율적임(불필요한 연산 안해도 되니까)
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;

		if (check(input)) cout << "YES\n";
		else cout << "NO\n";
	}
	//-------------------------------------------------------------------------
}