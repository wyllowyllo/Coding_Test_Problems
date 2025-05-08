#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];

vector<pair<int, int>> chickenPos;
vector<pair<int, int>> homePos;
int temp;



int ret= 987654;



void Select(int idx,vector<int> selection) {
	if (selection.size() == m) { //폐업시키지 않을 m개의 치킨집 선택
		
		
		int sum = 0;
		for (pair<int, int> h : homePos) {
			int minD = 987654;
			for (int s : selection) {
				int cx = chickenPos[s].second;
				int cy = chickenPos[s].first;

				int dist = abs(cy - h.first) + abs(cx - h.second);
				minD = min(minD, dist);
			}
			sum += minD;
		}
		ret = min(ret, sum);

		return;
	}

	for (int i = idx + 1; i < chickenPos.size(); i++) {
		selection.push_back(i);
		Select(i, selection);
		selection.pop_back();
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1) homePos.push_back({ i,j });
			else if (temp == 2) { chickenPos.push_back({ i,j }); }

			a[i][j] = temp;
		}
	}

	vector<int> s;
	Select(-1, s);
	cout << ret << "\n";

}