#include <bits/stdc++.h>
using namespace std;


//int car[3][100];
int cnt[100];

int main() {
	int A, B, C;
	
	cin >> A >> B >> C;

	//----------------------My Solution ----------------------------------
	/*int start, end;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			car[i][j] = 1;
		}
	}

	int count;
	int totalFee = 0;
	for (int i = 0; i < 100; i++) {
		count = 0;
		for (int j = 0; j < 3; j++) {
			if (car[j][i] == 1)
				count++;
		}

		if (count == 1) {
			totalFee += A * count;
		}
		else if (count == 2) {
			totalFee += B * count;
		}
		else if (count == 3) {
			totalFee += C * count;
		}
		
	}

	cout << totalFee;*/

	//----------------------------------------------------------

	//-----------------Solution 2------------------------------- 내 답안은 차량별 주차시간을 저장하는 배열을 만들어 총 3개의 배열을 가졌지만, 이 답안은 cnt라는 하나의 배열만 둠. 메모리 절약!
	

	int start, end;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++) cnt[j]++;
	}

	int ret = 0;
	for (int i = 1; i < 100; i++) {
		if (cnt[i]) {
			if (cnt[i] == 1) {
				ret += A * 1;
			}
			else if (cnt[i] == 2) {
				ret += B * 2;
			}
			else if (cnt[i] == 3) {
				ret += C * 3;
			}
		}
	}

	cout << ret << "\n";
	//---------------------------------------------------------
	return 0;

}