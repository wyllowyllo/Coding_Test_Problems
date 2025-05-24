#include <bits/stdc++.h>
using namespace std;

int n, k;
int ret;


#pragma region MySol
//가설 1 : 플러그 자리 없을 때마다, 자주 쓰는 전기용품은 최대한 뽑지 말고 그대로 두고, 자주 안쓰는 플러그부터 빼버리면 플러그 빼는 횟수가 최소가 될 것이다


// 처음에는 각 전기용품의 전체 사용횟수가 가장 작은 것이 pq의 top에 위치하도록 했음..
// 생각해보니... 사용횟수를 갱신해가며 '남은 사용횟수'가 가장 작은 것을 먼저 뽑아버리는 식으로 해야 할듯함
// 2 3 2 3 1 2 7 이런식으로 입력이 주어진다고 하면 2번 전기용품 쓸때마다 사용횟수 감소시켜, 남은 사용횟수가 많은 전기용품은 뽑지말고, 이제 몇번 또 안쓸 전기용품을 먼저 뽑아버려야 할듯
//근데 우선순위큐 쓰면 갱신을 못하는데..

//시간복잡도 계산해보니,  그냥 매번 남은 사용횟수별로 sort해서 pop해도 될수도?
//틀림... 
// 반례 : 남은 사용 횟수만으로 판단하면, 남은 횟수가 같은 두 플러그 A, B가 있을 때 “가장 늦게” 다시 쓰일 A가 아니라 “곧” 쓰일 B를 뽑아버릴 수 있습니다.
// 즉, 가장 '나중에'다시 쓰일 전기용품을 뽑아버리고 '곧'쓰일 전기용품은 그대로 두어야 함

//가설 2 : 전기용품 재사용 시점이 멀지 않은 전기용품은 그대로 두고, 가장 나중에 다시 쓰일 전기용품부터 뽑아버린다
//성공!



vector<int> vv; //멀티탭

int use[101]; //현재 사용중인 전기용품 
//int m[101]; //남은 사용횟수
queue<int> m[101]; //각 전기용품의 사용 시점


void MySol() {
	cin >> n >> k;

	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		//m[v[i]]++;
		m[v[i]].push(i);
	}

	/*
	첫번째 시도(가설 1)

	for (int i : v) {

	if (use[i]) {
		m[i]--;
		continue;
	}

	if (vv.size() < n) {
			vv.push_back(i);
			use[i] = 1;
			m[i]--;
		}
		else {
			sort(vv.begin(), vv.end(), [](int a, int b) {
				return m[a] > m[b]; });

			use[vv.back()] = 0;
			vv.pop_back(); //남은 사용횟수 가장 작은 것 pop
			ret++;

			vv.push_back(i);
			use[i] = 1;
			m[i]--;
		}

		}

		cout << ret << "\n";


	*/


	//두번째 시도

	for (int i : v) {
		if (use[i]) {
			m[i].pop();

			if (m[i].empty()) //이 기기는 이제 다시 쓰지 않음
				m[i].push(101); //재사용시점 가장 뒤로 가도록 설정

			continue;
		}

		if (vv.size() < n) {
			vv.push_back(i);
			use[i] = 1;
			m[i].pop();

			if (m[i].empty()) //이 기기는 이제 다시 쓰지 않음
				m[i].push(101); //재사용시점 가장 뒤로 가도록 설정
		}
		else {
			sort(vv.begin(), vv.end(), [](int a, int b) {
				return m[a].front() < m[b].front(); });

			use[vv.back()] = 0;
			vv.pop_back();
			ret++;

			vv.push_back(i);
			use[i] = 1;
			m[i].pop();
			if (m[i].empty()) //이 기기는 이제 다시 쓰지 않음
				m[i].push(101); //재사용시점 가장 뒤로 가도록 설정
		}
	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol_1

int a[104];
int visited[104];
int cnt;
const int INF = 987654321;
vector<int> v;


void Sol_1() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < k; i++) {
		if (!visited[a[i]]) {

			if (v.size() == n) {
				int last_idx = 0, pos;
				for (int _a : v) {
					int here_pick = INF;

					for (int j = i + 1; j < k; j++) {
						if (_a == a[j]) {//현재 사용중인 기기 중 _a 기기의 가장 빠른 재사용 시점
							here_pick = j; break; 
						}
					}

					//현재 사용중인 기기 중 가장 재사용 시점이 늦는 것(가장 미래에 다시 쓰게되는 기기)
					if (last_idx < here_pick) {
						last_idx = here_pick;
						pos = _a;
					}
				}


				//콘센트 뽑기
				visited[pos] = 0;
				cnt++;
				v.erase(find(v.begin(), v.end(), pos));
			}

			v.push_back(a[i]);
			visited[a[i]] = 1;
		}

	}

	cout << cnt << "\n";

}

#pragma endregion


int main() {
	Sol_1();
}