#include <bits/stdc++.h>
using namespace std;

int m[100][100];
int visited[100][100];
pair<int, int> dir[4] = { {-1,0},{0,1} ,{1,0} ,{0,-1} };
int w, h;
int t = 0;
int remainCheese=0; //���� ��� 1�ð��� ġ�� ���� ����
vector<pair<int, int>> emptyPos;

void DFS(int y, int x, vector<pair<int,int>>* v,bool* isAir) {

	visited[y][x] = 1;
	v->push_back({ y,x });

	//�� connected graph�� �ٱ�(�� �׵θ�)�� �´���ִ��� üũ
	if (!(*isAir) && (y == 0 || y == h - 1 || x == 0 || x == w - 1)) *isAir = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (m[ny][nx] != 0 || visited[ny][nx]) continue;
		DFS(ny, nx, v,isAir);
	}
}

void removeCheese(int y,int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (m[ny][nx] == 1) {
			m[ny][nx] = 0;
			emptyPos.push_back({ ny,nx });
		}
			
	}
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) emptyPos.push_back({ i,j });
			
		}
	}

	while (1) {
		if (emptyPos.size() == h * w) break;

		fill(&visited[0][0], &visited[0][0] + (100 * 100), 0);

		remainCheese = (w * h) - emptyPos.size();

		//0�� ���� conneted graph ã��, ���� �� 0�� connected graph�� �ٱ��� �´�� �ְ� c�� �´�� ���� �� �� �´���ִ� c�� ����
		vector<pair<int, int>> connectedGraph[10000];
		bool isGraphOutside[10000];
		int cnt = 0;
		for (auto pos : emptyPos) {
			bool isAir = false;
			if (!visited[pos.first][pos.second]) {
				DFS(pos.first, pos.second, &connectedGraph[cnt],&isAir);
				isGraphOutside[cnt]=isAir;
				cnt++;
			}
				
		}

		for (int i = 0; i < cnt; i++) {
			//0�� connected graph�� �ܺο� �´���ִ� ���, �ش� connected graph�� ������ ġ� ����
			if (isGraphOutside[i]) {
				for (auto node : connectedGraph[i])
					removeCheese(node.first, node.second);
			}
		}

		t++; //�� ���� ������ �ɸ��� �ð� ���
	}

	cout << t << "\n";
	cout << remainCheese << "\n";
}