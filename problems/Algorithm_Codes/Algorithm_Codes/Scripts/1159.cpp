#include <bits/stdc++.h>
using namespace std;

map<char, int> alpha;

int cnt[26];

int main() {
	int num;
	string first_name;
	

	cin >> num;


	//------------------------My Solution---------------------------------------------
	//for (int i = 0; i < num; i++) {
	//	cin >> first_name;

	//	if (alpha.find(first_name[0]) != alpha.end()) { //�ش� Ű�� �ʿ� �������
	//		alpha[first_name[0]]++;
	//	}
	//	else { //�ش� Ű�� �ʿ� ������� ���� �߰�
	//		alpha.insert({ first_name[0], 1 });
	//	}
	//}

	//vector<char> possible_Alpha;
	//for (auto a : alpha) {
	//	if (a.second >= 5) {
	//		possible_Alpha.push_back(a.first);
	//	}
	//}

	//if (possible_Alpha.size() > 0) {
	//	sort(possible_Alpha.begin(), possible_Alpha.end());
	//	for (char c : possible_Alpha)
	//		cout << c;
	//	cout << '\n';
	//}
	//else {
	//	cout << "PREDAJA" << '\n';
	//}

	//----------------------------------------------------------------------

	//------------------------Solution 1 -----------------------------------
	for (int i = 0; i < num; i++) {
		cin >> first_name;
		cnt[first_name[0] - 'a']++;
	}

	string ret;

	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5)
			ret += (char)(i + 'a');
	}

	if (ret.size()) cout << ret << '\n';
	else cout << "PREDAJA" << '\n';







	return 0;
}