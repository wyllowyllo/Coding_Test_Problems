#include <bits/stdc++.h>
using namespace std;

#define y1 mingwan


int n, m;
char a[301][301];
int visited[301][301];

#pragma region MySol

//풀이는 맞게 했는데, 시간 오래걸림 
//왜 ? 문제에서는 x1,y1,x2,y2이렇게 입력된다고 했는데, 실제 입력보니 y-x순으로 입력되는거였음...
//하....

int x1, y1, x2, y2;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}
bool BFS(int y, int x) {
	bool flag = false;
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		if (a[y][x] == '#') {
			flag = true;
			break;
		}
		else if (a[y][x] == '1') {
			a[y][x] = '0';
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}

	return flag;
}
void Jump() {
	int cnt = 0;

	while (!BFS(y1 - 1, x1 - 1)) {
		cnt++;
		//Print();
	}

	cnt++;
	//Print();

	cout << cnt << "\n";
}


void MySol() {
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	Jump();
}

#pragma endregion

#pragma region Sol_1

//여기서는 큐를 2개 사용하여 해결함.
//나도 이생각 하긴 했는데.. 1을 만나면 0으로 바꾸고, 그 위치를 따로 저장. 다음 jump시 그 위치들부터 다시 bfs시작하는 방식으로
//물론 이게 탐색범위가 확 줄어들어서 효율적이긴 했는데, 문제범위보고 시간복잡도 상 그냥 무식하게 풀어도 될거같아서 난 그냥 무식하게 함
//주목할 부분 : 여기서는 y,x입력받을때 pair를 안쓰고, int를 사용하여 해결함

void Sol_1() {
	queue<int> q;
	


	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

	y1--, x1--, y2--, x2--;
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}

	q.push(1000 * y1 + x1); //최대범위보다 여유있는 값(1000)을 이용하여 y1,x1이라는 두 값을 하나의 int값으로 표현
	visited[y1][x1] = 1;

	int c = 0;

	//범인(#)가 0으로 바뀌면 종료
	while (a[y2][x2] != '0') {
		c++;
		queue<int >temp;
		while (q.size()) {
			int y = q.front() / 1000; //y추출
			int x = q.front() % 1000; //x추출
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;

				visited[ny][nx] = c;

				//1이나 #이라면 0으로 바꾸고 또다른 큐에 넣기
				if (a[ny][nx] != '0') {
					a[ny][nx] = '0';
					temp.push(1000 * ny + nx);
				}
				else q.push(1000 * ny + nx);
			}

			

		}
		q = temp;
	}
	
	printf("%d\n", visited[y2][x2]);
}
#pragma endregion


int main() {
	Sol_1();
}