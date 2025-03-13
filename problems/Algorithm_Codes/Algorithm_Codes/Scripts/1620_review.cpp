#include <bits/stdc++.h>
using namespace std;

int n, m;
string name;

map<string, int> m1;
map<int, string> m2;
int num = 1;

string q;

#pragma region MySol()
void MySol() {
	for (int i = 0; i < n; i++) {
		cin >> name;
		m1[name] = num;
		m2[num] = name;
		num++;
	}

	for (int i = 0; i < m; i++) {
		cin >> q;
		if (isalpha(q[0])) cout << m1[q] << "\n";
		else cout << m2[stoi(q)] << "\n";
	}

}
#pragma endregion

#pragma region Sol_1()
void Sol_1() {
	for (int i = 0; i < n; i++) {
		cin >> name;
		m1[name] = i+1;
		m2[i+1] = name;
		
	}

	//atoi : const char*형의 인자를 받았을 때 문자열이라면 0, 숫자라면 1 반환 -> 문자열이 숫자인지, 문자열인지 판단할 때 유용
	//c_str() : string형을 const char* 형으로 변환
	//stoi : string형의 인자를 int형태로 변환

	for (int i = 0; i < m; i++) {
		cin >> q;
		if (atoi(q.c_str())==0) cout << m1[q] << "\n";
		else cout << m2[atoi(q.c_str())] << "\n";
	}
}
#pragma endregion


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	//MySol();
	
}