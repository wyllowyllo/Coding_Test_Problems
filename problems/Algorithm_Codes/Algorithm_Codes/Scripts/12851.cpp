#include <bits/stdc++.h>
using namespace std;

int n, k;

int ret = 9999999;



int visited[100001];
int way[100001];
int wayCnt = 0;


#pragma region MySol

//첫번째 시도 : 재귀를 이용하여 풀이했으나 , 예상대로 시간초과
//시간복잡도 3^10만 일거라 예상하긴 했는데...(pruning하긴 했어도 역시 안되네)

//두번째 시도 : BFS로 풀기 -> 반례가 있는듯
//나는 처음에 방문 방법의 수를 구할 때 방문할때마다 1씩 증가시키는 경우로 했는데, 이러면 안됨 -> 만약 현재 노드에 방문 가능한 방법이 3가지라면, 다음 노드 또한 최소 3가지의 방법으로 방문할 수 있는 것이기 때문
//따라서 첫 방문시에는 way[다음노드]=way[현재노드] 로 하고, 첫 방문은 아니지만 같은 시간 내에 방문이 가능한 경우라면 way[다음노드]+=way[현재노드] 이런식으로 방법의 수를 합산시켜 나가야 함

//세번째 시도 : BFS 랑 DFS 둘다쓰기 -> 시간초과. DFS는 아예 쓰면 안될듯 함

//두번째 시도의 반례 : n==k인 경우를 처리하는 조건문을 visited[k]=1랑 way[k]=1 초기화 전에 선언하고, 출력 후 return했음 -> 출력이 2번 나감 
// n==k인 경우를 처리하는 조건문을 아예 삭제하니 정답
// 조건문의 return 대신 exit(0) 했어도 됨
//시발


bool isIn(int idx) {
	return 0 <= idx && idx <= 100000;
}


void move(int idx, int cnt) {

	if (cnt > ret) return; //이미 최소시간 초과한 경우면 그냥 종료
	if (!isIn(idx)) return; //범위 넘어간 경우면 그냥 종료
	if (idx == k) {

		if (ret > cnt) {
			ret = cnt;
			//way = 1;
		}
		else if (cnt == ret) {
			//way++;
		}

		return;
	}

	//동생보다 앞에 있으면, 무조건 뒤로만 가기
	if (idx > k) {
		move(idx - 1, cnt + 1);
	}
	else {
		move(idx + 1, cnt + 1);
		move(idx - 1, cnt + 1);
		move(idx * 2, cnt + 1);
	}

}

void findWay(int idx, int cnt) {

	if (cnt > visited[k] - 1) return;
	if (!isIn(idx)) return; //범위 넘어간 경우면 그냥 종료
	if (idx == k) {
		wayCnt++;
		return;
	}

	//동생보다 앞에 있으면, 무조건 뒤로만 가기
	if (idx > k) {
		findWay(idx - 1, cnt + 1);
	}
	else {
		findWay(idx + 1, cnt + 1);
		findWay(idx - 1, cnt + 1);
		findWay(idx * 2, cnt + 1);
	}

}

void go(int pos) {
	visited[pos] = 1;
	way[pos] = 1;
	queue<int> q;

	q.push(pos);


	while (q.size()) {
		pos = q.front(); q.pop();

		vector<int>np;


		if (pos == k) {

			return;
		}

		np.push_back(pos + 1);
		np.push_back(pos - 1);
		np.push_back(pos * 2);

		for (int p : np) {
			if (!isIn(p)) continue;

			if (!visited[p]) { //첫 방문이라면
				visited[p] = visited[pos] + 1;
				way[p] = way[pos]; //다음 노드 방문 방법의 수는 현재 노드의 방문 방법 수와 같다(나중에 더 찾을수도 있음)
				q.push(p);
			}
			else if (visited[p] == visited[pos] + 1) //이미 방문한 전적이 있지만, 같은 시간 내에 방문할 수 있는 경우
				way[p] += way[pos]; //방문 방법의 수 합산

			//q.push(p);
		}
	}
}

void MySol() {
	cin >> n >> k;

	//move(n, 0);
	go(n);
	//findWay(n, 0);
	cout << visited[k] - 1 << "\n" << way[k] << "\n";
	//cout << visited[k] - 1 << "\n" << wayCnt << "\n";
}


#pragma endregion

#pragma region Sol_1

//경우의 수는? '더하는' 것이다!

const int MAX = 200000;

int visit[MAX + 4];
long long cnt[MAX + 4];

void Sol_1() {
	cin >> n >> k;

	//예외처리
	if (n == k) {
		puts("0"); puts("1"); //자동 줄바꿈 됨

		return;
	}

	visit[n] = 1;
	cnt[n] = 1;
	queue<int> q;

	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= MAX) {
				if (!visit[next]) {
					q.push(next);
					visit[next] = visit[now] + 1;
					cnt[next] += cnt[now]; //경우의 수 더해나감

				}
				else if (visit[next] == visit[now] + 1) //이미 이 노드를 방문했지만, 똑깥은 이동횟수로 이 노드에 도달할 수 있는 경우, 방문 방법 횟수를 갱신한다
					cnt[next] += cnt[now]; //경우의 수 더해나감
			}
		}
	}

	cout << visited[k] - 1 << '\n';
	cout << cnt[k] << '\n';
	return;
}

#pragma endregion

int main() {

}

