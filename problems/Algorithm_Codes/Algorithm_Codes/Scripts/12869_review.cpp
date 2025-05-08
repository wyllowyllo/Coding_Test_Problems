#include <bits/stdc++.h>
using namespace std;


int n;
int h[61][61][61]; //매 공격 후 남아있는 scv의 체력이 인덱스가됨

int scv[3];

vector<vector<int>> atkPattern;

void go(int a, int b, int c) {
	
	h[a][b][c] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ a,b,c });

	while (q.size()) {
		tie(a, b, c) = q.front(); q.pop();
		for (int i = 0; i < atkPattern.size(); i++) {
			int na= ((a -atkPattern[i][0])<0?0: (a - atkPattern[i][0]));
			int nb = ((b - atkPattern[i][1]) < 0 ? 0 : (b - atkPattern[i][1]));
			int nc = ((c - atkPattern[i][2]) < 0 ? 0 : (c - atkPattern[i][2]));

			if (na == 0 && nb == 0 && nc == 0) {
				cout << h[a][b][c];
				return;
			}

			if (h[na][nb][nc]) continue;

			h[na][nb][nc] = h[a][b][c]+1;
			q.push({ na,nb,nc });
		}
	}

	


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
		
	}
		
	vector<int> pattern;
	pattern.push_back(1);
	pattern.push_back(3);
	pattern.push_back(9);
	
	do {
		atkPattern.push_back(pattern);
	} while (next_permutation(pattern.begin(), pattern.end()));

	go(scv[0], scv[1], scv[2]);
	
}