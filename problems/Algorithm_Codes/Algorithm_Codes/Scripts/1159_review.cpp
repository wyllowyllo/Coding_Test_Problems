#include <bits/stdc++.h>
using namespace std;

#pragma region Mysol

	int n;
	string name;
	string result = "";
	map<char, int> nameMap;

	void Get_V() {
		cin >> n;
		while (n--) {
			cin >> name;
			nameMap[name[0]]++;
		}


		for (auto v : nameMap) {
			if (v.second >= 5) {
				result += v.first;
			}
		}

		if (result == "") {
			result = "PREDAJA";
			cout << result;
		}
		else {
			sort(result.begin(), result.end());
			cout << result;
		}
	}
#pragma endregion

#pragma region Sol_1

	//배열을 사용한 풀이
	void Sol_1() {
		int cnt[26] = { 0 };
		string ret = NULL;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name;
			cnt[name[0] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] >= 5) {
				ret += cnt[i] + 'a'; //숫자를 문자로 바꿈 -> ret+=char(cnt[i]+'a');
			}
		}

		if (ret.size()) cout << ret << "\n";
		else cout << "PREDAJA" << "\n";
	}

#pragma endregion


int main() {
	//Get_V();
}