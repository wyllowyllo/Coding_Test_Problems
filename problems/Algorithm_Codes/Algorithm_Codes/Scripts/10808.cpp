#include <bits/stdc++.h>
using namespace std;

int alphabet_num[26]{ 0, };

int main() {
	string word;
	cin >> word;

	//-------------------My Solution--------------------------------
	

	/*for (int i = 0; i < word.length(); i++) {
		int idx = (int)word[i] - 97;
		alphabet_num[idx]++;
	}

	for (int i : alphabet_num)
		cout << i << ' ';*/

	
	//----------------------------------------------------------------

	//------------------Solution 1------------------------------------
	/*for (char a : word) {
		alphabet_num[a - 'a']++;
	}
	for (int i : alphabet_num)
		cout << i << ' ';*/
	//----------------------------------------------------------------

	//------------------Solution 2------------------------------------
	map<char, int> alpha;

	//map �ʱ�ȭ
	for (int i = 'a'; i <= 'z'; i++) {
		alpha.insert({ (char)i, 0 });
	}
	//���ĺ��� key������ ����ϰ�, �� �󵵸� value������ ���
	for (char a : word) {
		alpha[a]++;
	}

	for (auto i : alpha)
		cout << i.second << ' ';

	return 0;
}