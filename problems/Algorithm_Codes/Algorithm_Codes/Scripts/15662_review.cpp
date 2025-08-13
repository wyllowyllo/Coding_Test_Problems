#include <bits/stdc++.h>
using namespace std;

int t, k;
string s;
vector<int>wheel[1001];

int n, d;
int ret = 0;

void rotateWheel(int num, int dir) {
	if (dir == -1) rotate(wheel[num].begin(), wheel[num].begin() + 1, wheel[num].end());
	else rotate(wheel[num].rbegin(), wheel[num].rbegin() + 1, wheel[num].rend());
}


void go(int num, int dir) {
	int l = wheel[num][6];
	int r = wheel[num][2];

	//현재바퀴 회전
	rotateWheel(num, dir);

	//현재 바퀴 왼쪽에 있는 바퀴 회전
	int prevL = l, prevDir = dir;
	for (int wheelNum = num - 1; wheelNum >= 0; wheelNum--) {
		if (wheel[wheelNum][2] == prevL) break;


		prevL = wheel[wheelNum][6];
		rotateWheel(wheelNum, prevDir*-1);
		prevDir = prevDir * -1;
	}

	//현재 바퀴 오른쪽에 있는 바퀴 회전
	int prevR = r;
	prevDir = dir;
	for (int wheelNum = num + 1; wheelNum < t; wheelNum++) {
		if (wheel[wheelNum][6] == prevR) break;


		prevR = wheel[wheelNum][2];
		rotateWheel(wheelNum, prevDir * -1);
		prevDir = prevDir * -1;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			wheel[i].push_back(s[j] - '0');
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> d;

		go(n-1, d);
	}

	for (int i = 0; i < t; i++) {
		if (wheel[i][0] == 1) ret++;
	}
	cout << ret << "\n";
}