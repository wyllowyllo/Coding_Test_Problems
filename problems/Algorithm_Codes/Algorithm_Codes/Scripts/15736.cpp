#include <bits/stdc++.h>
using namespace std;

int n;
int ret;


int main() {
	cin >> n;

	//백색이 위로 놓이려면 깃발 번호의 약수의 개수가 홀수개여야 함
	//즉 깃발 번호는 완전제곱수 (이외의 수는 항상 약수 개수가 짝수)
	//이때 1~n개 까지의 수 중 가장 큰 완전제곱수는 sqrt(n)보다 클 수 없다.

	cout << (int)sqrt(n) << "\n";

}