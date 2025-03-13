#include <bits/stdc++.h>
using namespace std;


int n, m;
int maze[101][101];
int visited[101][101];
int dx[4]{ 0,1,0,-1 }; int dy[4]{ -1,0,1,0 };

#pragma region  MySol

//시간 오래걸림...

//오래걸린 이유 1 : 따닥따닥 붙어서 입력되는 케이스의 처리방법 알지 못함
//오래걸린 이유 2 : 문자열로 입력을 받았는데, 이를 다시 정수로 제대로 변환하지 않아 답이 틀리게 나옴
	void BFS(int startY, int startX) {
		visited[startY][startX] = 1;

		queue<pair<int, int>> q;
		int y, x;
		q.push({ startY,startX });


		while (q.size()) {
			tie(y, x) = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
				if (!maze[ny][nx] || visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	void MySol() {
		cin >> n >> m;

		string line;

		for (int i = 1; i <= n; i++) { //한줄씩 입력받아 각 줄의 단어를 옮기는 방식 사용
			cin >> line;
			for (int j = 1; j <= m; j++)
				maze[i][j] = line[j - 1] - '0'; //아스키 코드를 이용하여, 문자를 숫자로 변환
		}


		BFS(1, 1);
		cout << visited[n][m] << "\n";
	}
#pragma endregion

#pragma region  Sol_1


//입력이 붙어서 전달되는 경우의 처리 : scanf 사용하기 (한글자씩 입력받기)
	void Sol_1() {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &maze[i][j]); //한글자씩 입력받기
			}
		}

		queue<pair<int, int>> q;
		int y, x;

		visited[0][0] = 1;
		q.push({ 0,0 });

		while (q.size()) {
			tie(y, x) = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || maze[ny][nx] == 0) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}

		printf("%d", visited[n - 1][m - 1]);
		
}

#pragma endregion




int main() {
	
	//MySol();
}