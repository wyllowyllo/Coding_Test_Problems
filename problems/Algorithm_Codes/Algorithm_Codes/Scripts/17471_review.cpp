#include <bits/stdc++.h>
using namespace std;

int n;
int p[11]; //선거구 구분위해 색칠하기
int a, b;

vector<int> adj[11];

int area[11];

int visited[11];
const int INF = 987654321;
int ret = INF;

void cal(vector<int> &v1, vector<int> &v2) {
	int cnt_1=0, cnt_2=0;
	for (int i : v1) {
		cnt_1 += p[i];
	}
	for (int i : v2) {
		cnt_2 += p[i];
	}

	ret = min(ret, abs(cnt_1 - cnt_2));

}
int go(int idx, int num) {
	int cnt = 1;
	visited[idx] = 1;

	for (int i : adj[idx]) {
		if (area[i] != num) continue;
		if (visited[i]) continue;


		cnt += go(i, num);
	}


	return cnt;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <=n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;

			adj[i].push_back(b);
		}
	}


	//n개의 조합 중 r개 고르는 모든 경우의 수
	for (int i = 0; i < (1 << n); i++) {
		memset(area, 0, sizeof(area));
		vector<int> area_1, area_2;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				area[j+1] = 1; //1번 선거구
				area_1.push_back(j + 1);

			} 
			else { area[j+1] = 2; area_2.push_back(j + 1); } //2번 선거구
		}

		//선거구 형성 이대로 가능한지 검사(연결되어있는가?)

		if (area_1.empty() || area_2.empty()) continue;

		memset(visited, 0, sizeof(visited));
		if (area_1.size() != go(area_1[0],1)) continue;

		memset(visited, 0, sizeof(visited));
		if (area_2.size() != go(area_2[0],2)) continue;

		//인구 차이 계산
		cal(area_1, area_2);
	}

	if (ret == INF) cout << -1 << "\n";
	else cout << ret << "\n";

}