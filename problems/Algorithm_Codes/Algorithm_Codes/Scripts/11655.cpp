#include <bits/stdc++.h>
using namespace std;


vector<string> Split(const string str, string delimiter) { //���ڿ����� �ܾ� ����
	vector<string> words;

	int startIdx = 0;
	int endIdx = str.find(delimiter);

	while (endIdx != str.npos) {
		string word = str.substr(startIdx, endIdx-startIdx);
		words.push_back(word);
		startIdx = endIdx + delimiter.size();
		endIdx= str.find(delimiter, startIdx);
	}

	words.push_back(str.substr(startIdx));

	return words;
}

int main() {
	
	//----------------------------------My Solution ---------------------------------------
	//string s;
	//vector<string> words;
	//vector<string> converted_words;
	//getline(cin, s); //���ڿ� �Է�
	//words = Split(s," "); //���� ������ ���ڿ� �ڸ���


	////ROT13 ����
	//for (string word : words) {
	//	for (int i = 0; i < word.size(); i++) {
	//		if (isalpha(word[i])) { //���ĺ��ΰ�?
	//			
	//			//��ҹ��� ����
	//			if (islower(word[i])) {
	//				int converted_c= ((int)word[i] + 13);
	//				if(converted_c>'z')
	//					word[i] = (char)('a'+(converted_c-'z'-1));
	//				else
	//					word[i] = (char)(converted_c);
	//				
	//			}
	//			else {
	//				int converted_c = ((int)word[i] + 13);
	//				if (converted_c > 'Z')
	//					word[i] = (char)('A' + (converted_c-'Z'-1));
	//				else
	//					word[i] = (char)(converted_c);
	//			}
	//		}
	//		
	//	}
	//	converted_words.push_back(word);
	//}

	////���
	//for (string word : converted_words) {
	//	cout << word << ' ';
	//}
	//cout << "\n";

	//--------------------------------------------------------------------------------------

	//-------------------------------Solution 1---------------------------------------------

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) { //�빮���̸�
			if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26; //Z �ƽ�Ű�� �Ѿ �� ���ĺ� ����ŭ ���� ���ư���(���������� ����)
			else s[i] = s[i] + 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {//�ҹ����̸�
			if (s[i] + 13 > 122) s[i] = s[i] + 13 - 26; //Z �ƽ�Ű�� �Ѿ �� ���ĺ� ����ŭ ���� ���ư���(���������� ����)
			else s[i] = s[i] + 13;
		}
	}

	cout << s << "\n";

	//-----------------------------------------------------------------------------------------
}