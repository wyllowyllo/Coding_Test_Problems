#include <bits/stdc++.h>
using namespace std;


int h, w;
int a[101][101];
char c;

#pragma region MySol

void MySol() {
	memset(a, -1, sizeof(a));

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c;
			if (c == 'c') {
				a[i][j] = 0;

				for (int k = j + 1; k < w; k++) {

					a[i][k] = k - j;

				}
			}

		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

}
#pragma endregion

#pragma region Sol_1

//나는 구름이 있는 위치와 현재 위치의 x좌표 차이만큼을 계산해서, 그것을 구름이 도착하는 시간으로 사용함
//여기서는 배열에서 구름이 있는 위치의 오른쪽 칸에 cnt를 할당하며, 이때 cnt는 1씩 증가함
string s;

void Sol_1() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '.')a[i][j] = -1;
			else a[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) {
				int cnt = 1;
				
				//현재 위치 x좌표의 오른쪽 좌표들을 검사
				while (a[i][j + 1] == -1) {
					a[i][j + 1] = cnt++;
					j++;
				}
			}
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) cout << a[i][j] << " ";
		cout << "\n";
	}

}
#pragma endregion


int main() {






}