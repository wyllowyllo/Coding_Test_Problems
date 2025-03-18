#include <bits/stdc++.h>
using namespace std;

string s;
int n;

#pragma region MySol

//bruteForce로 괄호를 넣고, 빼면서 모든 버전의 수식을 만듦
//dfs방식을 이용해 괄호 삽입해 나감. 문자열 끝에 도달했을떄가 리프 노드에 도달했을 때임.
//수식이 만들어졌다면(리프노드에 도달했다면), 먼저 괄호 안의 식을 먼저 계산함
//괄호 안의 계산이 모두 끝났다면, 왼쪽에서부터 계산시작
//첫번째 시도 실패 이유 : ret=max(ret,result)으로 최댓값 구하는데, ret을 0으로 초기화함... 계산결과가 음수인 경우가 있을 수 있음
//ret=-999999로 설정하니 성공!

int ret = -999999;


void Cal() {

	vector<int> operands;
	vector<char>operators;



	//수식을 검사하여, 괄호를 만나면 괄호 안을 먼저 계산하여 그 결과를 operands에 추가
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			int n1 = s[i + 1] - '0';
			char op = s[i + 2];
			int n2 = s[i + 3] - '0';

			int result;
			if (op == '+')result = n1 + n2;
			else if (op == '-')result = n1 - n2;
			else if (op == '*')result = n1 * n2;

			operands.push_back(result);
			i = i + 4;
		}
		else if (s[i] == ')') continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*') operators.push_back(s[i]);
		else operands.push_back(s[i] - '0');

	}

	//왼쪽에서부터 계산 시작
	int result = operands[0];

	for (int i = 0; i < operators.size(); i++) {
		char op = operators[i];

		if (op == '+') {
			result += operands[i + 1];
		}
		else if (op == '-') {
			result += (operands[i + 1] * -1);
		}
		else result *= operands[i + 1];
	}



	ret = max(ret, result);
}


void Print() {
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << "\n";
}

//모든 버전의 수식 만들기
void go(int startIdx) {

	if (startIdx > 0 && startIdx >= s.size()) {
		//Print();
		Cal();
		return;
	}


	for (int j = startIdx + 1; s[j] != '\0'; j++) {
		if (s[j] == '+' || s[j] == '-' || s[j] == '*') {
			s.insert(s.begin() + j - 1, '(');
			s.insert(s.begin() + j + 3, ')');

			go(j + 4);


			s.erase(s.begin() + j + 3);
			s.erase(s.begin() + j - 1);
		}

	}

	//Print();
	Cal();
	return;

}

void MySol() {
	cin >> n;
	cin >> s;

	go(-1);

	cout << ret;
}

#pragma endregion


#pragma region Sol_1

//완전탐색을 할 때는, '인덱스'를 활용하여 탐색할 생각을 하자!
//여기서는 누적합을 활용하여 풀었음
//어떻게 누적합이 가능하지? 어차피 괄호의 중복은 불가능하기 때문
//예를 들어 3*5+2 의 계산 결과는 17 또는 21 두 가지 뿐임 (경우의 수가 2개)
//따라서 어떤 것을 먼저 계산할 지 정해서, 그 계산결과를 누적해나가며, 수식의 끝에 도달했을 때 결과를 비교함

//내 풀이와의 차이점
//나는 문제를 봤을 때, 모든 경우의 수를 탐색해서 문제를 풀어야겠다고 생각했고, 수식에 괄호를 추가한 경우의 수를 모두 구현했음(수식을 실제로 만듦)
//수식을 실제로 만들고, 괄호가 추가된 해당 수식을 계산하는 로직을 또 따로 만듦
//여기서도 모든 경우의 수를 탐색해서 풀지만, 직접 수식을 만들지 않고 '인덱스'를 통한 완전탐색을 생각해 냄. 또한 완성된 수식을 왼쪽부터 검사하며 계산하지 않고 누적합을 이용함
//a*b+c 에서 나올 수 있는 풀이는 (a*b)+c, a*(b+c)뿐이므로, 재귀방식과 누적합을 통해 모든 경우의 수를 탐색하여 결과를 산출함

//키포인트 : 완전탐색을 할 때는, '인덱스'를 활용하여 탐색할 생각을 하자!

vector<int> num; //피연산자
vector<char> oper_str; //연산자
int n, ret = -987654321;
string s;

int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

//here은 현재 인덱스, _num은 연산결과의 누적합
//누적합과 인덱스를 인자로 전달하므로, 나와 달리 복원의 과정이 필요없다
void go(int here, int _num) {
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}

	go(here + 1, oper(oper_str[here], _num, num[here + 1])); //a*b+c 라는 수식이 있다면, (a*b)+c 이렇게 계산하는 경우

	if (here + 2 <= num.size() - 1) { //a*b+c 라는 수식이 있다면, a*(b+c) 이렇게 계산하는 경우
		int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(oper_str[here], _num, temp));
	}

	return;
}

void Sol_1() {
	cin >> n;
	cin >> s;

	
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0'); //처음에 숫자로 시작하므로, 짝수 인덱스가 피연산자이다
		else oper_str.push_back(s[i]);
	}

	go(0, num[0]);
	cout << ret << "\n";
}
#pragma endregion


int main() {
	Sol_1();
}