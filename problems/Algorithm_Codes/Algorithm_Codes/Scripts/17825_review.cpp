#include <bits/stdc++.h>
using namespace std;

int noon[10];
vector<int> board[33];
map<int, int> m;

struct horse {
	int p;

} h[4];

int visited[33];

void InitBoard() {

	//board 칸 set
	for (int i = 0; i <= 20; i++) {
		board[i].push_back(i+1);
	}
	
	board[5].push_back(22);
	board[22].push_back(23);
	board[23].push_back(24);
	board[24].push_back(30);

	board[10].push_back(25);
	board[25].push_back(26);
	board[26].push_back(30);
	

	board[15].push_back(27);
	board[27].push_back(28);
	board[28].push_back(29);
	board[29].push_back(30);

	board[30].push_back(31);
	board[31].push_back(32);
	board[32].push_back(20);

	//점수 set
	for (int i = 1; i <= 20; i++) {
		m[i] = 2*i;
	}

	
	m[22] = 13;
	m[23] = 16;
	m[24] = 19;
	m[25] = 22;
	m[26] = 24;
	m[27] = 28;
	m[28] = 27;
	m[29] = 26;
	m[30] = 25;
	m[31] = 30;
	m[32] = 35;

	m[21] = 0;
}

int ret;

pair<bool,int> check(int p, int noon) {
	int np = p;

	if (p == 5 || p == 10 || p == 15) {
		np = board[p][1];
		noon--;
		p = np;
	}

	while (noon--) {
		if (np == 21) return { true,21};
		

		np = board[p][0];
		p = np;
	}

	if (visited[np] && np!=21 ) return { false,0};

	return { true,np};
}
void move() {

}

void go(int idx, int point) {
	if (idx == 10) {
		ret = max(ret, point);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (h[i].p == 21) continue;

		auto np = check(h[i].p, noon[idx]);
		if (np.first) {

			int tmp = h[i].p;

			visited[h[i].p] = 0;
			h[i].p = np.second;
			visited[np.second] = 1;


			go(idx + 1, point + m[np.second]);

			visited[tmp] = 1;
			h[i].p = tmp;
			visited[np.second] = 0;

		}
	}
}
int main() {
	InitBoard();

	for (int i = 0; i < 10; i++) {
		cin >> noon[i];
	}

	
	go(0, 0);
	cout << ret << "\n";
}