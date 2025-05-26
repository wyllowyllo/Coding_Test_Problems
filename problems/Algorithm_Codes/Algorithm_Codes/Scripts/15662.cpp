#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

namespace My {
	int t, k;
	string s;

	int n, dir;
	vector<pair<int, int>> rot;
	vector<vector<int>> v;
	int ret;

	void Print() {
		cout << "\n";
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 8; j++)
				cout << v[i][j];
			cout << "\n";
		}
	}
	void RotateWheel(int WheelNum, int dir) {
		if (dir == -1)
			rotate(v[WheelNum].begin(), v[WheelNum].begin() + 1, v[WheelNum].end());
		else
			rotate(v[WheelNum].rbegin(), v[WheelNum].rbegin() + 1, v[WheelNum].rend());
	}
	void WheelCheck(int startWheel, int dir) {
		int leftEdge, rightEdge;



		int ldir = dir;

		leftEdge = v[startWheel][6];
		rightEdge = v[startWheel][2];


		//startWheel의 왼쪽에 있는 바퀴들 검사&회전
		for (int i = startWheel - 1; i >= 0; i--) {
			if (v[i][2] == leftEdge) break;

			leftEdge = v[i][6];
			rightEdge = v[i][2];
			ldir = -ldir;
			RotateWheel(i, ldir);
		}

		int rdir = dir;
		leftEdge = v[startWheel][6];
		rightEdge = v[startWheel][2];

		//startWheel의 오른쪽에 있는 바퀴들 검사&회전
		for (int i = startWheel + 1; i < t; i++) {
			if (v[i][6] == rightEdge) break;

			leftEdge = v[i][6];
			rightEdge = v[i][2];
			rdir = -rdir;
			RotateWheel(i, rdir);
		}

		//startWheel 돌리기
		RotateWheel(startWheel, dir);
	}



	void MySol() {
		cin >> t;


		for (int i = 0; i < t; i++) {
			vector<int> tmp;
			cin >> s;
			for (int j = 0; j < s.size(); j++) {
				tmp.push_back(s[j] - '0');
			}
			v.push_back(tmp);
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> n >> dir;
			rot.push_back({ n,dir });
		}

		for (auto i : rot) {
			WheelCheck(i.first - 1, i.second);
		}

		//Print();
		for (int i = 0; i < t; i++) {
			if (v[i][0]) ret++;
		}
		cout << ret << "\n";
	}
}
#pragma endregion


#pragma region Sol_1

namespace Sol_1 {
	typedef long long ll;
	int n, k, a, b, ret;
	string s[1004];

	void rot(int pos, int dir) {
		if (!dir) rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
		else rotate(s[pos].begin(), s[pos].begin() + s[pos].size() - 1, s[pos].end());
	}

	int findL(int pos) {
		for (int i = pos; i >= 1; i--) {
			if (s[i][6] == s[i - 1][2]) {
				return i;
			}
		}

		return 0;
	}

	int findR(int pos) {
		for (int i = pos; i <= n - 2; i++) {
			if (s[i][2] == s[i + 1][6]) {
				return i;
			}
		}

		return n - 1;
	}

	void Sol_1() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b; a--;
			b = (b == -1 ? 0 : 1);

			int l = findL(a);
			int r = findR(a);
			int cnt = 0;

			for (int pos = a; pos >= l; pos--) {
				rot(pos, cnt % 2 == 0 ? b : !b);
				cnt++;
			}

			cnt = 1;
			for (int pos = a + 1; pos <= r; pos++) {
				rot(pos, cnt % 2 == 0 ? b : !b);
				cnt++;
			}

		}

		for (int i = 0; i < n; i++)if (s[i][0] == '1')ret++;
		cout << ret << "\n";
	}
}

#pragma endregion

#pragma region Sol_2

//비트마스킹 활용한 풀이
namespace Sol_2 {

	int n, K, gear[1004], temp, num, dir, ret;

	void roll(int num, bool dir) {
		int bit_trim = (1 << 8) - 1;

		if (dir) {
			bool tmp = gear[num] & 1;
			gear[num] >>= 1; //오른쪽으로 한칸씩 shift
			if (tmp) gear[num] |= (1 << 7); //맨 뒤의 값이 1이었다면 그것을 맨 앞으로
		}
		else {
			bool tmp = gear[num] & (1 << 7);
			gear[num] <<= 1;
			if (tmp) gear[num] |= 1;
		}

		gear[num] &= bit_trim; //혹시나 shift시 8비트 자리 넘어간 값이 있다면 그 값들 없앰. 즉 하위 8비트만 남김 
	}

	int findL(int pos) {
		for (int i = pos; i >= 1; i--) {
			bool a = gear[i] & (1 << 1);
			bool b = gear[i - 1] & (1 << 5);

			if (a == b)
				return i;
		}

		return 0;
	}
	int findR(int pos) {
		for (int i = pos; i <= n - 2; i++) {
			bool a = gear[i] & (1 << 5);
			bool b = gear[i + 1] & (1 << 1);

			if (a == b)
				return i;
		}

		return n - 1;
	}
	void solve(int num, bool dir) {
		bool temp_dir = dir;
		int left = findL(num);
		int right = findR(num);

		for (int i = num; i >= left; i--) {
			roll(i, dir), dir = !dir;
		}

		dir = !temp_dir;
		for (int i = num+1; i <= right; i++) {
			roll(i, dir), dir = !dir;
		}
	}
	void Sol_2() {
		scanf("%d", &n); 
		
		for (int i = 0; i < n; i++) {
			for (int j = 7; j >= 0; j--) {
				scanf("%1d", &temp); //숫자 1개만 입력받기
				if (temp) gear[i] |= (1 << j);
			}
		}

		scanf("%d", &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &num, &dir);
			num--;
			solve(num, dir == 1);
		}

		for (int i = 0; i < n; i++) {
			if (gear[i] & (1 << 7)) ret++;
		}
		printf("%d\n", ret);
	}
}

#pragma endregion


int main() {
	Sol_2::Sol_2();
}
