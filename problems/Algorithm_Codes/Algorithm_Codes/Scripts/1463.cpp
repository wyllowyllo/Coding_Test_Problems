#include <bits/stdc++.h>
using namespace std;


namespace My {
	int n;

	int dp[1000004];
	const int MAX = 1e9;
	int go(int num) {
		if (num == 1) return 0;

		int& ret = dp[num];
		if (ret != MAX) return ret;

		if (num % 3 == 0) ret = min(ret, go(num / 3) + 1);
		if (num % 2 == 0) ret = min(ret, go(num / 2) + 1);

		return ret = min(ret, go(num - 1) + 1);
	}

	void sol() {
		cin >> n;

		fill(&dp[0], &dp[0] + 1000004, MAX);
		cout << go(n) << "\n";
	}


	//BFS로 풀기

	/*
	하지만 BFS에서는 “필요할 때만 큐에 넣는 것”이 맞습니다.

핵심은 이거예요:

BFS는 무가중치 최단경로이므로, x를 pop한 시점의 dist[x]는 최종값입니다.

이때 간선 x→y를 따라갈지 말지는 개선되느냐로 결정합니다.
즉, if (dist[y] > dist[x] + 1) { dist[y] = dist[x] + 1; push(y); }

그래서 7의 경우도 처음엔 dist[6]가 INF이므로 개선이 되어 당연히 push됩니다.
나중에 다른 경로를 통해 6이 더 짧게 발견되었는데도 7→6을 무조건 push하면, 개선이 없는데도 중복으로 큐에 넣게 되어 비효율만 생깁니다 (정확성은 유지되지만 큐가 불필요하게 커짐).
	
	그리고 x == 1을 pop한 즉시 break하면, 레벨 순서 특성상 그게 최단이라 더 빠릅니다.
	*/
	int visited[1000004];
	queue<int> q;
	void sol_2() {
		cin >> n;


		fill(&visited[0], &visited[0] + 1000004, MAX);
		q.push(n);
		visited[n] = 0;
		
		while (q.size()) {
			int num = q.front();
			q.pop();

			if (num == 1) break;

			if (num % 3 == 0) {
				if (visited[num / 3] > visited[num] + 1) {
					q.push(num / 3);
					visited[num / 3] = visited[num] + 1;
				}
			}
			if (num % 2 == 0) {
				if (visited[num / 2] > visited[num] + 1) {
					q.push(num / 2);
					visited[num / 2] = visited[num] + 1;
				}
			}

			if (num - 1 >= 1 && visited[num - 1] > visited[num] + 1) {
				visited[num - 1] = visited[num] + 1;
				q.push(num - 1);
			}

		}


		cout << visited[1] << "\n";
	}
}



int main() {
	My::sol_2();
}