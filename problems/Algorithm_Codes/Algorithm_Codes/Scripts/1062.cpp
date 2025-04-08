#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<string> words;
string s;

int alpha[30];

int ret = 0;


#pragma region MySol

//비트마스킹으로 풀어보려다, 어떻게 하는지 잘 모르겠어서, 브루트포스로 하되 필수단어는 꼭 포함시키는 것으로 최적화해서 풀었음

void check() {
	bool flag = true;
	int cnt = 0;

	for (string word : words) {
		flag = true;
		for (char c : word) {
			if (!alpha[c - 'a']) {
				flag = false;
				break;
			}
		}

		if (flag) cnt++;
	}

	ret = max(ret, cnt);
}

void select(int startIdx, int cnt) {

	if (cnt == k - 5) {
		check();
		return;
	}

	for (int i = startIdx + 1; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = 1;
			select(i, cnt + 1);
			alpha[i] = 0;
		}
	}
}

void MySol() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;

		string word;
		if (s.size() == 8) word = ("");
		else word = s.substr(4, s.size() - 8);

		words.push_back(word);
	}

	if (k < 5) {
		cout << 0 << "\n";
		return;
	}

	alpha['a' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1;
	alpha['c' - 'a'] = 1;


	

	select(-1, 0);

	

	cout << ret << "\n";






}

#pragma endregion


#pragma region MySol_2

//배열쓰지 말고 비트마스킹으로 풀어보기

void check(int select) {
	bool flag = true;
	int cnt = 0;

	for (string word : words) {
		flag = true;
		for (char c : word) {
			if (!(select & (1<<(c-'a')))) {
				flag = false;
				break;
			}
		}

		if (flag) cnt++;
	}

	ret = max(ret, cnt);
}
void go(int select, int idx,int cnt) {
	if (cnt == k) {
		check(select);
		return;
	}

	for (int i = idx+1; i < 26; i++) {
		if (select & (1 << i)) continue;
		go(select | (1 << i), i, cnt + 1);
	}

}
void MySol_2() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;

		string word;
		if (s.size() == 8) word = ("");
		else word = s.substr(4, s.size() - 8);

		words.push_back(word);
	}

	if (k < 5) {
		cout << 0 << "\n";
		return;
	}

	int select = 0;
	select |= (1 << (int)('a' - 'a'));
	select |= (1 << (int)('n' - 'a'));
	select |= (1 << (int)('t' - 'a'));
	select |= (1 << (int)('i' - 'a'));
	select |= (1 << (int)('c' - 'a'));

	

	go(select, -1,5);



	cout << ret << "\n";


}
#pragma endregion

int _words[51];


#pragma region Sol_1
//여기서는 입력받는 단어도 비트마스킹을 사용하여 정수 하나로 표현함

int count(int mask) {
	int cnt = 0;
	for (int word : _words) {
		if (word && (word & mask) == word) cnt++; //(word & mask) == word이 참이라면 word에 포함된 알파벳들이 mask에도 모두 있다는 뜻. 즉 단어에 있는 모든 알파벳을 배웠다는 뜻이 됨
	}

	return cnt;
}
int go2(int index, int k, int mask) {
	if (k < 0) return 0; //더이상 배울 단어 없음
	if (index == 26) return count(mask); //'z'까지 검사 완료함(모든 경우의 수 탐색 완료)

	int ret = go2(index + 1, k - 1, mask | (1 << index)); //어떠한 알파벳(1<<index) 포함하는 경우에 대해 재귀
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		ret = max(ret, go2(index + 1, k, mask)); //필스포함 단어가 아닌경우, 포함하지 않는 경우에 대해 재귀
	}

	return ret;

}
void Sol_1() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char str : s) {
			_words[i] |= (1 << (str - 'a')); // 단어에 포함된 알파벳을 비트마스킹으로 표시하며, 이를 합산하여 전체 단어를 정수 하나로 표시
		}
	}
}

#pragma endregion





int main() {
	//MySol_2();

	Sol_1();
}