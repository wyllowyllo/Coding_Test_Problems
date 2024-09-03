#include <bits/stdc++.h>
using namespace std;


vector<string> Split(const string line, string delimiter) {
	vector<string> words;

	int start = 0;
	int end = line.find(delimiter); //�ش� ���ڿ����� delimiter�� ��ġ ��ȯ

	while (end != line.npos) { //���̻� delimiterã�� �� ���������� �ݺ�
		string word = line.substr(start, end - start); //���ڿ� ����(������ġ, ũ��)
		words.push_back(word);

		start = end + delimiter.size(); //������ �ܾ��� �� ��ġ + ������ ũ��
		end = line.find(delimiter, start); //start��ġ���� �����Ͽ� �ٽ� ã��
	}
	words.push_back(line.substr(start)); //������ Ž�� ��ġ���� ���ڿ� ������ �ڸ���

	return words;
}
int main() {
	string line = "banana,apple,straw berry,pine_apple";
	
	vector<string> fruits=Split(line, ",");

	for (const string &  fruit : fruits) {
		cout << fruit << "\n";
	}
}