#include <bits/stdc++.h>
using namespace std;



int n;
int t;

//map<int, int> m1;
vector<int> v;

vector<int> diffs;


int cnt;

int gcd(int a, int b) {
	if (a == 0) return b;

	return gcd(b % a, a);
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;


		if (v.size()) { diffs.push_back(t - v[v.size() - 1]); }
		v.push_back(t);
		//m1[t] = 1;
	}

	//이제, diffs안에 들어있는 모든 간격 값(a,b,c....)의 최대공약수를 구해야 함
	//GCD(a, b, c) == GCD(GCD(a, b), c) --> 결합법칙 성립 !!! 이 원리를 이용하자!!
	int e = diffs[0];

	for (int i = 1; i < diffs.size(); i++) {
		e = gcd(diffs[i], e); //gcd(gcd(gcd()))...이런식
	}

	/*for (int i = v[0]; i < v[v.size() - 1];) {
		if (!m1[i + e])cnt++;
		i += e;
	}*/


	//이제 나무를 심을 최대간격을 구했다. 몇 그루를 더 심어야 하는가?
	int range = v[v.size() - 1] - v[0];
	int totalTree = range / e + 1; //이 간격 사이에 있어야 하는 총 나무 그루 수
	totalTree -= n; //이미 심어져 있는 나무 그루 수 제외

	cout << totalTree << "\n";
}