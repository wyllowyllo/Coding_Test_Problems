#include <bits/stdc++.h>
using namespace std;


int n, k;
string s;

vector<string> v;
#pragma region MySol

int ret = -1;

void select(int cnt, int idx, int alpha) {
	if (cnt == k - 5) {
		bool flag;
		int num = 0;
		for (string w : v) {
			flag = false;
			for (char c : w) {
				if (!(alpha & (1 << (c - 'a')))) {
					flag = true;
					break;
				}
			}

			if (!flag) num++;
		}

		ret = max(ret, num);
		return;
	}

	for (int i = idx + 1; i < 26; i++) {
		if (alpha & (1 << i)) continue;

		select(cnt + 1, i, alpha | (1 << i));

	}
}

void Sol_1() {
	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	if (k < 5) cout << 0;
	else {
		int alpha = 0;
		alpha |= (1 << 'a' - 'a');
		alpha |= (1 << 'n' - 'a');
		alpha |= (1 << 't' - 'a');
		alpha |= (1 << 'i' - 'a');
		alpha |= (1 << 'c' - 'a');

		//k-5개의 단어 선택

		select(0, -1, alpha);

		cout << ret << "\n";

	}
}
#pragma endregion

#pragma region Sol_1

int words[30];

int count(int mask) {
	int cnt = 0;

	for (int w : words) {
		if (w && (w & mask) == w) cnt++;
	}

	return cnt;
}

int go(int index, int k, int mask) {
	if (k < 0) return 0;
	if (index == 26) return count(mask);
	int ret = go(index + 1, k - 1, mask | (1 << index));

	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		ret = max(ret, go(index + 1, k, mask));
	}

	return ret;
}

void Sol_1() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (char c : s) {
			words[i] |= (1 << (c - 'a'));
		}
	}

	cout << go(0, k, 0) << "\n";
}
#pragma endregion



int main() {
	
	
}