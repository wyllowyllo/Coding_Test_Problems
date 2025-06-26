#include <bits/stdc++.h>
using namespace std;


namespace My {
	//첫번째 시도 : 그리디하게?
//접점 발생 시, from-to 간 거리가 큰 것이 나중에 다른 선과 겹칠 확률이 클 테니, 그 선을 지우는 식으로 하면 되지 않을까? 

//반례 있음.. -> 이 가설 폐기

//두번째 시도 : 그냥 각 전깃줄이 가지고 있는 접접 기록한 후, 접점 많은 전깃줄부터 없애기(모든 접점 없어질때까지)
// 반례 있음... -> 교점 개수가 같은 전깃줄이 여러 개 있을때는 어떤 전깃줄을 지워야하느냐...

//ㅈㅈ.. 모르겠다 도저히..
	int n;
	vector<pair<int, int>> v;
	int from, to;
	int cnt;

	vector<int> wires[501];
	int ret;

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n;

		/*for (int i = 0; i < n; i++) {
			cin >> from >> to;
			v.push_back({ from, to });
		}

		sort(v.begin(), v.end());*/


		//첫번째 시도

		//for (int i = 0; i < n; i++) {
		//	bool flag = false;
		//	for (int j = 0; j < i; j++) {

		//		if (v[j].first == -1) continue;

		//		if (v[j].second > v[i].second) { //접점 발생
		//			int diff = abs(v[i].second - v[i].first);

		//			if (abs(v[j].second - v[j].first) > diff) {
		//				v[j] = { -1,-1 }; //기존 선 지우기
		//				cnt++;
		//			}
		//			else {
		//				flag = true;
		//				break;
		//			}
		//			
		//		}
		//	}

		//	if (flag) { v[i]={ -1,-1 }; cnt++; }//현재 선 지우기
		//}

		//두번째 시도

		/*for (int i = 0; i < n; i++) {
			cin >> from >> to;
			v.push_back({ from, to });
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (v[j].second > v[i].second) {
					wires[v[i].first].push_back(v[j].first);
					wires[v[j].first].push_back(v[i].first);
					cnt++;
				}
			}
		}



		while (cnt) {
			int wireNum = 0;
			int maxCnt = 0;

			for (int i = 0; i < 501;i++) {
				if (maxCnt < wires[i].size()) {
					maxCnt = wires[i].size();
					wireNum = i;
				}
			}

			for (int i : wires[wireNum]) {
				for (int j = 0;j<wires[i].size();j++) {
					if (wires[i][j] == wireNum) {
						wires[i].erase(wires[i].begin() + j);
						break;
					}
				}
			}

			cnt -= wires[wireNum].size();
			wires[wireNum].clear();
			ret++;
		}

		cout << ret << "\n";*/
	}
}

namespace Sol {
	//문제풀이 흐름

	//1. 간단한 테스트케이스를 생각해서, 그 모습을 일단 그려봄 ({1,1}, {2,5}, {3,3}, {4,4})
	//위의 테스트케이스에선, {2,5}를 지우거나 또는 {3,3},{4,4}를 지우면 됨 -> 최적의 경우는 {2,5}를 지우는 것
	//2. {2,5}를 지운 후 , 값들을 다시 보니 {1,1}.{3,3},{4,4}임.
	//각 원소의 첫번째(혹은 두번째)값들을 나열해보면 1,3,4 인 것을 알 수 있다 --> LIS가 되는 경우인 것을 발견!
	//3. 따라서 최소의 전깃줄을 지우는 이 문제는, 곧 최대의 LIS를 구하는 것이 아닐까?

	//알고리즘 문제를 풀땐, 위처럼 명제 세워서 풀되, 만약 안되면 빠르게 변경해서 다르게 풀어보는 식으로 해야 함!

	//팁 : pair로 들어오는 입력은, sort해보자 -> 이 문제의 경우 sort해봤을 때, 'LIS를 구하는 게 아닐까?' 하는 힌트를 얻을 수 있었음
	
	int n, a, b, len, lis[504];

	vector<pair<int, int>> v;

	void Sol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			auto pos = lower_bound(lis, lis + len, v[i].second);

			if (*pos == 0) len++;
			*pos = v[i].second;
		}

		cout << n - len << "\n"; //len은 lis길이이자, 없애지 않고 유지하는 전깃줄 개수와 같으므로, 제거하는 전깃줄 수는 n-len
	}
}
int main() {
	Sol::Sol();
	
}