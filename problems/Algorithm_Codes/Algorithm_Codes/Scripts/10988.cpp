#include <bits/stdc++.h>
using namespace std;

int main() {
	string word;

	cin >> word;

	//--------------------My Solution---------------------------------------
	//��� �ε����� ��������, ���� �� idx->��� Idx, ������ �� idx->��� Idx�� �̵��ذ��鼭 ��
	//int firstIdx = 0;
	//int lastIdx = word.length() - 1;
	//int midIdx = (firstIdx + lastIdx) / 2;

	//bool ispalindrome=true;
	//if (word.length() % 2 == 0) { //¦�������� �ܾ��� ���
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
	//else { //Ȧ�������� �ܾ��� ���
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
	temp = word; //�Է´ܾ� ����

	reverse(temp.begin(), temp.end());//���ڿ��� ������ �Լ�, �� ���ڿ��� ������ ��ġ�Ƿ� �� ���ڿ��� �����Ͽ� ���

	cout << (word == temp) ? 1 : 0;


	return 0;
}