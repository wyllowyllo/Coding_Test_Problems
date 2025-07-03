#include <bits/stdc++.h>
using namespace std;


namespace My {
	//시간복잡도 잘못 계산해서, 완전탐색으로 함..

	/*나는 모든 도시가 서로 연결된 그래프가 워스트 케이스일 것이므로 이때의 각 정점의 간선은 n - 1개,
		즉 완전탐색할 경우 n개의 각 정점에서 다음 n개의 간선 중 하나(실제로는 방문 간선은 선택 안하므로 더 작겠지만) 선택하므로 n제곱.
		또 시작 위치를 n개의 도시 중 하나로 설정하므로 총 n세제곱이 될 거라고 봤고, n의 최대값이 16이길래 될 줄 알았어.*/

	//시작 노드 선택할 때 n, 그리고 각 노드 방문하면서 다음 노드 선택하는 경우의 수는 n-1, n-2 .....
	//따라서 n!임...

	//첫번째 시도 -> 완탐


	//두번째 시도-> DP
	//순회 경로는 결국 '사이클'이기 때문에, 어디서 출발하든 비용의 합은 바뀌지 않음
	//따라서 시작점은 그냥 0번으로 고정


	vector<int> adj[20];


	int dp[1<<16][20];  //첫번째 원소 : 방문한 도시 비트마스킹
						//두번째 원소 : 마지막에 머물러 있는 도시 번호

	/*
	dp[mask][j] = mask에 표시된 도시들을 모두 방문했고, 
               마지막으로 j에 있을 때 얻을 수 있는 최소 비용
	*/


	int n;
	int tmp;
	

	const int INF = 1e9;
	int ret = INF;
	/*void go(int startIdx, int curIdx, int visited, int cost, int cnt) {
		if (cost >= ret) return;
		if (cnt == n - 1) {
			if (adj[curIdx][startIdx]) {
				ret = min(ret, cost + adj[curIdx][startIdx]);
			}

			return;
		}

		visited |= (1 << curIdx);

		for (int i = 0; i < n; i++) {
			if (adj[curIdx][i] == 0) continue;
			if (visited & (1 << i)) continue;

			go(startIdx, i, visited, cost + adj[curIdx][i], cnt + 1);

		}
		return;
	}*/

	void Sol() {
		ios::sync_with_stdio(false);  cin.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {
				cin >> tmp;

				adj[i].push_back(tmp);
			}
		}

		int totalStates = (1 << 16) * 20;
		fill(&dp[0][0], &dp[0][0] + totalStates, INF);
		dp[1][0] = 0; //0번 도시를 출발점으로 고정
		

		for (int visited = 0; visited < (1 << n); visited++) { //현재까지 어떤 도시들을 방문했는지(방문한 도시의 모든 경우의 수 탐색)

			for (int i = 0; i< n; i++) {
				if (visited & (1 << i)) { //mask에 포함된 도시 하나 고름(mask에서 마지막에 머물러 있을 수 있는 도시 i를 고름)

					for (int j = 0; j < n; j++) {
						if (!(visited & (1 << j)) && adj[i][j] > 0) {
							//i에서 방문하지 않은 도시 j로 간다고 가정 i->j

							//"방문 집합에 j를 추가한 상태”에서 마지막이 j일 때의 최소 비용을 갱신

							/*
								mask 안에 마지막이 j인 경로를 만들려면
								우선 mask\{j}(즉, j를 뺀 집합)에서 어떤 도시 i에서 시작해
								“최소 비용으로” 그 부분 경로를 완성한 뒤
								한 걸음 더 i->j 간선 비용을 더하면 됩니다.
							*/
							int newVisited = visited | (1 << j);
							dp[newVisited][j] = min(dp[newVisited][j], dp[visited][i] + adj[i][j]); //이미 j를 방문하고 J에 머무르는 상태에서의 비용을 구한 상태라면, 그값과 현재값 비교하여 작은 경로값으로 갱신
						}
					}
					
				}
			}
		}

		int fullMask = (1 << n) - 1; //모든 도시 방문
		for (int i = 0; i < n; i++) {
			if (adj[i][0] == 0) continue;  // 돌아올 수 없으면 스킵
			ret = min(ret, dp[fullMask][i] + adj[i][0]);
		}

		cout << ret << "\n";
	}


	/*
2. 왜 이 정의가 최적을 보장하나?
(1) 최적 부분 구조
“어떤 순회 경로”를 생각해 봅시다.

예컨대 경로가
0→2→5→3→0 이라면,
이 전체 순회가 최소 비용이라면,
그 부분 경로
0→2→5 역시 “0에서 출발해서 {0,2,5}를 모두 방문하고 마지막이 5일 때” 최소 비용 경로여야 합니다.

만약 그 부분이 최소가 아니었다면, 더 작은 비용의 다른 부분 경로를 끼워 넣어 전체를 줄일 수 있으므로 모순이 생깁니다.

이게 DP의 핵심 아이디어예요.

“전체 최적 경로의 처음 몇 단계 역시 그 부분 집합에 대한 최적 경로” 라는 성질을 이용하는 겁니다.


------------------------------------------------------------------

1. 초기 상태부터 시작해

2. 작은 집합부터 차례로 “최소 경로”를 계산

3. 언제나 각각의 부분 집합 상태를 최소로 유지

4. 마지막에 “전체 집합 → 다시 출발점으로” 를 통해 순회 사이클 완성

*/

}

