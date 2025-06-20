#include <bits/stdc++.h>
using namespace std;

/*처음에 map을 활용하여 문제를 풀려 했는데, 시간 초과가 남 (맵의 입력과 참조는 logn의 시간 복잡도를 가지므로, 이 로직의 전체 시간복잡도는 nlogn이기 때문에 충분히 가능할거라 생각함)
알고보니 밑의 이유로 추가적인 시간이 더 소모되서 그런 듯함


for (int i = 0; i < n; i++) {
cin >> tmp;
_map[tmp]++
}
이런 식으로 입력을 받아 맵에 집어넣었는데, 
map에다 집어넣게되면 자동적으로 정렬이 들어가게 되기 때문에 시간 초과가 난 듯함

즉, 입력받을 때마다 정렬하게 되고, 그 결과 입력받을 때 N*O(logN)의 시간이 발생해버림..
즉 맵의 자동정렬 기능 때문에 시간복잡도 차이가 난 것임.
		*/
int t;
int n, m;

int tmp;
//map <int, int> _m;
vector<int> v;

int check(int num) {
	int left = 0;int right = v.size() - 1;


	while (left <= right) {
		int mid = (left + right) / 2;

		if (v[mid] == tmp) return 1;
		else if (v[mid] < tmp) left = mid + 1;
		else right = mid - 1;
	}


	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		//_m.clear();
		v.clear();

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}


		sort(v.begin(), v.end());

		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> tmp;
			cout << check(tmp) << "\n";
		}
		//cout << "\n";
	}
}