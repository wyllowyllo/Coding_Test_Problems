#include <bits/stdc++.h>
using namespace std;




//-------------------------------------------------My solution ---------------------------------------------//
/*
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
*/
//---------------------------------------------------------------------------------------------------------------

//----------------------------------------------Solution 1 -----------------------------------------------------

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first; //각각 숫자-빈도, 숫자-등장순서

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return mp_first[a.second] < mp_first[b.second]; //빈도수 같으면 먼저나온 수를 기준으로 정렬
	return a.first > b.first; //빈도수 많은순 정렬
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
	}

	for (auto i : mp) {
		v.push_back({ i.second, i.first }); //빈도수-숫자 쌍으로 push(빈도순으로 vector정렬위해)
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}

}