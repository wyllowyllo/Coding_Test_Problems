#include <bits/stdc++.h>
using namespace std;

int n;
int ret;

string s;
stack<int> stk;

int a[200001];

//~의 범위에 포함된다/포함되지 않는다가 중점이 되는 문제라면, 색칠하기를 고려해 보기!
//올바른 문자열에 포함되는 괄호인가, 포함되지 않는 괄호인가?


int main() {
	cin >> n;
	cin >> s;

	
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			if (stk.size()) {

				a[stk.top()] = 1;
				a[i] = 1;

				stk.pop();

			}
		}
		else stk.push(i);
	}

	int len = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) len++;
		else {
			ret = max(ret, len);
			len = 0;
		}
	}
	ret = max(ret, len);
	cout << ret << "\n";
}