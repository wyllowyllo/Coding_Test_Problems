#include <bits/stdc++.h>
using namespace std;


int a[110][110];

int n, l;

int ret;

#pragma region MySol

//너무 복잡하길래 뭔가 내가 비트마스킹 모르는 개념이 있나 생각해서 포기하려다가, 걍품
//비트마스킹 문제가 아니고 그냥, 구현 문제였음
//문제를 풀때, 너무 복잡해서 뭔가 스마트한 풀이법을 찾으려고 하기 보단 일단 무식하게 구현해서라도 풀어보기 !


void MySol() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	//행 체크
	for (int i = 0; i < n; i++) {
		int cnt_1 = 1;
		int cnt_2 = 1;
		bool flag = false;

		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) cnt_1++;
			else {
				if (a[i][j] == a[i][j + 1] - 1) { //더 높은 경우
					if (cnt_1 >= l) { cnt_1 = 1; continue; }
					else { flag = true; break; }
				}
				else if (a[i][j] == a[i][j + 1] + 1) { //더 낮은 경우
					cnt_2 = 1; int k;

					for (k = j + 1;; k++) {
						if (a[i][k] == a[i][k + 1]) cnt_2++;
						else break;
					}

					if (cnt_2 >= l) { j = j + l - 1; cnt_1 = 0; continue; }
					else { flag = true; break; }
				}
				else { flag = true; break; } //높이차이가 2
			}

		}

		if (!flag) ret++;
	}

	//열 체크
	for (int i = 0; i < n; i++) {
		int cnt_1 = 1;
		int cnt_2 = 1;
		bool flag = false;

		for (int j = 0; j < n - 1; j++) {
			if (a[j][i] == a[j + 1][i]) cnt_1++;
			else {
				if (a[j][i] == a[j + 1][i] - 1) { //더 높은 경우
					if (cnt_1 >= l) { cnt_1 = 1; continue; }
					else { flag = true; break; }
				}
				else if (a[j][i] == a[j + 1][i] + 1) { //더 낮은 경우
					cnt_2 = 1; int k;

					for (k = j + 1;; k++) {
						if (a[k][i] == a[k + 1][i]) cnt_2++;
						else break;
					}

					if (cnt_2 >= l) { j = j + l - 1; cnt_1 = 0; continue; }
					else { flag = true; break; }
				}
				else { flag = true; break; } //높이차이가 2
			}

		}

		if (!flag) ret++;
	}


	cout << ret << "\n";

}
#pragma endregion

#pragma region Sol_1
int b[110][110];

//나는 행과 열을 검사하는 로직을 따로 만들었지만, 여기서는 원래 행의 대칭 행을 따로 만들어서, 행 검사 로직만으로 문제를 해결함 (원 행렬의 열 == 대칭 행렬의  행 이므로)
//나는 오르막인 경우와, 내리막인 경우의 칸 수를 저장하는 cnt변수를 두개 썻지만, 여기서는 cnt를 하나만 써서 해결함

void solve(int a[110][110]) {
	for (int i = 0; i < n; i++) {
		int cnt = 1; int j;
		for ( j= 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) cnt++;
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;  // 경사로 크기 > 발판개수 이거나 경사로 겹치면 못놓음
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; //만약 cnt가 음수라면, 경사로 못놓음(경사로 크기 > 발판개수 이거나 경사로 겹침)
			else break;
		}

		if (j == n - 1 && cnt >= 0) ret++;
	}
}
void Sol_1() {
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);

			b[j][i] = a[i][j]; //대칭행렬 b 만들기
		}
	}

	solve(a);
	solve(b);

	printf("%d\n", ret);
}
#pragma endregion

int main() {
	
	
}