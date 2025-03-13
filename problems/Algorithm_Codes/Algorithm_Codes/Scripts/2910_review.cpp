#include <bits/stdc++.h>
using namespace std;


#pragma region MySol
//우선 빈도수가 많은 순으로 정렬을 하되, 같은 빈도수의 숫자에 대해서는 먼저 입력된 수를 우선으로 한다
//3개의 map을 사용하여 구현하였다(m1 : 각 숫자의 빈도, m2: 각 빈도별 해당 수들, m3 : 각 숫자 입력 순서)


map<int, int> m1; //숫자, 빈도
map<int, vector<int>, greater<int>> m2; //빈도, 숫자  -> 키에 대해 내림차순 정렬됨.
map<int, int> m3; //숫자, 입력순서

int n, c;
int temp;

void MySol() {
	cin >> n >> c;

	//우선 각 숫자의 빈도수를 저장하고, 각 숫자가 처음 입력됐을 때의 순서를 저장한다.
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m1[temp]++;

		if (m3[temp] == 0) m3[temp] = i + 1;
	}

	// 빈도수를 키로 하여 숫자들을 관리하는 map
	for (auto v : m1) {
		m2[v.second].push_back(v.first);
	}

	//m2는 빈도수 기준 내림차순으로 정렬된 상태이다. 이제 같은 빈도수를 가진 숫자들에 대해, 입력 순서가 빠른 것부터 출력한다.
	for (auto v : m2) {

		vector<int> nums = v.second;

		while (nums.size()) {

			int inputOrder = 1001;
			int targetNum;
			int pos = 0;

			for (int i = 0; i < nums.size(); i++) {
				if (m3[nums[i]] < inputOrder) {
					inputOrder = m3[nums[i]];
					targetNum = nums[i];
					pos = i;
				}
			}

			nums.erase(nums.begin() + pos);
			for (int j = 0; j < v.first; j++)
				cout << targetNum << " ";
		}

	}
}
#pragma endregion

#pragma region Sol_1
//여기서는 두 개의 map을 통해 구현하였다(카운팅배열, 입력순서 관리 map)
//이 문제를 보고, 커스텀 operation을 활용해야겠다는 생각을 해야한다.

typedef long long ll;
const ll INF = 1e18;
int a[1004];
vector<pair<int, int>> v1; //{빈도수, 숫자}
map<int, int> mp, mp_first; 

//cmp함수는 두 원소를 비교할 때 "이것이 저것보다 먼저 와야 하는지"를 결정하는 역할
//즉, std::sort 내부에서 두 원소 a와 b를 비교할 때, cmp(a, b)가 true를 반환하면 a가 b보다 앞에 오도록 정렬합니다.
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) { //빈도수가 같다면
		return mp_first[a.second] < mp_first[b.second]; //입력순서 비교
	}

	return a.first > b.first; //빈도수가 다를경우, 빈도수 큰 쪽을 기준으로 정렬
}

void Sol_1() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++; //카운팅배열
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; //첫번째 입력순서 저장

	}

	for (auto it : mp) {
		v1.push_back({ it.second, it.first });
	}

	sort(v1.begin(), v1.end(), cmp); //sort는 cmp가 true가 되는 케이스로 정렬
	

	//이제 v1은 빈도수로 내림차순 정렬하되, 같은 빈도수에 대해서는 먼저 입력된 수에 대해서  정렬됨.
	for (auto i : v1) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}

}


#pragma endregion


int main() {
	
	

	
	
}