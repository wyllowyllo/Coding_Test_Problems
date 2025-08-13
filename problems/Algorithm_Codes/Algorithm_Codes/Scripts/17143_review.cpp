#include <bits/stdc++.h>
using namespace std;


int R, C, m;

int r, c, s, d, z;

struct Shark {
	int r, c, s, d, z;
	bool dead = false;

}sharks[100001];

vector<int> a[104][104];


int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
int ret = 0;

void move(int idx) {

	Shark tmp = sharks[idx];
	pair<int, int> prev = { tmp.r, tmp.c };

	if (tmp.d < 2) { //위아래 이동
		int cnt = tmp.s % ((R-1)*2);
	

		int cur = tmp.r;
		for (int i = 0; i < cnt; i++) {
			int ny = cur + dy[tmp.d];

			if (ny < 0 || ny >= R) {
				tmp.d ^= 1;
				i--;
				continue;
			}
			cur = ny;
		}

		tmp.r = cur;
	}
	else {//양옆 이동
		int cnt = tmp.s % ((C-1)*2);
		
		int cur = tmp.c;
		for (int i = 0; i < cnt; i++) {
			int nx = cur + dx[tmp.d];

			if (nx < 0 || nx >= C) {
				tmp.d ^= 1;
				i--;
				continue;
			}
			cur = nx;
		}

		tmp.c = cur;

	}

	sharks[idx] = tmp;

	////이전 맵 위치에서 제거
	auto p = find(a[prev.first][prev.second].begin(), a[prev.first][prev.second].end(),idx);
	a[prev.first][prev.second].erase(p);

	//새 위치로 맵 업데이트
	a[tmp.r][tmp.c].push_back(idx);
}
bool cmp(int a, int b) {
	return sharks[a].z > sharks[b].z;
}
void Fight() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (a[i][j].size() > 1) {
				sort(a[i][j].begin(), a[i][j].end(), cmp);

				while (a[i][j].size() > 1) {
					sharks[a[i][j].back()].dead = true;
					a[i][j].pop_back();
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> R >> C >> m;

	for (int i = 0; i < m; i++) {
		cin >> r >> c >> s >> d >> z;

		r--;
		c--;
		d--;

		sharks[i].r = r;
		sharks[i].c = c;
		sharks[i].s = s;
		sharks[i].d = d;
		sharks[i].z = z;

		a[r][c].push_back(i);
	}

	for (int i = 0; i < C; i++) {

		//i번째 열에 있는 상어 중 가장 가까운 상어를 잡는다.
		for (int j = 0; j < R; j++) {
			if (a[j][i].size()) {
				int idx = a[j][i].front();
				a[j][i].pop_back();

				sharks[idx].dead = true;
				ret += sharks[idx].z;


				break;
			}
		}

		//상어 이동
		for (int k = 0; k < m; k++) {
			if (sharks[k].dead) continue;

			move(k);
		}

		//잡아먹기
		Fight();

	}

	cout << ret << "\n";
}