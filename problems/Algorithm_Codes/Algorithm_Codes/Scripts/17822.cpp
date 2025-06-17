#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, m, t;
	int x, d, k;
	int tmp;
	vector<vector<int>> disk;

	void RotateDist(int diskNum, int dir, int cnt) {
		if (dir == 1) {
			rotate(disk[diskNum].begin(), disk[diskNum].begin() + cnt, disk[diskNum].end());
		}
		else {
			rotate(disk[diskNum].rbegin(), disk[diskNum].rbegin() + cnt, disk[diskNum].rend());
		}
	}

	bool CheckAdj() {
		vector<pair<int, int>> removeList; //디스크 번호, 디스크 내 숫자 인덱스

		//같은 디스크 내 인접 번호 검사
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (disk[i][j] == 0) continue;

				if (disk[i][j] == disk[i][(j + 1) % m]) {
					removeList.push_back({ i,j });
					removeList.push_back({ i,(j + 1) % m });
				}
			}
		}

		//다른 디스크 간 인접 번호 검사
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (disk[j][i] == 0) continue;

				if (disk[j][i] == disk[j + 1][i]) {
					removeList.push_back({ j,i });
					removeList.push_back({ j + 1,i });
				}
			}
		}

		//같은 수 모두 지우기
		for (auto a : removeList) {
			disk[a.first][a.second] = 0;
		}

		return removeList.size() > 0;
	}
	void UpdateNum() {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (disk[i][j] == 0) continue;

				sum += disk[i][j];
				cnt++;
			}
		}

		if (cnt == 0) return;

		double avg = (double)sum / cnt;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (disk[i][j] == 0) continue;

				if (disk[i][j] > avg)
					disk[i][j] -= 1;
				else if (disk[i][j] < avg)
					disk[i][j] += 1;
			}
		}
	}
	void Print() {
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				cout << disk[i][j] << " ";
			}
			cout << "\n";
		}
	}

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);


		cin >> n >> m >> t;
		for (int i = 0; i < n; i++) {
			vector<int> v(m);

			for (int j = 0; j < m; j++) {
				cin >> v[j];
			}
			disk.push_back(v);
		}

		for (int i = 0; i < t; i++) {
			cin >> x >> d >> k;

			//x의 배수 디스크 회전
			for (int a = x; a <= n; a += x) {
				RotateDist(a - 1, d, k);
			}

			//Print();

			//인접 번호 검사 
			if (!CheckAdj()) {
				//인접한 번호가 없는 경우
				UpdateNum();
			}

			//Print();
		}



		//합 구하기
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (disk[i][j] == 0) continue;
				ret += disk[i][j];
			}
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
	const int dy[] = { -1, 0, 1, 0 };
	const int dx[] = { 0, 1, 0, -1 };


	bool flag = 1;
	void _rotate(int y, int dir, int k) {
		vector<int> v;

		for (int i = 0; i < m; i++)v.push_back(a[y][i]);
		if (dir == 1) rotate(v.begin(), v.begin() + k, v.end());
		else rotate(v.begin(), v.begin() + m - k, v.end());

		for (int i = 0; i < m; i++) a[y][i] = v[i];
	}

	void dfs(int y, int x) {
		//인접 번호 계산
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = (x + dx[i] + m) % m;

			if (ny < 0 || ny >= n) continue;
			if (visited[ny][nx]) continue;

			if (a[y][x] == a[ny][nx]) {
				visited[y][x] = visited[ny][nx] = 1;
				flag = 0;
				dfs(ny, nx);
			}
		}
	}

	bool findAdj() {
		flag = 1;

		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) continue;
				if (visited[i][j]) continue;

				dfs(i, j);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) a[i][j] = 0;
			}
		}
		return flag;
	}

	void setAverage() {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) continue;
				sum += a[i][j];
				cnt++;
			}
		}
		double av = (double)sum / (double)cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) continue;
				if ((double)a[i][j] > av) a[i][j]--;
				else if ((double)a[i][j] < av)a[i][j]++;
			}
		}
		return;
	}

	void Sol() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		cin >> n >> m >> T;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < T; i++) {
			cin >> x >> d >> k;

			for (int j = x - 1; j < n; j += x) {
				_rotate(j, d, k);
			}

			if (findAdj()) setAverage();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret += a[i][j];
			}
		}
		cout << ret << "\n";
	}
}
int main() {

	
}