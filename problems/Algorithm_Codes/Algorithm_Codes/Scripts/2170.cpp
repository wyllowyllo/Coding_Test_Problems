#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
int n;
vector<pair<ll, ll>> v;

ll x, y;
ll ret;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	ll start = v.front().first;
	ll end = v.front().second;

	for (int i = 1; i < v.size(); i++) {
		if (end < v[i].first) { //기존 선이랑 겹치거나 연결되지 않는 새 선인 경우
			ret+=end-start;

			start = v[i].first;
			end = v[i].second;
		}
		else { //기존 선이랑 겹치거나 연결되는 경우

			if(end<v[i].second) //끝점 더 긴걸로 갱신
				end = v[i].second; 
		}

	}

	ret+= end - start;

	cout << ret << "\n";
}