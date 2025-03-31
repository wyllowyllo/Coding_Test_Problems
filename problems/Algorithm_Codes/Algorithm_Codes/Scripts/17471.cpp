#include <bits/stdc++.h>
using namespace std;


int n, a, b;
int population[11];
vector<int> adj[11];


int visited[11];
char area[11];

const int INF = 1500;
int ret=INF;

int m, temp, comp[11];


#pragma region MySol

/*내가 생각한 로직 흐름
1. 비트마스킹으로 n개중 r개를 선택하는 조합 생성(r은 0 ~n)

2. 두 개의 집합으로 구분됨(1에서 선택한 번호 그룹, 그 외 번호 그룹)

3. 각 그룹의 번호끼리 연결되어있는지 확인

4. 3에서 각 그룹이 형성 가능하다면, 두 선거구의 인구 차이 계산
*/

//A,B선거구로 분할하고 각 선거구에 포함된 노드가 서로 연결되어있는지 확인하는 부분에서 오류 있었음
bool isConntected(vector<int>& v) { //BFS를 통해, v안의 노드들이 서로 연결되어 있는지 확인한다

	//처음 작성한 로직
	//오류 -> v에 포함되지 않는 노드들에 대해서도 탐색함
	/*memset(visited, 0, sizeof(visited));

	visited[v[0]] = 1;
	queue<int> q;
	q.push(v[0]);

	while (q.size()) {
		int num = q.front(); q.pop();

		for (int i = 0; i < adj[num].size(); i++) {
			int node = adj[num][i];
			if (visited[node]) continue;

			visited[node] = 1;
			q.push(node);
		}
	}


	for (int num : v) {
		if (!visited[num]) return false;
	}

	return true;*/

	//수정된 로직
	memset(visited, 0, sizeof(visited));
	visited[v[0]] = 1;
	queue<int> q;
	q.push(v[0]);

	int count = 1;

	while (!q.empty()) {
		int num = q.front(); q.pop();

		for (int i = 0; i < adj[num].size(); i++) {
			int node = adj[num][i];
			if (visited[node]) continue;

			// 노드가 그룹 v 안에 있는지 확인해야 함
			if (find(v.begin(), v.end(), node) != v.end()) {
				visited[node] = 1;
				q.push(node);
				count++;
			}
		}
	}

	// 그룹의 모든 노드를 방문했는지 확인
	return count == v.size();

}

void Cal() {
	int numA = 0, numB = 0;

	for (int i = 0; i < n; i++) {
		if (area[i] == 'A') numA += population[i];
		else numB += population[i];
	}

	ret = min(ret, abs(numA - numB));
}


void MySol() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> population[i];

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			adj[i].push_back(b - 1);
		}
	}

	//선거구 A를 만들 지역구 r개 선택
	for (int i = 0; i < (1 << n); i++) {

		fill(&area[0], &area[0] + 11, 'B');

		vector<int> A; vector<int> B;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				area[j] = 'A';
		}

		for (int i = 0; i < n; i++) {
			if (area[i] == 'A') A.push_back(i);
			else B.push_back(i);
		}

		//선거구B나 A에 포함된 지역이 없음
		if (B.empty() || A.empty()) continue;

		/*cout << '{';
		for (int v : A)
			cout << v << " ";
		cout << '}' << " ";

		cout << '{';
		for (int v : B)
			cout << v << " ";
		cout << '}' << "\n";*/


		//A선거구의  r개 지역구가 직접 연결되어 있는가?
		if (!isConntected(A)) continue;

		//B선거구의  n-r개 지역구가 직접 연결되어 있는가?
		if (!isConntected(B)) continue;



		//두 선거구의 인구 차이 계산
		Cal();

	}

	if (ret == INF) cout << -1 << "\n";
	else cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1

//이 문제는, 주어진 노드들에 대해서 2개의 connected component로 만드는 것이다
//즉, 노드들에 대해서 각각 빨간색, 파란색으로 색칠하여 두 가지의 노드 그룹으로 쪼개놓고(이때 이 그룹은 딱 2개로 되어야 한다), 나중에 방문할때 그 색깔로 색칠된 노드들에 대해서만 방문하는 식으로 한다

pair<int, int> dfs(int here, int value) {  //반환값 : {탐색한 노드 개수 , 인구수 합}
	visited[here] = 1;
	pair<int, int> ret = { 1,population[here] };
	for (int there : adj[here]) {
		if (comp[there] != value) continue; //다른색으로 칠해져있다면(다른 선거구라면) 패스
		if (visited[there]) continue;

		pair<int, int> _temp = dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}

	return ret;
}

void Sol_1() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> population[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;

			//양방향 간선
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	//선거구 A,B로 딱 2개가 생성되도록 함(i의 범위를 통해)
	for (int i = 1; i < (1 << n) - 1; i++) {
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);

		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { comp[j + 1] = 1; idx1 = j + 1; } //선거구 A에 포함될 지역 표시, 선거구 A dfs시작위치
			else idx2 = j + 1;// 선거구 B dfs시작위치
		}

		pair<int, int> comp1 = dfs(idx1, 1); //idx1에서 탐색시작. 1로 색칠된 노드 탐색
		pair<int, int> comp2 = dfs(idx2, 0); //idx2에서 탐색시작. 0으로 색칠된 노드 탐색

		if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));

	}
	cout << (ret == INF ? -1 : ret) << "\n";
}

#pragma endregion

int main() {

	Sol_1();
}