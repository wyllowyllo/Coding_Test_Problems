#include <bits/stdc++.h>

using namespace std;



void Problem_1() {
	string dopa = "umzunsik";

	//앞에서부터 3개의 문자열을 출력하라
	string str = dopa.substr(0, 3); //0번째부터 3개의 문자열값 빼오기
	cout << str << '\n';

	//해당 문자열을 거꾸로 해서 출력하라
	reverse(str.begin(), str.end());
	cout << str << '\n';

	//거꾸로된 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라
	str += "umzunsik";
	cout << str << '\n';
}

void Problem_2() {
	int N; //배열 크기
	int arr[100];
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//배열 요소들을 오름차순 정렬하라
	sort(&arr[0], &arr[N - 1]+1); //sort함수(배열 시작주소, 끝주소+1)
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << '\n';

	//배열 평균값을 계산하라
	printf("%.2f", (float)sum / N);
}
int main() {
	
	//Problem_1();
	Problem_2();
	return 0;
	
}