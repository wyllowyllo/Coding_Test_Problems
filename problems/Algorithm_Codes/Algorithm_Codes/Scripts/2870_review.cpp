#include <bits/stdc++.h>
using namespace std;

int n;
string l;

#pragma region MySol()

//문제 접근 : 문제 조건에서 long long 을 초과하는 수가 있겠다고 생각함
//문자열을 분리하여, 문자열의 길이에 따라 오름차순 정렬하되, 같은 길이의 문자열들끼리는 가장 높은 자릿수의 숫자부터 차례로 비교해나가가기로 함

//오래걸린부분 -> 0떼기 : 문자열 분리 시, 그 문자가 0이고 그 문자열이 전체문자열 끝부분이거나 뒤에 숫자가 있으면 문자열 분리할때 포함하지 않도록 함

vector<string> nums;

//각 문자열의 사이즈를 오름차순으로 정렬한다.
//만약 문자열의 사이즈가 같을 시 가장 높은 자릿수의 숫자부터 비교한다.
bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) return false;
			else if (a[i] < b[i]) return true;
		}

	}

	return a.size() < b.size();
}

void MySol() {
	cin >> n;
	while (n--) {
		cin >> l;

		//일단 숫자로 된 부분을 문자열로 저장해놓는다
		for (int i = 0; i < l.size(); i++) {
			if (!isalpha(l[i])) {

				if (l[i] == '0' && i + 1 != l.size() && !isalpha(l[i + 1])) {
					continue;
				}

				int j;
				for (j = i; j < l.size();) {
					if (!isalpha(l[j])) j++;
					else break;
				}

				string temp;
				temp = l.substr(i, (j - i));
				nums.push_back(temp);
				//cout << temp << " ";
				i = j;
			}
		}




	}

	sort(nums.begin(), nums.end(), cmp);


	for (auto n : nums)
		cout << n << "\n";
}
#pragma endregion

#pragma region Sol_1
//여기서는 문자냐 숫자냐를 판별할때 아스키 코드를 사용함 (문자열에서는 문자와 숫자만 포함되어있고 A가 65이므로, 이보다 작다면 숫자이다)
//나는 문자열 분리 시 특정 조건일 때 0을 포함하지 않고 건너뛰는 식으로 문자열을 분리함
//여기서는 일단 문자된 문자열에서, 조건적으로 0을 제거하는 방식임.

string ret;
string s;
vector<string> v;
void go() {
	while (true) {
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin()); //맨 앞이 0이라면 일단 제거한다
		else break;

	}

	if (ret.size() == 0) ret = "0";//숫자가 0인 경우 지워버린 0을 복구한다.
	v.push_back(ret);
	ret = "";
}

bool cmp2(string a, string b) {
	if (a.size() == b.size()) return a < b; //a,b는 string이지만, 길이가 같은 경우 대소비교할수있다 
	return a.size() < b.size();
}
void Sol_1() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ret = "";

		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 65) ret += s[j]; //숫자이면 ret에 포함시킨다.
			else if (ret.size()) go(); //문자라면, 이때까지 만든 ret에 불필요한 0을 제거한다

		}

		//문자열 끝에 다다르면 반복문 나옴, ret의 불필요한 0 제거
		if (ret.size()) go();
		sort(v.begin(), v.end(), cmp2);
		for (string i : v)cout << i << "\n";
	}
}

#pragma endregion





int main() {
	
}