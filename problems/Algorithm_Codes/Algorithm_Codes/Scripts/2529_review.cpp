#include <bits/stdc++.h>
using namespace std;

int k;
vector<char> o;

char tmp;
int v[10];

vector<string> ret;
bool check(int idx, int a, int b) {
	if (o[idx] == '<') return a < b;
	else return a > b;
}
void go(int idx,string s) {
	if (idx == k+1) {
		//cout << s << "\n";
		ret.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (v[i]) continue;
		if (!check(idx-1, s[idx - 1]-'0', i)) continue;

		s.push_back('0'+i);
		v[i] = 1;

		go(idx + 1, s);

		s.pop_back();
		v[i] = 0;
	}

	return;
}

int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> tmp;
		o.push_back(tmp);
	}

	for (int i = 0; i <= 9; i++) {
		v[i] = 1;
		go(1, to_string(i));
		v[i] = 0;
	}

	sort(ret.begin(), ret.end(), [](string a, string b) {
		if (a.size() == b.size()) return a > b;
		return a.size() > b.size();
});

	cout << ret.front() << "\n";
	cout << ret.back() << "\n";
}