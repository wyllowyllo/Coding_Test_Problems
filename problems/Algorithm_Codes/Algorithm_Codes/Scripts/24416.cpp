#include <bits/stdc++.h>
using namespace std;

int n;
int fibo[50];

int cnt_1, cnt_2;
int fib(int num) {
	if (num <= 2) { cnt_1++; return 1; }

	
	return fib(num - 1) + fib(num - 2);
}
int fibonacci(int num) {
	fibo[1] = fibo[2] = 1;

	for (int i = 3; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		cnt_2++;
	}

	return fibo[num];
}
int main() {
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << cnt_1 << " "<<cnt_2;

}