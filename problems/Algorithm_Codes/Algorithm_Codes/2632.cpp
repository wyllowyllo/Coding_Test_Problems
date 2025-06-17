
#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;


namespace My {
#pragma region MySol
	int pizza;
	int m, n;


	int A[MAX]; //피자 A에서 나올 수 있는 모든 종류의 피자 크기의 경우의 수
	int B[MAX]; //피자 B에서 나올 수 있는 모든 종류의 피자 크기의 경우의 수


	int A_cnt[1001];
	int B_cnt[1001];

	int tmp;
	int A_idx, B_idx;

	int ret;

	void MySol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> pizza;
		cin >> m >> n;

		for (int i = 1; i <= m; i++) {
			cin >> tmp;

			A_cnt[i] = A_cnt[i - 1] + tmp; //피자 누적합

		}

		//직선구간 처리
		//구간 시작부분 증가
		for (int j = 0; j <= m - 1; j++) {

			//구간 끝부분 감소
			for (int i = m; i > j; i--) {
				A[A_cnt[i] - A_cnt[j]]++;
			}
		}

		//여기서는 마지막 조각이 구역 끝이 아니고 구역 시작인 경우와, 구역 사이에 포함된 경우를 처리함
		//wrap-around구간 처리 (피자 끝과 시작이 연결되는 부분 포함하는 구역 크기 계산)
		for (int i = m; i >= 2; i--) { //구역 시작부분 인덱스 감소
			for (int j = 1; j < i - 1; j++) { //구역 끝부분 인덱스 증가
				A[A_cnt[m] - (A_cnt[i - 1] - A_cnt[j])]++; //전체 피자 크기 - (구역 시작부분 인덱스-1까지의 누적합 - 구역 끝부분 인덱스까지의 누적합)
			}

		}


		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			B_cnt[i] = B_cnt[i - 1] + tmp;//피자 누적합

		}

		//구간 시작부분 증가
		for (int j = 0; j <= n - 1; j++) {

			//구간 끝부분 감소
			for (int i = n; i > j; i--) {
				B[B_cnt[i] - B_cnt[j]]++;
			}
		}

		//여기서는 마지막 조각이 구역 끝이 아니고 구역 시작인 경우와, 구역 사이에 포함된 경우를 처리함
		//wrap-around구간 처리 (피자 끝과 시작이 연결되는 부분 포함하는 구역 크기 계산)
		//이는 전체 피자 크기 - 연산 제외 피자 구역 크기 계산하여 wrap around 구간 계산함
		for (int i = n; i >= 2; i--) { //구역 시작부분 인덱스 감소(이때, 이 구역은 연산 제외되는 구역의 시작부분임)
			for (int j = 1; j < i - 1; j++) { //구역 끝부분 인덱스 증가(이때, 이 구역은 연산 제외되는 구역의 끝부분임)
				B[B_cnt[n] - (B_cnt[i - 1] - B_cnt[j])]++; //전체 피자 크기 - (구역 시작부분 인덱스-1까지의 누적합 - 구역 끝부분 인덱스까지의 누적합)
			}

		}

		//A피자에서 나올수 있는 모든 피자크기 종류(i)에 대해 A+B=pizza인 경우의 수 탐색
		for (int i = 0; i < MAX; i++) {
			if (A[i]) {
				if (i == pizza) ret += A[i];
				else if (i < pizza) {
					if (B[pizza - i]) {
						ret += A[i] * B[pizza - i];
					}
				}
			}
		}

		if (B[pizza]) ret += B[pizza];

		cout << ret << "\n";
	}

#pragma endregion
}



#pragma region Sol_1
//A피자에서 만들어 낼 수 있는 크기의 경우의 수를 배열에 저장하고,
//B피자에서 만들어 낼 수 있는 크기의 경우의 수도 따로 배열에 저장한다.
//이후 A피자만으로 크기를 만들어 낼 수 있는 경우의 수 + B피자만으로 크기를 만들어 낼 수 있는 경우의 수 와,
//A,B피자를 통해 만들어 낼 수 있는 경우의 수(피자의 크기 k라 하면, A[n]*B[k-n]이런식으로 경우의 수 계산)

//문제와 같이, 원형 자료구조(끝과 시작이 이어지는) 에서 모든 연속된 구간을 구하는 것은 구현이 까다로움
//따라서, 원형 자료구조 -> 선형적인 자료구조로 만들어 보자!
//예를들어 피자가 (7,2,2,2,1)으로 구성되어있다 하면, (7,2,2,2,1)이걸 한번더 붙여서 (7,2,2,2,1,7,2,2,2,1)이런식으로 만들어서 계산해보자!

//이 문제와 같이 구간 쿼리를 구하는 문제는, 누적합을 사용하여 풀 생각을 하자!

/*
문제를 푸는 흐름 정리

1.처음에, 각 피자에서 만들 수 있는 모든 크기의 경우의 수를 구해서 배열에 저장하고자 함
2.그러나 그렇게 하니 수가 너무 많아져서 비효율... -> 이 문제는 경우의 수를 구하는 문제니까, 크기 자체를 저장하지 말고, 그 크기를 만들 수 있는 횟수(경우의 수)를 배열에 저장하자!
3. 원형 자료구조는 선형으로 바꿔보자!
4. 구간쿼리 문제는, 누적합을 생각해라!
*/
int a[1001], b[1001], ret,  want, n, m;

int psum_a[2002], psum_b[2002]; //원형 자료구조를 2배 크기의 선형자료구조로 만들었으므로, 누적합 배열 범위도 2배로!
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int> &mp) {
	for (int interval = 1; interval <= n; interval++) { //1~n크기까지 묶기
		for (int start = interval; start <= n + interval - 1; start++) {
			int sum = psum[start] - psum[start - interval];
			mp[sum]++;
			if (interval == n) break;
		}

	}
}

void Sol_1() {
	scanf("%d %d %d", &want, &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		psum_a[i] = psum_a[i - 1] + a[i]; //누적합 계산
	}

	for (int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n]; //2배 크기의 선형 자료구조를 가정하고, 그에 대한 누적합도 만들기

	for (int i = 1; i <= m; i++) {
		scanf("%d", b + i);
		psum_b[i] = psum_b[i - 1] + b[i];
	}
	for (int i = m + 1; i <= m * 2; i++) psum_b[i] = psum_b[i - 1] + b[i - m];

	make(n, psum_a, aCnt); //A피자에 대한 모든 경우의 수 생성
	make(m, psum_b, bCnt); //B피자에 대한 모든 경우의 수 생성

	ret = (aCnt[want] + bCnt[want]); //A,B각각에서 want사이즈 만들어 낼 수 있는 경우의 수
	for (int i = 1; i < want; i++) {
		ret += (aCnt[i] * bCnt[want - i]); //A와 B합쳐서 만들 수 있는 경우의 수 합산
	}

	printf("%d\n", ret);
}
#pragma endregion




int main() {
	Sol_1();
}
