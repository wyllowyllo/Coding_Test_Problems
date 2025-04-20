#include <bits/stdc++.h>
using namespace std;


int n;
vector<string> v;
string s;

map<string, bool> m1;

#pragma region MySol

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}

	return s1.size() < s2.size();
}

void MySol() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!m1[s]) { v.push_back(s); m1[s] = true; }
	}

	sort(v.begin(), v.end(), cmp);

	for (auto t : v) {
		cout << t << "\n";
	}
}

#pragma endregion

#pragma region Sol_1

set<string> words;
void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words.insert(s); //set은 중복을 허용하지 않는 컨테이너이므로 자동 중복 제거할 수 있음

	}

	vector<string> v2;
	v2.assign(words.begin(), words.end()); //set은 커스텀 sort할수 없으므로 벡터로 옮김

	sort(v2.begin(), v2.end(), [](string a, string b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
});
	for (auto t : v2) {
		cout << t << "\n";
	}
}
#pragma endregion

int main() {
	Sol_1();

}