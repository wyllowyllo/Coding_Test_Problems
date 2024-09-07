#include <bits/stdc++.h>
#define MAX_SIZE 100000

using namespace std;

int input_arr[MAX_SIZE];
int psum_arr[MAX_SIZE] = {0,};

int Sum1(int A, int B) {
	int sum = 0;

	for (int i = A; i <= B; i++) {
		sum = input_arr[i] + sum;

	}
	return sum;
}

int Sum2(int A, int B) {
	if (A == B)
		return input_arr[A];
	int mid = (B + A) / 2;

	return Sum2(A, mid) + Sum2(mid + 1, B);
}

int Prefix_Sum(int A, int B) {
	return psum_arr[B]- psum_arr[A-1];
}

int main() {
	int N; int M;
	
	int result_arr[MAX_SIZE];
	int result_arrIdx = 0;


	cin >> N >> M; //수의 개수N 과 합을 구해야 하는 횟수 M입력

	//N개의 수 입력
	for (int i = 0; i < N; i++) {
		cin >> input_arr[i + 1];
		psum_arr[i + 1] = input_arr[i + 1] + psum_arr[i]; //입력시 presum 배열 초기화
	}

	//구할 범위 (A,B)값을 M번 입력받고, 각각에 대한 연산결과 구함
	for (int i = 0; i < M; i++) {
		int A; int B;
		cin >> A >> B;
		//result_arr[result_arrIdx++] = Sum1(A, B); //이중 반복문 구조이기 때문에, worstcase에선 O(M*N)
		//result_arr[result_arrIdx++]=  Sum2(A, B); //resursion이용하여 합 구하는 방식, 트리로 확인해보면 연산횟수 위랑 차이없음.
		result_arr[result_arrIdx++] = Prefix_Sum(A, B); // 누적합 배열(psum_arr)에서 psum[B]-psum[A]의 결과는 A부터 B까지의 합과 같음


		/*
		Coding test Tip : 구간 쿼리 , 배열값이 바뀌지 않음(정적배열) 이면 누적합(prefix sum)방법이 유용!
		*/

	}

	//결과 출력
	for (int i = 0; i < result_arrIdx; i++)
		cout << result_arr[i] << '\n';

		

}