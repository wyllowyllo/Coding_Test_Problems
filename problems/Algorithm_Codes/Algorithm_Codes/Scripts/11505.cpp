//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, k;
//int a, b, c;
//
//const int MAX = 1000004;
//const int MOD = 1000000007;
//
//int num[MAX];
//int tree[MAX];
//
//void update(int idx,int prev_val ,int new_val) {
//
//	while (idx < MAX) {
//		tree[idx] /= prev_val;
//		tree[idx] = (tree[idx]* new_val)%MOD;
//		idx += (idx & -idx);
//	}
//}
//
//
//int mul(int idx) {
//	int ret = 1;
//	while (idx > 0) {
//		ret = (ret*tree[idx])%MOD;
//		idx -= (idx & -idx);
//	}
//
//	return ret%MOD;
//}
//bool check(int start, int end) {
//	for (int i = start; i <= end; i++) {
//		if (num[i] == 0) return false;
//	}
//
//	return true;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m >> k;
//
//	fill(tree, tree + MAX, 1);
//
//	for (int i = 1; i <= n; i++) {
//		cin >> num[i];
//
//		if(num[i]>0) update(i, 1,num[i]);
//	}
//
//	for (int i = 0; i < m + k; i++) {
//		cin >> a >> b >> c;
//
//		if (a == 1) {
//			int prev = num[b];
//			num[b] = c;
//
//			if (prev == 0) {
//				update(b, 1, num[b]);
//			}
//			else update(b, prev,num[b]);
//			
//		}
//		else {
//			if(check(b,c)) cout << mul(c) / mul(b - 1) << "\n";
//			else cout << 0 << "\n";
//		}
//	}
//
//}