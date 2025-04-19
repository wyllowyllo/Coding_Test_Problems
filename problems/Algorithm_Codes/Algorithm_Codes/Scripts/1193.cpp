#include <bits/stdc++.h>
using namespace std;

int x;


#pragma region MySol
int range = 1;

bool dir = false; //방향

void MySol() {
	cin >> x;

	int start = 1;
	int end = 1;

	while (true)
	{
		if (x <= end) {

			if (dir) {
				int order = x - start + 1;
				int row = order; int col = range - order + 1;
				printf("%d/%d\n", row, col);
			}
			else {
				int order = x - start + 1;
				int row = range - order + 1; int col = order;
				printf("%d/%d\n", row, col);
			}

			exit(0);
		}

		start = end + 1;
		end = start + range;
		dir = !dir;
		range++;
	}

}

#pragma endregion


#pragma region Sol_1

void Sol_1() {
	cin >> x;

	int line = 1;//몇번째 대각선에 속하는지
	while (x > line) {
		x -= line; //각 라인에 속한 개수만큼 차감
		line++;//다음 줄로
	}

	// line번째 대각선에서 X번째 원소가 정답
   // line이 짝수면 오른쪽에서 왼쪽으로 증가 / 홀수면 왼쪽에서 오른쪽으로 증가
	int numerator, denominator;
	if (line % 2 == 0) {
		numerator = x;
		denominator = line - x + 1;
	}
	else {
		numerator = line - x + 1;
		denominator = x;
	}

	cout << numerator << "/" << denominator << '\n';
	return;
}
#pragma endregion

int main() {


}