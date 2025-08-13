#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int x, d, k;


void Print(vector<vector<int>> & disk) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << disk[i][j] << " ";
		}
		cout << "\n";
	}
}
bool check(vector<vector<int>>& disk) {
	vector<pair<int, int>> list;

	//같은 원판 상의 인접 번호 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (disk[i][j] == 0) continue;

			if (disk[i][j] == disk[i][(j + 1) % m] || disk[i][j] == disk[i][(j>0?j-1:m-1)])
				list.push_back({ i,j });

		}
	}

	//다른 원판 상의 인접 번호 체크
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (disk[j][i] == 0) continue;

			if (j < n-1 && disk[j][i] == disk[j+1][i])
				list.push_back({ j,i });
			else if (j > 0 && disk[j][i] == disk[j - 1][i])
				list.push_back({ j,i });
		}
	}

	//지우기
	for (auto p : list) {
		disk[p.first][p.second] = 0;
	}

	return list.size() > 0;
}
void cal(vector<vector<int>>& disk) {
	//평균 구하기
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (disk[i][j]) {
				sum += disk[i][j];
				cnt++;
			}
		}
	}

	double avg = (double)sum / cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (disk[i][j]) {
				
				if (disk[i][j] > avg) disk[i][j] -= 1;
				else if (disk[i][j] < avg) disk[i][j] += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> t;
	vector<vector<int>> disk(n, (vector<int>(m, 0)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> disk[i][j];
		}
	}

	while (t--) {
		cin >> x >> d >> k;
		
		for (int j = x-1; j < n; j += x) {
			if (d) rotate(disk[j].begin(), disk[j].begin()+k, disk[j].end());
			else rotate(disk[j].rbegin(), disk[j].rbegin() + k, disk[j].rend());
		}
		//Print(disk);
		if (!check(disk)) {
			cal(disk);
		}
		//Print(disk);
	}

	//합 구하기
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (disk[i][j]) {

				ret += disk[i][j];
			}
		}
	}

	cout << ret << "\n";

}