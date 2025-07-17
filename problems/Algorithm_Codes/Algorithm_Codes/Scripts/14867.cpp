#include <bits/stdc++.h>
using namespace std;

namespace Sol {
	//A,B물통의 각 상태를 노드로 보면, A,B물통의 목표치까지 도달하는 최소경로가 이 문제의 답이 됨
	//즉 이 문제를 보고 BFS를 떠올릴 수 있어야 함(나는 실패, 완탐으로 하려니 시간복잡도 상 안된다고 생각함. 또한 dp로 하려니 공간복잡도상 안된다고 생각함)
	//그러나 총 상태값은 10만 *10만이므로, BFS를 위한 배열을 정의할 수 없음(공간복잡도 상 불가!)

	//그러나 문제를 잘 살펴보면, 실제 상태값의 범위는, 완전한 10만*10만이 아니라 그 범위 중 몇개의 값만 실제 상태값으로 가지게 되는 것을 알 수 있음
	//ex) 목표치가 10, 3 이라면, 가능한 상태값은 {0,0},{0,3},{10,3},{3,3},{6,3},{9,3} 으로 모든 10*10상태값을 가지는 게 아닌, 희소한 개수의 상태값만 가짐
	//따라서, map을 활용하여 bfs를 쓸 수 있다!

	//즉 이 문제의 키포인트는
	//문제를 보고, 최소 연산 횟수를 구하는 문제-> 현 상태값에서(현 노드) 다음 상태값까지(다음 노드) 갈 때의 코스트는 1로 동일-> BFS를 통한 최단경로 구하기 를 떠올릴 수 있어야 하고
	//BFS를 위한 자료구조를 고려할 때, 실제 노드의 총 개수는 10만*10만 아닌 sparse하다는 것을 파악하고, map을 쓸 수 있음을 생각할 수 있어야 했음


	int a, b, c, d;
	map<pair<int, int>, int>m;
	queue<pair<int, int>> q;

	void enqueue(int x, int y, int d) {
		if (m[{x, y}]) return;
		m[{x, y}] = d + 1;
		q.push({ x,y });
	}

	int bfs(int x, int y) {
		m[{x, y}] = 1;

		q.push({ x,y });
		while (q.size()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			enqueue(a, y, m[{x, y}]);
			enqueue(x, b, m[{x, y}]);
			enqueue(0, y, m[{x, y}]);
			enqueue(x, 0, m[{x, y}]);
			enqueue(min(x+y,a), max(0,x+y-a), m[{x, y}]); //B->A로 붓기
			enqueue(max(0,x+y-b), min(x+y,b), m[{x, y}]); //A->B로 붓기
		}
		if (m[{c, d}]) return m[{c, d}] - 1;
		else return -1;
	}

	void sol() {
		cin >> a >> b >> c >> d;
		cout << bfs(0, 0);
	}
	
}

int main() {
	Sol::sol();


}
