#include <bits/stdc++.h>
using namespace std;

#pragma region Ex1
int visited[4];
vector<int> adj[4];
vector<int> v;
void print() {
	for (int i : v) cout << char(i + 'A') << " "; //숫자를 문자로 변환
	cout << '\n';
}
void go(int idx) {
	if (v.size() == 3) {
		print();
		return;
	}

	for (int there : adj[idx]) {
		if (visited[there]) continue;
		visited[there] = 1;
		v.push_back(there);

		go(there);

		visited[there] = 0;
		v.pop_back();
	}
}

void Ex1() {
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(0);
	adj[2].push_back(1);
	adj[3].push_back(1);


	visited[0] = 1;
	v.push_back(0);
	go(0);
}
#pragma endregion

#pragma region #Ex2

const int n = 3;
int a[3][3] = {
{10, 20, 21},
{70, 90, 12},
{80, 110, 120}
};
int visited2[3][3];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0,-1 };
vector<int> v;

void Print2() {
	for (int i : v) cout << i << " ";
	cout << "\n";
}
void go(int y, int x) {
	if (y == n - 1 && x == n - 1) {
		Print2();
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited2[ny][nx]) continue;

		visited2[ny][nx] = 1;
		v.push_back(a[ny][nx]);

		go(ny, nx);

		visited2[ny][nx] = 0;
		v.pop_back();

	}
}
void Ex2() {
	visited2[0][0] = 1;
	v.push_back(a[0][0]);
	go(0, 0);
}
#pragma endregion


int main() {

}