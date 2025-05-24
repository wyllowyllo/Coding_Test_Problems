#include <bits/stdc++.h>
using namespace std;


#pragma region MySol

namespace MySol {
	int r, c, t;
	int a[51][51];
	int spreadDust[51][51]; //매 시간 확산하는 먼지의 양

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	int y, x;
	queue<pair<int, int>> q;
	vector<pair<int, int>> airCleaner;

	queue<pair<int, int>> FindDust() {
		queue<pair<int, int>> temp;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0) temp.push({ i,j });
			}
		}

		return temp;
	}

	void Spread() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (spreadDust[i][j] > 0) {
					a[i][j] += spreadDust[i][j];
				}
			}
		}
	}

	void AirClean() {
		//위쪽 순환(반시계)
		int y = airCleaner[0].first;
		int x = airCleaner[0].second;


		a[y - 1][x] = 0; //먼지 흡수

		for (int k = y - 2; k >= 0; k--) {
			a[k + 1][x] = a[k][x];
		}
		for (int k = x + 1; k < c; k++) {
			a[0][k - 1] = a[0][k];
		}
		for (int k = 1; k <= y; k++) {
			a[k - 1][c - 1] = a[k][c - 1];
		}
		for (int k = c - 2; k >= 1; k--) {
			a[y][k + 1] = a[y][k];
		}
		a[y][1] = 0;


		//아래쪽 순환(시계)
		y = airCleaner[1].first;
		x = airCleaner[1].second;


		a[y + 1][x] = 0; //먼지 흡수

		for (int k = y + 2; k < r; k++) {
			a[k - 1][x] = a[k][x];
		}
		for (int k = 1; k < c; k++) {
			a[r - 1][k - 1] = a[r - 1][k];
		}
		for (int k = r - 2; k >= y; k--) {
			a[k + 1][c - 1] = a[k][c - 1];
		}
		for (int k = c - 2; k >= 1; k--) {
			a[y][k + 1] = a[y][k];
		}
		a[y][1] = 0;
	}

	void Print() {
		cout << "\n";

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);


		cin >> r >> c >> t;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];

				if (a[i][j] > 0) q.push({ i,j });

				else if (a[i][j] == -1) {
					airCleaner.push_back({ i,j });
				}
			}
		}

		while (t--) {

			memset(spreadDust, 0, sizeof(spreadDust));

			//미세먼지 확산
			while (q.size()) {
				tie(y, x) = q.front(); q.pop();

				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
					if (a[ny][nx] == -1) continue;

					spreadDust[ny][nx] += a[y][x] / 5;

					cnt++;

				}

				a[y][x] -= (a[y][x] / 5) * cnt;
			}
			Spread();


			//Print();

			//공기청정기 작동
			AirClean();

			//남은 먼지 탐색
			queue<pair<int, int>> temp = FindDust();
			q = temp;

			//Print();

		}

		//합계
		int sum = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0) sum += a[i][j];

			}
		}
		cout << sum << "\n";
	}
}
#pragma endregion


#pragma region Sol_1
//여기서는 바람이 통하는 구간을 따로 구해놓고 시작함 (나는 매번 반복문으로 구간탐색하는 방식)
//바람이 통하는 구간을 모아놓고, 이를 한칸씩 미는 방식으로 먼지가 한칸씩 밀리는 것을 간략하게 구현함

namespace Sol_1 {
	int a[54][54], n, m, t, ret, temp[54][54];
	vector<pair<int, int>> v1, v2;


	int dy1[] = { 0,-1,0,1 };
	int dx1[] = { 1,0,-1,0 };
	int dy2[] = { 0,1,0,-1 };
	int dx2[] = { 1,0,-1,0 };

	void mise_go(int dy[], int dx[]) {
		fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);

		queue<pair<int, int>> q;

		//먼지 찾기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != -1 && a[i][j]) {
					q.push({ i,j });
				}
			}
		}

		while (q.size()) {
			int y, x;
			tie(y, x) = q.front(); q.pop();

			int spread = a[y][x] / 5;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue;
				temp[ny][nx] += spread;
				a[y][x] -= spread;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] += temp[i][j];
			}
		}

	}

	vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]) {
		vector<pair<int, int>> v;

		int cnt = 0;

		//시작위치
		int y = sy;
		int x = sx;

		while (true) {
			int ny = y + dy[cnt];
			int nx = x + dx[cnt];

			if (ny == sy && nx == sx) break; //시작위치로 다시 돌아오면 종료

			//범위 벗어나면 방향 바꿈
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				cnt++;
				ny = y + dy[cnt];
				nx = x + dx[cnt];
			}
			if (ny == sy && nx == sx) break; //시작위치로 다시 돌아오면 종료

			y = ny; x = nx;
			v.push_back({ ny,nx });
		}



		return v;
	}

	void go(vector<pair<int, int>> &v) {
		for (int i = v.size() - 1; i > 0; i--) {
			//한칸씩 밀어내기
			a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
		}

		a[v[0].first][v[0].second] = 0;
	}
	void Sol_1() {
		cin >> n >> m >> t;
		bool flag = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == -1) {
					if (flag) {
						v1 = chung(i, j, dy1, dx1); //공기청정기 위쪽 바람통하는 구역 구하기
						flag = false;
					}
					else v2 = chung(i, j, dy2, dx2); //공기청정기 아래쪽 바람통하는 구역 구하기
				}
				
			}
		}

		while (t--) {
			mise_go(dy1, dx1); //확산
			go(v1); //밀어내기
			go(v2); //밀어내기
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != -1)ret += a[i][j];
			}
		}

		cout << ret << "\n";
	}
}


#pragma endregion



int main() {

	Sol_1::Sol_1();

}