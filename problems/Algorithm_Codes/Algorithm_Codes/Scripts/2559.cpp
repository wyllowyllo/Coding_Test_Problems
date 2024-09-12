#include <bits/stdc++.h>
#define MIN -100000000;
using namespace std;

int temperature[100001];
int prefix_sum[100001];

int main() {

	
	int N, K;
	cin >> N >> K;

	//--------------------------My Solution-----------------------------------------------

	for (int i = 1; i <=N; i++) {
		cin >> temperature[i];
		prefix_sum[i] = prefix_sum[i - 1] + temperature[i]; //������ ���ϱ�
	}

	int maxSum = MIN;
	int sum;
	for (int i = K; i <= N; i++) {
		sum = prefix_sum[i] - prefix_sum[i - K];
		maxSum = (maxSum < sum) ? sum : maxSum;
	}

	cout << maxSum << '\n';

	//-------------------------------------------------------------------------------------

	//----------------------------Solution 1 ------------------------------------------------
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		prefix_sum[i] = prefix_sum[i - 1] + temp; //������ ���ϱ�
	}

	int ret;
	for (int i = K; i <= N; i++) {
		ret=max(ret,prefix_sum[i] - prefix_sum[i - K]); //�� ���� ū ���� ��ȯ�ϴ� max�Լ�
	}

	cout << ret << "\n";

	//-------------------------------------------------------------------------------------

	return 0;

}