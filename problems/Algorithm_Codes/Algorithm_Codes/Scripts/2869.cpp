#include <bits/stdc++.h>
using namespace std;

int a, b, v;
int main() {

	cin >> a >> b >> v;


	int day = ceil(((double)(v - b) / (a - b))); //처음에 float로 캐스팅했다가, 정밀도 손실 때문에 연산결과에 오차가 생겼음;;
	
	cout << day << "\n";
}
