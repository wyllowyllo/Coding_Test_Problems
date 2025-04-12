#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
stack<pair<int, int>> stk; //{높이, 인덱스}

int ret[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		while (stk.size() && stk.top().first < temp) {
			stk.pop();
		}
			
		if (stk.size() && stk.top().first >= temp) {
			ret[i] = stk.top().second+1;
		}

		stk.push({ temp,i });
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
}