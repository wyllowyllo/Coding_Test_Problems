#include <bits/stdc++.h>
using namespace std;


int n, c;
int num;

map<int, int> frequencyMap;//숫자-빈도 map
map<int, int>orderMap;//숫자-등장순서 map

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> num;
		frequencyMap[num]++;

		if (orderMap[num] == 0)
			orderMap[num] = (i + 1);
	}

	
	pair<int, int >v = {0,0};
	//숫자-빈도 map 조사하여, 빈도 높은순으로 정렬 -> 빈도 같을 경우 등장순서 비교

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