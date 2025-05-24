#include <bits/stdc++.h>
using namespace std;


#pragma region MySol

namespace MySol {

	typedef long long ll;

	int n;
	int che[4000001]; //에라토스테네스체
	ll p[4000001]; //누적합

	int ret;


	vector<int> getprimes() {
		vector<int> v;

		for (int i = 2; i <= n; i++) {
			if (che[i]) continue;

			for (int j = i * 2; j <= n; j += i) {
				che[j] = 1;
			}
		}
		for (int i = 2; i <= n; i++)
			if (che[i] == 0)
				v.push_back(i);

		return v;
	}

	void Sol() {
		cin >> n;

		vector<int> primes = getprimes();



		for (int i = 0; i < primes.size(); i++) {
			p[i + 1] = primes[i] + p[i];
		}

		//처음에 시도한 방법 -> 시간초과


		/*for (int i = 1; i <=primes.size(); i++) {
			if (p[i] < n) continue;
			else if (p[i] == n) {
				ret++;
				continue;
			}
			else {
				for (int j = 1; j < i; j++) {
					if (p[i] - p[j] == n) {
						ret++;
						break;
					}
					else if (p[i] - p[j] < n) break;
				}
			}

		}*/

		//두번째 시도한 방법 -> 투포인터 사용
		//성공!!
		int start = 0;
		int end = 1;

		while (start < end && end <= primes.size()) {
			if (p[end] - p[start] == n) {
				ret++;
				end++;
			}
			else if (p[end] - p[start] < n) end++;
			else start++;
		}



		cout << ret << "\n";
	}

}
#pragma endregion




#pragma region Sol_1

bool che[4000001];
int n, a[2000001], p, lo, hi, ret, sum;


void Sol_1() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			che[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!che[i]) a[p++] = i;
	}

	while (1) {
		if (sum >= n) sum -= a[lo++];
		else if (hi == p) break;
		else sum += a[hi++];
		if (sum == n) ret++;
	}

	printf("%d\n", ret);
}
#pragma endregion

int main() {
	Sol_1();


	
}