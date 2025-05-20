#include <bits/stdc++.h>
using namespace std;

string s;
string p;

#pragma region MySol

// find와 erase를 사용
//시간 초과

//투포인터를 써볼까?


void MySol() {
	cin >> s;
	cin >> p;

	//첫번째 시도

	/*auto start = 0;
	auto pos = s.find(p, 0);
	while (pos != string::npos) {
		s.erase(pos, p.size());
		start = max(0, (int)(pos - p.size()));
		pos = s.find(p, start);
	}

	if (!s.size()) cout << "FRULA\n";
	else cout << s << "\n";*/

	//두번째 시도
	//틀린 풀이
	//string rp = p;
	//reverse(rp.begin(), rp.end());


	/*auto start_1 = 0;
	auto start_2 = s.size()/2;

	auto p1 = s.find(p, start_1);
	auto p2 = s.find(p, start_2);

	while ((p1!=string::npos || p2!=string::npos) && (p1 < p2)) {

		if (p1 != string::npos) {
			s.erase(p1, p.size());
			start_1 = max(0, (int)(p1 - p.size()));
			p1=s.find(p, start_1);
		}
		
		if (p2 != string::npos) {
			if (p1 != string::npos) p2 = p2 - p.size();
			s.erase(p2, p.size());

			start_2 = max((int)(s.size() / 2), (int)(p2 - p.size()));
			p2=s.find(p, start_2);
		}

		
		
	}
	

	while (p2 != string::npos) {
		
		s.erase(p2, p.size());

		start_2 = max((int)(s.size() / 2), (int)(p2 - p.size()));
		p2 = s.find(p, start_2);
	}

	if (!s.size()) cout << "FRULA\n";
	else cout << s << "\n"; */
}

//스택 활용
//성공!

void MySol_2() {
	cin >> s;
	cin >> p;

	
	string ret="";
	for (int i = 0; i < s.size(); i++) {
		
		ret.push_back(s[i]);
		if (ret.size() >= p.size()&& ret.back()==p.back()) {
			string tmp = ret.substr(ret.size() - p.size(), p.size());
			if (tmp == p) {
				for (int j = 0; j < p.size(); j++) {
					ret.pop_back();
				}
			}
		}

	}



	if (!ret.size()) cout << "FRULA\n";
	else cout << ret << "\n";
		
	
}

#pragma endregion

#pragma region Sol_1

//erase를 활용한 풀이

void Sol_1() {
	cin >> s >> p;

	string ret = "";
	for (char c : s) {
		if (ret.size() >= p.size() && ret.substr(ret.size() - p.size(), p.size())==p) {
			ret.erase(ret.end() - p.size(), ret.end());
		}

	}

	if (!ret.size()) cout  << "FRULA" << "\n";
	else cout << ret << '\n';
}
#pragma endregion

#pragma region Sol_2

//stack을 활용한 풀이

void Sol_2() {
	cin >> s >> p;
	stack<char> stk;

	for (char c : s) {
		if (stk.size() >= p.size() && stk.top() == p[p.size() - 1]) {
			string ss = "";
			for (char i : p) {
				ss += stk.top(); stk.pop();
			}

			reverse(ss.begin(), ss.end());
			if (ss != p) {
				for (int i : ss) {
					stk.push(i);
				}
			}
		}
	}

	string ret = "";
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
#pragma endregion

int main() {
	//MySol();
	//MySol_2();
}