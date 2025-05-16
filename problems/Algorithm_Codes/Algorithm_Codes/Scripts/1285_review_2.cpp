#include <bits/stdc++.h>
using namespace std;

int n;
char _a[21][21];

string s;
int ret = 500;


void flipRow(vector<int> v) {
	for (auto i : v) {
		for (int j = 0; j < n; j++) {
			_a[i][j] = (_a[i][j] == 'H' ? 'T' : 'H');
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < n; j++) {
			_a[i][j] = s[j];
		}
	}

	//(n개의 행 중 뒤집을 행 선택)
	for (int i = 0; i < (1<<n); i++) {
		vector<int> v1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				v1.push_back(j);
			}
		}

		//행 뒤집기
		flipRow(v1);

		int result = 0;
		
		//열은 직접 뒤집기 x -> 뒷면의 개수가 최소가 되도록 뒤집을지,말지 결정한 다음 개수만 카운트
		for (int a = 0; a < n; a++) {
			int cnt = 0; //뒷면 개수
			for (int b = 0; b < n; b++) {
				if (_a[b][a] == 'T') cnt++;
			}

			result += min(cnt, n - cnt);
		}

		ret = min(ret, result);

		//행 복구
		flipRow(v1);
	}

	cout << ret << "\n";
}