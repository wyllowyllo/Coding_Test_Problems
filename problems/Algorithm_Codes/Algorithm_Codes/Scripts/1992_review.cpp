#include <bits/stdc++.h>
using namespace std;

int n;
int a[70][70];
string line;

#pragma region MySol

// 1. 중앙 좌표를 구할때, (x2-x1)/2 이런식으로 구함.. 이렇게 하면 길이의 절반을 구하는 것임. 중앙 좌표를 구하려면 (x2+x1)/2이런식으로 하기!
// 2. cin과 getline을 같이쓰다보니, cin 이후에 버퍼에 남아있던 개행문자때문에 제대로 입력을 못받음. 버퍼를 비우던가, 아니면 cin getline둘중하나만 통일하기!
// 3. 숫자 <-> 문자 변환방법 :   line[j] - '0' : 문자를 숫자로 변환 / (char)(a[y1][x1] + '0') : 숫자를 문자로 변환

int GetSum(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			sum += a[i][j];
		}
	}

	return sum;
}
string compress(int x1, int y1, int x2, int y2) {
	string ret;
	// if 숫자 합이 0 또는 n*n만큼인지 검사
	int sum = GetSum(x1, y1, x2, y2);
	int size = pow((x2 - x1) + 1, 2);

	if (sum == 0 || sum == size) {
		ret = (char)(a[y1][x1] + '0');
	}
	else {
		// else 가운데 좌표값을 구해서, 그 점 기준으로 4분할
		//int mid_x = (x2 - x1) / 2; int mid_y = (y2 - y1) / 2; //이렇게 하면 길이의 절반을 구하는 것임(절반의 좌표는 아래처럼!)
		int mid_x = (x2 + x1) / 2; int mid_y = (y2 + y1) / 2;


		ret += '(';
		ret += compress(x1, y1, mid_x, mid_y);
		ret += compress(mid_x + 1, y1, x2, mid_y);
		ret += compress(x1, mid_y + 1, mid_x, y2);
		ret += compress(mid_x + 1, mid_y + 1, x2, y2);
		ret += ')';
	}




	return ret;
}
void MySol() {
	cin >> n;
	getline(cin, line); //cin 입력 후 개행문자 남아있었음. 그거 제거하기 위해 사용
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		for (int j = 0; j < line.size(); j++) {
			a[i][j] = line[j] - '0';
		}
	}

	cout << compress(0, 0, n - 1, n - 1) << "\n";
}
#pragma endregion

#pragma region Sol_1
string s;

//여기서는 기준좌표(왼쪽 상단) 기준으로  size/2만큼 검사하는 방식을 사용
//나는 중앙점을 구한 뒤, 그 점을 기준으로 4분할하여 각각을 검사하였으나, 여기서는 기준좌표부터 z방향으로 검사하는 방식으로 접근함
//분할된 부분이 모두 1또는0 이냐, 아니냐를 검사할 때, 여기서는 문자가 달라지면 분할된 부분이 통일되지 않았다고 판단함. 나는 총합을 구해서 0이냐 n*n이냐로 정하는 방식이었음.
//대략적인 로직 순서 : 1. 기준점부터 시작하여 z방향으로 탐색 2. 만약 문자가 통일되지 않았다면 3.divide and conquer 방식으로 다시 4부분에 대해 검사

string quard(int y, int x, int size) {

	if (size == 1) return string(1, a[y][x]);

	char b = a[y][x];
	string ret = "";

	//인자로 시작 좌표와 사이즈를 받아서, 그 사이즈의 절반만큼 검사한다...
	for (int i = y; i < y + size / 2; i++) {
		for (int j = x; j < x + size / 2; j++) {
			if (b != a[i][j]) {
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x+size/2, size / 2);
				ret += quard(y+size/2, x, size / 2);
				ret += quard(y+size/2, x+size/2, size / 2);
				ret += ')';

				return ret;
			}
		}
	}

	return string(1, a[y][x]);
}

void Sol_1() {
	//여기서는 cin으로 입력받는것으로 통일했기 때문에, 나처럼 입력버퍼 비울필요 없었음
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j]; 
		}
	}
	cout << quard(0, 0, n) << '\n';
}

#pragma endregion



int main() {
	

}