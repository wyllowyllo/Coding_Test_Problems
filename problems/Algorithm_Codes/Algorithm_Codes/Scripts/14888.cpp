#include <bits/stdc++.h>
using namespace std;

int n;
int a[12];
int op[4];

int mx = -1000000001;
int mn = 1000000001;

void go(int ret,int plusCnt, int subCnt, int mulCnt, int divCnt, int idx) {
	if (idx == n) {
		mx = max(ret, mx);
		mn = min(ret, mn);
		return;
	}

	if (plusCnt)
		go(ret + a[idx], plusCnt - 1, subCnt, mulCnt, divCnt, idx + 1);
	if (subCnt)
		go(ret - a[idx], plusCnt, subCnt-1, mulCnt, divCnt, idx + 1);
	if (mulCnt)
		go(ret * a[idx], plusCnt, subCnt, mulCnt-1, divCnt, idx + 1);
	if (divCnt)
		go((ret<0? ((ret*-1)/a[idx])*-1 : ret/a[idx]), plusCnt, subCnt, mulCnt, divCnt - 1, idx + 1);

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	go(a[0], op[0], op[1], op[2], op[3], 1);

	cout << mx << "\n" << mn << "\n";
}