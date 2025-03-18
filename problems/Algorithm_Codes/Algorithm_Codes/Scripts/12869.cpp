#include <bits/stdc++.h>
using namespace std;


//int n;
//vector<int> scv; //scv의 체력
//
//int cnt = 0;
//int ret = 999999;
//
//
//#pragma region MySol
//
////아 이게 나는 순열을 활용한 문제인거라 생각하고, 순열을 모두 구한 후 각 순열의 순서에 따라 scv의 체력을 감소시켰는데,
////이게 보니까 순열 문제가 아니구나...
////그냥 첫번째,두번째,세번째 공격할 대상을 매번 맘대로 정할수 있네
////즉 첫번째 공격당할 scv, 두번쨰 공격당할 scv, 세번째 공격당할 scv 이렇게 정해놓고 체력 깎는게 아니라
////그냥 매번 공격타임마다 뭘 첫번째로 공격할지 정할수있구나
////그렇게 해서 최소한의 공격으로 모든 scv를 죽이면 되는 문제
//
////두번째 시도 : 매번 체력 많은 순으로 내림차순 정렬시키기
////아 이것도 아님... 
//
////세번째 시도 : 매 타임마다 순열을 생성 -> 첫번째와 달리, 공격할 떄마다, 남은 체력에 대해서 공격순서 순열을 만듦
////순열 만들고 공격, 남은 체력에 대해 또 순열 만들고 각 케이스마다 공격... 이걸 반복
//
////scv는 최대 3개이므로 순열의 개수는 3! == 6
////scv최대체력은 60
////워스트 케이스일때 시간복잡도는 3! ^ 60  (60번 공격해야 모두 죽일 수 있다고 가정하면, 매번 공격할때마다 순열을 만듦), 3!의 60 승 ==6의 60승  --> 이건 말이 안되는데....
////재귀로 permutation 만들어가다, 최소 공격 횟수 초과하는 순서일 경우엔 pruning?
//
////네번째 시도 : 일단 scv 순열 구해서 모두 저장해놓은다음, 매 차례 어떤 순서로 공격할지 정함
////예제는 다 맞게 처리하는데, 시간초과나네...
////아 죽은 scv는 제외해야지!
////그래도 시간초과되는데.. 모든 경우의 수를 찾는식으로 하면 안되나..?
//
////처음 시간 복잡도를 계산할 때 , 체력이 60이고 매번 1씩 감소한다고 가정하면(실제로는 체력이 빠르게 줄어들어 공격을 60번씩 하진 않겠지만)
////매 공격마다 3!의 공격 순서를 모두 고려하므로 3!의 60 승이라고 생각했음 (메모이제이션 없이 재귀로만 해결하려하면 이게맞음)
////그러나 실제로는 scv의 체력은 0~60이므로, scv의 상태의 총 개수는 61*61*61 임
////즉 시간복잡도는 (61의 3승) * 3! (메모이제이션(혹은 DP)를 사용한다면)
//
//
//vector<int> scvIdx; //scv 인덱스
//
//vector<vector<int>> perm; //순열 저장
//
//bool isAllDie() {
//
//	for (int i = 0; i < scv.size(); i++) {
//		if (scv[i] > 0)
//			return false;
//	}
//
//	return true;
//}
//void Permutation() {
//	
//	sort(scvIdx.begin(), scvIdx.end());
//
//	//모든 경우의 수 저장
//	do {
//		perm.push_back(scvIdx);
//	} while (next_permutation(scvIdx.begin(), scvIdx.end()));
//}
//
//void Print() {
//	for (int i = 0; i < scv.size(); i++) {
//		cout << scv[i] << " ";
//	}
//	cout << "\n";
//}
//void Attack(int& atkCnt) {
//
//	if (atkCnt >= ret) {
//		return;
//	}
//
//	if (isAllDie()) {
//		ret = min(atkCnt, ret);
//		return;
//	}
//
//
//	for (int i = 0; i < perm.size(); i++) {
//
//		//공격
//		vector<int>& attackSeq = perm[i];
//		map<int, bool> destroyed;
//
//		int damage = 9;
//		for (int j = 0; j < n; j++) {
//			if (scv[attackSeq[j]] <= 0) { //scv 파괴되었으면 데미지 줄 필요 x
//				destroyed[attackSeq[j]] = true;
//				continue;
//			}
//
//
//			scv[attackSeq[j]] -= damage;
//			damage /= 3;
//		}
//		atkCnt++;
//
//		Attack(atkCnt);
//
//		//복구
//		int heal = 9;
//		for (int j = 0; j < n; j++) {
//			if (destroyed[attackSeq[j]]) { //파괴되어서 데미지 안받은 scv는 복구필요 x
//				continue;
//			}
//
//			scv[attackSeq[j]] += heal;
//			heal /= 3;
//		}
//		atkCnt--;
//
//
//	}
//}
//
//void MySol() {
//	cin >> n;
//
//	int health;
//	for (int i = 0; i < n; i++) {
//		cin >> health;
//		scv.push_back(health);
//		scvIdx.push_back(i);
//	}
//
//	Permutation();
//
//	int atkCnt = 0;
//	Attack(atkCnt);
//
//	cout << ret << "\n";
//}
//#pragma endregion
//
//#pragma region MySol_2 
////문제를 풀지못해 강의를 보고 해결책을 찾음
//
////내 풀이의 경우 예제는 모두 해결했으나, 시간초과가 뜸.
////내 풀이대로 했을 때 워스트 케이스에서 시간 복잡도가 너무 커짐
////즉, 다른 풀이로 바꿔야함을 깨닫고 접근법을 바꿨어야 한다!
//
////각 단계에서의 scv의 남은 체력이 정점이 될 테고, 그 정점에 연결된 간선은 6개(공격패턴이 (9,3,1) 이므로, 3! = 6) 이다.
////각 단계에서 6개 간선 중 1개 선택하면 그 공격 패턴을 선택하는 방식이 되고, 그렇게 해서 다음 노드로 이동했을 때 그 노드는 공격을 맞고 남은 체력이 된다.
////이 문제의 목표는, scv의 체력이 (0,0,0) 이 되는 가장 작은 공격횟수를 구하는 것이다
////즉 (0,0,0)이라는 노드에 도달하기까지 걸리는 최소경로의 길이를 구하는 것이다.
////각 간선(한 노드당 6개 간선)의 가중치는 모두 같다(공격 1회 하는거니까)
////즉 이 문제는, 내 풀이처럼 dfs가 아니라 bfs로 접근해야 한다!!!
//
////그렇게 해서 코드 짰는데, 메모리 초과 뜸;;
////이건 나에게 허락된 수준의 문제가 아닌가..
//vector<int> atk = { 9,3,1 };
//vector<vector<int>> atkPattern;
//
//bool AllKill(vector<int>& health) {
//	for (int i = 0; i < health.size(); i++) {
//		if (health[i] > 0)
//			return false;
//	}
//
//	return true;
//}
//
//void BFS() {
//	
//	queue<pair<vector<int> ,int>> remain;
//	remain.push({ scv,0 });
//
//	while (remain.size()) {
//		vector<int> health = remain.front().first; 
//		int atkCnt = remain.front().second;
//		remain.pop();
//
//		if (AllKill(health)) {
//			ret = min(ret, atkCnt);
//			return;
//		}
//
//		for (int i = 0; i < atkPattern.size(); i++) {
//			vector<int>& atkSeq = atkPattern[i];
//			vector<int> temp = health;
//
//			//공격
//			for (int j = 0; j < n; j++) {
//				temp[j] -= atkSeq[j];
//			}
//			
//			remain.push({ temp,atkCnt+1});
//		}
//
//	}
//
//	
//	
//}
//
//void MySol_2() {
//	cin >> n;
//
//	int health;
//	for (int i = 0; i < n; i++) {
//		cin >> health;
//		scv.push_back(health);
//	}
//
//	sort(atk.begin(), atk.end());
//	//공격패턴 6개 저장
//	do {
//		atkPattern.push_back(atk);
//	} while (next_permutation(atk.begin(), atk.end()));
//
//	BFS();
//
//	cout << ret << "\n";
//}
//
//
//#pragma endregion

