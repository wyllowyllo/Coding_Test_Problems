#include <bits/stdc++.h>
using namespace std;

int n;
string t1, t2;
map<string, bool> m1;
vector<string> name;

#pragma region MySol

void MySol() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;

		name.push_back(t1);

		if (t2 == "enter") {
			m1[t1] = true;
		}
		else {
			m1[t1] = false;
		}
	}

	vector<string> ret;

	for (string s : name) {
		if (m1[s]) ret.push_back(s);
	}

	sort(ret.begin(), ret.end(), greater<string>());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	for (string s : ret) {
		cout << s << "\n";
	}
}
#pragma endregion

#pragma region Sol_1
string status, nm;
void Sol_1() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	set<string> people;

	while (n--) {
		cin >> nm >> status;
		if (status == "enter") {
			people.insert(nm);
		}
		else {
			people.erase(nm);
		}
	}

	vector<string> ret(people.begin(), people.end());
	sort(ret.rbegin(), ret.rend());

	for (const string& name : ret) {
		cout << name << '\n';
	}
}
#pragma endregion


int main() {


	Sol_1();
}