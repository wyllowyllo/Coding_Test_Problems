#include <bits/stdc++.h>

using namespace std;

//------------------------------My Solution-------------------------------------
//�켱 �������ǰ� ��������� �����ؼ�, �����ϰ� Ǯ �� ���� �� ������ �����ϰ� Ǯ���!
//(�� ������ �뷫 1000�� ���϶�� �����ϰ� Ǯ �� �ִ� ����� ��찡 ����)
// �� ������ �ֿ���� : � ������ �ϴ� bruteforce�� Ǯ���!!
int n;
int cnt = 0;
string title = "666";

int main() {
	cin >> n;

	while (cnt < n) {
		if (title.find("666")!=title.npos) cnt++;
		if (cnt == n) break;
		title = to_string(stoll(title) + 1);
	}

	cout << title << "\n";
}

//------------------------------------------------------------------------------