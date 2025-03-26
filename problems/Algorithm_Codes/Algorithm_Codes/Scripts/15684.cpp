#include <bits/stdc++.h>

using namespace std;

int n, m, h;

int _a[31][11][11]; //가로선 위치번호, 세로선번호 1, 세로선번호 2

vector<pair<int, int>> additionalEdges; //가로선 추가 가능한 위치 리스트
//int ret =9999999;
bool flag = false;


const int INF = 987654321;
int a, b, ret = INF, visited[34][34];

#pragma region MySol

//첫번째 시도 : 3차원 배열로 사다리를 구현하고, DFS를 하며 가로선 추가 가능한 위치에 하나씩 놓아보며 그때마다 사다리게임 수행하며 결과 확인
//시간 초과


//두번째 시도 : 일단 가로선 추가 가능한 위치를 따로 저장하고, 거기서 최대 3개를 뽑는 조합을 구해 가로선을 추가했을떄의 결과를 비교 
//성공!
//구현 까다롭네 .... 하루종일걸림

int go(int num, int depth) {
	//사다리 내려가기

	//끝까지 도달
	if (depth == h - 1) {

		return num;
	}
	for (int i = depth + 1; i < h; i++) {
		for (int j = 0; j < n; j++) {
			if (_a[i][num][j]) {
				return go(j, i);
			}

		}

	}

	return num;
}

void PrintResult() {
	//각 번호별로 사다리 타서 결과 보기
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " : " << go(i, -1) + 1;
		cout << "\n";
	}
}

void MakeEdgeList() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			int k = j + 1;
			if (_a[i][j][k]) continue; //이미 가로선이 있으면 패스
			if (j > 0 && _a[i][j - 1][k - 1]) continue; //가로선 추가할 곳 왼쪽에 가로선이 있으면 패스
			if (_a[i][j + 1][k + 1]) continue; //가로선 추가할 곳 오른쪽에 가로선이 있으면 패스

			additionalEdges.push_back({ i,j });

		}
	}
}
bool GameStart() {
	for (int i = 0; i < n; i++) {
		if (go(i, -1) != i) return false; //i번 세로선의 결과는 i가 아님
	}

	return true; //i번 세로선의 결과는 i
}

void DFS(int cnt) {

	//1. dfs로 가로선 추가 (최대 3개)
	//2. 생성된 가로선에 대해 사다리타기 실행
	//3. i번 세로선 결과가 i번이 되거나, 추가하는 가로선이 3개를 넘어가면 종료

	if (cnt > 3) return;
	if (cnt >= ret) return;

	//모든 세로선 i번이 i번에 도달함
	if (GameStart()) {
		ret = min(cnt, ret);
		flag = true;
		return;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			int k = j + 1;
			if (_a[i][j][k]) continue; //이미 가로선이 있으면 패스
			if (j > 0 && _a[i][j - 1][k - 1]) continue; //가로선 추가할 곳 왼쪽에 가로선이 있으면 패스
			if (_a[i][j + 1][k + 1]) continue; //가로선 추가할 곳 오른쪽에 가로선이 있으면 패스

			_a[i][j][k] = 1;
			_a[i][k][j] = 1;

			DFS(cnt + 1);

			_a[i][k][j] = 0;
			_a[i][j][k] = 0;

		}
	}
}

void AddEdgeAndTest(vector<int>& v) {
	//가로선 추가
	for (auto idx : v) {
		pair<int, int> line = additionalEdges[idx];

		_a[line.first][line.second][line.second + 1] = 1;
		_a[line.first][line.second + 1][line.second] = 1;

	}

	//테스트
	if (GameStart()) {
		ret = min((int)v.size(), ret);
		flag = true;
	}

	//복구
	for (auto idx : v) {
		pair<int, int> line = additionalEdges[idx];

		_a[line.first][line.second][line.second + 1] = 0;
		_a[line.first][line.second + 1][line.second] = 0;

	}
}

void combi(int startIdx, int cnt, vector<int>& v) {

	if (cnt >= ret) return;

	if (cnt == v.size()) {

		AddEdgeAndTest(v);
		return;
	}

	for (int i = startIdx + 1; i < additionalEdges.size(); i++) {
		v.push_back(i);
		combi(i, cnt, v);
		v.pop_back();
	}


}

void MySol() {
	cin >> n >> m >> h;

	int pos;
	int edge;

	//입력값에 따라 가로선 위치 초기화하기
	for (int i = 0; i < m; i++) {
		cin >> pos >> edge;
		_a[pos - 1][edge - 1][edge] = 1;
		_a[pos - 1][edge][edge - 1] = 1;
	}

	MakeEdgeList();

	//0개 ~ 3개의 가로선을 선택하는 조합 생성 후, 각 조합의 가로선 추가했을 때 사다리게임 결과 보기
	for (int i = 0; i <= 3; i++) {
		vector<int> v;
		combi(-1, i, v);
	}

	//DFS(0);

	if (flag) cout << ret << "\n";
	else cout << -1 << "\n";
}
#pragma endregion

#pragma region Sol_1

//나는 3차원 배열을 사용하여 사다리를 구현하였으나, 이 풀이에서는 2차원 배열만으로 사다리 표현함({높이, 세로선번호})
//나는 가로선 놓을 때 from,to 표현하기위해 (높이,from,to)이렇게 3차원 배열을 썻지만, 어차피 to 는 from+1이니까 굳이 3차원배열쓸 필요없이 2차원 배열쓰는게 공간복잡도 상 더 좋음

//나는 처음에 dfs로 구현하면 시간초과나길래, 방법을 바꿔서 조합을 먼저 구하고, 그 조합에 따른 결과를 비교하는 방식으로 함
//여기서는 dfs로 하되, 다음 재귀 호출에서는 이전의 높이값을 전달하여 그 높이 이후부터 탐색하도록 함
//내 dfs는 재귀호출할때마다 이전 진행값부터 검사하는게아니라 처음부터 모든 경우를 싹 검사해서(이미 검사 이전에 했는데 여기서 또함) 시간 초과남

//사다리 따라 내려가보기. 나는 재귀호출하는식으로 했지만 여기서는 반복문으로 처리함
bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start]) start++; //가로선타고 오른쪽으로 이동
			else if (visited[j][start - 1]) start--; //가로선타고 왼쪽으로 이동

		}

		if (start != i) return false;
	}

	return true;
}


void go_2(int here, int cnt) { //시작 높이, 현재까지 놓은 가로선 개수
	if (cnt > 3 || cnt >= ret) return;
	if (check()) {
		ret = min(ret, cnt); return;
	}

	for (int i = here; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go_2(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

void Sol_1() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b; visited[a][b] = 1;

	}

	go_2(1, 0);
	cout << ((ret == INF) ? -1 : ret) << "\n";
}
#pragma endregion



int main() {
	
	Sol_1();
}