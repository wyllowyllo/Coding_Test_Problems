

#include <bits/stdc++.h>
#pragma warning(disable: 4996)


using namespace std;


int a[5][5];
int n, m;

#pragma region MySol

//행렬의 각 부분이 가로집합에 포함될지, 세로집합에 포함될지를 결정
	//그럼 위의 경우의 수는 최대 2^16  (대략 6만?)
	//그렇게 정한 집합방향에 따라 집합 형성 후, 사이즈 구하기

int group[5][5]; //각 부분이 가로집합에 포함될지, 세로집합에 포함될지를 설정
int visited[5][5];

int mx = 0;
string s;


void SetDirect(int idx) {
	if (idx == (n * m)) {

		memset(visited, 0, sizeof(visited));
		int sum = 0;

		//설정된 그룹 방향에 따라 그룹 형성
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) continue;

				if (group[i][j] == 0) { //가로방향으로 그룹형성 시작
					int groupNum = 0;
					for (int k = j; k < m; k++) {
						if (group[i][k] == 1) break; //세로방향그룹에 속하는 칸을 만나면 탈출
						if (visited[i][k]) break;
						groupNum *= 10;
						groupNum += a[i][k];
						visited[i][k] = 1;
					}

					sum += groupNum;
				}
				else { //세로방향으로 그룹형성 시작

					int groupNum = 0;
					for (int k = i; k < n; k++) {
						if (group[k][j] == 0) break; //가로방향그룹에 속하는 칸을 만나면 탈출
						if (visited[k][j]) break;
						groupNum *= 10;
						groupNum += a[k][j];
						visited[k][j] = 1;
					}

					sum += groupNum;

				}
			}
		}

		//완성된 그룹의 값 합 sum 과 최댓값 mx 비교
		mx = max(mx, sum);
		return;
	}

	for (int i = 0; i < 2; i++) {
		group[idx / m][idx % m] = i; //해당 칸이 0이면 가로집합에 속하고, 1이면 세로집합에 속함
		SetDirect(idx + 1);
	}

}


void MySol() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}


	SetDirect(0);
	cout << mx << "\n";
}
#pragma endregion

#pragma region Sol_1

int ret;

void Sol_1() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);//공백으로 구분되지 않을 때, 숫자 1개씩 입력받기
		}
	}

	//n*m의 맵에서 각 숫자가 가로집합에 포함될지, 세로집합에 포함될지를 정함(0==가로, 1==세로)
	//나는 재귀를 사용하여 전체 경우의 수를 정했지만, 여기서는 비트마스킹을 활용하여 더욱 간략하고 효과적으로 경우의 수를 구현함
	for (int s = 0; s < (1 << n * m); s++) {
		int sum = 0;

		//가로 검사
		for (int i = 0; i < n; i++) {
			int cur = 0;

			for (int j = 0; j < m; j++) {
				int k = i * m + j; //(한 행당 칸의 수인 m) × (현재 행 번호 i) + (현재 열 번호 j)
				if ((s & (1 << k)) == 0) { //해당 칸이 가로집합에 속함
					cur = cur * 10 + a[i][j];

				}
				else {
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}

		//세로 검사
		for (int j = 0; j < m; j++) {
			int cur = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j; //(한 행당 칸의 수인 m) ×(현재 행 번호 i) + (현재 열 번호 j)

				if ((s & (1 << k)) != 0) { //해당 칸이 세로집합에 속함
					cur = cur * 10 + a[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}
		ret = max(ret, sum);
	}

	cout << ret << "\n";
}

#pragma endregion



int main() {
	
	Sol_1();

	
}