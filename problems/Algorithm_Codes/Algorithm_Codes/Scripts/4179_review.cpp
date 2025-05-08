#include <bits/stdc++.h>
using namespace std;


//메모리 초과 계속나서 고생함...

//알고보니 불의 bfs와 사람의 bfs할때, fire[ny][nx]<fire[y][x]+1 이 조건문에서 <= 대신 <로 해서 큐에 쓸데없이 push가 많이 된거였음...
const int INF = 1000001;
int r, c;
char a[1001][1001];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int visited[1001][1001];
int fire[1001][1001];

vector<pair<int, int>> fires;
pair<int, int> jPos;
bool escape = false;
int escapeTime = 1000001;

queue<pair<int, int>> fq;
void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		if ((y == 0 || y == r - 1 || x == 0 || x == c - 1)) {
			escape = true;
			escapeTime =visited[y][x];
			break;
		}
			

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (visited[ny][nx] || a[ny][nx] == '#' || a[ny][nx]=='F') continue;
			if (fire[ny][nx] <= visited[y][x] + 1) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
		
	}
}

void spread() {
	int y; int x;
	
	
	while (fq.size()) {
		tie(y, x) = fq.front(); fq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (fire[ny][nx] <= fire[y][x] + 1) continue;
			if (a[ny][nx] == '#' || a[ny][nx]=='F') continue;

			fire[ny][nx] = fire[y][x] + 1;
			fq.push({ ny,nx });
		}

	}
}



int main() {
	cin >> r >> c;

	fill(&fire[0][0], &fire[0][0] + 1001 * 1001, INF);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			
			if (a[i][j] == 'F') {
				fq.push({ i,j });
				fire[i][j] = 1;
			}
			else if (a[i][j] == 'J')jPos = { i,j };
		}
	}

	
	spread();
	bfs(jPos.first, jPos.second);
	
	if (!escape)cout << "IMPOSSIBLE\n";
	else cout << escapeTime << "\n";
}