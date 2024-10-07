#include <bits/stdc++.h>
using namespace std;

//----------------------------------------My Solution --------------------------------------------
//짝짓기와 관련된 문제 ->>>> 스택으로 해결해보기 !!!!!!!
/*int n;
int input;
int m[1000001];

stack<pair<int,int>> stk;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	fill(&m[0], &m[0] + n, -1);
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		while (!stk.empty() && stk.top().second < input) {
			m[stk.top().first] = input;
			stk.pop();
		}
		stk.push({i,input});
	}

	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}

}*/
//------------------------------------------------------------------------------------------------

//----------------------------------------Solution 1----------------------------------------------
int n, a[1000004], ret[1000004];
stack<int> s;
int main() {
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (s.size() && a[s.top()] < a[i]) {
			ret[s.top()] = a[i]; s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
}