#include <bits/stdc++.h>
using namespace std;

int n;
int m;


char a[51][51];
int ret = 2501;
int cnt = 0;

#pragma region MySol

//전체 보드에서 체스판이 시작되는 왼쪽 위 좌표를 선택
//그 좌표가 W일때의 다시 칠해야하는 개수와, B일때 다시 칠해야하는 개수를 카운트
//시작 좌표로부터 x,y값을 추가해가며 체크판 검사하는데, x+y가 짝수인 경우 그 사각형의 색깔은 시작 좌표 사각형의 색과 같아야 함




void MySol() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) { //시작위치 설정

			for (int k = 0; k < 2; k++) {
				char start = (k == 0) ? 'W' : 'B';
				cnt = 0;



				for (int y = 0; y < 8; y++) {
					for (int x = 0; x < 8; x++) {
						char expected = ((y + x) % 2 == 0) ? start : (start == 'W' ? 'B' : 'W');
						if (a[i + y][j + x] != expected) cnt++;
					}
				}

				ret = min(ret, cnt);
			}

		}


	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1

// 1. 8*8 정답 체스판을 미리 만들어 놓음(W시작/B시작 총 2가지)
// 2. 입력받은 보드에서 시작위치 정해 8*8보드판 만들때, 모든 라인을 비트마스크로 변환. 이후 정답 체스판과 xor비교
// 3. xor비교시 1의 개수만큼 정답 체스판과 차이나는 것이므로 이것이 틀린 개수가 된다

uint8_t patternW[8], patternB[8];

void initPattern() {
	for (int y = 0; y < 8; y++) {
		uint8_t line = 0;
		for (int x = 0; x < 8; x++) {
			if ((y + x) % 2 == 0) line |= (1 << (7 - x));
		}

		patternW[y] = line;
		patternB[y] = ~line;
	}
}

int countDiff(uint8_t board[8], uint8_t pattern[8]) {
	int diff = 0;
	for (int i = 0; i < 8; i++) {
		diff += __builtin_popcount(board[i] ^ pattern[i]); //__builtin_popcount()는 비트 1의 개수를 빠르게 세어줌
	}

	return diff;
}

void Sol_1() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	initPattern();

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			uint8_t board[8];

			for (int y = 0; y < 8; y++) {
				uint8_t line = 0;

				for (int x = 0; x < 8; x++) {
					if (a[i + y][j + x] == 'W') line |= (1 << (7 - x));
				}
				board[y] = line;
			}

			int costW = countDiff(board, patternW);
			int costB = countDiff(board, patternB);
			ret = min({ ret,costW,costB });
		}
	}

	cout << ret << "\n";
}
#pragma endregion

int main() {

	Sol_1();

}