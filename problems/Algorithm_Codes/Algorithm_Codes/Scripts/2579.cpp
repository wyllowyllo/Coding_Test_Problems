#include <bits/stdc++.h>
using namespace std;

namespace My {

	//문제 조건 상 마지막 도착 계단을 반드시 밟아야 하는데, 연속한 3개 계단을 밟으면 안된다는 제한 때문에
	//마지막 계단을 안밟은 결과가 최댓값이 되는 케이스가 발생함..
	//계속 생각해봤는데, 그냥 시작지점에서 재귀 시작하지 말고 , 역으로 마지막 계단에서 시작하게 하는게 제일 확실할 듯...

	//그래도 안되길래, 혹시 상태값 하나로 한게 문제인가 싶어서 각 계단을 몇번 순서로 밟았는지를 상태값으로 해서, 2차원 dp로 해보니 됨..


	/*
	“연속 3칸 금지” 때문에 현재 칸 i의 최댓값만 저장하면, 그 값이 i-1을 밟고 온 경우인지 i-2에서 점프해 온 경우인지를 알 수 없어서 다음 상태로의 선택 가능성이 달라집니다.
즉, 미래 전이( i+1 로 갈 수 있는지)가 달라지니, 상태에 “연속으로 밟은 개수(or 직전 선택 여부)”를 포함해야 합니다
	
	만약 1차원 dp로 하려면, 
	dp[i] = max(dp[i-2], dp[i-3] + a[i-1]) + a[i]

초기값:
dp[1]=a[1], dp[2]=a[1]+a[2], dp[3]=max(a[1], a[2]) + a[3]
여기서 dp[i-3] + a[i-1] 항이 “i-1을 밟고 오되 i-2는 건너뛴 경우”를 암묵적으로 담아 연속 3칸을 방지합니다.

이런식으로 해야 함
	*/
	int n;
	int point[304];

	int dp[304][4];

	int go(int here, int cnt) {
		if (cnt == 3 && here>=1) return -1e9;
		if (here < 1) {
			return 0;
		}

		int& ret = dp[here][cnt];
		if (ret) return ret;


		ret = max(go(here - 1, cnt + 1), go(here - 2, 1)) + point[here];
		return ret;
	}

	void sol() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> point[i];
		}

		cout << go(n, 1) << "\n";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	My::sol();
}