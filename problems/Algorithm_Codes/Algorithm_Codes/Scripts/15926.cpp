#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ret,cnt;
int d[200001];
stack<int> _stk;

#pragma region MySol

//스택을 활용하여, ')'마다 pop하는데 그 때 스택이 비게되면 길이를 축적하는 식으로 함
//반례 생김...

//좋은 문자열 -> 스택연산 다 했을때 스택이 비면 좋은 문자열임
//그냥 문자열에서 한글자씩 떼보면서 좋은 문자열 찾아볼까
//시간복잡도 worst case는 n(n-1)/2.  20만 * 20만 == 400억.. 에반데

//포기..진짜 모르겠음


void MyTry_1() {
	cin >> n;
	cin >> s;

	stack<char> stk;
	int len = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') { stk.push(s[i]); }
		else {
			if (stk.size()) {
				stk.pop();
				cnt++;

				if (stk.empty()) {
					len += cnt * 2;
					cnt = 0;
				}

			}
			else {
				ret = max(ret, len);
				len = 0;
				cnt = 0;
			}
		}
	}
	ret = max(ret, len);

	cout << ret << "\n";
}

void MyTry_2() { //이것도 반례 있네.. 폐기하자

	//1. ()위치를 먼저 찾는다.
	//2 좌,우로 검사했을때 왼쪽이 ( 이고 오른쪽이 )이면 길이추가
	//3 또는 오른쪽이 ( 이면 오른쪽 쭉 검사

	cin >> n;
	cin >> s;


	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '(' && s[i + 1] == ')') { //1. ()위치를 먼저 찾는다.
			int len = 2;

			int j;
			for (j = 1;; j++) { //2 좌,우로 검사했을때 왼쪽이 ( 이고 오른쪽이 )이면 길이추가
				if (i - j >= 0 && i + 1 + j < n && s[i - j] == '(' && s[i + 1 + j] == ')') {
					len += 2;
				}
				else break;
			}
			ret = max(ret, len);

			i = i + 1 + j;
			if (i < n && s[i] == '(') {//3 또는 오른쪽이 ( 이면 오른쪽 쭉 검사
				stack<char> stk;
				int cnt = 0; int k;
				stk.push(s[i]);
				for (k = i + 1; k < n; k++) {
					if (s[k] == '(') stk.push(s[k]);
					else {
						if (stk.empty()) { break; }
						stk.pop();
						cnt++;
						if (stk.empty()) {
							len += cnt * 2;
							cnt = 0;
						}

					}
				}


				i = k;
				ret = max(ret, len);
			}
			else {
				ret = max(ret, len);
				len = 0;
			}


		}
	}

	cout << ret << "\n";
}

#pragma endregion


#pragma region Sol_1

//아이디어 1 : 배열을 활용
// ((())))(())) 라는 입력이 들어왔다고 가정하면, 배열을 통해 각 괄호가 올바른 문자열에 포함되면 1, 그렇지 않으면 0으로 저장
// 배열 왼쪽부터 검사했을때 1이면 누적했다가, 0을 만나면 초기화하는 식으로 각 괄호열의 길이 구해서 최대길이 갱신

//스택을 활용하는건 생각했는데, 배열을 통한 카운트는 생각못함...


void Sol_1() {
	cin >> n >> s;

	//올바른 괄호문자열에 포함되는 괄호에만 1이 표시됨
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') _stk.push(i);
		else if (_stk.size()) {
			d[i] = d[_stk.top()] = 1; // '('와 ')'의 인덱스에 1넣기
			_stk.pop();

		}
	}

	//배열 검사
	for (int i = 0; i < n; i++) {
		if (d[i]) {
			cnt++;
			ret = max(ret, cnt);
		}
		else cnt = 0;
	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_2

//스택만을 활용하여 푸는 방법

//올바른 괄호 문자열을 찾았을 때, 그 덩어리(괄호쌍)을 기반으로 max값을 만들기

void Sol_2() {
	cin >> n;
	cin >> s;

	_stk.push(-1); //-1넣어두기 (분기점으로 활용하기 위해)

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') _stk.push(i);
		if (s[i] == ')') {
			_stk.pop();
			if (!_stk.empty()) {
				ret = max(ret, i - _stk.top()); //i-_stk.top()이 문자열 길이가 됨 -> ()만났을 때 양옆으로 확장시켜나가는 개념
			}
			else {
				_stk.push(i); //분기점 저장
			}
		}
	}

	cout << ret << "\n";
}
#pragma endregion



int main() {
	//Sol_1();
	Sol_2();
}