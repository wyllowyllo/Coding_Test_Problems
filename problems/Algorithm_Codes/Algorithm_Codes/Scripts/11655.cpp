#include <bits/stdc++.h>
using namespace std;


vector<string> Split(const string str, string delimiter) { //문자열에서 단어 추출
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
	//getline(cin, s); //문자열 입력
	//words = Split(s," "); //띄어쓰기 단위로 문자열 자르기


	////ROT13 수행
	//for (string word : words) {
	//	for (int i = 0; i < word.size(); i++) {
	//		if (isalpha(word[i])) { //알파벳인가?
	//			
	//			//대소문자 구별
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

	////출력
	//for (string word : converted_words) {
	//	cout << word << ' ';
	//}
	//cout << "\n";

	//--------------------------------------------------------------------------------------

	//-------------------------------Solution 1---------------------------------------------

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) { //대문자이면
			if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26; //Z 아스키값 넘어갈 시 알파벳 수만큼 빼서 돌아가기(역방향으로 증가)
			else s[i] = s[i] + 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {//소문자이면
			if (s[i] + 13 > 122) s[i] = s[i] + 13 - 26; //Z 아스키값 넘어갈 시 알파벳 수만큼 빼서 돌아가기(역방향으로 증가)
			else s[i] = s[i] + 13;
		}
	}

	cout << s << "\n";

	//-----------------------------------------------------------------------------------------
}