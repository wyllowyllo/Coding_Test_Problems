#include <bits/stdc++.h>
using namespace std;

const int MAX=21;

int n;
char a[MAX][MAX];
char b[MAX][MAX];
string s;

const int INF = 500;
int ret=INF;

enum type { ROW,COL };

int _a[44];

#pragma region MySol
//한번의 연산에서, 하나의 행 또는 열을 선택하여 뒤집음
	//이 연산의 횟수 제한은 없음
	//즉 전체집합 n*n에서 연산을 할 원소를 선택하여 집합 생성. (원소가 없을 경우 아예 뒤집지 않음. 집합이 n*n이라면 모든 행과 열에 대해서 flip수행)

	//비트마스킹을 이용하여 모든 집합을 생성한다

//모든 경우의 수에 대해, 행과 열을 뒤집었을 때의 뒷면개수 계산함 -> 시간초과

//두번째 시도 : 모든 경우의 수에 대해 행을 뒤집고, 열은 직접 뒤집지 않고 개수만 계산함
//열은 뒤집는 대신, 열을 뒤집는 것이 더 이득인지 아닌지를 계산해서 개수를 비교.
//즉, 열을 뒤집는 연산을 실제로 하지 않고 최적의 결과를 계산.


void Print() {
	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}



void flipAll(vector<pair<type, int>>& v, char b[MAX][MAX]) {

	for (pair<type, int> value : v) {
		if (value.first == ROW) {
			for (int i = 0; i < n; i++) {
				if (b[value.second][i] == 'H') b[value.second][i] = 'T';
				else  b[value.second][i] = 'H';
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (b[i][value.second] == 'H') b[i][value.second] = 'T';
				else  b[i][value.second] = 'H';
			}
		}
	}

	//뒷면 개수 확인
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] == 'T') cnt++;
		}
	}

	ret = min(ret, cnt);
}

void flipRow(int rowNum) {
	for (int i = 0; i < n; i++) {
		b[rowNum][i] = (b[rowNum][i] == 'H') ? 'T' : 'H';
	}
}

int CountCol() {
	//모든 열에 대해, 열을 뒤집을지 말지를 결정(T의 개수가 최소화되는 쪽으로)

	int cnt = 0;
	for (int i = 0; i <  n; i++) {
		int colCnt=0;
		for (int j = 0; j < n; j++) {
			if (b[j][i] == 'T') colCnt++;
		}

		cnt += min(colCnt, n - colCnt); //열을 뒤집을지 말지를 결정(T의 개수가 최소화되는 쪽으로). 뒤집으면 T의 개수가 n-colcnt로 바뀜
	}

	return cnt;
}
void MySol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
			
		}
	}
	

	//한번의 연산에서, 하나의 행 또는 열을 선택하여 뒤집음
	//이 연산의 횟수 제한은 없음
	//즉 전체집합 n*n에서 연산을 할 원소를 선택하여 집합 생성. (원소가 없을 경우 아예 뒤집지 않음. 집합이 n*n이라면 모든 행과 열에 대해서 flip수행)

	//비트마스킹을 이용하여 모든 집합을 생성한다


	//행 선택
	for (int i = 0; i < (1 << n); i++) {

		
		memcpy(b, a, sizeof(a));

		//vector<pair<type, int>> v_1;
		

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				//v_1.push_back({ ROW, j });
				flipRow(j);
			}

			////행을 선택한 후, 열 선택
			//for (int k = 0; k < (1 << n); k++) {
			//	vector<pair<type, int>> v_2 = v_1;

			//	for (int t = 0; t < n; t++) {
			//		if (k & (1 << t)) {
			//			v_2.push_back({ COL, t });
			//		}
			//	}

			//	flipAll(v_2, b);
			//}

			ret=min(ret,CountCol()); //행뒤집기를 적용한 후, 모든 열에 대해 T의 개수가 최소화되는 방향으로 열뒤집기를 할지/말지 결정


		}
	}

	cout << ret << "\n";
}

#pragma endregion

#pragma region Sol_1

//이 풀이에서는 나처럼 HTF..와 같은 입력값에 대해 배열로 처리하지 않고, 숫자 하나로 관리함
//예를들어 H=0, T=1이라 생각해서, HTT 는 011  -> 3이런식으로.



void go(int here) {

	//마지막 행까지 뒤집기 완료함
	if (here == n + 1) {
		int sum = 0;

		for (int i = 1; i <= (1 << (n - 1)); i *= 2) { //첫번쨰 열.. 두번째 열... n-1번째 열까지 검사
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (_a[j] & i) cnt++; // T라면
			sum += min(cnt, n - cnt); //열을 뒤집을 경우와 , 뒤집지 않는 경우 중 T(뒷면)의 개수가 최소인 경우를 선택한다
		}

		ret = min(ret, sum);
		return;
	}

	go(here + 1); //행 뒤집지 않고 다음 행으로
	_a[here] = ~_a[here]; //행 뒤집기
	go(here + 1); //행 뒤집고 다음 행으로
	
}

void Sol_1() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') _a[i] |= value; //TFT... 같이 되어있는 한 행을, 숫자 하나로 표현함 ex) TFF 는 100 
			value *= 2;
		}
	}

	go(1);
	cout << ret << "\n";
}
#pragma endregion


int main() {
	//MySol();
	Sol_1();
}