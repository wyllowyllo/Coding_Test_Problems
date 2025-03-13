#include <bits/stdc++.h>
using namespace std;

#pragma region MySol
//현재는 모든 노드를 대상으로, 그 노드를 루트로 해서 탐색하는 방식 ->시간초과남
	//근데, 특정 노드가 누군가의 자식이라면, 어차피 그 부모 노드가 더 값이 클건데 그럴경우 굳이 이 노드를 탐색해볼 필요는 없음
	//흠... 결국 부모 노드가 없는 노드의 경우에만 탐색하고, 거기서 우열을 정하면 되지 않나?
	//위처럼 바꿨는데도 시간초과남...
	//트리 구축하고, 탐색하는 방식 말고 다르게 해야하나..?


	//그래프 indgree의 수를 합산하는 방식?
	//트리는 단방향그래프니까 edge를 합산? 근데 edge는 결국 자식수랑 같잖아
	//자식수만 합산?

	//아 근데 문제를 다시보니, 이거 트리로 구현하면 안되네..그래프로 구현해야할듯

	//수정) 흠... 결국 부모 노드가 없는 노드의 경우에만 탐색하고, 거기서 우열을 정하면 되지 않나?
	//윗부분에서 답이 틀리게 나오는 경우 있어서 수정함
	// 아 이거 visited없이 그냥 다 방문하니까 시간초과나는거였네... 방문했던 곳 다시 방문 안하니까 성공함                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
vector<int> graph[10001];
int visited[10001];
int n, m;
int a, b;

int cnt = 0;
int maxCnt = -1;
vector<int> coms;

map<int, vector<int>> m1; //대상 노드, 부모 노드들

void dfs(int startNode) {
	visited[startNode] = 1;
	cnt++;
	for (int n : graph[startNode]) {

		if (!visited[n])
			dfs(n);
	}

	
}

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		graph[b].push_back(a); //b를 상위노드로 하고, 그 하위노드로 a추가
		m1[a].push_back(b); //a의 상위 노드로 b 추가
	}



	for (int i = 1; i <= n; i++) {
		//i번 노드의 상위노드가 없을 때만 dfs시작
		
			cnt = 0;
			memset(visited, 0, sizeof(visited));

			dfs(i);
			if (maxCnt < cnt) {
				coms.clear();
				coms.push_back(i);
				maxCnt = cnt;
			}
			else if (maxCnt == cnt) {
				coms.push_back(i);
			}
		



	}

	sort(coms.begin(), coms.end());
	for (auto c : coms) cout << c << " ";

}
#pragma endregion


int dp[10001];
#pragma region Sol_1

//문제 범위를 보고, worst case에서 시간복잡도 생각해보기
//노드 수 최대값이 10000개고, 이를 모두 dfs한다 했을 때 최악의 경우 dfs당 10000의 시간복잡도 걸림(모든노드 방문)
//즉 worst case일 때 시간복잡도는 10000 * 10000 = 1억
//1억 이하라면, brute force로 풀릴 가능성 높으므로 일단 시도해보기!

int mx;

int go(int here) {
	visited[here] = 1;
	int ret = 1;

	for (int there : graph[here]) {
		if (visited[there]) continue;
		ret += go(there);
	}
	return ret;
}
void Sol_1() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = go(i);
		mx = max(dp[i], mx);
	}

	//나는 최댓값을 계속 갱신해나가며, 그 최댓값과 같은 리턴값을 지닌 노드의 번호를 vector로 저장해놓다가, 최댓값이 갱신되면 그 벡터도 초기화시켜 다시 쌓아가는 식으로 했음
	//출력할때는 그 벡터를 sort해서 출력했음
	//여기서는 그냥 각 노드의 return값을 저장해놓고, 그 배열을 검사하며 최댓값과 같으면 출력하는 식으로 함
	//초기화&정렬 과정이 없으므로 이게 더 효울적인 코드 (공간복잡도는 좀 더 크지만)
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " ";
}

#pragma endregion


int main() {
	
	MySol();


}