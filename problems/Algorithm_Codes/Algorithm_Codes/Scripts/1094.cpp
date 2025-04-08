#include <bits/stdc++.h>
using namespace std;

int x;


#pragma region MySol

//문제 이해를 잘못해서 오래걸림;;;
//

int stick = 64; //막대기 종류
int cnt = 0;


void MySol() {
	cin >> x;

	if (x == 64) { cout << 1 << "\n"; return 0; }


	while (true) {

		if (x <= 0) break;
		int s = (stick & -stick);// 가장 하위에 있는 1의 위치 찾기 (즉, 가장 짧은 길이의 막대기 찾기)

		int stick_half = (s / 2); //가장 짧은 막대기 반갈


		if (stick_half <= x) {
			x -= stick_half;
			cnt++;
		}



		stick |= stick_half;
	}

	cout << cnt << "\n";
}
#pragma endregion

#pragma region Sol_1

// 막대기를 계속 반갈했을 때, 그 조합으로 x를 만드는 문제
// ex ) x=23 이라면, 16 + 4 + 2 + 1 로 할수 있음.
// 이떄 23의 이진수 표현은 10111. 이는 16+4+2+1과 같음
//다시말해, 이 문제는 주어진 수를 이진수로 변환하여 그때의 1의 개수를 구하는 문제임.

int ret = 1;
void Sol_1() {

	cin >> x;

	while (x != 1) {
		if (x % 1) ret++; //홀수이면, 2로 나눴을때 나머지가 1이므로
		x /= 2;
	}
	
	cout << ret << "\n";
}
#pragma endregion


int main() {

	

}