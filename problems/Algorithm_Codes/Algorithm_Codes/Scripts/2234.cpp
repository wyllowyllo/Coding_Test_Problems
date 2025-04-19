#include <bits/stdc++.h>
using namespace std;

int a[51][51];
int b[51][51];

int visited[51][51];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int m, n;

int roomSize[2504];
int max_size = 0;


const int _dy[] = { 0,-1,0,1 };
const int _dx[] = { -1,0,1,0 };

int cnt, compSize[254], mx, big;

#pragma region MySol

//첫번째 시도 : 벽 하나 없애고, connetec componenent탐색 수행 -> 이거 반복하기
//시간초과


//두번째 시도 : 처음 bfs를 할때 방 별로 색깔을 칠해둠.(방 별로 사이즈도 저장해둠) 이후 각 방의 벽을 검사하며 파괴할 때, 파괴한 벽 기준 좌/우(또는 위/아래) 로 다른 색으로 칠해져있으면 다른 방임
// 파괴한 벽 기준으로 나뉘는 서로다른 두 방의 크기의 합을 구해 최대 방 사이즈 갱신
//틀림... 왜지?
//틀린 이유 : roomSize를 저장하는 배열 크기가 너무 작았던 듯... 크기 늘리니까 성공

//세번째 시도 : 첫번째 시도와 방법은 동일하나, 벽 없애고 모든 connected componenent를 재탐색하는 게 아니라 벽 없앤 그 구역의 connected Graph만 재탐색한다. -> 성공했으나, 시간 많이걸림


void go(int y, int x, int color = 0) {

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	//b[y][x] = color; //색칠하기(방 구분 위해)
	int size = 1;

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (a[y][x] & (1 << 1) && ny == y - 1) continue; //현재방의 북쪽으로 벽이 있으면 북쪽으로 못감
			if (a[y][x] & (1 << 0) && nx == x - 1) continue; //현재방의 서쪽으로 벽이 있으면 서쪽으로 못감
			if (a[y][x] & (1 << 2) && nx == x + 1) continue; //현재방의 동쪽으로 벽이 있으면 동쪽으로 못감
			if (a[y][x] & (1 << 3) && ny == y + 1) continue; //현재방의 남쪽으로 벽이 있으면 남쪽으로 못감

			visited[ny][nx] = 1;
			//b[ny][nx] = color; //색칠하기(방 구분 위해)
			size++;
			q.push({ ny,nx });
		}
	}

	//roomSize[color] = size;//방 별 사이즈 저장
	max_size = max(max_size, size);
}

int FindRooms() {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	int color = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				go(i, j, color);
				cnt++;
				color++;
			}

		}
	}


	return cnt; //방 개수 반환
}



void destroyWall() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			//각 방의 4방향 벽 중 1개 선택
			for (int k = 0; k < 4; k++) {
				if (a[i][j] & (1 << k)) {
					if (j == 0 && k == 0) continue; //왼쪽 최외곽 벽일 경우는 제외
					if (j == n - 1 && k == 2) continue; //오른쪽 최외곽 벽일 경우는 제외
					if (i == 0 && k == 1) continue; //위쪽 최외곽 벽일 경우는 제외
					if (i == m - 1 && k == 3) continue; //아래쪽 최외곽 벽일 경우는 제외

					//a[i][j] &= ~(1 << k); //벽 없애기
					//FindRooms(); //방 탐색
					//a[i][j] |= (1 << k); //벽 복원

					//if (k == 2 && b[i][j] != b[i][j + 1]) { //벽 기준 좌, 우로 다른 방일 경우
					//	max_size = max(max_size, roomSize[b[i][j]] + roomSize[b[i][j + 1]]);
					//}
					//else if (k == 0 && b[i][j] != b[i][j - 1]) {//벽 기준 좌, 우로 다른 방일 경우
					//	max_size = max(max_size, roomSize[b[i][j]] + roomSize[b[i][j - 1]]);
					//}
					//else if (k == 1 && b[i][j] != b[i-1][j]) {//벽 기준 위, 아래로 다른 방일 경우
					//	max_size = max(max_size, roomSize[b[i][j]] + roomSize[b[i-1][j]]);
					//}
					//else if (k == 3 && b[i][j] != b[i+1][j]) {//벽 기준 위, 아래로 다른 방일 경우
					//	max_size = max(max_size, roomSize[b[i][j]] + roomSize[b[i+1][j]]);
					//}

					a[i][j] &= ~(1 << k); //벽 없애기
					memset(visited, 0, sizeof(visited));
					go(i, j); //방 탐색
					a[i][j] |= (1 << k); //벽 복원
				}
			}
		}
	}
}

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << FindRooms() << "\n"; //방 개수 출력
	cout << max_size << "\n"; //가장ㅇ 넓은 방 사이즈 출력


	destroyWall();

	cout << max_size << "\n"; //벽 하나 제거했을 때 가장 넓은 방 사이즈 출력
}

#pragma endregion


#pragma region Sol_1
//여기서는 connected compoenent탐색을 할때, int반환 타입의 재귀 함수를 사용하여 사이즈를 구함

//벽을 부수고 방을 합칠 때, 나처럼 굳이 특정 칸의 벽을 검사해서 그걸 없애는 과정이 없음. 그냥 수평 또는 수직으로 인접한 칸 두개 비교해서 그 칸이 서로 다른 방이면 사이즈 합침



int dfs(int y, int x, int cnt) {
	if (visited[y][x]) return 0;
	visited[y][x] = cnt; //색칠하기(방 구분위해) -> 굳이 나처럼 visited(방문처리) 랑 방 색칠 배열(b)를 따로 두지 않고 하나로 처리함

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		if (!(a[y][x] & (1 << i))) { //가려는 방향으로 벽이 없는 경우
			int ny = y + _dy[i];
			int nx = x + _dx[i];

			ret += dfs(ny, nx, cnt);
		}
	}

	return ret; //dfs의 최종 반환값은 connected component의 크기가 됨
}
void Sol_1() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt++;
				compSize[cnt] = dfs(i, j, cnt); //각 방의 사이즈 저장
				mx = max(mx, compSize[cnt]);
			}
		}
	}

	//두 방 합칠때 크기 갱신

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < m) { //overflow 방지코드
				int a = visited[i + 1][j];
				int b = visited[i][j];

				if (a != b) { //위아래로 비교했을때, 다른 방이면
					big = max(big, compSize[a] + compSize[b]);
				}
			}

			if (j + 1 < n) {//overflow 방지코드
				int a = visited[i][j + 1];
				int b = visited[i][j];

				if (a != b) {
					big = max(big, compSize[a] + compSize[b]);
				}
			}
		}
		
	}

	cout << cnt << "\n" << mx << "\n" << big << "\n";
}

#pragma endregion

int main() {
	Sol_1();
}