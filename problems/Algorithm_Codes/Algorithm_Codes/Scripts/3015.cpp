#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;
stack<pair<ll, ll>> stk; //왜 long long? n최대범위 50만이므로, 같은 높이의 입력이 50만개 들어올 경우 중첩(second)값은 최대  50만 * 50만이기 때문
ll ret, temp;

#pragma region Sol_1

//해당 문제는 짝짓기 문제이므로, 우선 스택을 사용하여 접근하는걸 우선적으로 생각해보자
//스택은 top을 기반으로 하기 때문에, 해당 문제도 top을 기준으로, 그 앞부분을 검사해 나가는 방식(즉 뒤에서 앞으로 검사&처리하는 방식)으로 생각해 본다

//스택에 push해 나가다가, 스택의 top보다 큰 게 왔을 때 pop을 해 나간다(뒷부분부터 앞부분으로 쌍을 맺어 나가는 방식)

//모노톤 스택 - 스택 안의 값이 항상 오름차순 또는 항상 내림차순으로 유지되도록 push/pop을 제어함
//내 앞이나 뒤에 있는 더 큰/작은 값을 빠르게 찾고 싶을때 사용함
//이 문제 또한 top보다 현재 키가 크거나 같을 경우에만 pop하고, 작을 경우에는 push함으로써 decreasing monotonic stack을 구현한 것임.

void Sol_1() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		int cnt = 1; //중첩 개수

		while (stk.size() && stk.top().first <= temp) { //앞의 사람보다 키가 크거나 같을때
			ret += stk.top().second; //쌍의 수 증가

			if (stk.top().first == temp) { //키가 같을경우
				cnt = stk.top().second + 1; //중첩 증가
			}
			else {
				cnt = 1;
			}

			stk.pop();

		}

		if (stk.size()) ret++; //만약 스택 pop없을 경우(스택 top보다 작은 값 입력되어 그냥 push된 경우) 그 붙어있는 2개는 쌍이 되므로 그 쌍 추가하는 코드
		stk.push({ temp,cnt });
	}

	cout << ret << "\n";
}

#pragma endregion

int main() {
	Sol_1();
}