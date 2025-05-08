#include <bits/stdc++.h>
using namespace std;

int n;
string eq;
int result = -2100000000;

vector<int> num;
vector<char> op;
int cal(char c, int a, int b) {
	switch (c)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	}
}

void go(int idx, int sum) {
	if (idx == num.size()-1) {
		result = max(result, sum);
		return;
	}
	go(idx + 1, cal(op[idx], sum, num[idx + 1]));

	if (idx + 2 <= num.size() - 1) {
		int temp = cal(op[idx + 1], num[idx + 1], num[idx + 2]);
		go(idx + 2, cal(op[idx], sum, temp));
	}
	
}

//문제를 봤을 때 전체 수식에서 괄호를 끼워넣은 각각의 새로운 수식들을 생각했음.
//전체적으로 보지 말고, 쪼개서 보면
//a+b*c 는 (a+b)*c 또는 a+(b*c) 두 가지 밖에 없으므로, 완탐으로 풀되 누적합으로 구할 수있다!
//문제를 쪼개서 작은 부분부터 해결하여 그걸 합해서 문제를 해결해보려는 자세를 갖자

int main() {
	cin >> n;
	cin >> eq;

	//완전탐색을 할 때는 항상 인덱스를 기반으로 로직을 짤 생각을 하자!
	//인덱스 기반 접근이므로 연산자와, 피연산자를 구분하여 관리하는 것이 편하다!

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(eq[i] - '0');
		else op.push_back(eq[i]);
	}

	go(0, num[0]);

	cout << result << "\n";

}