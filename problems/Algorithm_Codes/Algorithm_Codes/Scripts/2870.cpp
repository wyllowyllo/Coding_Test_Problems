#include <bits/stdc++.h>
using namespace std;



//--------------------------------------------My Solution -------------------------------------------------------------
// 
// 이 문제의 주요 사항 : 변수 범위 !! (100글자의 숫자가 입력될 경우, long long 을 초과하는 범위라 변수에 담을 수 없다 -> string으로 저장해야 함!)
// sort함수의 커스텀 비교함수 적용법 알기!

/*
int n;
string input;
vector<string> ret;

bool cmp(string L1, string L2) {
	//문자열 비교 -> 길이가 같다면, 단순 크기 비교. 길이가 다르다면, 길이가 더 긴게 큰 값이므로 크기 비교
	if (L1.size() == L2.size()) return L1 < L2;
	else return L1.size() < L2.size();
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			char c = input[j];
			if (!isdigit(c)) continue;
			else if (c == '0' && (j != input.size() - 1 && isdigit(input[j + 1]))) continue; //0이 문자열 끝에 있거나, 0앞뒤로 문자가 있으면 입력, 아니면 무시
			else {
				string num; int k;

				for (k = j; k < input.size(); k++) {
					if (!isdigit(input[k]))break;
					num += input[k];
				}
				ret.push_back(num);
				j = k - 1;
			}
		}


	}

	//커스텀 비교함수 적용한 sort
	//cmp함수가 모두 true가 뜨도록 ret정렬함
	sort(ret.begin(), ret.end(), cmp);

	for (auto i : ret) cout << i << '\n';

}*/
//-------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------Solution 1-------------------------------------------------------------

int n;
vector<string> v;
string s, ret;

void go() {
	while (true) {
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin()); //문자열 크기가 1이상이고, 0이 맨 앞에 있을 경우 제거해 나감
		else break;
	}
	if (ret.size() == 0) ret = "0"; // 만약 0000등과 같은 수인 경우, 앞의 코드에서 0이 모두 지워짐. ->0으로 변경
	v.push_back(ret);
	ret = "";
}
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 65) ret += s[j]; //s[j]가 숫자일 경우 추가(아스키 코드 65(A)이하)
			else if (ret.size()) go(); //문자 만났을 경우, 이전까지 추가한 ret이 있을 경우(수열) 0제거작업 ㄱㄱ
		}
		if (ret.size()) go();
	}
	sort(v.begin(), v.end(), cmp); //v의 모든 요소가 cmp를 만족하도록 정렬(cmp가 true가 뜨도록)
	for (string i : v) cout << i << "\n";
}
