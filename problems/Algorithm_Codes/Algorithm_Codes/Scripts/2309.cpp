#include <bits/stdc++.h>
using namespace std;

int input[9];
vector<vector<int>> resultsList;

void Combi(int startIdx, vector<int> list, int depth) {
	if (depth == 7) {
		resultsList.push_back(list);
		return;
	}

	for (int i = startIdx + 1; i < 9; i++) {
		list.push_back(input[i]);
		Combi(i, list, depth + 1);
		list.pop_back();
	}
}

bool checkSum(vector<int> list) {
	int sum = 0;
	for (int i : list)
		sum += i;

	return (sum == 100);
}

void Print(vector<int> list) {
	for (int i : list) {
		cout << i << '\n';
	}
}

//n�� �� ������ �����ϴ� r�� �̱� == n�� �� ������ �������� ���ϴ� n-r�� ��������
void Solve(pair<int,int>* ret, int sum) {

	
	

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (sum - input[i] - input[j] == 100) {
				*ret = { i,j };
				return;
			}

		}
	}

	

	
}

void Swap(int a_Idx, int b_Idx) {
	int temp = input[a_Idx];
	input[a_Idx] = input[b_Idx];
	input[b_Idx] = temp;
}

vector<int> result;
void Make_Permutation(int n, int r, int depth) {
	if (depth == 7) { 
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += input[i];
		}
		if (sum == 100 && result.size() == 0) {
			for (int i = 0; i < 7; i++)
				result.push_back(input[i]);
			sort(result.begin(), result.end());
			
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		Swap(depth, i);
		Make_Permutation(n,r,depth+1);
		Swap(i, depth);
	}
}




int main() {
	
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
	}

	//---------------------------My Solution-------------------------------------------------
	//vector<int> list;
	//Combi(-1, list, 0);

	////��� ����Ʈ Ž��
	//for (auto result : resultsList) {
	//	if (checkSum(result)) {
	//		sort(result.begin(), result.end()); //�������� ����
	//		Print(result);
	//		break;
	//	}
	//}
	//--------------------------------------------------------------------------------------


	//---------------------------Solution using Permutation---------------------------------
	/*vector<int> inputV;
	for (int i : input)
		inputV.push_back(i);

	sort(inputV.begin(), inputV.end());
	
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += inputV[i];
		}

		if (sum == 100) {
			
			for (int i = 0; i < 7; i++) {
				cout << inputV[i] << '\n';
			}
			break;
		}
	} while (next_permutation(inputV.begin(), inputV.end()));*/

	//----------------------------------------------------------------------------------------

	//---------------------------Solution using the concept "nCr == nCn-r" -------------------
	//int sum = 0;
	//for (int value : input)
	//	sum += value;
	//
	//pair<int, int> ret;
	//vector<int> result;

	////���տ� ���ԵǸ� ������ �������� ���ϴ� ���ҵ� ã��
	//Solve(&ret,sum);

	////�� ���� �� ���� �����
	//for (int i = 0; i < 9; i++) {
	//	if (i == ret.first || i == ret.second) {
	//		continue;
	//	}
	//	result.push_back(input[i]);
	//}

	////���� �� ���
	//sort(result.begin(), result.end());
	//for (int i : result) cout << i << " ";
	//----------------------------------------------------------------------------------------

	//---------------------------Solution using permutation implemented by recursion" -------------------

	Make_Permutation(9, 7,0);
	for (int i : result)
		cout << i << '\n';

	return 0;
}