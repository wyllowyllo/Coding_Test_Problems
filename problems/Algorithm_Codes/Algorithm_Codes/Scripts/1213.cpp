#include <bits/stdc++.h>
using namespace std;

string name;
map<char, int> alphaMap; //이름 내 각 알파벳 개수 저장용 맵

int cnt[200]; //map 대신 count배열 선언하여 문제 해결할 수도 있음(solution 1)

int main() {
	cin >> name;

	//-------------------------------------My Solution--------------------------------------------
	for (int i = 0; i < name.length(); i++) {
		alphaMap[name[i]]++;
	}

	int startIdx = 0;
	int endIdx = name.length() - 1;
	int midIdx = (startIdx + endIdx) / 2;

	if (name.length() % 2 == 0) { //총 길이가 짝수
		for (auto alpha : alphaMap) {
			if (alpha.second % 2 != 0) { //짝수길이에서 각 알파벳 개수가 짝수개가 아니면 팰린드롬 생성 x
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}
			else {
				while (alpha.second > 0) {
					name[startIdx++] = alpha.first;
					name[endIdx--] = alpha.first;
					alpha.second-= 2;
				}
			}
		}
	}
	else { //총 길이가 홀수
		char midIdxC = NULL;
		for (auto alpha : alphaMap) {
			if (alpha.second % 2 != 0) { 
				if (midIdxC == NULL) { //홀수개인 알파벳이 단 하나만 있으면, 그 단어 하나빼서 중앙으로 이동. 여러개일경우 팰린드롬 생성 x
					midIdxC = alpha.first;
					alpha.second--;
				}
				else {
					cout << "I'm Sorry Hansoo" << "\n";
					return 0;
				}
			}
				while (alpha.second > 0) {
					name[startIdx++] = alpha.first;
					name[endIdx--] = alpha.first;
					alpha.second -= 2;
				}
			
		}
		name[midIdx] = midIdxC; //중앙에 홀수개인 알파벳이동
	}

	cout << name << "\n";

	//-------------------------------------------------------------------------------------

	//---------------------------------Solution 1-----------------------------------------

	//홀수개인 문자 개수가 2개 이상이면 팰린드롬을 생성하지 못하는 점을 활용.
	char mid;
	int flag;
	string ret;
	for (char a : name) cnt[a]++;
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) //비트변환할시 짝수는 11..0, 홀수는 11..1 이런식으로 나오므로, 홀수라면 해당 연산은 true가 된다.
			{
				mid = char(i); flag++;
				cnt[i]--;
			}
			if (flag == 2) break; //홀수개인 문자가 2개 이상임

			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret; //ret앞에 문자 붙이기
				ret += char(i); //ret 뒤에 문자 붙이기
			}
		}
	}
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid); //중앙에 삽입
	if (flag == 2) cout << "I'm Sorry Hanson\n";
	else cout << ret << "\n";

	//----------------------------------------------------------------------------------
	return 0;
}