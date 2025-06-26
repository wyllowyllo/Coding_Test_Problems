#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];

int cnt[1001];
int pre[1001];
int last;

vector<int> lis;
pair<int, int> _m[1001];

int _lis[1001];
void go(int idx) {
	if (idx == -1) return;

	lis.push_back(a[idx]);
	go(pre[idx]);
}

void go_2(int idx) {
	if (idx ==  -1) return;
	go_2(pre[idx]);
	printf("%d ", a[idx]);
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	/*fill(cnt, cnt + 1001, 1);
	fill(pre, pre + 1001, -1);

	int len = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				pre[i] = j;

				if (len < cnt[i]) {
					len = cnt[i];	
					last = i;
				}
			}
		}
	}

	go(last);
	cout << len << "\n";
	reverse(lis.begin(), lis.end());
	for (int i : lis) cout << i << " ";*/

	int len = 0;
	fill(_lis, _lis + 1001, 1001);
	int lastIdx = 0;

	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(_lis, _lis + len, a[i]);

		int l = (int)(pos - _lis);

		if (*pos == 1001) {
			len++;
			lastIdx = i;
		}
		*pos = a[i];
		_m[i] = { l, a[i] };
	}

	cout << len << "\n";

	stack<int> stk;
	for (int i = lastIdx; i >= 0; i--) {
		if (_m[i].first == len - 1) {
			stk.push(_m[i].second);
			len--;
		}
	}

	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}
}