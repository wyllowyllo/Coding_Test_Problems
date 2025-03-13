#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

//첫번째 시도

//값 입력받을때마다, 아직 오큰수를 가지지 못한 수를 대상으로 대소비교함
//입력받은 값이 더 크다면, 오큰수로 설정하고 그 수를 검사대상에서 제거
//시간 초과됨

//두번째 시도
//스택을 활용해볼까? 값 입력받을때마다 top과 비교, 만약 새 입력값이 더 크다면 오큰수 설정 후 pop
//위 과정을 top>새값 일때까지 반복
//새값을 stack에 push
//성공!!!

//스택을 사용하니 비교&제거시간이 확연히 작음. 

int n, a;
int NGE[1000001];
vector<pair<int, int>> v;

stack<pair<int, int>> stk;

void MySol() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(NGE, -1, sizeof(NGE));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;

		//첫번째 시도한 방법
		/*for (int j = 0; ; ) {
			if (j >= v.size()) break;

			if (v[j].first < a) {
				NGE[v[j].second] = a;
				v.erase(v.begin() + j);
			}
			else j++;
		}

		v.push_back({a,i});*/

		//
		while (stk.size() && stk.top().second < a) {
			NGE[stk.top().first] = a; //오큰수 설정
			stk.pop(); //스택에서 제거
		}
		stk.push({ i,a });
	}

	for (int i = 0; i < n; i++) {
		cout << NGE[i] << " ";
	}
}

#pragma endregion

#pragma region Sol_1

//이 문제는 짝짓기 문제이다
//짝짓기 문제는, 스택을 한번 활용해보자!

//생각의 흐름
//1. 오큰수가 결정이 안되었다면, 일단 담아놓자
//2. 오큰수가 결정이 되면, 그때 뺀다


#pragma endregion


int main() {

}