#include <bits/stdc++.h>
using namespace std;

namespace My {
	string s1, s2;

	stack<pair<int, int>> stk;
	string ret;



	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		cin >> s1 >> s2;


		for (int i = 0; i < s1.size(); i++) {
			char c = s1[i];


			if (stk.empty()) {
				if (c == s2[0]) {
					stk.push({ c,0 });
				}
				else {
					stk.push({ c,-1 });
				}
			}
			else {
				if (c == s2[stk.top().second + 1]) {
					stk.push({ c, stk.top().second + 1 });
				}
				else {
					if (c == s2[0]) {
						stk.push({ c,0 });
					}
					else {
						stk.push({ c,-1 });
					}
				}
			}

			if (stk.top().second == s2.size() - 1) {
				int n = (int)(s2.size());
				while (n--)
					stk.pop();
			}

		}

		while (stk.size()) {
			ret += stk.top().first;
			stk.pop();
		}

		if (ret.size()) {
			reverse(ret.begin(), ret.end());

			cout << ret << "\n";
		}
		else cout << "FRULA" << "\n";

	}
}

namespace Sol_1 {
	//문자열 ABC4C4와 폭발문자열 C4가 있다고 하면,
	//어떠한 빈 배열 ret에다가 A, AB, ABC, ABC4... 이런식으로 한글자씩 붙여나감
	//이때 폭발 문자열의 길이가 2이므로, ret의 길이가 2 이상이 될 때, ret의 '뒤에서부터' 2만큼의 문자열과 폭발 문자열을 비교
	//만약 각 검사 시 그 부분 문자열이 폭발 문자열과 같다면, erase!

	string S, T, ret;

	void sol() {
		cin >> S >> T;

		for (char a : S) {
			ret += a;

			if (ret.size() >= T.size() && ret.substr(ret.size() - T.size(), T.size()) == T)
				ret.erase(ret.end() - T.size(), ret.end());
		}

		if (!ret.size())cout << "FRULA" << "\n";
		else cout << ret << "\n";
	}
}

namespace Sol_2 {
	//스택 안의 원소 수 >=폭발 문자열 길이 이고, 스택의 top의 문자가 폭발 문자열의 끝과 같을 때,
	//폭발 문자열 길이만큼 pop하여, 그때 생성된 문자열을 뒤집어 폭발 문자열과 비교
	//만약 폭발 문자열과 다르다면, 다시 push하여 원상복구

	string S, T, ret;
	stack<char> stk;

	

	void Sol_2() {
		cin >> S >> T;
		for (char i : S) {
			stk.push(i);
			if (stk.size() >= T.size() && stk.top() == T[T.size() - 1]) {
				string ss = "";
				for (char a : T) {
					ss += stk.top();
					stk.pop();
				}

				reverse(ss.begin(), ss.end());
				if (T != ss) {
					for (int j : ss) {
						stk.push(j);
					}
				}


			}
		}

		if (stk.size() == 0) {
			cout << "FRULA\n";
		}
		else {
			while (stk.size()) {
				ret += stk.top(); stk.pop();
			}
			reverse(ret.begin(), ret.end());
			cout << ret << "\n";
		}
	}
}

int main() {
	

}