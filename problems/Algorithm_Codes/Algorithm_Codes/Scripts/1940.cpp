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
	
	
	/* ���� ���� �߸���->�� ���� ���� �ϳ��� ������ ����⿡, ������ ����� �ش� ������ ������� �ɷ� �����ߴµ�, �׳� �ܼ��� ������ ���� �� ������ ���ո� ���ϴ� ��������...
	   ������ ��޵��� �ʴ� ���׿� ���� ���������ؼ� Ǯ�� �ʱ� ! */
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

	//if (M > 200000) cout << 0 << "\n"; //(���ʿ� �Ұ����� ��� ����)����� ������ȣ�� �ִ� 100,000�̹Ƿ� ���� �ִ� 200,000�̴�.
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

	//recursion�� �̿��Ͽ� combination����� -> �̶� call by value�� �ϸ� �ð��ʰ���! call by reference�� �ϱ�!
	for (int i = 0; i < N; i++) cin >> a[i];
	vector<int> set;
	if (M > 200000) cout << 0 << "\n";
	else {
		Combi(-1, set);
		cout << cnt << "\n";
	}
		
	return 0;
}