#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, num;



#pragma region MySol

//첫번째 시도 : vector에 숫자 저정한 후, 명령어에 따라 reverse및 erase반복
//시간 초과

//두번째 시도 : 마지막 출력때에만 reverse를 함.
//R이 나올때마다 플래그 변수를 반전시켜, 앞에서 지울지 뒤에서 지울지를 정함
//성공


//주의 : 입력 문자열 처리를 처음에 잘못함. 

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> t;

	while (t--) {
		cin >> p;
		cin >> n;
		cin >> num;

		vector<int> result;
		bool flag = false;
		bool first = true;


		int cur = 0;
		for (char c : num) {
			if (isdigit(c)) { // 숫자면
				cur = cur * 10 + (c - '0');
			}
			else if (c == ',' || c == ']') { // 구분자면
				if (cur != 0) {
					result.push_back(cur);
					cur = 0;
				}
			}
		}


		for (int i = 0; i < p.size(); i++) {


			if (p[i] == 'R') {
				first = !first;
				//reverse(result.begin(), result.end());
			}
			else {
				if (result.size() == 0) {
					flag = true;
					break;
				}

				if (first) result.erase(result.begin());
				else result.erase(result.end() - 1);

			}


		}

		if (!first) reverse(result.begin(), result.end());

		if (flag) cout << "error\n";
		else {
			cout << '[';
			for (int i = 0; i < result.size(); i++) {
				cout << result[i];

				if (i != result.size() - 1) cout << ',';
			}
			cout << ']';
			cout << "\n";
		}



	}
}
#pragma endregion

#pragma region Sol_1

//문제를 보면, D를 할 때 항상 문자열의 맨 앞이나 맨 뒤의 문자를 제거한다
//따라서 자료구조 데크를 활용하면 쉽게 문제를 풀 수 있다

void sol_1() {
	cin >> t;
	while (t--)
	{
		deque<int> D;
		int x = 0;
		cin >> p >> n >> num;

		for (char c : num) {
			if (c == '[' || c == ']') continue;
			if (c >= '0' && c <= '9') x = (x * 10) + c - '0';
			else {
				if (x > 0) D.push_back(x);
				x = 0;
 			}
		}

		if (x > 0) D.push_back(x);

		bool error = false, rev = false;

		for (char a : p) {
			if (a == 'R') rev = !rev;
			else {
				if (D.empty()) {
					error = true;
					break;
				}

				if (rev) D.pop_back();
				else D.pop_front();
			}
		}

		if (error) cout << "error" << '\n';
		else {
			cout << "[";
			if (rev) reverse(D.begin(), D.end());
			for (int i = 0; i < D.size(); i++) {
				cout << D[i];
				if (i < D.size() - 1) cout << ",";
			}
			cout << "]\n";
		}

	}
}
#pragma endregion

int main() {
	sol_1();
}