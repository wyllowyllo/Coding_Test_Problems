#include <bits/stdc++.h>
using namespace std;


string name;
map<char, int> m1;
string prefix="", suffix="";


#pragma region Mysol

void MySol() {
	cin >> name;

	for (char c : name) {
		m1[c]++;
	}

	//sort(m1.begin(), m1.end());

	if (name.size() == 1) {
		cout << name << "\n";
		return;
	}
	else if (name.size() % 2 == 0) {
		//이름 길이가 짝수이면 모든 문자가 짝수개여야 함
		for (auto v : m1) {
			if (v.second % 2 != 0) {
				cout << "I'm Sorry Hansoo\n";
				return;
			}
			else {
				for (int i = 0; i < v.second / 2; i++) {
					prefix += v.first;
					suffix += v.first;
				}
			}
		}

		reverse(suffix.begin(), suffix.end());
		string ret = prefix + suffix;
		cout << ret << "\n";
		return;

	}
	else {
		//이름 길이가 홀수이면 한 문자만 홀수고 나머진 모두 짝수
		string mid = "";
		for (auto v : m1) {
			if (v.second % 2 != 0) {
				if (mid == "") {
					mid = v.first;
					v.second--;
					for (int i = 0; i < v.second / 2; i++) {
						prefix += v.first;
						suffix += v.first;
					}

				}
				else {
					cout << "I'm Sorry Hansoo\n";
					return;
				}

			}
			else {
				for (int i = 0; i < v.second / 2; i++) {
					prefix += v.first;
					suffix += v.first;
				}
			}
		}

		reverse(suffix.begin(), suffix.end());
		string ret = prefix + mid + suffix;
		cout << ret << "\n";
		return;
	}
}
#pragma endregion

#pragma region Sol_1

//가장 먼저 해야 할 일 : 어떤 케이스일 때 팰린드롬을 만들 수 없을까?
//내가 찾은 답 : 문자열의 길이가 짝수이면 모든 알파벳 개수가 짝수여야 하고, 길이고 홀수이면 하나의 알파벳만 홀수고 나머지 문자는 다 짝수여야 함
//솔루션의 답 : 홀수개인 문자가 없거나, 1개만 있어야 함.

//두번째 문제 : 팰린드롬이 여러개라면, 오름차순 순으로 정렬된 것을 출력해야 함
//내가 찾은 답 : map에서 키를 알파벳으로 하면, map상에서 자동으로 오름차순 정렬됨
//솔루션의 답 : 입력되는 문자는 A ~ Z 사이의 값이므로, Z부터 중앙값에 넣기 시작하여 A까지 갈수록 양옆에 붙여나가는 방식

void Sol_1() {
	int cnt[200] = { 0 }; //카운팅 배열
	int flag = 0;
	char mid;
	string ret = "";

	cin >> name;

	for (char c : name) cnt[c]++;
	for (int i = 'Z'; i >= 'A'; i--) { //Z부터 시작하여 붙이기 -> 결과값은 자연스레 오름차순 정렬된 값이 됨

		if (cnt[i]) { //해당 문자가 있다면
			if (cnt[i] & 1) { //홀수인가?
				mid = char(i); flag++;
				cnt[i]--;
			}

			if (flag == 2) break; //홀수개인 문자가 2개 이상인 경우

			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret; //앞에 붙이기
				ret += char(i); //뒤에 붙이기
			}
		}
	}

	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid); //중앙에 mid값 삽입
	if (flag == 2) cout << "I'm Sorry Hansoo\n"; //홀수 개 문자 2개이상
	else cout << ret << "\n";

}
#pragma endregion

int main() {
	//MySol();
	Sol_1();
	return 0;
}