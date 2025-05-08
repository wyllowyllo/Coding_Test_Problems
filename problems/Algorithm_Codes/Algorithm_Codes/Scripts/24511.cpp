#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001];
deque<int> dq;

int temp;

//stack인 경우 입력받은 값을 그대로 다시 출력하므로 굳이 고려 x
//queue들만 모아서 하나의 deque로 관리


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (a[i] == 0) dq.push_front(temp);
	}

	cin >> m;

	if (dq.empty()) {
		for (int i = 0; i < m; i++) {
			cin >> temp;
			cout << temp << " ";


		}
	}
	else {
		for (int i = 0; i < m; i++) {
			cin >> temp;
			cout << dq.front() << " ";
			dq.push_back(temp);
			dq.pop_front();

		}
	}







}