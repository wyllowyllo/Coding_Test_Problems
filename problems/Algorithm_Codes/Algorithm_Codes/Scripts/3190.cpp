#include <bits/stdc++.h>
using namespace std;
#define time ff
#define y1 cc

#pragma region MySol

namespace my {
	int n, k, l;
	int a[101][101];


	int visited[101][101];
	int x, y;

	char c;
	int t;

	queue<pair<int, char>> q;
	vector<pair<int, int>> body;


	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };
	int dirIdx;


	pair<int, int> head = { 0,0 };

	void MySol() {
		cin >> n >> k;

		for (int i = 0; i < k; i++) {
			cin >> y >> x;
			a[y - 1][x - 1] = 1;
		}
		cin >> l;



		for (int i = 0; i < l; i++) {
			cin >> x >> c;
			q.push({ x,c });
		}

		visited[0][0] = 1;
		body.push_back({ 0,0 });

		while (true) {
			t++;

			int moveY = dy[dirIdx] * 1;
			int moveX = dx[dirIdx] * 1;


			head.first += moveY;
			head.second += moveX;

			if (head.first < 0 || head.first >= n || head.second < 0 || head.second >= n || visited[head.first][head.second]) {
				break;
			}

			if (a[head.first][head.second]) { //사과가 있는 경우
				a[head.first][head.second] = 0;

				pair<int, int> tmp = body.back(); //꼬리 있던 칸
				visited[body.back().first][body.back().second] = 1; //꼬리 있던 칸 비우지않고 그대로

				// 한칸씩 몸체 움직이기
				for (int i = body.size() - 1; i >= 1; i--) {
					body[i].first = body[i - 1].first;
					body[i].second = body[i - 1].second;
				}
				body[0].first = head.first;
				body[0].second = head.second;

				visited[head.first][head.second] = 1; //머리 있는 칸 방문처리

				body.push_back(tmp); //몸길이 늘어남
			}
			else {

				// 한칸씩 몸체 움직이기
				visited[body.back().first][body.back().second] = 0; //꼬리 있던 칸 다시 비워짐

				for (int i = body.size() - 1; i >= 1; i--) {
					body[i].first = body[i - 1].first;
					body[i].second = body[i - 1].second;
				}
				body[0].first = head.first;
				body[0].second = head.second;

				visited[head.first][head.second] = 1; //머리 있는 칸 방문처리
			}


			if (q.size() && t == q.front().first) {
				if (q.front().second == 'D') dirIdx = (dirIdx + 1) % 4;
				else dirIdx = ((dirIdx - 1) >= 0 ? dirIdx - 1 : 3);

				q.pop();
			}

		}

		cout << t << "\n";
	}
}
#pragma endregion

#pragma region Sol_1

//나는 지렁이의 몸체 각 부분이 한칸씩 땡겨지는 방식으로 구현했으나, 여기서는 움직일때마다 꼬리를 pop하고(사과 먹었으면 pop하지 않음) 앞의 부분에 새 부분을 push하는 식으로 구현함 
// -> 뒷부분을 지우고, 앞부분을 더하는 식 -> 데크 사용!

namespace Sol {
	typedef long long ll;
	int n, k, l, y, x, t, ret, idx, dir = 1;
	int a[104][104], visited[104][104], time;
	char c;
	deque<pair<int, int>> dq;
	vector<pair<int, int>> _time;
	const int dy[] = { -1, 0, 1, 0 };
	const int dx[] = { 0, 1, 0, -1 };



	void Sol_1() {
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> y >> x;
			a[--y][--x] = 1; //사과위치 저장
		}

		cin >> l;

		for (int i = 0; i < l; i++) {
			cin >> t >> c;

			if (c == 'D') _time.push_back({ t,1 }); //R일때 인덱스 1 증가하는, L일때 인덱스 3증가하는 식으로 방향 인덱스 정함
			else _time.push_back({ t,3 });
		}

		dq.push_back({ 0,0 });

		while (dq.size()) {
			time++;

			tie(y, x) = dq.front();
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) break;

			if (!a[ny][nx]) { //사과가 없다면
				visited[dq.back().first][dq.back().second] = 0;

				dq.pop_back(); //꼬리부분 지움
			}
			else a[ny][nx] = 0; //사과가 있다면 꼬리 지우지 않음. 사과는 없앰.

			visited[ny][nx] = 1;
			dq.push_front({ ny,nx });

			if (time == _time[idx].first) {
				dir = (dir + _time[idx].second) % 4;
				idx++;
			}
		}

		cout << time << "\n";
	}
}
#pragma endregion


int main() {
	

}