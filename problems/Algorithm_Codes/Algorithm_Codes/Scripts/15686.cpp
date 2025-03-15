#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];

#pragma region MySol
	
vector<pair<int, int>> homes;
vector<pair<int, int>> chickens;

int min_cityDist = 99999999;
int ret;


int Cal(vector<pair<int, int>>& select) {

	int total = 0;

	//각 집 기준 치킨거리 계산
	for (auto home : homes) {

		int min_distance = 10000;

		for (auto s : select) {
			int dist = abs(home.first - s.first) + abs(home.second - s.second);
			min_distance = min(dist, min_distance);
		}

		total += min_distance;
	}


	return total;
}

//m개 선택하는 조합 구하기
void combi(int idx, vector<pair<int, int>>& select, int maxCnt) {
	if (select.size() == maxCnt) {
		//각 집의 치킨거리 계산하고, 이를 합산하여 도시의 치킨거리 계산
		int cityDist = Cal(select);

		//도시의 치킨거리 계산
		if (min_cityDist > cityDist) {
			min_cityDist = cityDist;
			ret = maxCnt;
		}
		return;
	}

	for (int i = idx + 1; i < chickens.size(); i++) {
		select.push_back(chickens[i]);

		combi(i, select, maxCnt);

		select.pop_back();
	}

}


void MySol() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) chickens.push_back({ i,j });
			else if (a[i][j] == 1) homes.push_back({ i,j });
		}
	}



	for (int i = 0; i <= m; i++) {
		vector<pair<int, int>> v;
		combi(-1, v, i);
	}

	cout << min_cityDist << "\n";
}
#pragma endregion

#pragma region Sol_1

//문제를 봤을 때, 무식하게 풀 수 있는가 를 먼저 봐야함
//문제 로직을 추상적으로 구상해보고, 그 시간 복잡도를 생각해보기

//치킨집 m개를 뽑고, 이걸 기반으로 모든 집과 거리를 비교해서 그 집 거리 중 가장 작은 거리를 더해서 도시의 치킨거리 구함

//n의 최대범위가 50이므로 맵의 최대범위는 2500, 얼핏보면 2500 C m을 구하는 것이라 생각해서 브루트포스가 안되겠다 생각할수 있음
//그러나 문제 제한조건을 봤을때, 실제로는 13 C r * 100(집의 최대개수) * r 의 시간복잡도를 갖는다  (r개의 치킨집을 뽑은 후, 각 집 별로 각 치킨집과의 거리 계산하므로 13Cr*100*r)
//따라서 worst 케이스는 13C6 or 13C7 * 100 * (6 or 7)  -> 13의 중앙 즈음이  13Cr의 가장 큰 값이 되니까 6 또는 7


//내 풀이와 다른 점 : 나는 남겨둘 치킨집의 개수를 0 ~ m 까지 증가시켜가며, 그때의 조합을 구해 최단거리를 구하는 방식으로 해결함
//이 풀이에서는 남겨둘 치킨집의 개수를 m으로 정함.
//왜냐하면, 치킨집을 최대한 많이 남겨둘수록 전체적인 도시의 치킨거리가 줄어들 것이기 때문임(치킨집이 많이 분포할수록 각 집에서의 치킨거리가 아무래도 짧을테니까)
//따라서, 결국 m개(최대개수)를 남기는 것이 최적해이기 때문에, 그 미만인 경우는 계산할 필요가 없음
//나는 bruteForce로 풀었지만, 이 풀이는  bruteForce 와 backtracking 모두를 적용해서 푼 풀이임. -> 훨씬 빠르다!

int result = 987654321;
vector<vector<int>>chickenList; //이중 vector : 조합들 ({0,1,2}, {0,1,3},...)등을 저장해놓아야 하기에 이중 벡터를 사용함
vector<pair<int, int>> _home, chicken;

void combi(int start, vector<int> v) {
	if (v.size() == m) {
		chickenList.push_back(v); //조합 저장
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

void Sol_1() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1)_home.push_back({ i, j });
			if (a[i][j] == 2)chicken.push_back({ i, j });
		}
	}

	vector<int> v;
	combi(-1, v);

	//만든 조합에 대해, 모든 집과의 거리 비교
	for (vector<int> cList : chickenList) {
		int ret = 0;

		for (pair<int, int> home : _home) {
			int _min = 987654321;
			
			//한 조합을 구성하는 원소들(이때 원소는 인덱스)을 통해 거리비교
			for (int ch : cList) {
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				_min = min(_min, _dist);
			}

			ret += _min;
		}

		result = min(result, ret);
	}

	cout << result << "\n";

}

#pragma endregion

int main() {
	
	Sol_1();

}