#include <bits/stdc++.h>
using namespace std;

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
			if(!flag && Judge(input[i])=="Vowels") flag = true;

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