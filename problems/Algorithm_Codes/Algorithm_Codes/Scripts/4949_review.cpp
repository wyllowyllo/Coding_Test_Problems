#include <bits/stdc++.h>
using namespace std;

string s;

#pragma region MySol

//나는 닫힌 괄호(), ])가 입력되었을 때, 스택이 그에 맞는 열린 괄호라면 pop, 그렇지 않다면(스택이 비었거나, 대응되는 괄호가 아님) 무조건 no를 출력하는 방식으로 함

bool check() {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '(' || s[i] == '[') stk.push(s[i]);
		else if (s[i] == ')') {
			if (stk.size() && stk.top() == '(') stk.pop();
			else return false;
		}
		else if (s[i] == ']') {
			if (stk.size() && stk.top() == '[') stk.pop();
			else return false;
		}

	}

	return stk.empty();
}

void MySol() {
	while (true) {
		getline(cin, s);
		if (s == ".") break;



		if (check()) cout << "yes\n";
		else cout << "no\n";

	}
}

#pragma endregion


#pragma region Sol_1

//여기서는 닫힌 괄호가 입력될 때, 스택 사이즈가 0이거나 top의 괄호가 대응되지 않는 괄호일때 무조건 no
//검사가 끝난 후, 스택이 비어있고 플래그변수가 true라면 yes 출력
void Sol_1() {
	while (true) {
		string s;
		getline(cin, s);

		if (s == ".") break;

		stack<int> stk;
		bool check = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ')') {
				if (stk.size() == 0 || stk.top() == '[') {
					check = false;
					break;
				}

				else {
					stk.pop();
				}
			}
			

			if (s[i] == ']') {
				if (stk.size() == 0 || stk.top() == '(') {
					check = false;
					break;
				}
				else {
					stk.pop();
				}
			}

			if (s[i] == '(') stk.push(s[i]);
			if (s[i] == '[') stk.push(s[i]);
		}

		if (check && stk.size() == 0) cout << "yes\n";
		else cout << "no\n";
	}
}
#pragma endregion

int main() {

	
	
}