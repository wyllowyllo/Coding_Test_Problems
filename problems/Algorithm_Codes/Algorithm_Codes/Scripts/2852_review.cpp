#include <bits/stdc++.h>


#pragma region MySol

int score[3]; //점수
int winTime[3]; //누적시간
int startToWin[3]; //이기기 시작한 시간

int n;
int current_winTeam = -1; //현재 이기고 있는 팀(1 or 2) 저장 변수


int team;
string _time;


void MySol() {
	cin >> n;
	while (n--) {
		cin >> team;
		cin >> _time;


		(team == 1) ? score[1]++ : score[2]++; //스코어 계산

		string min = _time.substr(0, 2); string sec = _time.substr(3, 2);
		int totalTime = (stoi(min) * 60 + stoi(sec)); //시간 변환


		if (score[1] > score[2] && current_winTeam == -1) {
			current_winTeam = 1;


			startToWin[1] = totalTime;
		}


		else if (score[1] < score[2] && current_winTeam == -1) {
			current_winTeam = 2;

			startToWin[2] = totalTime;
		}

		else if (score[1] == score[2]) {
			//동점이 되는 시간

			//이기고 있었던 팀의 누적시간 계산
			winTime[current_winTeam] += totalTime - startToWin[current_winTeam];

			//현재 이기고 있는 팀 다시 없음
			current_winTeam = -1;
		}
	}

	//경기 종료 후 이기고 있던 팀의 누적시간 계산
	int endTime = 48 * 60;
	winTime[current_winTeam] += endTime - startToWin[current_winTeam];

	for (int i = 1; i <= 2; i++) {
		int min = winTime[i] / 60;
		int sec = winTime[i] % 60;

		printf("%02d:%02d\n", min, sec);
	}
}
#pragma endregion

#pragma region Sol_1

//내가 한 방법 : 이기고 있던 시간을 구할 때, (동점이 된 시간) - (처음 이기기 시작한 시간) 으로 계산한다
// 여기서는, 매번 입력받을 때마다 시간차를 누적시키는 방식으로 접근함

using namespace std;
#define prev mingwan
string s, prev;
int o, A, B, asum, bsum;

string print(int a) {
	//int를 분:초 형식으로 변환
	string d = "00" + to_string(a / 60); //00+분
	string e = "00" + to_string(a % 60); //00+초

	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size()-2,2); //문자열 끝에서 2번쨰부터 반환
}
int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int& sum, string s) {
	sum += (changeToInt(s) - changeToInt(prev));
}

void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> s;
		if (A > B) go(asum, s);
		else if (B < A) go(bsum, s);
		o == 1 ? A++ : B++;
		prev = s;
	}

	if (A > B)go(asum, "48:00");
	else if (B > A)go(bsum, "48:00");
	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";
}


#pragma endregion


int main() {

	
	
}