#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;
int n;
vector<int> a[MAX];

int mp, mf, ms, mv;


#pragma region MySol

//비트마스킹을 활용하여, nCr의 조합 구할 때 r이 0~n일때의 조합을 빠르게 구함
//첫번째 시도는 실패했는데, 같은 cost일때 사전순으로 정렬하는 조건을 추가하니 성공

typedef struct A {
public:
	vector<int> ingredients;
	int cost;

	A(vector<int> v, int cost) {
		ingredients = v;
		this->cost = cost;
	}
};

vector<A> ret;



bool check(vector<int>& v) {

	vector<int> temp;
	int sum[4] = { 0,0,0,0 };

	for (int i = 0; i < v.size(); i++) {
		temp = a[v[i]];
		for (int j = 0; j < 4; j++) {
			sum[j] += temp[j];
		}

	}

	if (sum[0] < mp) return false;
	if (sum[1] < mf) return false;
	if (sum[2] < ms) return false;
	if (sum[3] < mv) return false;


	return true;
}

bool cmp(A& a, A& b) {
	if (a.cost != b.cost) return a.cost < b.cost;
	return a.ingredients < b.ingredients; // 비용이 같을 때 사전순으로
}

void MySol() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	int temp;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 5; j++) {
			cin >> temp;
			a[i].push_back(temp);
		}
	}


	//n개중 r개 선택했을 때, 최소 영양성분을 만족하는 조합 찾기

	for (int i = 0; i < (1 << n); i++) { //i는 r개를 뜻함(0개~n개) //몇번째 재료를 선택할 것인가?
		vector<int> idx;

		for (int j = 0; j < n; j++) { //i의 1이 켜진 위치 검사하기(켜져있다면, 그거 포함시키기!)
			if (i & (1 << j)) {
				idx.push_back(j);
			}
		}

		if (check(idx)) {

			//비용 계산
			int cost = 0;
			for (auto v : idx) {
				cost += a[v][4];
			}

			//{재료조합, 비용} 저장

			ret.push_back(A(idx, cost));
		}

	}

	//cost에 대해 오름차순 정렬
	sort(ret.begin(), ret.end(), cmp);

	//결과 출력
	if (ret.size()) {
		cout << ret[0].cost << "\n";

		for (int idx : ret[0].ingredients)
			cout << idx + 1 << " ";
		cout << "\n";
	}
	else cout << -1 << "\n";
}

#pragma endregion

#pragma region MySol_2

//재귀로 조합 구해서 짜보기
//이게 더 빠르네...?

void combi(int idx, int r,int cost,vector<int>& v) {

	if (v.size() == r) {
		if (check(v)) {
			ret.push_back(A(v,cost));
		}
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		v.push_back(i);
		cost += a[i][4];

		combi(i, r, cost,v);

		v.pop_back();
		cost -= a[i][4];
	}
}
void MySol_2() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	int temp;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 5; j++) {
			cin >> temp;
			a[i].push_back(temp);
		}
		
	}

	//n개중 r개 선택하는 조합
	for (int i = 0; i <= n; i++) {
		vector<int> v;
		combi(-1,i,0,v);
	}

	sort(ret.begin(), ret.end(),cmp);

	if (ret.size()) {
		cout << ret[0].cost << "\n";

		for (int idx : ret[0].ingredients)
			cout << idx + 1 << " ";
		cout << "\n";
	}
	else cout << -1 << "\n";


}
#pragma endregion


#pragma region Sol_1
typedef long long ll;
const int INF = 987654321;

int c, d, e, f, result = INF, sum;
struct B {
	int mp, mf, ms, mv, cost;
}b[16];

map<int, vector<vector<int>>> ret_v;

void Sol_1() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		cin >> b[i].mp >> b[i].mf >> b[i].ms >> b[i].mv >> b[i].cost;
	}

	//내 코드와 다른 점 1 : 문제 조건에서 mp+mf+ms+mv>0이라고 했으므로, i==0일때는 계산할 필요없다
	for (int i = 1; i < (i << n); i++) {
		c = d = e = f = sum = 0;
		vector<int> v;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				v.push_back(j + 1);
				c += b[j].mp;
				d += b[j].mf;
				e += b[j].ms;
				f += b[j].mv;
				sum += b[j].cost;
			}
		}

		if (c >= mp && d >= mf && e >= ms && f >= mv) {

			//내 코드와 다른 점 2 : 최솟값을 저장하는 result보다 작은 값 발견시 result를 갱신하고, map을 통해 해당 최솟값을 만족하는 조합을 저장
			//-> 이후 정렬 시 정렬할 원소 수가 내 버전보다 훨씬 작음 -> 더 빠른 결과 출력!
			if (result >= sum) {
				result = sum;
				ret_v[result].push_back(v);
			}
		}
	}

	if (result == INF) cout << -1 << '\n';
	else {
		sort(ret_v[result].begin(), ret_v[result].end());
		cout << result << "\n";
		for (int a : ret_v[result][0]) {
			cout << a << " ";
		}
	}
}

#pragma endregion


int main() {
	//MySol();
	//MySol_2();
}