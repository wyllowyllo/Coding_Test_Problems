#include <bits/stdc++.h>
#define MAX 100
using namespace std;


//-----------------------------------------My Solution -----------------------------------------------//
//int m, n, k;
//int cnt = 0;
//int inputM[MAX][MAX];
//int visited[MAX][MAX];
//int width[MAX];
//
//const pair<int, int> dir[4] = { {-1,0},{0,1},{1,0} ,{0,-1} };
//
//void DFS(int y, int x,const int cnt) {
//
//	visited[y][x] = 1;
//	width[cnt]++;
//	for (int i = 0; i < 4; i++) {
//		int ny = y + dir[i].first;
//		int nx = x + dir[i].second;
//
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//		if (inputM[ny][nx] == 1 || visited[ny][nx]) continue;
//		DFS(ny, nx,cnt);
//	}
//}
//
//void SetRec(pair<int,int> leftB, pair<int,int> rightT) {
//
//	for (int i = leftB.second; i < rightT.second; i++) {
//		for (int j = leftB.first; j < rightT.first; j++) {
//			inputM[i][j] = 1;
//		}
//	}
//}
//int main() {
//	cin >> m >> n >> k;
//
//	pair<int, int>leftB, rightT;
//	for (int i = 0; i < k; i++) {
//		cin >> leftB.first >> leftB.second; //x,y��
//		cin >> rightT.first >> rightT.second;
//
//		SetRec(leftB, rightT);
//	}
//
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (inputM[i][j] == 0 && !visited[i][j]) {
//				DFS(i, j, cnt);
//				cnt++;
//			}
//		}
//	}
//
//	sort(&width[0], &width[cnt]);
//	cout << cnt << "\n";
//	for (int i = 0; i < cnt; i++) cout << width[i] << " ";
//
//}

//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------Solution 1 -------------------------------------------------------
// �� ��ȯ�� �ϴ� ������ recursion���� �����ϱ�

#define y1 aaaa //bits/stdc++.h ���̺귯�� �ȿ� �̹� y1������ ���ǵǾ� ���� ->��ȣ�� ���� ���� define���
int a[MAX][MAX], m, n, k, x1, x2, y1, y2, visited[MAX][MAX];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
vector<int> ret;

//dfs�� ���ȣ���Ű��, ret�� ������Ŵ. main���� ȣ���� dfs(ù ȣ��)�� return���� ���ȣ��� ������ ret�� ���� ���� ��
int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[ny][nx]) continue;
		if (a[ny][nx] == 1) continue;
		ret += dfs(ny, nx);
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				a[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1 && visited[i][j] == 0) {
				ret.push_back(dfs(i, j));
			}
		}
	}
	
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int i : ret) cout << i << " ";
}