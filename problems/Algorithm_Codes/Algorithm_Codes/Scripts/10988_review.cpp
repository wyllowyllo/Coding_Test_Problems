#include <bits/stdc++.h>
using namespace std;

string word;
string temp;
#pragma region Mysol
	bool IsPal() {

		int size = word.size();
		if (size == 1) {
			return true;
		}
		else {
			int mid = size / 2;

			for (int i = 0; i < mid; i++) {
				if (word[i] != word[size - 1 - i]) {
					return false;
				}
			}
			return true;

		}

	}
#pragma endregion

#pragma region Sol_1

	//원래 문자열과, 문자열 전체를 뒤집은 것과 비교 시 똑같으면 팰린드롬
	void Sol_1() {
		temp = word; //reverse함수는 원래 문자열에 영향을 미치므로, 복사본 저장
		
		reverse(temp.begin(), temp.end());
		if (temp == word) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	

#pragma endregion



int main() {
	cin >> word;
	//bool ret=IsPal();
	//cout << (ret) ? 1 : 0;

	Sol_1();
}