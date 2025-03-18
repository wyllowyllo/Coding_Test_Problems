#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[1001][1001];
int visited[1001][1001];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


#pragma region MySol

//첫 시도 : BFS를 하며, 매 순간 지훈이가 이동 가능한 위치 갱신하고, 불이 번지게 함 ->실패
//불과 지훈이의 이동이 동시에 진행되는 거니까, 기존 방식처럼 지훈이가 이동할수 있는 위치 정해놓고, 불을 번지게 하는건 안되나?
//불이 다 번졌을 때의 맵을 먼저 구성해 놓고, 남은 위치를 지훈이가 이동하는 식으로 변경할까?
//아 이건 아닌듯 첫 시도한 방법이 방향이 맞는듯, 먼저 불을 다 번지게해놓으면 탈출을못하네

//흠... 이것도 조합으로 풀어야 하나?
//지훈이가 4방향 중 1방향으로 이동했을 때, 불이 4방향으로 번지기

//방법은 맞는데, 반례를 생각하지 못하는건가...

//방법 수정함 : 처음에는 지훈이의 위치를 pop할떄마다(지훈이가 이동할때마다) 불의 각 위치에서 4방향으로 퍼져나가는 식이었음
//이렇게 하면 지훈이의 이동과 불의 확산을 '동시에'처리하지 못함(동기화 x)
//각 단계에서 지훈이가 이동할 수 있는 위치를  전부 pop해서 처리한 후, 불이 퍼지게 함
//첫번째 방법은 바로 실패한 반면, 이 방법은 54%까지 성공함... 그러나 실패. 반례가 있는듯?
//반례 발견 : 지훈이가 탈출구에 도달하는 순간과, 불이 그 탈출구에 번지는 순간이 동일한 타입스텝에 일어날 경우
//이 경우는 지훈이가 탈출하지 못해야 하지만, 지금처럼  1. 지훈이의 이동을 모두 처리 2. 불이 번짐 의 순서로 동기화시키면, 이 반례를 잡지 못하고 지훈이가 탈출하게 됨
//1. 불이 번짐 2. 지훈이의 이동을 모두 처리 이런식으로 두 로직의 순서를 바꿔야 이 동시성의 모호성을 잡아낼수 있다.

/*키포인트*/
//불과 사람의 이동을 '동시에'처리해야 함
//불의 이동이 먼저인지, 사람의 이동이 먼저인지 를 고민해야 됐음!

queue<pair<int, int>> firePos;
pair<int, int> startPos;


bool escape = false;
int escapeTime = 0;


void BFS(int Y, int X) {



	visited[Y][X] = 1;

	queue<pair<int, int>> q_jihoon;

	//처음 지훈이 이동할 위치
	for (int i = 0; i < 4; i++) {
		int ny = Y + dy[i];
		int nx = X + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (a[ny][nx] == '#' || a[ny][nx] == 'F' || visited[ny][nx]) continue;

		visited[ny][nx] = visited[Y][X] + 1;

		q_jihoon.push({ ny,nx });
	}


	while (q_jihoon.size()) {

		//불 번지기
		int qSize = firePos.size();
		for (int i = 0; i < qSize; i++) {

			pair<int, int> fp = firePos.front(); firePos.pop();

			for (int i = 0; i < 4; i++) {
				int ny = fp.first + dy[i];
				int nx = fp.second + dx[i];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (a[ny][nx] == '#' || a[ny][nx] == 'F') continue;

				a[ny][nx] = 'F';

				firePos.push({ ny,nx });

			}
		}

		//지훈 이동 처리
		qSize = q_jihoon.size();
		for (int i = 0; i < qSize; i++) {
			tie(Y, X) = q_jihoon.front(); q_jihoon.pop(); //이동



			//탈출구 도착?
			if (((Y == 0 || Y == r - 1 || X == 0 || X == c - 1) && a[Y][X] == '.')) {
				escape = true;
				escapeTime = visited[Y][X];
				return;
			}

			if (a[Y][X] == 'F') continue; //이동할 위치에 불 번졌으면 넘기기

			//지훈 이동가능 위치 검사
			for (int i = 0; i < 4; i++) {
				int ny = Y + dy[i];
				int nx = X + dx[i];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (a[ny][nx] == '#' || a[ny][nx] == 'F' || visited[ny][nx]) continue;

				visited[ny][nx] = visited[Y][X] + 1;
				q_jihoon.push({ ny,nx });
			}
		}




	}

}

void MySol() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			if (a[i][j] == 'F')
				firePos.push({ i,j });

			else if (a[i][j] == 'J')
				startPos = { i,j };
		}
	}

	if (startPos.first == 0 || startPos.first == r - 1 || startPos.second == 0 || startPos.second == c - 1)
	{
		cout << 1 << "\n";
		return;
	}


	BFS(startPos.first, startPos.second);

	if (escape) cout << escapeTime << "\n";
	else cout << "IMPOSSIBLE\n";
}
#pragma endregion

#pragma region Sol_1

//BFS로 지훈이의 최단거리와, 불의 최단거리를 각각 구함
//만약 특정 지점의 불의 최단거리보다 지훈이의 최단거리가 더 작다면, 지훈이가 먼저 도착할 수 있는 것임

//내 방법은 지훈이의 이동과 불 번짐을 같은 타입스텝 내에 처리하며 이동시켜나가는 거였음
//여기서는 그렇게 하지 않고, 각각의 최단거리를 bfs로 구하고, 그 거리를 비교하여 갈수 있냐, 없냐를 정함
//그래서 나와는 달리 지훈이가 먼저 이동할것인지, 불이 먼저 이동할것인지를 정할 필요가 없음

const int INF = 987654321;
int n, m, sx, sy, ret, y, x;
int fire_check[1004][1004], person_check[1004][1004];

bool in(int a, int b) {
	return 0 <= a && a < n && b >= 0 && b < m; //맵 범위 안 인지를 검사
}

void Sol_1() {
	queue<pair<int, int>>q;
	cin >> n >> m;

	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF); //INF로 초기화
	//만약 INF로 초기화하지 않는다면(0으로 초기화되었다면), 불이 아예 없는 케이스인 경우를 처리할 수 없음

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				fire_check[i][j] = 1; //방문처리
				q.push({ i,j });
			}
			else if (a[i][j] == 'J'){
				sy = i; sx = j; //지훈이 위치 저장
			}
		}
	}

	//불에 대해 bfs수행
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	//지훈이에 대해 bfs수행
	person_check[sy][sx] = 1;
	q.push({ sy,sx });

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//탈출구 도착
		if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
			ret = person_check[y][x];
			break;
		}


		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (person_check[ny][nx] || a[ny][nx] == '#') continue;
			if (fire_check[ny][nx] <= person_check[y][x] + 1) continue; //불이 먼저 도달하는 경우에는 못감, 처음에 fire_check을 INF로 초기화 안했다면 불이 아예 없을 때 지훈이도 아예 움직일수가 없음;
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	return;
}

#pragma endregion


int main() {
	Sol_1();
}