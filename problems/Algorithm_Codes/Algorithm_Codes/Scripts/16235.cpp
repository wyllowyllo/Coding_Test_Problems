#include <bits/stdc++.h>
using namespace std;

namespace My {

	int n, m, k;
	int a[11][11];
	int nutrition[11][11];

	int x, y, z;


	struct tree {
		int y, x, age;
	};

	vector<tree> v;

	void reproduction(int y, int x) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {

				if (i == 0 && j == 0) continue;

				int ny = y + i;
				int nx = x + j;

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

				v.push_back({ ny,nx,1 });
			}
		}
	}


	void sol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n >> m >> k;

		fill(&a[0][0], &a[0][0] + 11 * 11, 5);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> nutrition[i][j];
			}
		}

		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			v.push_back({ x - 1,y - 1,z });
		}


		for (int i = 0; i < k; i++) {
			//봄
			sort(v.begin(), v.end(), [](tree a, tree b) {
				return a.age < b.age;
			});

			vector<tree> live, dead;
			for (int i = 0; i < v.size(); i++) {

				if (a[v[i].y][v[i].x] >= v[i].age) {
					a[v[i].y][v[i].x] -= v[i].age;
					v[i].age++;
					live.push_back(v[i]);
				}
				else dead.push_back(v[i]);

			}

			v.clear();
			v = live;

			//여름
			for (int i = 0; i < dead.size(); i++) {
				int amount = dead[i].age / 2;
				a[dead[i].y][dead[i].x] += amount;
			}

			//가을
			for (int i = 0; i < v.size(); i++) {
				if (v[i].age % 5 == 0) {
					reproduction(v[i].y, v[i].x);
				}
			}

			//겨울
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] += nutrition[i][j];
				}
			}
		}

		int ret = 0;
		for (auto i : v) {
			ret++;
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	int n, m, k, A[14][14], yangbun[14][14], ret;
	vector<int> a[14][14];
	const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	void sprintSummer() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j].size() == 0) continue;

				int die_tree = 0;
				vector<int> temp;

				sort(a[i][j].begin(), a[i][j].end());

				for (int tree : a[i][j]) {
					if (yangbun[i][j] >= tree) {
						yangbun[i][j] -= tree;
						temp.push_back(tree + 1);
					}
					else die_tree += tree / 2;
				}
				a[i][j] = temp;
				yangbun[i][j] += die_tree;
			}
		}
	}
	void fall() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j].size() == 0) continue;
				for (int tree : a[i][j]) {
					if (tree % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							int ny = i + dy[d];
							int nx = j + dx[d];
							if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
							a[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
	void winter() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				yangbun[i][j] += A[i][j];
			}
		}
	}

	void sol() {
		cin >> n >> m >> k;
		fill(&yangbun[0][0], &yangbun[0][0] + 14 * 14, 5);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> A[i][j];
			}
		}

		for (int i = 0; i < m; i++) {
			int x, y, z; 
			cin >> x >> y >> z; 
			x--; y--;

			a[x][y].push_back(z);
		}

		for (int i = 0; i < k; i++) {
			sprintSummer();
			fall();
			winter();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret += a[i][j].size();
			}
		}

		cout << ret << "\n";
	}
}
int main() {
	
}