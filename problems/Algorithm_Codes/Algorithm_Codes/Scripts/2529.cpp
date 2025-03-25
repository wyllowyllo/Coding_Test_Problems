#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string max_v = "-1", min_v = "9999999999";

char op[10];

int idx = 0;

int k;

int n, check[10];
char a[20];
vector<string> ret;

#pragma region MySol


bool isSelected(int num, vector<int>& v) {
	for (int n : v) {
		if (num == n) return true;
	}

	return false;
}

void make(int idx, string num, vector<int> selected) {
	if (idx == k) {
		if (stoll(max_v) < stoll(num)) {
			max_v = num;
		}
		if (stoll(min_v) > stoll(num)) {
			min_v = num;
		}

		return;
	}


	if (op[idx] == '<') {
		for (int i = 0; i <= 9; i++) {
			if (num[idx] - '0' < i && !isSelected(i, selected)) {

				selected.push_back(i);
				make(idx + 1, num + to_string(i), selected);
				selected.pop_back();

			}
		}
	}

	else {
		for (int i = 9; i >= 0; i--) {
			if (num[idx] - '0' > i && !isSelected(i, selected)) {

				selected.push_back(i);
				make(idx + 1, num + to_string(i), selected);
				selected.pop_back();

			}
		}
	}


}


void MySol() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> op[idx++];
	}

	for (int i = 0; i <= 9; i++) {
		string num = to_string(i);
		vector<int> v; v.push_back(i);
		make(0, num, v);
	}

	cout << max_v << "\n" << min_v << "\n";

}
#pragma endregion


#pragma region Sol_1

// 숫자는 한 자리수이고, 쓴 수는 다시 쓰지 못함. 또한 부등호가 최대 9개이므로 수는 최대 10개
// 즉 이 문제의 시간복잡도는 10! 이다 -> 완전탐색으로 풀 수 있는 문제이다

//나는 이 수를 쓴 적이 있느냐를 판단하기 위해 인자로 vector를 전달해서 검사하는 식으로 함
//여기서는 check라는 전역배열을 하나 가져다 놓고, check[n]= true - 재귀함수 호출 -  복구 하는 식으로 처리함
//나는 비교를 위해 인자로 받은 벡터를 쭉 검사했지만, 여기서는 해당 수를 인덱스로 해서 배열의 값을 검사하기에 , 이 방법이 더 빠르다!

bool good(char x, char y, char op) {
	if (x < y && op == '<') return true;
	if (x > y && op == '>') return true;
	return false;
}

//완전탐색을 할 때는 일반적으로 인덱스 기반으로 탐색한다.
void go(int idx, string num) {

	if (idx == n + 1) {
		ret.push_back(num); return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue; //이 수를 쓴 적이 있다면 다시 쓰지않음
		if (idx == 0 || good(num[idx - 1], i + '0', a[idx - 1])) {
			//처음 시작 위치이거나, 부등호 앞뒤 수가 부등호를 만족한다면
			// i +'0' 으로 숫자->문자 변환

			check[i] = 1;
			go(idx + 1, num + to_string(i));
			check[i] = 0;
		}
	}

	return;
}
void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i]; //부등호 입력

	go(0, "");

	sort(ret.begin(), ret.end()); //문자열의 대소비교? 일단 문자열 길이를 우선으로 해서 대소 정하고, 문자열 길이 같다면 숫자비교
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}
#pragma endregion


int main() {
	Sol_1();
	
}