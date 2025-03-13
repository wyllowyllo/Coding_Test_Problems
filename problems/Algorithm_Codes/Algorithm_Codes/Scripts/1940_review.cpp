#include <bits/stdc++.h>
using namespace std;

int n, m;
int num;
vector<int> nums;
int cnt[10000001];
int total = 0;

int _m[15001] = { 0 };

#pragma region Mysol

//첫번째 시도 : fail
//재료는 '고유'번호를 가진다길래 번호 중복이 안된다는 의미로 이해했는데, 같은 번호를 가진 재료도 있음
// 위 이유로 인해 조합 문제라고 생각을 안했으나, 조합으로 접근해야 함
// 키 포인트 : 문제를 읽고 임의판단 하지말고, 문제에 제시된 조건에만 집중
// 
//두번째 시도 : fail
//번호 중복이 된다는 점까지 고려하여 코드를 수정함(조합을 구한다음 갑옷 개수를 구하는 방식은 아님)
// nt[n]과 cnt[m-n]의 각 개수를 곱하여 만들 수 있는 갑옷의 개수를 구하는 방식으로 구현함
// 그러나 예외(n == m-n 인 경우) 상황에서 올바른 답을 내놓지 못하여 실패
//아래 코드 수정본으로 조합을 구하진 않지만, 올바른 답을 출력함

//결론 : 문제를 제대로 읽고 임의판단하지 말자. (조합을 구하지 않고 답을 구하려했으나, 예외상황때문에 결국 조합을 구해야 함. 이건 조합 문제가 맞음)
void Mysol() {
	int count = 0;


	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
		cnt[num]++;
	}

	for (auto n : nums) {

		if (n >= m)
			continue;

		if (cnt[m - n]) {

			if (n == m - n) count += (cnt[n] * (cnt[n] - 1) / 2); //기존 코드에서는 이 부분이 없었기 때문에 false뜸. (n == m-n인 경우) 이럴경우 그냥 nCr을 구함 -> 결국 조합을 구해야 하네...
			else count += cnt[m - n] * cnt[n];

			cnt[m - n] = 0;
			cnt[n] = 0;
		}
	}

	cout << count << "\n";
}

#pragma endregion

#pragma region Sol_1
void Sol_1() {
	int a[15001] = { 0 };
	int count = 0;
	//재료 2개를 뽑는 조합이므로, 이중 중첩 반복문으로 조합 구할 수 있다
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (m > 200000) cout << 0 << "\n"; //재료 최대값이 10만이므로, 합은 20만을 넘길수 없다
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] + a[j] == m) count++;
			}
		}
		cout << count << "\n";
	}
}
#pragma endregion


#pragma region MySol_2
//재귀를 사용하여 조합 구하기
void combi(int startIdx, vector<int> &v) {
	if (v.size() == 2) {
		int sum = 0;
		for (auto a : v) sum += a;

		if (sum == m) total++;

		return;

	}
	for (int i = startIdx + 1; i < n; i++) {
		v.push_back(_m[i]);
		combi(i, v);
		v.pop_back();
	}
}
void MySol_2(){
	
	for (int i = 0; i < n; i++) {
		cin >> _m[i];
	}

	vector<int> v;
	combi(-1, v);

	cout << total << "\n";
}
#pragma endregion






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	//Mysol();
	//Sol_1();
	MySol_2();
}