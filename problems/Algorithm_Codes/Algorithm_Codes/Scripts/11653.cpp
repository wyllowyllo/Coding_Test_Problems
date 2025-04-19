#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;

	for (int i = 2; i * i <= n; i++) { //n의 인수 찾기
		while (n % i == 0) { //인수 찾았다면 
			cout << i << "\n";
			n /= i; //인수 출력 후 소거
		}
	}
	if (n > 1) cout << n << "\n";
}