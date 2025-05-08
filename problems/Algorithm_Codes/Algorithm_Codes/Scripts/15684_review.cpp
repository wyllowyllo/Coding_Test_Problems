#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int a, b;


int hori[2][31][11]; // (가로선 기준 우/좌) , (가로선 위치(행)), (세로선 번호(열))



//i번 세로선의 결과가 i번이 나오려면
//그 세로선의 좌,우 가로선이 0이거나 짝수개여야 한다(즉 % 2 했을때 나머지가 0)
//모든 가로선의 좌,우 가로선이 0이거나 짝수개이면 된다

//위 로직으로 했을 시 반례가 있어서 폐기(예제 5)
//그냥 가로선 따라 직접 이동해서 결과 보는걸로 변경





int ret = 4;

//bool check() { 	//모든 세로선 사다리타기 결과
//	
//	for (int i = 0; i < n; i++) {
//		int leftCnt = 0, rightCnt = 0;
//
//		for (int j = 0; j < h; j++) {
//			if (hori[0][j][i]) leftCnt++;
//			if (hori[1][j][i]) rightCnt++;
//		}
//
//		if (leftCnt % 2 != 0 || rightCnt % 2 != 0) return false;
//	}
//
//	return true;
//}

bool go() {
	for (int i = 0; i < n; i++) { //각 세로선에 대해 사다리타기
		int num = i;
		int curNum = i;
		for (int j = 0; j < h; j++) {
			if (hori[1][j][curNum]) curNum += 1;
			else if (hori[0][j][curNum]) curNum -= 1;
		}


		if (num != curNum) return false;
	}

	return true;
}

void addHori(int row, int cnt) {
	if (cnt == 4) {
		return;
	}

	if (go()) {
		ret = min(ret, cnt);
		return;
	}

	//가로선 추가할 위치 선택;
	for (int i = row; i < h; i++) {
		for (int j = 0; j < n-1; j++) {

			if (hori[1][i][j] || hori[0][i][j] || hori[0][i][j+1]) continue;

			//가로선 추가
			hori[1][i][j] = 1; //j->j+1로 가는 가로선
			hori[0][i][j + 1] = 1;  //j+1->j로 가는  가로선

			addHori(i, cnt + 1);

			//가로선 제거
			hori[1][i][j] = 0; //j->j+1로 가는 가로선
			hori[0][i][j + 1] = 0;  //j+1->j로 가는  가로선
		}
	}
}

int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		//가로선 
		hori[1][a-1][b-1] = 1; //오른쪽으로 나가는 가로선
		hori[0][a-1][b] = 1; //왼쪽에서 들어오는 가로선
	}

	addHori(0, 0);


	//cout << ret << "\n";

	if (ret > 3)cout << -1 << "\n";
	else cout << ret << "\n";

}