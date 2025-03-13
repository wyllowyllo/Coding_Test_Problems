#include <bits/stdc++.h>
using namespace std;

int t,n;
int cnt = 0;

#pragma region MySol

/* 5!는 120이므로, 여기서부터 뒷자리에 0이 생긴다

		n이 4 이하라면 뒷자리의 0의 개수는 0개이다

		0의 개수 ? 10이 몇개 곱해졌는가 ?

		10 = 5 * 2

		즉 5의 개수와 2의 개수를 알 수 있다면, 곧 10의 개수를 알 수 있고, 그것은 0의 개수와 같을 것이다

		0의 개수를 구하여라 = 10의 개수를 구하여라 = 5와 2의 개수를 구하여라

		n != 1 * 2 * 3 * .... * n 이므로, 각 수에 포함된 5와 2의 개수를 카운트하면 될듯*/

		//답은 맞음
		//그러나 시간 초과로 실패... 더 빠른 방법은?
void MySol() {

	cin >> t;
	while (t--) {
		cin >> n;

		if (n < 5) {
			cout << 0 << "\n";
			continue;
		}
			
			


		int cnt_2 = 0; int cnt_5 = 0;

		for (int k = 5; k <= n; k++) {

			int temp = k;
			while (true)
			{
				if (temp ==0 || (temp % 2 != 0 && temp % 5 != 0)) break;

				if (temp % 2 == 0) cnt_2++, temp /= 2; //2개수 증가시키고, 원래 수에서 2를 없앤다
				if (temp % 5 == 0) cnt_5++, temp /= 5; // 5개수 증가시키고, 원래 수에서 5를 없앤다
			}
			
		}

		cnt = min(cnt_2, cnt_5);

		cout << cnt << "\n";
		cnt = 0;
	}
}
#pragma endregion

#pragma region Sol_1
//나는 소인수 2와 5의 개수를 곱할때, n!을 구성하는 수 1,2,3,...,n의 순서로 하나하나 검사하여 해당 수에 포함된 2와 5의 개수를 구해 누적하는식으로 함
//이렇게 하면 시간 복잡도 너무 커짐

//새로운 아이디어 필요 : 어떤 수 n에 포함된 모든 2의 개수 == 어떤 수 n에 포함된 2의 개수, 4의 개수, 8의 개수....와 같이 2의 승수의 개수의 합
//새로운 접근법이 필요할때, 그래프를 그리거나 도표를 그리거나 해서 아이디어 찾아보기!


void Sol_1() {
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		int ret2 = 0, ret5 = 0; //2와 5의 개수

		for (int j = 2; j <= n; j *= 2) { //2의 거듭제곱
			ret2 += n / j; //해당 수 n에 2의 각 승수가 포함된 개수 누적

		}
		for (int j = 5; j <= n; j *= 5) {
			ret5 += n / j;
		}
		cout << min(ret2, ret5) << "\n";
	}
}

#pragma endregion



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Sol_1();
}