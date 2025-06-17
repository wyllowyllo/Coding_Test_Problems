#include <bits/stdc++.h>
using namespace	std;

#pragma region MySol

//전체 누적합에서 suffix 누적합을 빼는 방식으로 부분합 구함
//이때 부분합이 최대가 되기 위해선, 최소가 되는 suffix(0이하의 값을 가지게 됨)를 구한 다음 그 부분을 제거하면, 전체 부분합에서 -로 작용하는 부분을 제거하는 것이므로, 자연스레 최대의 누적합을 구할 수 있을 것이라 생각함
const int MAX = 987654321;
const int MIN = -987654321;

int cnt[100001];

int n, tmp;
int ret = MIN;

int suffix = MAX;

void MySol() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cnt[i + 1] = cnt[i] + tmp;

		suffix = min(suffix, cnt[i]);

		ret = max(ret, max(cnt[i + 1], cnt[i + 1] - suffix));
	}

	cout << ret << "\n";
}
#pragma endregion

#pragma region Sol

//누적된 합 자체가 음수라면 버리고, 양수라면 계속 더하면서, 각 구간마다 max값을 구해서 값을 갱신해 나가며 최댓값을 구함

int sum, int a;

void Sol() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		sum += a;
		ret = max(ret, sum);

		if (sum < 0) sum = 0; //만약 계속 누적하다 구간 합이 음수가 되는 경우면, 구간에 포함시키지 않고 다시 처음부터 시작

	}

	printf("%d\n", ret);
}
#pragma endregion


int main() {
	
	Sol();
}