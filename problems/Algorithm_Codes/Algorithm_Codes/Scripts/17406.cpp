
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];
int b[51][51];

int k;

int r, c, s;
struct A {
	int r, c, s;
	A(int r,int c, int s) {
		this->r = r;
		this->c = c;
		this->s = s;
	}
};
vector<A> v;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };


int ret = 6000;

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void RotateEdges(int ly,int lx, int ry,int rx) {
	if (ly-ry == 0) {
		//Print();
		return;
	}

	vector<int> vv;
	vector<pair<int,int>> seq;
	int y = ly;
	int x = lx;
	int dir = 0;

	vv.push_back(a[y][x]);
	seq.push_back({ y,x });

	//edge 추출
	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny == ly && nx == lx) break;

		if (nx<lx || nx>rx || ny<ly || ny>ry) {
			dir++;
			continue;
		}

		vv.push_back(a[ny][nx]);
		seq.push_back({ ny,nx });

		y = ny;
		x = nx;
	}

	//Rotate
	rotate(vv.rbegin(), vv.rbegin() + 1, vv.rend());
	
	//Update
	for (int i = 0; i < seq.size(); i++) {
		a[seq[i].first][seq[i].second] = vv[i];
	}

	//left corner, right corner update
	RotateEdges(ly + 1, lx + 1, ry - 1, rx - 1);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	memcpy(b, a, sizeof(a));

	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		A tmp=A(r, c, s);
		v.push_back(tmp);
	}

	vector<int> rotateIdx;
	for (int i = 0; i < k; i++)
		rotateIdx.push_back(i);
	
	do {
		memcpy(a, b, sizeof(b));

		for (int n : rotateIdx) {
		
			int leftUp_Y = v[n].r - v[n].s - 1;
			int leftUp_X = v[n].c - v[n].s - 1;
			int rightBottom_Y = v[n].r + v[n].s - 1;
			int rightBottom_X = v[n].c + v[n].s - 1;

			RotateEdges(leftUp_Y, leftUp_X, rightBottom_Y, rightBottom_X);
		}
		//check
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += a[i][j];
			}
			ret = min(ret, sum);
		}


	} while (next_permutation(rotateIdx.begin(), rotateIdx.end()));
	
	

	cout << ret << "\n";
}
