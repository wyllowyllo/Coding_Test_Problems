#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	//---------------------My Solution-----------------------------------------------
	
	//int ret = 1;
	//while (scanf("%d", &n)!=EOF) { //테스트케이스가 정확히 명시되지 않았으므로, 입력이 올때마다 받는다.
	//	long long multiple = 1;
	//	while (multiple % n != 0) {
	//		(multiple *= 10) += 1;
	//		multiple %= n;
	//		ret++;
	//	}

	//	printf("%lld\n", ret);
	//	ret = 1;
	//}
	//------------------------------------------------------------------------------

	//---------------------Solution 1-----------------------------------------------
	while (scanf("%d", &n) != EOF) {
		int cnt = 1, ret = 1;
		if (cnt % n == 0) {
			printf("%d\n", ret);
			break;
		}
		else {
			cnt = (cnt * 10) + 1;
			cnt %= n;
			ret++;
		}
	}
	return 0;
}