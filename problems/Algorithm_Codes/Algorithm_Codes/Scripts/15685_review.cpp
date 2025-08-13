#include <bits/stdc++.h>
using namespace std;

namespace My {
	//각 세대의 드래곤커브 방향은, 이전 세대 드래곤커브 각각 반시계 회전 +이전 세대의 드래곤커브 방향

	int n;
	int x, y, d, g;

	int a[101][101];
	struct curve {
		int x, y, d, g;
	}curves[21];

	int dy[] = { 0,-1,0,1 };
	int dx[] = { 1,0,-1,0 };
	int ret;

	void Print() {
		cout << "\n";
		for (int i = 0; i <= 10; i++) {
			for (int j = 0; j <= 10; j++) {
				cout << a[i][j];
			}
			cout << "\n";
		}
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> d >> g;

			curves[i].x = x;
			curves[i].y = y;
			curves[i].d = d;
			curves[i].g = g;
		}



		for (int i = 0; i < n; i++) {

			curve cur = curves[i];
			deque<int> dir;
			pair<int, int> last;




			//0세대
			a[cur.y][cur.x] = 1;
			int ny = cur.y + dy[cur.d];
			int nx = cur.x + dx[cur.d];
			a[ny][nx] = 1;

			if (cur.g == 0) continue;

			//1세대
			int dirIdx = (cur.d + 1) % 4;
			ny = ny + dy[dirIdx];
			nx = nx + dx[dirIdx];

			dir.push_back(dirIdx);
			last = { ny,nx };
			a[ny][nx] = 1;


			for (int j = 2; j <= cur.g; j++) {
				vector<int> tmp;

				for (auto k : dir) {
					dirIdx = (k + 1) % 4;
					tmp.push_back(dirIdx);

				}
				for (auto k : tmp) {

					dir.push_front(k);
				}

				for (auto k : dir) {

					ny = last.first + dy[k];
					nx = last.second + dx[k];

					a[ny][nx] = 1;
					last = { ny,nx };
				}


			}
			//Print();
		}


		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (i + 1 > 100 || j + 1 > 100) continue;
				if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1])
					ret++;
			}
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	//각 세대의 방향 인덱스를 모아보면 규칙을 발견할 수 있다
	//각 세대의 모든 드래곤 커브 방향 인덱스 리스트 = 이전 세대의 드래곤 커브 방향 인덱스 역순에 1 더한 것 + 이전 세대 방향 인덱스 리스트
	//나는 각 세대의 움직임을 화살표로 그려보면서 규칙을 발견했지만, 여기서는 더 나아가 화살표의 인덱스를 보며 규칙을 발견했다.
	//즉 풀이 원리는 동일했으나, 인덱스로 규칙을 찾았기 때문에 로직 작성이 더욱 명확하고 간결해진 것이다
	//앞으로는 로직을 생각할때, '인덱스 베이스'로 접근해보도록 하자..

	const int dy[] = { 0, -1, 0, 1 };
	const int dx[] = { 1, 0, -1, 0 };
	vector<int> dragon[4][11];
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

	//각 세대에서의 커브 시작 방향에 따른 총 방향 인덱스 리스트 생성

	void makeDragon() { 
		for (int i = 0; i < 4; i++) {
			dragon[i][0].push_back(i); //0세대
			dragon[i][1].push_back((i + 1) % 4); //1세대

			//2세대 ~ 10 세대는 이전 세대 방향 인덱스 리스트의 역순에다가 +1 한 것과, 이전 세대 방향 인덱스 리스트를 합친 것임
			for (int j = 2; j <= 10; j++) {
				int n = dragon[i][j - 1].size();
				for (int k = n - 1; k >= 0; k--) {
					dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
				}
				for (int k = 0; k < n; i++) {
					dragon[i][j].push_back(dragon[i][j - 1][k]);
				}
			}
		}
	}
	void sol() {
		cin >> n;
		makeDragon();

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

int main() {
	
}