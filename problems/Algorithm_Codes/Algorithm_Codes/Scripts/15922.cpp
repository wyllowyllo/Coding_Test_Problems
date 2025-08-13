#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;
int l=-1e9-4, r=-1e9-4;

typedef long long ll;
ll ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		if (r < x) {
			ret += r - l;
			l = x;
			r = y;
		}

		else if (r < y) {
			r = y;
		}
	}

	ret += r - l;

	cout << ret << "\n";
}