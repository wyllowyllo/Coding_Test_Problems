#include <bits/stdc++.h>
using namespace std;

#pragma region MySol

//투포인터를 이용하여 풀었음
//처음에 ret을 int로 설정해서 오답이 됨..
//이 문제의 수열 최대길이는 10만이고 모든 원소가 서로 다를때 경우의 수는 O(n^2)이므로 int범위를 능가함
//long long 타입으로 바꾸니 성공!

typedef long long ll;
int n;
ll ret;

int visited[100001];

void MySol() {
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int start = 0;
	int end = 0;


	while (start <= end) {
		if (end == n) {
			ret += end - start;
			start++;
			continue;
		}

		if (visited[v[end]]) {

			ret += end - start;


			visited[v[start]] = 0;
			start++;
		}
		else {

			visited[v[end]] = 1;
			end++;
		}

	}

	cout << ret << "\n";
}
#pragma endregion


#pragma region Sol_1

//팁 : 경우의 수 문제는 그냥 long long 쓰기! (크기가 int초과하는 문제가 많음)

/*
일단 이 문제는 투포인터를 이용해서 배열 내의 모든 유일한 요소로 구성된 부분 배열을 찾아야 합니다.

왜 그런 생각이 나왔냐라는 것에 대한 플로우를 생각해보면...

이문제를 보시고 범위기반으로 유일한 요소로 구성됨->범위 ? ->투포인터로 범위를 정해서 해볼까 ? ->투포인터로 풀 생각을 해야 함.->배열의 시작과 끝을 동시에 관리할 수 있어, 중복 요소를 빠르게 탐지하고 처리할 수 있기 때문이죠.



자 그러면 투포인터로 어떻게 풀어야할까 ? 까지 와야 합니다.

일단 e, s를 기반으로 지금의 범위를 만들고 -> (e - s)를 더해서->현재 s에서 e까지의 모든 유일한 부분 배열에 대한 것을 고려할 수 있지 않을까 ? ->그러면서 ..e 포인터를 오른쪽으로 이동하며 새로운 요소를 추가하고 새 요소가 중복되지 않으면 계속 이동하고, 중복되면 s 포인터를 오른쪽으로 이동하여 중복 요소를 제거하는 식으로다가 해볼까 ?



근데? 마지막에 와서는 e - s를 더하면 될까? 어 ? 안되네 ? ->아아..이 때는(e - s) * (e - s + 1) / 2를 더해서 그 때의 모든 유일한 부분 배열을 한 번 더 계산해야 정답이구나

이래서 2개의 로직이 나오게 되는 것입니다.
*/



namespace Sol_1 {
	long long s, e,n;
	long long cnt[100001], a[100001];

	void Sol() {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", a + i); //배열 a에 값 저장
		}

		while (e < n) {
			if (!cnt[a[e]]) { //아직 중복되는 수가 나온적 없는 경우
				cnt[a[e]]++;
				e++;
			}
			else {
				ret += (e - s); //이 idx를 포함한 unique한 수열의 경우의 수 구해서 더하기
				cnt[a[s]]--;
				s++;
			}
		}

		//반복문 탈출 시, 남아있는 범위에 대해서, 그 범위에서 만들 수 있는 유니크한 수열 개수 구하기
		//ex) 1 2 3 1 2 에서 s=2이고 e=4인 상황, 이 범위에서 나올 수 있는 경우는 {3}, {1}, {2}, 
		//																		{3,1}, {1,2},
		//																				{3,1,2} 총 6가지이다. (따라서 기존처럼 e-s를 더하는 거로 안됨)
		//다시보면 이것은 원소3개짜리 1개, 2개짜리 2개, 1개짜리 3개인 상황. 즉 경우의 수는 1+2+3 과 같다. -> 등차수열의 합 공식을 사용하면 바로 구할수 있음!

		ret += (long long)(e - s) * (e - s + 1) / 2; //이 범위에서 unique한 수열의 경우의 수 구해서 더하기
		printf("%lld\n", ret);

	}
}

#pragma endregion



int main() {
	


}