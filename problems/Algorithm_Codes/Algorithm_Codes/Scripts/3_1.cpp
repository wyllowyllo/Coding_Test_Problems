#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v;

#pragma region Ex1
bool check(int n) {
	if (n <= 1) return 0; //1 이하라면 소수가 아니다
	if (n == 2) return 1; //2 라면 소수이다
	if (n % 2 == 0) return 0; //2로 나누어 떨어진다면 소수가 아니다

	//인수 구하기
	for (int i = 3; i * i <= n; i++) {
		if (n % i == 0) return 0; //나누어떨어진다면 i를 인수로 가지는 경우이다
	}

	return 1;

}
//최종적으로 go에서 반환되는 값은, sum이 소수가 되는 경우의 수임
int go(int idx, int sum) {

	//기저사례 : idx가 끝까지 도달했다면, 이때까지 합한 sum을 판별한다
	if (idx == n) {
		return check(sum);
	}

	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);//idx를 증가시켜나가며, v[idx]를 포함시키는 경우와, 포함시키지 않는 경우에 대해 검사한다.
}

void Ex1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	cout << go(0, 0) << "\n";
}

#pragma endregion

#pragma region Ex2

const int mod = 11;
int ret;

void go2(int idx, int sum) {

	if (ret == 10) {
		//문제는 sum을 11로 나누었을 때 나오는 나머지가 가장 큰 값을 구하는 것임
		//근데 mod 11하면 나올 수 있는 가장 큰 값은 10임
		//그러므로, 조합을 구하다가, 이미 최대값 10이 나와버린 경우 더 이상 탐색을 할 필요 없이 바로 종료해버리면 됨( 어차피 10보다 클수가 없음)
		//이를 pruning(가지치기) 라고 함. (가망이 없으면 그냥 버린다)
		return;
	}
	if (idx == n) {
		ret = max(ret, sum % mod);
		return;
	}

	//idx를 증가해가며, 조합에 v[idx]를 포함하는 경우와, 포함하지 않는 경우를 탐색
	go(idx + 1, sum+v[idx]); 
	go(idx + 1, sum);

}

void Ex2() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	go(0,0);
	cout << ret << "\n";

}

#pragma endregion

int main() {
	
}