#include <bits/stdc++.h>
using namespace std;


#pragma region MySol
string s = "";

//잘못된 인덱스 접근해서 골머리 앓음...
bool judge(int idx) {
	if (s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u') return true;
	else return false;
}

bool isAcceptable() {

	bool flag = false; //모음 포함?

	for (int i = 0; i < s.size(); i++) {
		if (!flag && judge(i)) flag = true;

		if (s.size() >= 2 && i < s.size() - 1) { //처음에 사이즈 체크 없이 해서 오류남.. 
			if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
				return false;
		}

		if (s.size() >= 3 && i < s.size() - 2) { //처음에 사이즈 체크 없이 해서 오류남.. 문자열 길이가 3보다 작은경우 idx범위 초과하는 경우 발생

			bool first = judge(i); bool second = judge(i + 1); bool third = judge(i + 2);
			if (first == second && second == third) return false;
		}

	}

	if (flag) return true;
	return false;
}

void MySol() {
	while (true) {
		cin >> s;

		if (s == "end") break;

		if (isAcceptable())
			cout << "<" << s << ">" << " is acceptable.\n";
		else
			cout << "<" << s << ">" << " is not acceptable.\n";


	}
}

#pragma endregion

#pragma region Sol_1
int lcnt, vcnt;

//연속된 3개의 글자가 전부 모음or자음인지 검사할 때, 각각 lcnt, vcnt를 두어 개수를 카운트함. 모음or자음이 연속되지 않으면 초기화하는 방식
//연속된 2개의 글자가 같은 글자인지 검사할때 prev(이전글자)와 비교함
bool isVowel(int idx) {
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

void Sol_1() {
	
	while (true) {
		cin >> s;
		if (s == "end") break;
		lcnt = vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;

		for (int i = 0; i < s.size(); i++) {
			int idx = s[i];

			//자음, 모음이 연속되지 않으면 0으로 초기화한다.
			if (isVowel(idx)) lcnt++, vcnt = 0, is_include_v = true;
			else vcnt++, lcnt = 0;

			if (vcnt == 3 || lcnt == 3) flag = 1;
			if(i>=1 && (prev==idx) && (idx!='e' && idx!='o')) flag=1;

			prev = idx;
		}

		if (is_include_v == 0) flag = 1;
		if (flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}
	

}
#pragma endregion



int main() {
	
	
}