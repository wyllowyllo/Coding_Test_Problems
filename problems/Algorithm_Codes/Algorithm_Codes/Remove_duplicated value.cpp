#include <bits/stdc++.h>
using namespace std;

vector<int> values = { 1,1,2,2,3,3,4,4,5,5,5 };
vector<int> values_2 = { 2,3,3,4,1,1,1,1,4,5,6,7,8,9 };

void Solution_1() {
	map<int, bool> value_map; //���� �ߺ� Ű�� ������� ������, �̸� �̿��Ͽ� �迭���� �ߺ� ���Ҹ� ������ �� �ִ�.

	for (int i : values) {
		if (value_map[i])
			continue;
		value_map[i] = true;
	}

	vector<int> result;
	for (auto value : value_map) {
		result.push_back(value.first); //Ű�� ����
	}

	for (auto value : result)
		cout << value << " ";
}
void Solution_2() {
	//Unique() �޼��� Ȱ���ϱ�
	sort(values_2.begin(), values_2.end()); //�������� ����
	auto endIdx=unique(values_2.begin(), values_2.end()); //unique ��ȯ����, ���� �迭�� ��� ���� ���Եǰ� �ߺ��� �κ��� ���ŵ� ������ �迭�� �� ���� ��ġ(�ߺ����� ����+1 �� ��ġ)
	values_2.erase(endIdx, values_2.end()); //�ߺ����� ������ ���ҹ迭�� ������ ������ ����

	for (auto value : values_2)
		cout << value << " ";

	
}
int main() {
	//Solution_1();
	Solution_2();
}