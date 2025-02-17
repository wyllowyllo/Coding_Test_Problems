#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = { 1,2,3 };
	vector<int> a2 = { 1,2,3,100,200 };

	//next_permutation[from, end) : 
	//n개의 원소의 순열을 구할 수 있는 함수 (algorithm 헤더에 포함)
	// 주어진 컨테이너의 시작과 끝 iterator 전달. 만약 해당 컨테이너에 다음 순열이 존재하면 그 컨테이너의 원소를 해당 순열 순서로 바꾸고 true를 반환하고, 다음 순열이 없다면 false를 반환
	//사전에 컨테이너가 오름차순 정렬된 상태여야 함

#pragma region n개중 n개 고르는 순열 계산
	/*
	sort(&a[0], &a[0]+3);
	do {
		for (int i : a) {
			cout << i << ", ";
		}
		cout << "\n";
	} while (next_permutation(&a[0], &a[0] + 3));


	return 0;*/



	/*do {
		for (int i : a) cout << i << ", ";
		cout << '\n';
	} while (next_permutation(a, a + 3));*/

	
	/*
	sort(a2.begin(), a2.end());
	do {
		for (int i : a2) cout << i << ", ";
		cout << '\n';
	} while (next_permutation(a2.begin(), a2.end()));*/
#pragma endregion

#pragma region n개 중 r 개를 고르는 순열 계산
	//next_permutation에 의해 n!의 결과값을 얻지만, 그 중 앞의 r개만 출력함으로써, n개 중 r개를 얻는 순열을 구현함 (대신 값이 중복되는 문제 있음)

	sort(a2.begin(), a2.end());
	do {
		for (int i = 0; i < 2; i++) cout << a2[i] << ", ";
		cout << "\n";
	} while (next_permutation(a2.begin(), a2.end()));
#pragma endregion


	
}