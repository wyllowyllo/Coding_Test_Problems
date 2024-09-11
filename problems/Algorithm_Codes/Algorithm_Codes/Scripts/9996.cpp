#include <bits/stdc++.h>
using namespace std;


vector<string> Split(const string pattern, string delimiter) {
	vector<string> str;

	int startIdx = 0;
	int endIdx = pattern.find(delimiter);

	while (endIdx != pattern.npos) {
		str.push_back(pattern.substr(startIdx, endIdx - startIdx));
		startIdx = endIdx + delimiter.size();
		endIdx = pattern.find(delimiter, startIdx);
	}
	str.push_back(pattern.substr(startIdx));

	return str;
}

int main() {

	//-----------------------------------------My Solution------------------------------------
	int N;
	string pattern;
	cin >> N; //파일개수 입력
	cin >> pattern; //패턴 입력
	cin.ignore();

	string fName;
	vector<string> fileNames;
	for (int i = 0; i < N; i++) {
		getline(cin, fName);
		fileNames.push_back(fName);
	}

	vector<string> str = Split(pattern, "*"); // '*'기준 좌, 우 문자열로 분리

	//각 파일이름에 대해 패턴 비교
	for (auto file : fileNames) {
		if (file.size() < str[0].size() + str[1].size()) { //파일이름 길이가 패턴 양쪽 길이 합보다 짧음
			cout << "NE" << "\n";
			continue;
		}

		string leftPart = file.substr(0, str[0].size()); // 패턴의 '*' 왼쪽 문자열과 파일 이름 비교
		string rightPart = file.substr(file.size() - str[1].size()); // 패턴의 '*' 오른쪽 문자열과 파일 이름 비교

		if (leftPart == str[0] && rightPart == str[1]) {
			cout << "DA" << "\n";
		}
		else {
			cout << "NE" << "\n";
		}
	

	}

	//------------------------------------------------------------------------------------------

	//-------------------------------Solution 1-------------------------------------------------
	int n;
	string pat;
	string pre, suf;
	int pos;

	cin >> n;
	cin >> pat;

	pos = pat.find("*"); // *의 인덱스 저장
	pre = pat.substr(0, pos); //패턴의 * 앞부분 추출
	suf = pat.substr(pos + 1); //패턴의 * 뒷부분 추출

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.size() < pre.size() + suf.size()) { //접두사, 접미사 길이 합보다 파일이름 길이가 작음
			cout << "NE" << "\n";
		}
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA" << "\n";
			else cout << "NE" << "\n";
		}

		
	}

	//------------------------------------------------------------------------------------------------------
	return 0;
}