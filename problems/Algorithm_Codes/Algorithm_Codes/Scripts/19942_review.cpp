#include <bits/stdc++.h>
using namespace std;


int n;
int mp, mf,ms, mv;

int a[5][20];
//const int INF = 600 * 15;
//int result = INF;

vector<pair<int,vector<int>>> ret;

void check(int v) {
	int mpSum=0, mfSum=0, msSum=0, mvSum = 0;
	int cost = 0;

	for (int i = 0; i < n; i++) {
		if (v & (1 << i)) {
			mpSum += a[0][i];
			mfSum += a[1][i];
			msSum += a[2][i];
			mvSum += a[3][i];
			cost += a[4][i];
		}
	}

	if (mpSum < mp || mfSum < mf || msSum < ms || mvSum < mv) return;

	
	vector<int> t;
	for (int i = 0; i < n; i++) {
		if (v & (1 << i))
			t.push_back(i + 1);
	}
	ret.push_back({ cost, t });
}
int main() {
	cin >> n;

	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 5; j++) {
			cin>>a[j][i];
		}
	}

	//최소 영양성분 만족하는 조합 구하기 (nCr)
	for (int i = 0; i < (1 << n); i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				s |= (1 << j); //조합 생성
			}
		}

		check(s); //조건 만족한다면 가격비교
	}

	if (ret.empty()) cout << -1 << "\n";
	else {
		sort(ret.begin(), ret.end());
		sort(ret.front().second.begin(), ret.front().second.end());

		cout << ret.front().first << "\n";
		for (auto i : ret.front().second)
			cout << i << " ";

	}
}