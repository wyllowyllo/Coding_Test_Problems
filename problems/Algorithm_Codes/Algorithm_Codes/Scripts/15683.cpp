#include <bits/stdc++.h>
using namespace std;

namespace My {
	int n, m;
	int a[10][10];
	int tmp[10][10];


	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	vector<pair<int, int>> cams;

	int ret = 987654321;

	void Stare(vector<pair<int, int>> dir, int idx) {

		for (auto d : dir) {
			int sx = cams[idx].second;
			int sy = cams[idx].first;


			while (true) {
				sx += d.first; sy += d.second;

				if (sx < 0 || sx >= m || sy < 0 || sy >= n || a[sy][sx] == 6) break;
				if (a[sy][sx] > 0) continue;

				a[sy][sx] = -1;
			}
		}
	}
	void RotateCam(int rot, int idx) {
		vector<pair<int, int>> dir;
		if (a[cams[idx].first][cams[idx].second] == 1) {
			int dirIdx = 0;
			dirIdx = (dirIdx + rot) % 4;
			dir.push_back({ dx[dirIdx], dy[dirIdx] });
		}
		else if (a[cams[idx].first][cams[idx].second] == 2) {
			int dirIdx_1 = 0; int dirIdx_2 = 2;
			dirIdx_1 = (dirIdx_1 + rot) % 4;
			dirIdx_2 = (dirIdx_2 + rot) % 4;


			dir.push_back({ dx[dirIdx_1], dy[dirIdx_1] });
			dir.push_back({ dx[dirIdx_2], dy[dirIdx_2] });
		}
		else if (a[cams[idx].first][cams[idx].second] == 3) {
			int dirIdx_1 = 3; int dirIdx_2 = 0;
			dirIdx_1 = (dirIdx_1 + rot) % 4;
			dirIdx_2 = (dirIdx_2 + rot) % 4;


			dir.push_back({ dx[dirIdx_1], dy[dirIdx_1] });
			dir.push_back({ dx[dirIdx_2], dy[dirIdx_2] });
		}
		else if (a[cams[idx].first][cams[idx].second] == 4) {
			int dirIdx_1 = 3; int dirIdx_2 = 0; int dirIdx_3 = 2;
			dirIdx_1 = (dirIdx_1 + rot) % 4;
			dirIdx_2 = (dirIdx_2 + rot) % 4;
			dirIdx_3 = (dirIdx_3 + rot) % 4;


			dir.push_back({ dx[dirIdx_1], dy[dirIdx_1] });
			dir.push_back({ dx[dirIdx_2], dy[dirIdx_2] });
			dir.push_back({ dx[dirIdx_3], dy[dirIdx_3] });
		}
		else {
			for (int i = 0; i < 4; i++)
				dir.push_back({ dx[i], dy[i] });
		}

		Stare(dir, idx);
	}

	void Calculate() {
		int size = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0)
					size += 1;
			}
		}

		ret = min(ret, size);
	}
	void Print() {
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	void OperateCams(vector<int> rot) {
		if (rot.size() == cams.size()) {

			memset(tmp, sizeof(tmp), 0);

			//현재 맵 저장
			memcpy(tmp, a, sizeof(a));

			//카메라 감시지대 생성
			for (int i = 0; i < rot.size(); i++) {
				RotateCam(rot[i], i); //회전 각도, 카메라 번호
			}

			//사각지대 계산
			Calculate();
			//Print();

			//복구
			memcpy(a, tmp, sizeof(tmp));
			return;
		}

		for (int i = 0; i < 4; i++) {
			rot.push_back(i);
			OperateCams(rot);
			rot.pop_back();
		}
	}

	void MySol() {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] >= 1 && a[i][j] <= 5)
					cams.push_back({ i,j });
			}
		}

		vector<int> v;
		OperateCams(v);

		cout << ret << "\n";
	}
}



int main() {
	



}