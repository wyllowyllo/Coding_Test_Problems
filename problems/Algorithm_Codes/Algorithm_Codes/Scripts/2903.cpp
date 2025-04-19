#include <bits/stdc++.h>
using namespace std;

int n;
int ret = 2; //처음 사각형의 한 변의 점은 2개


#pragma region MySol

//한변 위에 존재하는 점의 개수의 제곱 == 모든 점의 개수
//따라서 관계식을 구해 n번 분할 시 점의 개수를 누적해 나감

void MySol() {
	cin >> n;



	for (int i = 0; i < n; i++) {
		int p = ret + pow(2, i); //사각형를 분할해 나갈수록, 한 변 위에 존재하는 점의 개수는 2,3,5,9,17... 개로 증가. 즉 n번째 분할시 점의 개수= n-1번째 분할때의 점의 개수 + 2^(n-1)
		ret = p;
	}




	cout << ret * ret << "\n";
}

#pragma endregion

#pragma region Sol_1

//문제 : 정사각형을 n번 반복해서 분할할 때, 총 점의 개수를 구해라

/*
n = 0 → 2 x 2 점 (총 4점)

n = 1 → 3 x 3 점 (총 9점)

n = 2 → 5 x 5 점 (총 25점)

n = 3 → 9 x 9 점 (총 81점)

n = 4 → 17 x 17 점 (총 289점)

즉, 점 개수 = (한 변의 점 개수)^2
*/

//핵심 아이디어 : 점화식 유도
/*
한 변의 점 개수를 ret이라고 할 때

ret₀ = 2
ret₁ = 2 + 2⁰ = 3
ret₂ = 3 + 2¹ = 5
ret₃ = 5 + 2² = 9
ret₄ = 9 + 2³ = 17
ret₅ = 17 + 2⁴ = 33
...

결국 점화식은 retₙ = retₙ₋₁ + 2^(n-1)

즉 retₙ = 2 + (2⁰ + 2¹ + 2² + ... + 2ⁿ⁻¹)
     = 2 + (2ⁿ - 1)   // 등비수열 합
     = 2ⁿ + 1
*/
void Sol_1() {
	cin >> n;
	int ret = (1 << n) + 1; // 2^n + 1 -_> 비트마스킹으로 2^n표현
	cout << ret * ret << '\n';
}
#pragma endregion

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Sol_1();
}