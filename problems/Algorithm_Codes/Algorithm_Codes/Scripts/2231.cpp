#include <bits/stdc++.h>
using namespace std;

int n;
int num;
int ret;
int main() {

	//시간복잡도 : n이 최대 100만이고, 이때의 자릿수는 7자리. 즉 대략적으로 n*7정도의 시간복잡도
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num = i;
		string s = to_string(i);
		
		for (int j = 0; j < s.size(); j++)
			num += (s[j] - '0');

		if (num == n) {
			ret = i;
			break;
		}
	}

	cout << ret << "\n";
}