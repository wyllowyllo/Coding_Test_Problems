#include <bits/stdc++.h>
using namespace std;

const int MAX = 1501;
int r, c;
char a[MAX][MAX];

string s;
int cnt = 0;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[MAX][MAX];

int searchNode[MAX][MAX];

queue<pair<int, int>> q;
queue<pair<int, int>> fq;

pair<int, int> swan[2];
int idx;

#pragma region MySol

//첫번째 시도 : 첫번째 백조의 위치에서 bfs해서 두번째 위치를 찾고, 찾지 못했다면 얼음 녹이기
//시간 초과

//두번째 시도 : Search할때도, 처음부터 찾지 말고 melt처럼 큐 두개써서 특정 탐색시작위치에서부터 시작
//47%에서 틀림.

//틀린 이유 : 백조(L)이 있는 곳도 물인데, 그걸 간과함... 백조 위치까지 포함하니 정답!

bool search() {
	//백조 찾기


	bool isFind = false;
	queue<pair<int, int>> temp;


	while (fq.size()) {
		pair<int, int> pos = fq.front();
		fq.pop();

		if (pos == swan[1]) {
			isFind = true;
			break;
		}
		else if (a[pos.first][pos.second] == 'X') {
			temp.push(pos);
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
			if (searchNode[ny][nx]) continue;

			searchNode[ny][nx] = 1;
			fq.push({ ny,nx });
		}
	}

	fq = temp;

	return isFind;
}


void Print() {
	cout << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}

void melt() {
	//얼음 녹이기

	pair<int, int> pos;
	queue<pair<int, int>> temp;

	visited[q.front().first][q.front().second] = 1;

	while (q.size()) {
		pos = q.front(); q.pop();

		if (a[pos.first][pos.second] == 'X') {
			a[pos.first][pos.second] = '.';
			temp.push({ pos.first, pos.second });
			continue;
		}
		//else if (a[pos.first][pos.second] == 'L') continue;

		for (int i = 0; i < 4; i++) {
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}


	}
	q = temp;

}

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = s[j];

			if (a[i][j] == '.') q.push({ i,j });
			else if (a[i][j] == 'L') {
				q.push({ i,j });
				swan[idx++] = { i,j };
			}
		}
	}

	searchNode[swan[0].first][swan[0].second] = 1;
	fq.push({ swan[0].first,swan[0].second });

	while (!search()) {

		melt();
		//Print();
		cnt++;
	}

	cout << cnt << "\n";
}
#pragma endregion


#pragma region Sol_1

//여기서도 얼음 녹이기, 백조 찾기 할 때 각각 2개의 큐를 사용하여 탐색 범위를 설정함.


int visited_swan[MAX][MAX];
int day, swanY, swanX, y, x;

queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> empty;
	swap(q, empty); //새로만든 빈 큐와 q를 바꿈. 즉 q는 비어있는 큐가 됨
}
void water_melting() {
	while (waterQ.size()) {
		tie(y, x) = waterQ.front(); waterQ.pop();


		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx])continue;

			//어차피 얼음 옆의 물에 대해서만 4방향으로 검사하면 되므로, waterQ에는 push안해도 된다.(얼음 만날때만 얼음 녹이고 그 위치 temp에 넣으면 됨)
			if (a[ny][nx] == 'X') {
				visited[ny][nx] = 1;
				water_tempQ.push({ ny, nx });
				a[ny][nx] = '.';
			}
		}
	}
}
bool move_swan() {
	while (swanQ.size()) {
		tie(y, x) = swanQ.front(); swanQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx])continue;

			visited_swan[ny][nx] = 1;
			if (a[ny][nx] == '.') swanQ.push({ ny,nx });
			else if (a[ny][nx] == 'X') swan_tempQ.push({ ny,nx });
			else if(a[ny][nx] == 'L') return true;
		}

		return false;
	}
}
void Sol_1() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'L') { swanY = i; swanX = j; }
			if (a[i][j] == '.' || a[i][j] == 'L') visited[i][j] = 1, waterQ.push({ i,j });


		}

		swanQ.push({ swanY,swanX });
		visited_swan[swanY][swanX] = 1;

		
	}

	while (true) {
		if (move_swan()) break;

		water_melting();
		swanQ = swan_tempQ;
		waterQ = water_tempQ;

		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		day++;
	}

	cout << day << "\n";
}



#pragma endregion



int main() {
	
}