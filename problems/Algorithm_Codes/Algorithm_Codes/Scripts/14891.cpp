#include <bits/stdc++.h>
using namespace std;

int k;
string s;

int n, dir;
vector<pair<int, int>> rot;
vector<vector<int>> v;
int ret;

void Print() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++)
			cout << v[i][j];
		cout << "\n";
	}
}
void RotateWheel(int WheelNum, int dir) {
	if (dir == -1)
		rotate(v[WheelNum].begin(), v[WheelNum].begin() + 1, v[WheelNum].end());
	else
		rotate(v[WheelNum].rbegin(), v[WheelNum].rbegin() + 1, v[WheelNum].rend());
}
void WheelCheck(int startWheel, int dir) {
	int leftEdge, rightEdge;



	int ldir = dir;

	leftEdge = v[startWheel][6];
	rightEdge = v[startWheel][2];


	//startWheel의 왼쪽에 있는 바퀴들 검사&회전
	for (int i = startWheel - 1; i >= 0; i--) {
		if (v[i][2] == leftEdge) break;

		leftEdge = v[i][6];
		rightEdge = v[i][2];
		ldir = -ldir;
		RotateWheel(i, ldir);
	}

	int rdir = dir;
	leftEdge = v[startWheel][6];
	rightEdge = v[startWheel][2];

	//startWheel의 오른쪽에 있는 바퀴들 검사&회전
	for (int i = startWheel + 1; i < 4; i++) {
		if (v[i][6] == rightEdge) break;

		leftEdge = v[i][6];
		rightEdge = v[i][2];
		rdir = -rdir;
		RotateWheel(i, rdir);
	}

	//startWheel 돌리기
	RotateWheel(startWheel, dir);
}
int main() {

	for (int i = 0; i < 4; i++) {
		vector<int> tmp;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			tmp.push_back(s[j] - '0');
		}
		v.push_back(tmp);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> dir;
		rot.push_back({ n,dir });
	}

	for (auto i : rot) {
		WheelCheck(i.first - 1, i.second);
	}

	//Print();
	if (v[0][0]) ret += 1;
	if (v[1][0]) ret += 2;
	if (v[2][0]) ret += 4;
	if (v[3][0]) ret += 8;

	cout << ret << "\n";
}