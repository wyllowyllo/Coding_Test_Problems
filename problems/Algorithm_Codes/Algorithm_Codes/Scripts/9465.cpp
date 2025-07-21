#include <bits/stdc++.h>
using namespace std;

//이전에 어떤 스티커를 골랐는지에 따라, 이후 어떤 스티커를 선택할 수 있는지가 나뉘므로, 이전의 선택을 dp의 상태값으로 설정해야 함
//그러나 그걸 하나하나 배열의 차원으로 만들어버릴 수는 없으니...(비트마스킹으로 하는것도 안되고) 
//이렇듯 주어진 공간복잡도를 고려할때, 어떻게 상태값을 설정해야 할지, 메모라이제이션할 자료구조를 어떤 걸로 할지 고민을 해봐야 하는 문제

//매 열에 대해서 '위 스티커를 뗀 경우, 아래 스티커를 뗀 경우, 스티커를 떼지 않은 경우' 3가지 경우가 있다는 것을 이용해 DP로 해결해야 하는 문제
int n, t;

int a[2][100001]; //y,x

typedef long long ll;


ll dp[100001][3];//열 번호, 이전 열에서 무엇을 선택했는지(이전 열에서 고르지 않음,이전 열에서 위쪽 고름(0행), 이전 열에서 아래쪽 고름(1행))

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


/// <summary>
/// 
/// </summary>
/// <param name="idx"></param>
/// <param name="prev">0 : 이전 열에서 고르지 않음, 1 : 이전 열에서 첫번째 행 고름, 2 : 이전 열에서 두번째 행 고름 </param>
/// <returns></returns>
ll go(int idx, int prev) {
	if (idx == n) {
		return 0;
	}

	ll& ret = dp[idx][prev];
	if (ret!=-1) return ret;

	ret = go(idx + 1, 0); //이번 열에서 고르지 않음

	//이전 열에서 첫번째 행 고르지 않았다면, 이번 열에서 첫번째 선택 가능 
	if (prev != 1)
		ret = max(ret, go(idx + 1, 1) + a[0][idx]);
	//이전 열에서 두번째 행 고르지 않았다면, 이번 열에서 두번째 선택 가능 
	if (prev != 2)
		ret = max(ret, go(idx + 1, 2) + a[1][idx]);

	return ret;
	
}

void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main() {
	fastIO();
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));

		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		
		//top down 방법
		//cout<<go(0,0)<<"\n";

		//bottom up 방법
		dp[0][0] = 0;
		dp[0][1] = a[0][0];
		dp[0][2] = a[1][0];


		for (int i = 1; i < n; i++) {
			// 아무 것도 안 고르기: 이전 열의 어떤 상태에서든 올 수 있다
			dp[i][0] = max({ dp[i - 1][0],dp[i - 1][1] ,dp[i - 1][2] });
			// 위쪽 고르기: 이전에 위쪽(1)은 금지
			dp[i][1] = max( dp[i - 1][0] ,dp[i - 1][2])+a[0][i];
			// 아래쪽 고르기: 이전에 아래쪽(2)는 금지
			dp[i][2] = max( dp[i - 1][0],dp[i - 1][1])+a[1][i];
		}

		cout << max({ dp[n - 1][0],dp[n - 1][1] ,dp[n - 1][2] })<<"\n";
	}
}