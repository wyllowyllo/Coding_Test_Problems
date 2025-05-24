#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ret = 0;

int n, k;
int m, v;

vector<pair<int, int>> jew;

#pragma region MySol
//가설 : 각 가방에 담을 수 있는 보석 중 최대의 가치를 지닌 보석을 넣어야 한다

//뭔가 가방 용량이 클수록 담을 수 있는 보석의 경우의 수가 많아질 것이므로, 가방을 오름차순 정렬해서 용량 작은것부터 채워야 할거같음
// 
// 
// 가방을 오름차순 정렬하고, 보석의 무게에 대해 오름차순 정렬한다.

//보석의 무게에 대해 오름차순 정렬하고, 같은 무게이면 가격에 대해 내림차순 정렬?
//근데 이렇게 하면 무게 1 - 가격 3인보석 2개, 무게 2- 가격 2인 보석 1개 있다고 하면 용량 1,2,인 가방 두개는 무게 1인 보석 2개를 담아야하는게 그러지 못함

//가방을 오름차순 정렬하고, 보석 무게에 대호 오름차순 정렬한 다음
//pq를 활용하여 top에 가장 가치가 큰 보석이 오게 함
//가방 용량 작은것->큰것부터 조사하고 이때 보석의 무게가 작은것->큰것부터 조사하게 함
//만약 현재 보석의 무게가 가방 용량을 초과했다면, pop하여 그 가방에 담을 수 있는 보석 중 가장 가치가 큰 것을 담음
//그다음 가방에 대해서는 보석 처음부터 검사할 필요없이 검사했던 보석부터 다시 쭉 검사하면 됨(두번째 가방은 처음 가방보다 용량이 클 것이고, 따라서 pq안의 원소들을 담을 수 있기 때문, 또 top에 위치한 보석이 pq중 가장 가치가 큰 보석일 것이므로)
//보석 조사 끝나면 bagCnt(아직 보석을 담지 않은 가방) 개수만큼 pop하여 보석담기



	void MySol() {
		cin >> n >> k;


		for (int i = 0; i < n; i++) {
			cin >> m >> v;
			jew.push_back({ m,v });
		}

		vector<int> bags(k);
		for (int i = 0; i < k; i++) {
			cin >> bags[i];
		}


		sort(jew.begin(), jew.end());
		sort(bags.begin(), bags.end());

		priority_queue<int>pq;

		int j = 0;
		int bagCnt = k;
		for (int i : bags) {
			
			for (j; j < jew.size(); j++) {
				if (i < jew[j].first) {
					if (pq.size()) {
						ret += pq.top();
						pq.pop();
					}
					bagCnt--;
					break;
				}
				else { pq.push(jew[j].second);}
			}

			
		}

		while (bagCnt && pq.size()) {
			ret += pq.top();
			pq.pop();
			bagCnt--;
		}
		
		
		

		cout << ret << '\n';


	}



#pragma endregion

#pragma region Sol_1
//나는 bagCnt라는 변수를 따로 둬서 전체 가방 중 보석을 담을 수 없는 가방을 제외한 가방들 안에 보석을 담는 식으로 함
//나는 가방용량과 보석 무게 비교를 먼저 하고, 가방용량<보석무게 일 경우 pop, 그렇지 않을 경우 push함
//여기서는 일단 push를 먼저 하고, 넣을 수 있는 모든 보석을 push한 후 pop을 함
//나처럼 굳이 처리 안된 가방 수만큼 따로 처리하는 분기 없는 더 깔끔한 코드임


	void Sol_1() {
		cin >> n >> k;
		vector<pair<ll, ll>> v(n);
		vector<ll> vv(k);

		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		for (int i = 0; i < k; i++) cin >> vv[i];

		sort(v.begin(), v.end());
		sort(vv.begin(), vv.end());
		priority_queue<ll> pq;

		int j = 0;
		for (int i = 0; i < k; i++) {
			while (j < n && v[j].first <= vv[i]) {
				pq.push(v[j++].second);
			}

			if (pq.size()) {
				ret += pq.top(); pq.pop();
			}
		}

		cout << ret << "\n";

}

#pragma endregion



int main() {
	//MySol();
	Sol_1();
}