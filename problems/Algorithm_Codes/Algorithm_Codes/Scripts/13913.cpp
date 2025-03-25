#include <bits/stdc++.h>
using namespace std;

const int MAX=100001;

int visited[MAX];
int lastIdx[MAX];

int n, k;


#pragma region MySol

//처음 시도 : 최소시간을 구하고, 역추적을 통해 그 경로를 스택에 저장한 후 출력
//위 시도가 실패해서 모든 경로를 다 출력해야하는 줄 알고, 모든 경로를 다 출력하는 방식으로 변경
//알고보니 n==k일때 그냥 0만 출력해서 틀린거였음. 경로까지 포함해서 출력
//성공!

void Track() {
	stack<int> stk;

	stk.push(k);
	int idx = lastIdx[k];

	//역추적
	while (true) {
		if (idx == -1) break;

		stk.push(idx);
		idx = lastIdx[idx];
	}

	//경로 출력
	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}
}

void Move(int startPos) {
	queue<int> q;


	q.push(startPos);
	visited[startPos] = 1;
	lastIdx[startPos] = -1;

	int pos;

	while (q.size()) {
		pos = q.front(); q.pop();

		if (pos == k) {
			cout << visited[k] - 1 << "\n"; //최소시간
			Track();

			return;
		}

		for (int next : {pos + 1, pos - 1, pos * 2}) {
			if (next < 0 || next>100000) continue;
			if (visited[next]) continue;

			visited[next] = visited[pos] + 1;
			lastIdx[next] = pos;
			q.push(next);
		}
	}


}

void MySol() {
	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n" << n << "\n";
		return;
	}



	Move(n);
}

#pragma endregion

#pragma region Sol_1

//나는 MAX 값을 100001로 잡았는데, 여기서는 20만 이상으로 잡음
//왜? n과 k값은 10만 이하지만, k로 갈 때 경로가 10만을 넘어가면 안 된다는 조건은 없음.
//계산 중 나올수 있는 최댓값은 10만*2 ==20만 이므로, 최대범위를 20만+여유공간 으로 산정함

#define prev aaa
#define next aaaa

const int max_n = 200004;
int visit[max_n], prev[max_n], ret, here, cnt, next;


void Sol_1() {
	queue<int> q;

	cin >> n >> k;
	visit[n] = 1;
	q.push(n);

	while (q.size()) {
		here = q.front();
		q.pop();

		if (here == k) {

			ret = visit[k];
			break;
		}

		for (int next : {here + 1, here - 1, here * 2}) {
			if (next >= max_n || next < 0 || visit[next]) continue;

			visit[next] = visit[here] + 1;
			prev[next] = here;
			q.push(next);
		}
	}

	vector<int> v;
	for (int i = k; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);

	cout << ret - 1 << '\n';
	reverse(v.begin(), v.end()); //나는 stack으로 경로를 출력했지만, 여기서는 reverse로 순서를 뒤집어서 그냥 바로 출력함
	for (int i : v) cout << i << " ";
	return;

	
}


#pragma endregion


int main() {
	

}