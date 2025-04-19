#include <bits/stdc++.h>
using namespace std;

int n;
int m;

int cards[101];
int ret = -1;
int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin>>cards[i];
	}
		

	//n개 카드 중 3개 선택
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = 0;
				sum = cards[i] + cards[j] + cards[k];
				if (sum <=m) ret = max(ret, sum);
			}
		}
	}

	cout << ret << "\n";

}