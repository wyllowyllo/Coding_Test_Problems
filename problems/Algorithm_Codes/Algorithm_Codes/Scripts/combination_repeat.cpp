#include <bits/stdc++.h>
using namespace std;


int n = 5, r = 3; //5개 숫자(0,1,2,3,4) 중 3개를 뽑는 조합 구하기
void PrintV(vector<int>& v) {

	for (int i : v) {
		cout << i << ", ";
	}
	cout << "\n";
}

#pragma region 재귀로 조합 생성하기

//조합은 n개의 원소 중 r개를 선택하여 담아내는 것
//재귀를 활용하여, 원소를 넣었다, 다시 복원했다를 반복하며 모든 조합을 구할 수 있다
	void Make_Combination(int startIdx, vector<int>& v) {
		if (v.size() == r) {
			PrintV(v);
			return;
		}

		for (int i = startIdx + 1; i < n; i++) {
			v.push_back(i);
			Make_Combination(i, v);
			v.pop_back();
		}
	}
	
#pragma endregion


#pragma region 중복 반복문으로 조합 생성하기

	//n개중 r개를 뽑는 조합을 생성하기 위해서는, r번 중첩되는 중첩 반복문을 통해서도 구현이 가능하다
	//따라서 r의 크기가 작은 경우 중첩 for문으로(구현이 간단하고, 재귀보다 코스트가 적음), r의 크기가 큰 경우 재귀로 구현하는 것이 좋다.
	void Make_Combi() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					cout << "{ " << i << ", " << j << ", " << k << "  }\n";
				}
			}
		}
		/*
		또는 이런식도 가능하다(조합은 순서 상관 없으므로)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < j; k++) {
					cout << "{ " << i << ", " << j << ", " << k << "  }\n";
				}
			}
		}*/
	}

#pragma endregion

int main() {
	vector<int> v = {};
	//Make_Combination(-1, v);
	Make_Combi();
}