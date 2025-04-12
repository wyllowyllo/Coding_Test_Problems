#include<bits/stdc++.h>
using namespace std;

int n;
int temp;
stack<int> stk_1; //인덱스, 누적
stack<pair<int, int>> stk_2; //인덱스, 누적


int h[100001]; //각 건물의 높이 정보
pair<int, int> ret[100001]; //{볼수있는 건물 개수, 건물번호}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		h[i] = temp;

		/* 오른쪽 건물 기준으로 왼쪽 건물 바라보기 */
		//스택은 항상 오름순을 유지한다
		if (stk_1.size() && h[stk_1.top()] > temp) {

			
			ret[i].first = 1; //볼수 있는 건물개수 저장
			ret[i].second = stk_1.top() + 1; //볼수 있는 가장 가까운 건물번호


	
		}
		else stk_1.push(i); //인덱스 push


		//----------------------------------------------------------------

		/* 왼쪽 건물 기준으로 오른쪽 건물 바라보기 */

		//스택은 항상 오름순을 유지한다
		if (stk_2.size() && h[stk_2.top().first] > temp) {

			while (stk_2.size() && h[stk_2.top().first] > temp) {
				
				auto stackTop= stk_2.top();
				stk_2.pop();

				
				/* 왼쪽 건물 기준으로 오른쪽 건물 바라보기 */
				if(stk_2.size())
					stk_2.top().second = stackTop.second + 1;

				ret[stackTop.first].first += stackTop.second; //볼수 있는 건물개수 저장
				if(ret[i].second==0 )ret[i].second = stk_2.top().first + 1; //볼수 있는 가장 가까운 건물번호
			}

		}
		stk_2.push({i,0}); //인덱스 push
		
	}

	for (int i = 0; i < n; i++) {
		if (ret[i].first == 0) cout << 0 << '\n';
		else {
			cout << ret[i].first << " " << ret[i].second<<'\n';
		}
	}

}