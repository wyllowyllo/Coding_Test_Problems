#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;

int N, M;
int m[max_n][max_n];
int visited[max_n][max_n];

//------------------------------My Solution -----------------------------------//
//문제를 착각해서 처음에 DFS를 사용하여 풀려고 시도함 -> 그러나 이 문제는 경로 중 1개를 찾는 것이 아니라, 가능한 경로 중 최소경로를 찾는 것
//해당 문제는 간선의 가중치가 일정하므로, BFS를 사용해야 함! 
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
	cin.ignore(); //입력버퍼 비우기

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
			scanf("%1d", &m[i][j]); //입력이 따닥따닥 붙어서 주어지는 경우, 이 방법으로 입력받을 수 있다!(%1d == 한자리의 int값을 받겠다)
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
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || m[ny][nx] == 0) continue; //이때, 반드시 ny,nx가 맵 인덱스 범위 안에 있는지 검사를 먼저 해야함! 
			                                                                        //(m[ny][nx]==0 가 조건으로 먼저 올 경우, 인덱싱 에러 발생할 수 있음!)
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[Y][X] + 1;
			q2.push({ ny, nx });
		}
	}

	/*
	나의 코드와 다른 점 : 내 코드는 목적지에 도착할 경우, 그 누적값이 원래 최소값보다 작은 경우 최솟값을 갱신하도록 되어 있음
	그러나, 이 코드로 입력되는 맵은 간선의 가중치가 모두 일정함. 따라서 BFS로 구현할 경우 어디 경로가 어디 경로보다 가중치가 더 작거나 하는 경우가 없음(모두 일정)
	따라서 최소 누적값을 따로갱신할 필요 없이, BFS로 간선탐색이 완료되면 자연스레 visited[N-1][M-1]에 저장된 값이 최소값이 됨.
	*/
	printf("%d", visited[N - 1][M - 1]);
}