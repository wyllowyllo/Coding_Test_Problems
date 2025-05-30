#include <bits/stdc++.h> 
using namespace std;


#pragma region MySol

namespace My {

	int n;
	int x, y, d, g;

	const int max_n = 101;
	int a[max_n][max_n];

	const int dy[] = { 0,-1,0,1 };
	const int dx[] = { 1,0,-1,0 };

	const double PI = 3.141592;
	const double rad = (-90.0f) * (PI / 180.0f);

	int ret;
	//회전변환 행렬 정의 (원점이 중점이고 반지름이 radius인 원)
	double rotateMat[2][2] = {
		{cos(rad), sin(rad) * (-1)},
		{sin(rad), cos(rad)}
	};

	pair<int, int> Rotate(int y, int x, int centerY, int centerX) {



		//평행이동
		y = -(y - centerY);
		x = x - centerX;

		//회전변환
		int rx = round(rotateMat[0][0] * x + rotateMat[0][1] * y);
		int ry = round(rotateMat[1][0] * x + rotateMat[1][1] * y);

		//다시 원래 위치로 평행이동
		int nx = centerX + rx;
		int ny = centerY - ry;

		//cout << ny <<" "<<nx << "\n";

		return { ny,nx };
	}
	void DragonCurve(int x, int y, int d, int g) {

		a[y][x] = 1;
		int edgeY = y + dy[d];
		int edgeX = x + dx[d];

		a[edgeY][edgeX] = 1;

		int centerY;
		int centerX;

		vector<pair<int, int>> p;
		p.push_back({ y,x });
		p.push_back({ edgeY,edgeX });

		int ny, nx;
		for (int i = 1; i <= g; i++) {

			centerY = p.back().first;
			centerX = p.back().second;
			for (int i = p.size() - 2; i >= 0; i--) {
				tie(ny, nx) = Rotate(p[i].first, p[i].second, centerY, centerX);

				a[ny][nx] = 1;
				p.push_back({ ny,nx });
			}
		}


	}
	void Scan() {
		for (int i = 0; i < max_n - 1; i++) {
			for (int j = 0; j < max_n - 1; j++) {
				if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
					ret++;
				}
			}
		}
	}



	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> d >> g;

			DragonCurve(x, y, d, g);
		}

		//정사각형 검사
		Scan();

		cout << ret << "\n";
	}
}
#pragma endregion

#pragma region Sol_1

//기하처럼 보이는 문제는, 거의 대부분 '규칙찾기' 문제임을 기억하자!!
//기하같이 보이는 문제를 보면, 규칙을 먼저 찾아보자!

//세대별 드래곤 커브의 방향을 모아보면, {이전 세대 방향 집합의 역순 +1} + {이전 세대 방향 집합 } 인 것을 알 수 있다!


namespace Sol {
	const int dy[] = { 0, -1, 0, 1 };
	const int dx[] = { 1, 0, -1, 0 };
	vector<int> dragon[4][11]; //{시작방향,세대}
	int cnt, n, x, y, d, g, a[101][101];

	void go(int x, int y, int d, int g) {
		a[x][y] = 1;

		for (int i = 0; i <= g; i++) {
			for (int dir : dragon[d][i]) {
				x += dx[dir];
				y += dy[dir];
				a[x][y] = 1;
			}
		}
	}
	void MakeDragon() {
		for (int i = 0; i < 4; i++) {
			dragon[i][0].push_back(i); //0세대 드래곤커브 방향
			dragon[i][1].push_back((i + 1) % 4); //1세대 드래곤커브 방향

			for (int j = 2; j <= 10; j++) { //2세대 ~ 10세대
				int n = dragon[i][j - 1].size(); 

				//현재 세대의 방향 집합 = 이전세대의 방향의 역순으로 해서 +1씩 + 직전세대 방향 집합
				for (int k = n - 1; k >= 0; k--) {
					dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
				}
				for (int k = 0; k < n; k++) {
					dragon[i][j].push_back(dragon[i][j - 1][k]);
				}
			}
		}
	}

	void Sol_1() {
		cin >> n;
		MakeDragon(); //0세대의 시작 방향 d 4가지에 따른 10세대까지의 각 세대 드래곤 커브 방향집합 생성

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> d >> g;
			go(x, y, d, g);
		}

		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1])cnt++;
			}
		}
		cout << cnt << "\n";
	}
}

#pragma endregion

int main() {
	Sol::Sol_1();
}