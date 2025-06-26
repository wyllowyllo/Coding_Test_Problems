#include <bits/stdc++.h>
using namespace std;

namespace MY {
	int n;
	int v[1000001];

	//수열 생성 시 사용하는 배열
	int v2[1000001]; //가장 긴 수열의 값 저장하는 배열
	int tailIdx[1000001];//위 값에 대한 원래 배열의 인덱스


	int pre[1000001];
	int len;

	const int INIT = 1e9 + 4;

	vector<int> ret;
	//void go(int idx,vector<int> &a) {
	//	if (a.size() == len) {
	//
	//		cout << len << "\n";
	//		for (int i = a.size()-1; i >=0; i--) {
	//			cout << v[a[i]] << " ";
	//		}
	//		exit(0);
	//	}
	//
	//
	//	for (int i = idx-1; i >=0; i--) {
	//		if (v[a.back()] > v[i]) {
	//			a.push_back(i);
	//
	//			go(i, a);
	//
	//			a.pop_back();
	//		}
	//	}
	//}

	void go(int idx) {
		if (idx == -1) {
			return;
		}

		ret.push_back(idx);
		go(pre[idx]);

	}

	void mysol() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		fill(pre, pre + 1000001, -1);
		fill(v2, v2 + 1000001, INIT);


		for (int i = 0; i < n; i++) {
			auto pos = lower_bound(v2, v2 + len, v[i]);
			int l = (int)(pos - v2); //이 원소가 v2의 어디에 들어갈 것인가 (길이가 l인 증가부분수열의 마지막 꼬리값 위치)

			if (*pos == INIT) {
				//수열에서 가장 큰 값(꼬리값)이 갱신됨
				len++;
			}

			*pos = v[i]; //길이가 l인 증가부분수열의 마지막 원소(꼬리값) 갱신
			tailIdx[l] = i;// 길이가 l인 증가부분수열의 마지막 원소(꼬리값)이 원래 배열(v)에서 어느 인덱스인지(인덱스갱신)

			pre[i] = (l > 0 ? tailIdx[l - 1] : -1); //v2의 각 원소에 대한 이전 원소 인덱스  
		}

		go(tailIdx[len - 1]);
		cout << len << "\n";
		for (int i = ret.size() - 1; i >= 0; i--) {
			cout << v[ret[i]] << " ";
		}
	}
}

namespace sol {
	int n, lis[1000004], len, num;
	pair<int, int> ans[1000004];
	stack<int> stk;
	const int INF = 1e9 + 4;

	void Sol() {
		fill(lis, lis + 1000004, INF);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &num);

			auto lowerPos = lower_bound(lis, lis + len, num);
			int _pos = (int)(lower_bound(lis, lis + len, num) - lis); //lis에서의 위치

			if (*lowerPos == INF) len++;

			*lowerPos = num;

			//i번 num에 대한 lis에서의 위치와 숫자 저장
			ans[i].first = _pos;
			ans[i].second = num;
		}

		printf("%d\n", len);
		for (int i = n - 1; i >= 0; i--) {
			if (ans[i].first == len - 1) { //len의 길이를 갖는 증가부분수열(lis)의 마지막 원소인 경우
				stk.push(ans[i].second); len--;
			}
		}

		while (stk.size()) {
			printf("%d\n", stk.top()); stk.pop();
		}
	}
}

int main() {
	
	sol::Sol();
}
