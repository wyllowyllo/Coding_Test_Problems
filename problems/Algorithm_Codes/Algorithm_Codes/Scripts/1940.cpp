#include <bits/stdc++.h>
using namespace std;

map<int, int> materials;

int a[150001];
int N, M;
int cnt = 0;

void Combi(int startIdx, vector<int> &set) {
	if (set.size() ==2) {
		int sum = 0;
		for (int j : set) sum += j;
		if (sum == M) cnt++;
		return;
	}
	for (int i = startIdx + 1; i < N; i++) {
		set.push_back(a[i]);
		Combi(i, set);
		set.pop_back();
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	


	//--------------------------My solution (Wrong) -------------------------------------------
	
	
	/* 문제 이해 잘못함->두 개의 재료로 하나의 갑옷을 만들기에, 갑옷을 만들면 해당 재료들은 사라지는 걸로 이해했는데, 그냥 단순히 재료들이 있을 때 가능한 조합만 구하는 문제였음...
	   문제에 언급되지 않는 사항에 대해 지레짐작해서 풀지 않기 ! */
	/*int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		materials[input]++;

		if (materials[M - input]) {
			materials[input]--;
			materials[M - input]--;
			count++;
		}
	}

	cout << count << "\n";*/

	//-----------------------------------------------------------------------------------------

	//---------------------------------Solution 1--------------------------------------------
	//for (int i = 0; i < N; i++) cin >> a[i];

	//if (M > 200000) cout << 0 << "\n"; //(애초에 불가능한 경우 제외)재료의 고유번호는 최대 100,000이므로 합은 최대 200,000이다.
	//else {
	//	for (int i = 0; i < N; i++) {
	//		for (int j = i + 1; j < N; j++) {
	//			if (a[i] + a[j] == M) cnt++;
	//		}
	//	}
	//	cout << cnt << "\n";
	//}
	

	//---------------------------------------------------------------------------------------

	//----------------------------------Solution 2-------------------------------------------

	//recursion을 이용하여 combination만들기 -> 이때 call by value로 하면 시간초과남! call by reference로 하기!
	for (int i = 0; i < N; i++) cin >> a[i];
	vector<int> set;
	if (M > 200000) cout << 0 << "\n";
	else {
		Combi(-1, set);
		cout << cnt << "\n";
	}
		
	return 0;
}