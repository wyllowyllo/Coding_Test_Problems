#include <bits/stdc++.h>
using namespace std;

string input;

#pragma region MySol
	int a[26] = { 0, };


	void Count() {


		for (char c : input) {
			int idx = c - 97;
			a[idx]++;
		}

		for (int i = 0; i < 26; i++) {
			cout << a[i] << " ";
		}
	}
#pragma endregion

#pragma region Sol_1
	int cnt[26];

	void Sol_1() {
		for (char a : input) {
			cnt[a - 'a']++;

		}
		for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
	}
#pragma endregion




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;

	//Count();

	Sol_1();
}