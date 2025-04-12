#include <bits/stdc++.h>
using namespace std;

int cnt[1000002]; //횟수저장
int NGF[1000002];
int n;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(NGF, -1, sizeof(NGF));
	cin >> n;

	vector<pair<int, int>> vec;// 인덱스, 숫자 쌍
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		vec.push_back({ i,temp });
		cnt[temp]++;
	}

	stack<pair<int,int>> stk;
	for (auto v : vec) {

		if (stk.size() && cnt[stk.top().second] < cnt[v.second]) {
			while (stk.size() && cnt[stk.top().second] < cnt[v.second]) {
				NGF[stk.top().first] = v.second;
				stk.pop();
			}

		}

		stk.push(v);
	}



	for (int i = 0; i < n; i++) {
		cout << NGF[i] << " ";
	}

}