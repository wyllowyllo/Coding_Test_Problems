#include <bits/stdc++.h>
using namespace std;

int n;
int num[12];
int op[4];



int min_ret = 1e9;
int max_ret=-1e9;

int cal(int _op, int A, int B) {
	int result = 0;
	switch (_op) {
	case 0:
		result = A + B;
		break;
	case 1:
		result = A - B;
		break;
	case 2:
		result = A * B;
		break;
	case 3:
		if (A < 0) result = ((-1 * A) / B) * -1;
		else result = A / B;
		break;
	}

	return result;
}
void go(int idx,int result) {
	if (idx == n - 1) {
		max_ret = max(max_ret, result);
		min_ret = min(min_ret, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;

		op[i]--;
		go(idx + 1, cal(i, result, num[idx+1]));
		op[i]++;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	go(0, num[0]);

	cout << max_ret << "\n" << min_ret << "\n";
}