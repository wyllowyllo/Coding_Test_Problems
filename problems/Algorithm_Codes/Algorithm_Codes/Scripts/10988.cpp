#include <bits/stdc++.h>
using namespace std;

int main() {
	string word;

	cin >> word;

	//--------------------My Solution---------------------------------------
	//가운데 인덱스를 기준으로, 왼쪽 끝 idx->가운데 Idx, 오른쪽 끝 idx->가운데 Idx로 이동해가면서 비교
	//int firstIdx = 0;
	//int lastIdx = word.length() - 1;
	//int midIdx = (firstIdx + lastIdx) / 2;

	//bool ispalindrome=true;
	//if (word.length() % 2 == 0) { //짝수길이의 단어인 경우
	//	if ((char)word[midIdx] != (char)word[midIdx + 1])
	//		ispalindrome = false;

	//	else {
	//		for (int i = 0; i < midIdx; i++) {
	//			if ((char)word[i] != word[lastIdx - i]) {
	//				ispalindrome = false;
	//				break;
	//			}
	//		}
	//	}
	//}
	//else { //홀수길이의 단어인 경우
	//	for (int i = 0; i <midIdx; i++) {
	//		if ((char)word[i] != word[lastIdx - i]) {
	//			ispalindrome = false;
	//			break;
	//		}

	//	}
	//}

	//cout << (ispalindrome) ? 1 : 0 << '\n';

	//--------------------------------------------------------------------

	//------------------------Solution 1 ----------------------------------
	string temp;
	temp = word; //입력단어 복사

	reverse(temp.begin(), temp.end());//문자열을 뒤집는 함수, 원 문자열에 영향을 미치므로 원 문자열을 복사하여 사용

	cout << (word == temp) ? 1 : 0;


	return 0;
}