#pragma region Sol_1

//scv의 체력 상태를 노드화시킴. 이때 각 노드의 간선은 6개이고 각 간선은 공격패턴을 의미 3차원 행렬로 그래프 표현
//현재 노드(체력상태) 가 12,10,3이고, {9,3,1} 이렇게 공격한다면 다음에 이동할 노드는  3,7,2 가 된다
//visited배열로 해당 노드까지 도달할 때까지의 가중치를 표현. 이때 이 가중치는 공격 횟수가 됨
//scv한 대의 체력은 0 ~ 60이므로, scv가 총 3대일 때 상태의 경우의 수는 60*60*60
//scv 체력이 모두 0일때, 즉 {0,0,0}노드에 도달하기까지의 가중치가 문제의 답이 된다.

int n;
const int INF = 987654321;
int dp[64][64][64], scvH[3]; 
int visited[64][64][64];

//공격패턴
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

//3차원 좌표, scv가 3대라면 각각의 체력상태
struct A {
	int a, b, c;
};

queue<A> q;

int solve(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });

	while (q.size()) {
		//현재 위치
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (visited[0][0][0]) break; //모든 scv가 0이라면 탈출

		for (int i = 0; i < 6; i++) {
			//최소값 0
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}

	return visited[0][0][0] - 1;

}
void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> scvH[i];

	cout << solve(scvH[0], scvH[1], scvH[2]) << "\n";
	return;

}
#pragma endregion



int main() {
	
	Sol_1();

}