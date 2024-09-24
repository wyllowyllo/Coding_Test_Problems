#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;

int N, M;
int m[max_n][max_n];
int visited[max_n][max_n];

//------------------------------My Solution -----------------------------------//
//������ �����ؼ� ó���� DFS�� ����Ͽ� Ǯ���� �õ��� -> �׷��� �� ������ ��� �� 1���� ã�� ���� �ƴ϶�, ������ ��� �� �ּҰ�θ� ã�� ��
//�ش� ������ ������ ����ġ�� �����ϹǷ�, BFS�� ����ؾ� ��! 
int ret = 1000000;
pair<int, int> dir[4] = { {-1,0},{0,1},{1,0} ,{0,-1} };

void BFS(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY,startX });
	visited[startY][startX] = 1;

	int y, x;
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();

		if (y == N && x == M) {
			if (ret > visited[y][x]) ret = visited[y][x];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i].first;
			int nx = x + dir[i].second;

			if (nx<1 || nx>M || ny<1 || ny>N) continue;
			if (visited[ny][nx] || !m[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main() {
	cin >> N >> M;
	cin.ignore(); //�Է¹��� ����

	for (int i = 1; i <= N; i++) {
		string input;
		getline(cin, input);
		for (int j = 1; j <=M; j++) {
				m[i][j]=input[j-1]-'0';
		}
	}
	
	BFS(1, 1);
	cout << ret << "\n";

//-------------------------------------------------------------------------//

//---------------------Soluiton 1-------------------------------------------
	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, 1, 0, -1 };
	int Y, X;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &m[i][j]); //�Է��� ���ڵ��� �پ �־����� ���, �� ������� �Է¹��� �� �ִ�!(%1d == ���ڸ��� int���� �ްڴ�)
		}
	}

	queue<pair<int, int>> q2;
	visited[0][0] = 1;
	q2.push({ 0,0 });
	while (q2.size()) {
		tie(Y, X) = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int ny = Y + dy[i];
			int nx = X + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || m[ny][nx] == 0) continue; //�̶�, �ݵ�� ny,nx�� �� �ε��� ���� �ȿ� �ִ��� �˻縦 ���� �ؾ���! 
			                                                                        //(m[ny][nx]==0 �� �������� ���� �� ���, �ε��� ���� �߻��� �� ����!)
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[Y][X] + 1;
			q2.push({ ny, nx });
		}
	}

	/*
	���� �ڵ�� �ٸ� �� : �� �ڵ�� �������� ������ ���, �� �������� ���� �ּҰ����� ���� ��� �ּڰ��� �����ϵ��� �Ǿ� ����
	�׷���, �� �ڵ�� �ԷµǴ� ���� ������ ����ġ�� ��� ������. ���� BFS�� ������ ��� ��� ��ΰ� ��� ��κ��� ����ġ�� �� �۰ų� �ϴ� ��찡 ����(��� ����)
	���� �ּ� �������� ���ΰ����� �ʿ� ����, BFS�� ����Ž���� �Ϸ�Ǹ� �ڿ����� visited[N-1][M-1]�� ����� ���� �ּҰ��� ��.
	*/
	printf("%d", visited[N - 1][M - 1]);
}