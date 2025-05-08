#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
int n;
int x;
int cur = 1;

#pragma region MySol

void MySol() {
	cin >> n;
	while (n--) {
		cin >> x;

		while (stk.size() && stk.top() == cur) {
			stk.pop();
			cur++;
		}
		if (x == cur) { cur++; }
		else {
			if (stk.size() && stk.top() > x) stk.push(x);
			else if (stk.empty()) stk.push(x);
			else { cout << "Sad\n"; return; }
		}



	}


	cout << "Nice\n";
}
#pragma endregion

#pragma region Sol_1

void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		while (!stk.empty() && stk.top() == cur) {
			stk.pop();
			cur++;
		}

		if (x == cur) cur++;
		else stk.push(x); //대소비교 없이 일단 push
	}

	//입력이 끝난 후 스택 정리
	while (!stk.empty() && stk.top() == cur) {
		stk.pop();
		cur++;
	}
	if (stk.empty()) cout << "Nice\n";
	else cout << "Sad\n";
	
}
#pragma endregion



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Sol_1();
}