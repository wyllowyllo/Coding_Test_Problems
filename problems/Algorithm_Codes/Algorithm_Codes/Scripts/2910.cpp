#include <bits/stdc++.h>
using namespace std;


int n, c;
int num;

map<int, int> frequencyMap;//����-�� map
map<int, int>orderMap;//����-������� map

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> num;
		frequencyMap[num]++;

		if (orderMap[num] == 0)
			orderMap[num] = (i + 1);
	}

	
	pair<int, int >v = {0,0};
	//����-�� map �����Ͽ�, �� ���������� ���� -> �� ���� ��� ������� ��

	while (frequencyMap.size()) {
		v = { 0,0 };
		for (auto i : frequencyMap) {
			if (v.second < i.second) {
				v = i;
			}
			else if (v.second == i.second) {
				if (orderMap[v.first] > orderMap[i.first])
					v = i;
			}
		}

		for (int i = 0; i < v.second; i++)
			cout << v.first << " ";

		frequencyMap.erase(v.first);
	}

	
	

}