#include <bits/stdc++.h>

using namespace std;



void Problem_1() {
	string dopa = "umzunsik";

	//�տ������� 3���� ���ڿ��� ����϶�
	string str = dopa.substr(0, 3); //0��°���� 3���� ���ڿ��� ������
	cout << str << '\n';

	//�ش� ���ڿ��� �Ųٷ� �ؼ� ����϶�
	reverse(str.begin(), str.end());
	cout << str << '\n';

	//�Ųٷε� �ش� ���ڿ� ���� "umzunsik"�̶� ���ڿ��� �߰��϶�
	str += "umzunsik";
	cout << str << '\n';
}

void Problem_2() {
	int N; //�迭 ũ��
	int arr[100];
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//�迭 ��ҵ��� �������� �����϶�
	sort(&arr[0], &arr[N - 1]+1); //sort�Լ�(�迭 �����ּ�, ���ּ�+1)
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << '\n';

	//�迭 ��հ��� ����϶�
	printf("%.2f", (float)sum / N);
}
int main() {
	
	//Problem_1();
	Problem_2();
	return 0;
	
}