namespace Sol {
	//DP란? 부분최적해를 기반으로, 이 최적해들을 쌓고 쌓고 쌓아서 글로벌한 최적해를 만드는 것!

	/*
	a에서 d까지 간다고 했을 때(a->d)
	a->b->c->d 와 
	a->c->b->d 중 최소를 구하면 됨.

	이때 (a,b,c) -> d 와  (a,c,b) -> d 는 차이가 있을까? (즉 이전에 방문한 노드 집합 a,b,c의 순서는 상관 있을까?)

	a->b->c와 a->c->d는 물론 경로가 다르므로 코스트도 다르겠지만,
	a,b,c를 다 방문하고 d를 간다 라고 했을 때, 우리는 a,b,c를 다 방문하는 루트 중 최소 루트를 찾아서 그 다음 d를 방문하면 된다!
	결국 (a,b,c) -> d 와  (a,c,b) -> d는 순서가 상관이 없는 것이다!

	이 문제의 최대범위는 n<=16이고, 이 문제가 순서가 상관이 있다고 하면 시간복잡도는 16!이다.
	그러나 a,b,c를 방문하고 d를 방문한다고 했을 때 순서에 상관없이 집합 (a,b,c)의 최솟값에다가 d로 가도 되는 것임

	즉 부분최적해 (a,b,c)에다가 d로 가고, 또 부분최적해 (a,b,c,d)에다가 e로 가고... 이런식임.

	따라서 순서를 신경쓸 필요 없고, 어떤 노드를 집합에 포함하냐, 포함하지 않냐에 따라 만들어진 방문노드 집합에 대해, 다음노드 d로의 코스트를 더하는 식으로 하면 됨.
	따라서 시간복잡도는 2^n

	/*
	이 문제는 출발점이 지정되어 있지 않음
	그래서 각 지점이 출발점일 때를 모두 고려해야 하는 것 처럼 보임

	그러나 사이클을 보면 알겠지만, (2->3->1->2)나 (3->1->2->3)은 코스트가 같다. 즉 출발점은 상관이 없다.

	*/

	//이 풀이를 보면 완전탐색과 비슷한 구조이나, 메모라이제이션을 도입하여 중복 연산을 하지 않는다.

	int n, dp[16][1 << 16], dist[16][16];
	const int INF = 987654321;
	/// <summary>
	/// 
	/// </summary>
	/// <param name="here"> 인덱스 </param>
	/// <param name="visited">방문 집합 </param>
	/// <returns></returns>
	int tsp(int here, int visited) {
		if (visited == (1 << n) - 1) { //모든노드 방문
			
			return dist[here][0]?dist[here][0]:INF; //만약 현재노드에서 다시 시작노드로 돌아갈 수 없다면 INF반환(즉 이 경로는 정답 후보에서 무조건 제외되도록 매우 큰 코스트 반환시켜버림)

			// tip : dp의 탑다운 방식으로 문제를 풀 때,  기저사례에서 해당 경우가 답이 되지 않게 제외시키려면 -> 현 문제가 최대를 구하는 문제라면 답이 될 수 없는 최소를 반환시키고, 최소를 구하는 문제라면 답이 될 수 없는 최대를 반환시킨다.
		}

		//만약 visited를 방문했고 현재 위치가 here일때의 최소 비용을 이미 구했다면, 그거 리턴
		int& ret = dp[here][visited];
		if (ret != -1) return ret;

		ret = INF;
		for (int i = 0; i < n; i++) {
			//다음 방문할 노드 i 결정(방문한 적 없고, 경로 있는 노드 i)
			if (visited & (1 << i)) continue;
			if (dist[here][i] == 0) continue;


			ret=min(ret,tsp(i, visited | (1 << i)) + dist[here][i]);
		}

		return ret;
	}

	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> dist[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));
		cout << tsp(0, 1) << '\n';
	}
}

namespace MySol{
	int n;
	int tmp;
	vector<int> adj[20];
	int dp[20][1 << 16];

	int go(int here, int visited) {
		if (visited == (1 << n) - 1) {
			if (adj[here][0]) return adj[here][0];
			return 1e9;
		}

		int& ret = dp[here][visited];
		if (ret != -1) return ret;

		ret = 1e9;
		for (int i = 0; i < n; i++) {
			if (visited & (1 << i)) continue;
			if (adj[here][i] == 0) continue;

			ret= min(ret,go(i, visited | (1 << i))+adj[here][i]);
		}

		return ret;
	}

	void Sol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				adj[i].push_back(tmp);
			}
		}

		memset(dp, -1, sizeof(dp));

		cout << go(0, 1) << "\n";

		return;
	}
}


int main() {
	//My::Sol();
	//Sol::sol();
	MySol::Sol();
}


