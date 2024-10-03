#include <bits/stdc++.h>
using namespace std;

int t;
string input;

bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(') stk.push(c); //���� ��ȣ�� push
		else {
			if (!stk.empty()) stk.pop(); 
			else return false; //�� ���ÿ� ���� ��ȣ�� �ԷµǴ� ����� -> �� ��� �� �Է¹��� �ʿ䵵 ���� ������ false��. (�Ұŵ� ���ɼ��� �����Ƿ�)
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
	//�� ���ÿ� ')'�ԷµǴ� ��쿡 ���̻� �������� �ʰ� �ٷ� false����ϹǷ� �� �ڵ庸�� ���� �� ȿ������(���ʿ��� ���� ���ص� �Ǵϱ�)
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;

		if (check(input)) cout << "YES\n";
		else cout << "NO\n";
	}
	//-------------------------------------------------------------------------
}