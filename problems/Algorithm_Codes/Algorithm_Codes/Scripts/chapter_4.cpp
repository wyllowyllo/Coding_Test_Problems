#include <bits/stdc++.h>

using namespace std;

const int n = 4;
string a[n] = { "apple", "strawberry", "grape", "pear" };
#pragma region 비트마스킹을 이용한 경우의 수


// {사과, 딸기 , 포도, 배} 의 모든 경우의 수 구하기

void Test_1(){
	

	//i는 0000 , 0001 , 0010, ... , 1111 까지를 뜻함(0~15)
	for (int i = 0; i < (1 << n); i++) {
		string ret = "";
		//j는 0 , 1, 2, 3을 기반으로 해당 번째의 비트가 켜져있나 꺼져있나를 통해 집합을 확인함
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				ret += (a[j] + " ");
			}
		}

		cout << ret << "\n";
	}

	return;
}


#pragma endregion

#pragma region 비트마스킹을이용한매개변수전달
//사과라는 매개변수가 포함되어 있고, 이어서 사과 + 포도, 사과 + 배 이런 식의 매개변수를 더하는 것을 구현하기


void go(int num) {
	string ret = "";

	//전달받은 수에서, 어떤 요소가 1인지를 검사해 결과를 출력
	for (int i = 0; i < 4; i++) {
		if (num & (1 << i)) ret += a[i] + " ";
	}
	cout << ret << "\n";
}
void Test_2() {
	//사과라는 매개변수는 일단 기본으로 포함되어 있고, 거기서 다른 과일들을 추가하는 식으로 하기
	for (int i = 1; i < n; i++) {
		go(1 | (1 << i));
	}
}
#pragma endregion

int main() {
	//Test_1();
	Test_2();
}
