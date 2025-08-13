#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10][10];

struct CCTV {
	int y, x;
	int dir;
} cams[10];
int idx;

int ret = 100;

int dy[] = { -1,0,1,0 };
int dx[] = { 0, 1, 0, -1 };

void View(int camIdx, int cnt) {

	//회전 각도 설정
	int cast_dir = cams[camIdx].dir;
	for (int i = 0; i < cnt; i++) {
		cast_dir <<= 1;
		if (cast_dir & (1 << 4)) {
			cast_dir &= ~(1 << 4);
			cast_dir |= (1 << 0);
		}
	}

	//투사
	
	for (int i = 0; i < 4; i++) {
		if (cast_dir & (1 << i)) {
			int y = cams[camIdx].y;
			int x = cams[camIdx].x;
			while (true) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
				if (a[ny][nx] == 6) break;
				if (a[ny][nx] == 0)  a[ny][nx] = -1;
				
				y = ny;
				x = nx;
				
			}
			

		}
	}


}
void check() {
	int _size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) _size++;
		}
	}
	ret = min(ret, _size);
}
void go(int here) {
	if (here == idx) {
		check();
		return;
	}

	//here번 카메라 회전 각도 설정
	for (int i = 0; i < 4; i++) {
		int temp[10][10];
		memcpy(temp, a, sizeof(temp));

		View(here, i);

		go(here + 1);

		//복원
		memcpy(a, temp, sizeof(a));
	}
}
int getMask(int num) {
	if (num == 1) return 1;
	if (num == 2) return 10;
	if (num == 3) return 3;
	if (num == 4) return 11;
	if (num == 5) return 15;
}
int main() {
	


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j]>=1 && a[i][j]<=5) {
				cams[idx].y = i;
				cams[idx].x = j;
				cams[idx].dir = getMask(a[i][j]);
				idx++;
			}
		}
	}

	go(0);

	cout << ret << "\n";
}