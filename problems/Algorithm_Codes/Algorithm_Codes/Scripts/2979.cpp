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

	//-----------------Solution 2------------------------------- �� ����� ������ �����ð��� �����ϴ� �迭�� ����� �� 3���� �迭�� ��������, �� ����� cnt��� �ϳ��� �迭�� ��. �޸� ����!
	

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