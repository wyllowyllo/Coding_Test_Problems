#include <bits/stdc++.h>
using namespace std;


#pragma region MySol

namespace My {
	int R, C, M;

	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,1,-1 };

	struct Shark
	{
		int r, c;
		int s;
		int d;
		int z;

		Shark(int r, int c, int s, int d, int z) {
			this->r = r;
			this->c = c;
			this->s = s;
			this->d = d;
			this->z = z;
		}
	};

	int r, c, s, d, z;
	vector<Shark*> a[101][101];



	vector<Shark*> v;
	vector<Shark*> tmp;

	int ret;

	Shark* killShark = NULL;

	void Fight() {
		tmp.clear();

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (a[i][j].size() > 1) {
					sort(a[i][j].begin(), a[i][j].end(), [](auto a, auto b) {
						return a->z > b->z; });

					while (a[i][j].size() > 1) a[i][j].pop_back();
					tmp.push_back(a[i][j].front());
				}
				else if (a[i][j].size() == 1) tmp.push_back(a[i][j].front());
			}
		}
	}

	void MySol() {
		cin >> R >> C >> M;

		for (int i = 0; i < M; i++) {
			cin >> r >> c >> s >> d >> z;
			Shark* sh = new Shark(r - 1, c - 1, s, d - 1, z);
			v.push_back(sh);
			a[r - 1][c - 1].push_back(sh);
		}


		for (int i = 0; i < C; i++) {

			killShark = NULL;
			//상어잡기
			for (int j = 0; j < R; j++) {
				if (a[j][i].size()) {
					killShark = a[j][i].front();
					ret += killShark->z;
					a[j][i].pop_back();
					break;
				}
			}

			//상어 이동
			vector<Shark*> m[101][101]; //새로 만들 상어 맵
			for (auto sh : v) {

				if (sh == killShark) continue;

				int cycle = (sh->d < 2 ? (R - 1) * 2 : (C - 1) * 2);
				int move = sh->s % cycle;

				while (move--) {
					int nr = sh->r + dy[sh->d], nc = sh->c + dx[sh->d];
					if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
						// 방향 반전
						if (sh->d == 0) sh->d = 1;
						else if (sh->d == 1) sh->d = 0;
						else if (sh->d == 2) sh->d = 3;
						else sh->d = 2;
						nr = sh->r + dy[sh->d];
						nc = sh->c + dx[sh->d];
					}
					sh->r = nr; sh->c = nc;
				}

				m[sh->r][sh->c].push_back(sh);
			}

			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					a[i][j].swap(m[i][j]);

			//상어 싸움
			Fight();

			v.clear();
			v = tmp;
		}

		cout << ret << "\n";
	}
}
#pragma endregion




#pragma region Sol_1

namespace Sol {

#define max_n 101


	struct Shark {
		int y, x, s, dir, z, death;
	}a[max_n*max_n]; //모든 상어의 정보 관리하는 배열

	const int dy[] = { -1,1,0,0 };
	const int dx[] = { 0,0,1,-1 };

	int shark[max_n][max_n], R, C, M, ret, temp[max_n][max_n];


	void Sol_1() {
		cin >> R >> C >> M;

		for (int i = 1; i <= M; i++) {
			cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
			

			a[i].y--; a[i].x--; a[i].dir--;

			if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
			else a[i].s %= (2 * (C - 1));

			shark[a[i].y][a[i].x] = i;
		}

		//낚시꾼 이동
		for (int t = 0; t < C; t++) {

			//낚시
			for (int y = 0; y < R; y++) {
				if (shark[y][t]) {
					a[shark[y][t]].death = 1; //그 상어 사망처리
					ret += a[shark[y][t]].z;
					shark[y][t] = 0;
					break;
				}
			}


			memset(temp, 0, sizeof(temp));

			//상어 이동
			for (int i = 1; i <= M; i++) {
				if (a[i].death) continue;

				int y = a[i].y;
				int x = a[i].x;
				int s = a[i].s;
				int d = a[i].dir;
				int ny, nx;

				while (1) {
					ny = y + s * dy[d];
					nx = x + s * dx[d];

					if (ny < R && ny >= 0 && nx < C  && nx >= 0) break;

					if (d <= 1) { //상하이동일 경우
						if (ny < 0) {
							s -= y;
							y = 0;
						}
						else {
							s -= R - 1 - y;
							y = R - 1;
						}
					}
					else { //좌우이동일 경우
						if (nx < 0) {
							s -= x;
							x = 0;
						}
						else {
							s -= C - 1 - x;
							x = C - 1;
						}
					}

					//d가 0이면 1, 1이면 0
					 //d가 2이면 3, 3이면 2
					d ^= 1;

				}

				//이동한 위치에 다른 상어가 있는 경우 크기 비교
				if (temp[ny][nx]) {
					if (a[temp[ny][nx]].z < a[i].z) {
						a[temp[ny][nx]].death = 1;
						temp[ny][nx] = i;
					}
					else a[i].death = 1;
				}
				else temp[ny][nx] = i;

				a[i].y = ny;
				a[i].x = nx;
				a[i].dir = d;
			}
			memcpy(shark, temp, sizeof(temp));
		}

		cout << ret << "\n";
	}
}
#pragma endregion


int main() {
	//My::MySol();
	Sol::Sol_1();
}