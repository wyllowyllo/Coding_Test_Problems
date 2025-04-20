#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


lli a, b;



lli gcd(lli i, lli j) {
	if (i == 0) return j;

	return gcd(j % i, i);
}

lli lcm(lli i, lli j) {
	return (i * j) / gcd(i, j);
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	cout << lcm(a, b) << "\n";
	
}