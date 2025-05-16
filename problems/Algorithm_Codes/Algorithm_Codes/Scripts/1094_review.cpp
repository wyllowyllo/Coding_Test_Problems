#include <bits/stdc++.h>
using namespace std;


int x;
int ret;
void go(int stick,int x, int cnt) {
	if (x == 0) { ret = cnt; return; }

	if (x >=stick) {
		go(stick/2, x-stick,cnt+1);
	}
	else if (x < stick) {
		go(stick / 2,x,cnt);
	}
}
int main() {
	cin >> x;

	go(64, x, 0);

	cout << ret << '\n';
}