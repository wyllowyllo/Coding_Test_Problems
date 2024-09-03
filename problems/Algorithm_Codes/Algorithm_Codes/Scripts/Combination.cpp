#include <bits/stdc++.h>
using namespace std;

vector<int> a = { 1,2,3,4,5 };
void Find_Combination(int startIdx, vector<int> combiSet);

void Solution_1() {
	//a 의 원소 중 3개 뽑기(조합) ->5C3 
	vector<int> combiSet;
	Find_Combination(-1, combiSet); //첫번째 원소 결정 후 두번째 원소의 탐색범위 결정, 두번째 원소 결정 후 세번째 원소의 탐색범위 결정 -> 생성된 결과는 각각 다름
}

void Find_Combination(int startIdx, vector<int> combiSet) {
	//recursion 함수에선, 기저조건 항상 설정하기!
	if (combiSet.size() == 3) {
		for (int num : combiSet)
			cout << num << " : ";
		cout << '\n';
		return;
	}

	for (int i = startIdx + 1; i < a.size(); i++) {
		combiSet.push_back(a[i]);
		Find_Combination(i, combiSet);
		combiSet.pop_back();
	}
}

void Solution_2() {
	//a 의 원소 중 3개 뽑기(조합) ->5C3 반복문 사용 ver

	//첫번째 원소 결정 후 두번째 원소의 탐색범위 결정, 두번째 원소 결정 후 세번째 원소의 탐색범위 결정
	//뽑는 원소의 수에 따라 반복문 중첩 횟수가 다름.
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			for (int k = j + 1; k < a.size(); k++) {
				cout << a[i] << " : " << a[j] << " : " << a[k] << "\n";
			}
			
		}
	}
	
}

int main() {
	//Solution_1();
	Solution_2();
}