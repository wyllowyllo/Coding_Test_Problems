#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------------------My Solution -----------------------------------------------------------
/*
string input;
bool flag;

string Judge(char c) {
	string ret;
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		ret = "Vowels";
		break;
	case 'b':
	case 'c':
	case 'd':
	case 'f':
	case 'g':
	case 'h':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		ret = "Consonants";
		break;
	default:
		ret = "others";
		break;
	}

	return ret;
}
int main() {
	while (1) {
		cin >> input;
		if (input == "end") break;

		flag = false;

		for (int i = 0; i < input.size(); i++) {
			if (Judge(input[i]) == "others") {
				flag = false;
				break;
			}
			if(!flag && Judge(input[i])=="Vowels") flag = true; //������ ���ԵǾ� �ִ��� �˻�

			if (i <=input.size() - 2) {
				if (input[i] == input[i + 1] && (input[i] != 'e' && input[i] != 'o')) {
					flag = false;
					break;
				}
			}
			if (i <=input.size() - 3) {
				if ((Judge(input[i]) == Judge(input[i + 1])) && (Judge(input[i + 1]) == Judge(input[i + 2]))) {
					flag = false;
					break;
				}

			}
		}

		if(!flag) cout << '<' << input << '>' << " is not acceptable.\n";
		else cout << '<' << input << '>' << " is acceptable.\n";
	}
}
*/
//------------------------------------------------------------------------------------------------------------------------

//---------------------------------Solution 1---------------------------------------
string s;
int lcnt, vcnt; //����, ���� ī��Ʈ

bool isVowel(int idx) {
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main() {
	while (true) {
		cin >> s;
		if (s == "end") break;
		lcnt = vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;

		for (int i = 0; i < s.size(); i++) {
			int idx = s[i]; //���� �ƽ�Ű �ڵ�

			//���� �Ǵ� ���� ���� 3�� ������ ��� üũ
			if (isVowel(s[i])) lcnt++, vcnt = 0, is_include_v = true;
			else vcnt++, lcnt = 0;

			if (lcnt == 3 || vcnt == 3) flag = true;

			//���� ���ڿ� �Ȱ����� ��
			if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')) {
				flag = true;
				
			}
			prev = idx;
		}

		if (!is_include_v) flag = 1;
		if (flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}
}






