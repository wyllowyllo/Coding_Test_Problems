#include <bits/stdc++.h>
using namespace std;

//----------------------------------------My Solution ----------------------------//
/*map<int, string >m1; //팀-마지막 골 시간
int m2[2]; //팀-승리 누적시간

int score[2]; //팀1,2 점수

int n;
int team, winTeam=-1;
string winStartTime; //이기기 시작한 시점
string t;

int ConvertToSec(string score_time) {
	int min = stoi(score_time.substr(0, 2));
	int sec = stoi(score_time.substr(3));
	int total = min * 60 + sec;

	return total;
}
string ConvertToMinSec(int score) {

	if (score == 0) return string("00:00");
		

	string min, sec;
	min= to_string(score / 60);  score %= 60;
	sec =to_string(score);

	

	if (min.size() == 1) min = "0" + min;
	if (sec.size() == 1) sec = "0" + sec;
	

	return string(min + ":" + sec);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> team >> t; //팀-득점시간 입력

		m1[team -1]=t;
		score[team - 1]++;

		if (winTeam == -1 && score[0] > score[1]) {
			winTeam = 0;
			winStartTime = t;
		}
			
		else if (winTeam == -1 && score[0] < score[1]) {
			winTeam = 1;
			winStartTime = t;
		}
		else if (score[0] == score[1]) {
			int t1 = ConvertToSec(winStartTime);
			int t2 = ConvertToSec(m1[team-1]);
			
			int diff = abs(t2 - t1);
			m2[winTeam] += diff;

			winTeam = -1;
		}
	}

	if (score[0] != score[1]) {
		int t1 = ConvertToSec(winStartTime);
		int endTime = ConvertToSec("48:00");

		int diff = abs(endTime - t1);
		m2[winTeam] += diff;
	}
	

	for(int i=0;i<2;i++)
		cout << ConvertToMinSec(m2[i]) << "\n";

}*/

//-------------------------------------------------------------------------------

//-----------------------------------Solution 1----------------------------------
//나는 이기고 있는 팀이 바뀔 때마다 시간을 계산해서 누적했으나, 이 방법에서는 매 입력마다 시간차를 누적시킴
#define prev mingwan //prev변수를 정의한 라이브러리가 포함되었으므로, define으로 정의

int n, o, A, B, asum, bsum;
string s, prev;

string print(int a) {
	string min = "00" + to_string(a / 60);
	string sec = "00" + to_string(a % 60);

	return min.substr(min.size() - 2, 2) + ":" + sec.substr(sec.size() - 2, 2);
}
int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3).c_str()); //c_str():const char* 을 리턴함(문자열 변경 방지)
}
void go(int& sum, string s) {
	sum += (changeToInt(s) - changeToInt(prev));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> s;
		if (A > B) go(asum, s);
		else if (B < A) go(bsum, s);
		o == 1 ? A++ : B++;
		prev = s;
	}
}