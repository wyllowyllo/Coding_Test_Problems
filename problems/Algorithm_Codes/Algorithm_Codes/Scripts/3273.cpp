#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ret;

int n, x;


#pragma region MySol

void MySol() {
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cin >> x;

	sort(v.begin(), v.end());

	int l = 0; int r = n - 1;

	while (l < r) {
		if (v[l] + v[r] == x) {
			ret++;
			r--;
		}
		else if (v[l] + v[r] < x) l++;
		else r--;
	}

	cout << ret << "\n";
}
#pragma endregion

//두 수를 가지고 무언가를 한다ㅏ -> 일단 투포인터 생각해보기!



int main() {
	
}