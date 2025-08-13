#include <bits/stdc++.h>
using namespace std;

namespace My {
	int _size;
	int m, n;

	int A[2004];
	int B[2004];
	int ret;

	//A,B누적합
	int A_piece[1000004];
	int B_piece[1000004];


	void sol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> _size;
		cin >> m >> n;

		int A_total = 0;
		int B_total = 0;
		for (int i = 0; i < m; i++) {
			cin >> A[i];
			A[i + m] = A[i];
			A_piece[A[i]]++;
			A_total += A[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> B[i];
			B[i + n] = B[i];
			B_piece[B[i]]++;
			B_total += B[i];
		}

		A_piece[A_total]++;
		B_piece[B_total]++;

		//A,B피자의 모든 시작점-끝점 구간에 대한 누적합 계산
		int sum = 0;
		for (int i = 0; i < m; i++) { //A피자 시작점
			sum = A[i];
			for (int j = i + 1; j < i + m - 1; j++) { //A피자 끝점
				sum += A[j];
				A_piece[sum]++;
			}
		}

		for (int i = 0; i < n; i++) { //B피자 시작점
			sum = B[i];
			for (int j = i + 1; j < i + n - 1; j++) { //B피자 끝점
				sum += B[j];
				B_piece[sum]++;
			}
		}


		A_piece[0] = B_piece[0] = 1;
		for (int i = 0; i <= _size; i++) {
			ret += (A_piece[i] * B_piece[_size - i]);
		}

		cout << ret << "\n";
	}
}

namespace Sol {
	int a[1001], b[1001], ret, psum_a[2002], psum_b[2002], 
		want, n, m;
	map<int, int> aCnt, bCnt;

	void make(int n, int psum[], map<int, int>& mp) {
		for (int interval = 1; interval <= n; interval++) {
			for (int start = interval; start <= n + interval - 1; start++) {
				int sum = psum[start] - psum[start - interval];
				mp[sum]++;
				if (interval == n) break;
			}
		}
	}

	void sol() {
		scanf("%d %d %d", &want, &n, &m);

		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			psum_a[i] = psum_a[i - 1] + a[i];
		}

		for (int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n];

		for (int i = 1; i <= m; i++) {
			scanf("%d", b + i);
			psum_b[i] = psum_b[i - 1] + b[i];
		}

		for (int i = m + 1; i <= 2 * m; i++) psum_b[i] = psum_b[i - 1] + b[i - m];

		make(n, psum_a, aCnt);
		make(m, psum_b, bCnt);

		for (int i = 1; i < want; i++) {
			ret += (aCnt[i] * bCnt[want - i]);

		}
		printf("%d\n", ret);

	}
}

int main() {
	
}