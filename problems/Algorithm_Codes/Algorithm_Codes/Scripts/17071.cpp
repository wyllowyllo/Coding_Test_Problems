#include <bits/stdc++.h>
using namespace std;


const int MAX = 500001;
int n, k;
int visited[MAX]; //도착시간
int targetPos[MAX];

int visit[2][MAX], a, b, ok, turn = 1;

#pragma region MySol

//71퍼까지 가다가.. 시간초과
//풀이 자체는 맞는데, 이게 이미 아무 의미가 없는 경우인데 계속 push해서 의미없는 검사를 반복하기 때문에 그런듯
//GG

bool flag;
int ret;

void targetMove() {

	targetPos[0] = k; //처음위치

	//시간에 따른 위치값 저장
	for (int i = 1; i < MAX; i++) {
		targetPos[i] = targetPos[i - 1] + i;
	}

}

void Move(int pos) {
	 
	visited[pos] = 1;
	queue<pair<int, int>> q; //{위치,시간}
	q.push({ pos,1 }); 

	pair<int, int> v;
	while (q.size()) {
		v = q.front(); q.pop();

		//만약 같은 시간에 같은 위치라면
		if (v.first == targetPos[v.second - 1]) {
			flag = true;
			ret = v.second - 1;


			return;
		}

		if (targetPos[v.second - 1] >= MAX) return;

		for (int next : {v.first + 1, v.first - 1, v.first * 2}) {
			if (next < 0 || next >= MAX) continue;

			//처음 방문
			if (!visited[next]) {
				visited[next] = v.second + 1;
				q.push({ next,v.second + 1 });
			}
			//방문한적 있지만, 다른 시간에 재방문한 경우 
			else if (visited[next] < v.second + 1) {
				//visited[next] = visited[v.first] + 1;
				visited[next] = v.second + 1;
				q.push({ next,v.second + 1 });
			}

			//어떤 노드에 이미 한번 방문했고, 같은 타임라인 내에 그 노드에 도착하는 다른 경우는 큐에 포함하지 않는다

		}
	}
}

void MySol() {
	cin >> n >> k;


	//시간에 따른 동생 위치값 초기화
	targetMove();

	//수빈이의 이동
	Move(n);

	if (flag) cout << ret << "\n";
	else cout << -1 << "\n";
}

#pragma endregion

#pragma region Sol_1

//이 문제는 수빈이 위치와 동생 위치, 2가지 상태값이 존재하므로, 2차원 배열을 활용해야 함
//visited[y][x] 여기서 y는 동생위치, x는 수빈위치 이런식으로
//근데 그렇게 하면 공간복잡도가 50만 * 50만 이므로 너무 큼
//따라서 밑의 방법을 활용하여 수빈이가 홀짝인 것만 체크하면 됨을 알아냄 -> visited[2][50만] 으로 해결함


//수빈이와 동생이 만나는 경우는 2가지이다
// 1. 수빈이와 동생이 같이 가면서 만나는 경우
// 2. 수빈이가 먼저 도착하고, 홀짝이 맞았을 때 

//수빈이가 어떤 위치에 먼저 도착하고, 이후 동생이 도착하는 경우라면 수빈이와 동생은 만날 수 있다
//왜 ? 수빈이가 그 위치에서 동생이 올때까지 계속 왔다리 갔다리 하고 있으면 되기 때문
//이때 동생과 수빈의 도착시간이 모두 홀수거나, 모두 짝수여야함

//ex) 수빈이가 어떤 좌표에 5초가 되었을 때 도착했고, 동생이 6초에 도착한다고 하자
//수빈이는 동생이 올때까지 왔다리갔다리 해야 하는데, 왔다리갔다리(+1,-1)해서 다시 그 좌표에 올 시간은 2초가 지난 7초일 것임. 즉 5초에 도착했고, 7초에 다시 도착하는데 동생은 6초에 도착하므로 서로 만나지 못함
//만약 수빈이가 5초, 동생이 7초에 같은 좌표에 도착한다면, 도착시간 모두 홀수이므로 수빈이는 동생과 만날 수 있음
//만약 수빈이가 5초, 동생이 7초에 같은 좌표에 도착한다면, 도착시간 모두 짝수이므로 수빈이는 동생과 만날 수 있음



void Sol_1() {
	cin >> a >> b;
	if (a == b) { cout << 0 << "\n"; return; }

	queue<int> q;
	visit[0][a] = 1;
	q.push(a);

	while (q.size()) {
		b += turn; //1초,2초,...마다 바뀌는 동생의 위치

		if (b >= MAX) break;

		//(만나는 경우 2) 짝수 또는 홀수시간에 이미 수빈이가 방문했다면, 만날수 있다(수빈이는 동생올동안 이자리에서 와리가리쳤음)
		if (visit[turn % 2][b]) {
			ok = true;
			break;
		}
		int qSize = q.size(); //턴 분리
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();

			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx < 0 || nx >= MAX || visit[turn % 2][nx]) continue; //같은 턴에 이미 방문했다면 다시 방문 x
				visit[turn % 2][nx] = visit[(turn + 1) % 2][x] + 1; //이전 턴의 위치 도착시간 +1
				
				//(만나는경우1) 수빈이와 동생이 같이 가면서 만나는 경우
				if (nx == b) {
					ok = 1;
					break;

				}
				q.push(nx);
			}
			if (ok)break;
		}
		if (ok)break;
		turn++;
	}
	if (ok) cout << turn << "\n";
	else cout << -1 << "\n";

}

#pragma endregion


int main() {
	//MySol();
	Sol_1();
}