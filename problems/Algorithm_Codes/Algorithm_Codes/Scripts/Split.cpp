#include <bits/stdc++.h>
using namespace std;


#pragma region 문자열에서 단어 추출하기

vector<string> Split(const string & input, const string delimiter) { //원본 문자열과 구분자를 인자로
	auto start = 0;
	auto end = input.find(delimiter); //구분자가 있는 곳 찾아 위치반환

	vector<string> result;

	while (end != string::npos) { //더이상 구분자 찾을 수 없을 때까지 반복
		result.push_back(input.substr(start, end-start)); //substr(문자열 시작위치, 추출 문자열 크기) 사용하여 추출
		start = end + delimiter.size(); //start위치 업데이트
		end = input.find(delimiter, start); //end 위치 업데이트(다시 구분자 위치 찾는데, 이때 start위치부터 시작하여 찾음)
	}

	//문자열 끝 도달시 반복문 탈출. 이때 마지막 위치의 문자열 추가
	result.push_back(input.substr(start)); 
	return result;
}

#pragma endregion

int main() {
	string s = "banana,apple,peach,lemon";
	vector<string> ret = Split(s,",");
	for (const string & str : ret) cout << str << "\n";
}