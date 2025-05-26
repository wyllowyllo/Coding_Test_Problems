#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

int n;
int temp;
int ret;

void Rotate(vector<vector<int>>& v) {
	vector<vector<int>> tmp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = v[n - j - 1][i];
		}
	}

	v = tmp;
}

void Merge(vector<vector<int>>& v) {
	vector<int> line;

	for (int i = 0; i < n; i++) {
		line.clear();

		for (int j = 0; j < n; j++) {
			if (v[i][j])
				line.push_back(v[i][j]);
		}

		vector<int> new_line;
		for (int i = 0; i < line.size(); i++) {
			if (i < line.size() - 1 && line[i] == line[i + 1]) {
				new_line.push_back(line[i] * 2);
				i++;
			}
			else new_line.push_back(line[i]);
		}
		new_line.resize(n, 0);
		v[i] = new_line;
	}
}

void Check(vector<vector<int>> v) {
	//cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << v[i][j] << " ";
			ret = max(ret, v[i][j]);
		}
		//cout << "\n";
	}


}

void Move(int cnt, vector<vector<int>> v) {
	if (cnt == 5) {
		Check(v);
		return;
	}



	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temp = v;
		//0도,90도,180도,270도 회전
		for (int j = 0; j < i; j++) {
			Rotate(temp);
		}
		Merge(temp);
		Move(cnt + 1, temp);
	}
}

void MySol() {
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	Move(0, v);
	cout << ret << "\n";
}

#pragma endregion

#pragma region Sol_1

struct Board {
	int a[24][24];

	void _rotate90() {
		int temp[24][24];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[n - j - 1][i];
			}
		}

		memcpy(a, temp, sizeof(a));
	}
	void _move() {
		int temp[24][24];

		for (int i = 0; i < n; i++) {
			int c = -1, d = 0; //temp에 들어가있는 수가 있느냐

			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;
				if (d && a[i][j] == temp[i][c]) temp[i][c] *= 2, d = 0;

				else temp[i][++c] = a[i][j], d = 1;

			}

			for (c++; c < n; c++) temp[i][c] = 0; //나머지 0으로 채움
		}

		memcpy(a, temp, sizeof(a));
	}
	void get_max() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, a[i][j]);
			}
		}
	}

};

void go(Board c, int here) {
	if (here == 5) {
		c.get_max();
		return;
	}

	for (int i = 0; i < 4; i++) {
		Board d = c;
		d._move();
		go(d, here + 1);
		c._rotate90();
	}
}

void Sol_1() {
	cin >> n;
	Board c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c.a[i][j];
		}
	}

	go(c, 0);
	cout << ret << "\n";
}
#pragma endregion



int main() {
	
}