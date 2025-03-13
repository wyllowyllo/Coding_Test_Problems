#include <bits/stdc++.h>
using namespace std;


int n, k;
int psum[1000001] = { 0 };
int v;

#pragma region MySol

//최솟값을 처음에 그냥 0으로 설정해버려서 첫 시도에 틀렸음. 문제를 보고 최솟값을 어떻게 설정할지 생각하기
void MySol() {

	for (int i = 1; i <= n; i++) {
		cin >> v;
		psum[i] = v + psum[i - 1];
	}

	int max = -100000000000;
	int sum = 0;
	for (int i = 1; i + k - 1 <= n; i++) {
		sum = psum[i + k - 1] - psum[i - 1];
		if (max < sum) max = sum;
	}
	cout << max << "\n";
}
#pragma endregion

#pragma region Sol_1

// 이 문제는 최솟값을 어떻게 설정하는지가 관건임.
// 이 문제의 최솟값은 ? -100*(10만번) >> -1000만

void Sol_1() {
	int ret=-10000004;
	
	for (int i = 1; i <= n; i++) {
		cin >> v; psum[i] = v + psum[i - 1];
	}
	for (int i = k; i <= n; i++) {
		ret = max(ret, psum[i] - psum[i - k]);
	}
	cout << ret << "\n";
}
#pragma endregion

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> k;
	
	//MySol();
	
}