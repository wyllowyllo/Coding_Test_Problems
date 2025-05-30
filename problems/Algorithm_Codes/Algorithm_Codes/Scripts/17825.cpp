#include <bits/stdc++.h>
using namespace std;

#pragma region MySol
 
namespace My {
	struct Node {
		int score;

		Node* next = NULL;
		Node* branch = NULL;

		Node(int score = 0) {
			this->score = score;
		}


	};

	Node* startNode;
	Node* branch_1;
	Node* branch_2;
	Node* branch_3;
	Node* mid_Node;
	Node* lastNode;
	Node* finishNode;

	vector<int> v;
	Node* horse[4]; //각 말의 위치
	int ret = 0;

	/// <summary>
/// 윷놀이 게임판 만들기
/// </summary>
	void MakeBoard() {
		Node* prev;

		startNode = new Node();
		finishNode = new Node();
		prev = startNode;

		//default
		for (int i = 2; i <= 40; i += 2) {
			Node* node = new Node(i);

			if (i == 10) branch_1 = node;
			else if (i == 20) branch_2 = node;
			else if (i == 30) branch_3 = node;

			prev->next = node;
			prev = node;
		}
		lastNode = prev;
		lastNode->next = finishNode;

		//중앙- 도착 노드 간선
		mid_Node = new Node(25);
		prev = mid_Node;
		for (int i = 30; i < 40; i += 5) {
			Node* node = new Node(i);
			prev->next = node;
			prev = node;
		}
		prev->next = lastNode;

		//첫번째 브랜치 간선
		Node* node = new Node(13);
		branch_1->branch = node;
		prev = node;
		for (int i = 16; i <= 19; i += 3) {
			node = new Node(i);
			prev->next = node;
			prev = node;
		}
		prev->next = mid_Node;

		//두번째 브랜치 간선
		node = new Node(22);
		branch_2->branch = node;
		prev = node;

		node = new Node(24);
		prev->next = node;
		node->next = mid_Node;

		//세번째 브랜치 간선
		node = new Node(28);
		branch_3->branch = node;
		prev = node;
		for (int i = 27; i >= 26; i--) {
			node = new Node(i);
			prev->next = node;
			prev = node;
		}
		prev->next = mid_Node;

	}

	void Init() {
		//게임판 생성
		MakeBoard();

		//시작위치 설정
		for (int i = 0; i < 4; i++)
			horse[i] = startNode;
	}


	bool MoveHorse(int horseIdx, int turnIdx) {
		int cnt = v[turnIdx]; //주사위 눈 개수
		Node* pointer;

		//한칸 이동 (브랜치가 있을 경우 브랜치로 이동)
		if (horse[horseIdx]->branch != NULL)
			pointer = horse[horseIdx]->branch;
		else
			pointer = horse[horseIdx]->next;
		cnt--;

		//나머지 눈 만큼 이동
		for (int i = 0; i < cnt; i++) {
			if (pointer == finishNode) break;
			pointer = pointer->next;
		}

		//다른 말이 이미 있는지 검사
		for (int i = 0; i < 4; i++) {
			if (horse[i] == pointer && pointer != finishNode) {
				return false;
			}
		}

		//말 이동
		horse[horseIdx] = pointer;
		return true;
	}
	void go(int turnIdx, int score) {
		if (turnIdx == 10) {
			ret = max(ret, score);
			return;
		}

		for (int i = 0; i < 4; i++) {
			Node* prevPos = horse[i];

			if (horse[i] == finishNode) continue;
			if (!MoveHorse(i, turnIdx)) continue;


			go(turnIdx + 1, score + horse[i]->score);
			horse[i] = prevPos; //말 위치 복구
		}
	}

	void MySol() {
		int tmp;
		for (int i = 0; i < 10; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		Init();

		go(0, 0);

		cout << ret << "\n";
	}
}
#pragma endregion

#pragma region Sol_1

namespace Sol {
	const int INF = 987654321;
	int a[14], mal[4], n = 10;
	int v[104];
	vector<int> adj[54];


	int move(int here, int cnt) {
		if (here == 100) return 100;
		if (adj[here].size() >= 2) {
			here = adj[here][1]; cnt--;
		}

		if (cnt) {
			queue<int> q;
			q.push(here);
			int there;

			while (q.size()) {
				int x = q.front(); q.pop();
				there = adj[x][0];

				q.push(there);

				if (there == 100) break;
				cnt--;
				if (cnt == 0) break;

			}

			return there;
		}
		else return here;

	}

	bool isMal(int mal_idx, int idx) {
		if (mal_idx == 100) return false;

		for (int i = 0; i < 4; i++) {
			if (i == idx) continue;
			if (mal[i] == mal_idx) return true;
		}

		return false;
	}
	void add(int here, int there) {
		adj[here].push_back(there);
	}

	void setMap() {
		for (int i = 0; i <= 19; i++) add(i, i + 1);
		add(5, 21); add(21, 22); add(22, 23); add(23, 24);
		add(15, 29); add(29, 30); add(30, 31); add(31, 24);

		add(10, 27); add(27, 28); add(28, 24); add(24, 25);
		add(25, 26); add(26, 20); add(20, 100);

		v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10;
		v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
		v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
		v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
		v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25;
		v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
		v[29] = 28; v[30] = 27; v[31] = 26;
	}

	int go(int here) {
		if (here == n) return 0;

		int ret = 0;
		for (int i = 0; i < 4; i++) {
			int temp_idx = mal[i];
			int mal_idx = move(temp_idx, a[here]);

			if (isMal(mal_idx, i)) continue;

			mal[i] = mal_idx;
			ret = max(ret, go(here + 1) + v[mal_idx]);
			mal[i] = temp_idx;

		}

		return ret;
	}

	void Sol_1() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL); setMap();
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << go(0) << "\n";
	}
}
#pragma endregion



int main() {
	

}