#include <bits/stdc++.h>
using namespace std;

int n;


typedef long long ll;
ll ret;

int visited[100001];

int main() {
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	visited[v[0]] = 1;
	int l = 0, r = 1;
	while (true) {
		if (r == n) {

			while (l < r) {
				ret += r - l;
				l++;
			}
			
			break;
		}

		if (visited[v[r]]) {
			ret += r - l;
			visited[v[l]] = 0;
			l++;
		}
		else {
			visited[v[r]] = 1;
			r++;
		}
	}

	cout << ret << "\n";
}