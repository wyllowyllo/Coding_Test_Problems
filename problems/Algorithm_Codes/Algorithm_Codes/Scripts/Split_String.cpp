#include <bits/stdc++.h>
using namespace std;


vector<string> Split(const string line, string delimiter) {
	vector<string> words;

	int start = 0;
	int end = line.find(delimiter); //해당 문자열에서 delimiter의 위치 반환

	while (end != line.npos) { //더이상 delimiter찾을 수 없을때까지 반복
		string word = line.substr(start, end - start); //문자열 추출(시작위치, 크기)
		words.push_back(word);

		start = end + delimiter.size(); //추출한 단어의 끝 위치 + 구분자 크기
		end = line.find(delimiter, start); //start위치부터 시작하여 다시 찾기
	}
	words.push_back(line.substr(start)); //마지막 탐색 위치부터 문자열 끝까지 자르기

	return words;
}
int main() {
	string line = "banana,apple,straw berry,pine_apple";
	
	vector<string> fruits=Split(line, ",");

	for (const string &  fruit : fruits) {
		cout << fruit << "\n";
	}
}