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


	cin >> N >> M; //���� ����N �� ���� ���ؾ� �ϴ� Ƚ�� M�Է�

	//N���� �� �Է�
	for (int i = 0; i < N; i++) {
		cin >> input_arr[i + 1];
		psum_arr[i + 1] = input_arr[i + 1] + psum_arr[i]; //�Է½� presum �迭 �ʱ�ȭ
	}

	//���� ���� (A,B)���� M�� �Է¹ް�, ������ ���� ������ ����
	for (int i = 0; i < M; i++) {
		int A; int B;
		cin >> A >> B;
		//result_arr[result_arrIdx++] = Sum1(A, B); //���� �ݺ��� �����̱� ������, worstcase���� O(M*N)
		//result_arr[result_arrIdx++]=  Sum2(A, B); //resursion�̿��Ͽ� �� ���ϴ� ���, Ʈ���� Ȯ���غ��� ����Ƚ�� ���� ���̾���.
		result_arr[result_arrIdx++] = Prefix_Sum(A, B); // ������ �迭(psum_arr)���� psum[B]-psum[A]�� ����� A���� B������ �հ� ����


		/*
		Coding test Tip : ���� ���� , �迭���� �ٲ��� ����(�����迭) �̸� ������(prefix sum)����� ����!
		*/

	}

	//��� ���
	for (int i = 0; i < result_arrIdx; i++)
		cout << result_arr[i] << '\n';

		

}