#include <bits/stdc++.h>
using namespace std;



int n;

//약수의 개수가 짝수개라면 닫힌 창문, 홀수개라면 열린 창문

//약수 개수가 홀수개가 되는 경우는, 이 수가 어떤 '정수'의 제곱수인 경우.
//즉 제곱근이 정수이면 이 수는 약수의 개수가 홀수이다


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	

	int cnt = 0;

	/*for (int j = 1; j <= n; j++) {


		//첫번째 시도
		
		//set<int> s;
		////j의 인수 구하기
		//for (int k = 1; k * k <= j; k++) {
		//	if (j % k == 0) {
		//		s.insert(k);
		//		s.insert(j / k);
		//	}
		//}


		//if (s.size() % 2 != 0) cnt++;

		
		//두번째 시도
		double t = sqrt(j);
		if ((t - (int)t) == 0) cnt++;
	}*/


	//세번째 시도

	//반복문 써서 하나하나 검사하지 말고, 그냥 n이하의 제곱수 개수를 구하기
	// 완전제곱수만 약수 개수가 홀수가 되고, 그렇지 않은 수는 무조건 약수 개수가 짝수이다
	//즉 완전제곱수의 개수==열린 창문의 개수가 된다
	//n이하인 수 중 제곱수는 루트 n개다 (가장 큰 완전제곱수는 루트n이하이기 때문에)
	

	
	cnt = sqrt(n);
	cout << cnt << "\n";

}