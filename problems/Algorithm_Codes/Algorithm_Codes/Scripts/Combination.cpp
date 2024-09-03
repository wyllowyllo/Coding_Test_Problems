#include <bits/stdc++.h>
using namespace std;

vector<int> a = { 1,2,3,4,5 };
void Find_Combination(int startIdx, vector<int> combiSet);

void Solution_1() {
	//a �� ���� �� 3�� �̱�(����) ->5C3 
	vector<int> combiSet;
	Find_Combination(-1, combiSet); //ù��° ���� ���� �� �ι�° ������ Ž������ ����, �ι�° ���� ���� �� ����° ������ Ž������ ���� -> ������ ����� ���� �ٸ�
}

void Find_Combination(int startIdx, vector<int> combiSet) {
	//recursion �Լ�����, �������� �׻� �����ϱ�!
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
	//a �� ���� �� 3�� �̱�(����) ->5C3 �ݺ��� ��� ver

	//ù��° ���� ���� �� �ι�° ������ Ž������ ����, �ι�° ���� ���� �� ����° ������ Ž������ ����
	//�̴� ������ ���� ���� �ݺ��� ��ø Ƚ���� �ٸ�.
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