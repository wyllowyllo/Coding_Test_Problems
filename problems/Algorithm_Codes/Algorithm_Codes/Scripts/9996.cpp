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
	cin >> N; //���ϰ��� �Է�
	cin >> pattern; //���� �Է�
	cin.ignore();

	string fName;
	vector<string> fileNames;
	for (int i = 0; i < N; i++) {
		getline(cin, fName);
		fileNames.push_back(fName);
	}

	vector<string> str = Split(pattern, "*"); // '*'���� ��, �� ���ڿ��� �и�

	//�� �����̸��� ���� ���� ��
	for (auto file : fileNames) {
		if (file.size() < str[0].size() + str[1].size()) { //�����̸� ���̰� ���� ���� ���� �պ��� ª��
			cout << "NE" << "\n";
			continue;
		}

		string leftPart = file.substr(0, str[0].size()); // ������ '*' ���� ���ڿ��� ���� �̸� ��
		string rightPart = file.substr(file.size() - str[1].size()); // ������ '*' ������ ���ڿ��� ���� �̸� ��

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

	pos = pat.find("*"); // *�� �ε��� ����
	pre = pat.substr(0, pos); //������ * �պκ� ����
	suf = pat.substr(pos + 1); //������ * �޺κ� ����

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.size() < pre.size() + suf.size()) { //���λ�, ���̻� ���� �պ��� �����̸� ���̰� ����
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