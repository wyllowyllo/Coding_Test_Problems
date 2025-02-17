#include <bits/stdc++.h>
using namespace std;


#pragma region  Unique 사용하여 중복요소 없애기

//unique : 범위 안의 요소 중, 앞에서부터 서로 비교해나가며 중복되는 요소를 지우고, 나머지 요소들은 삭제하지 않고 그대로 둠

vector<int> v;

//int main() {
//	for (int i = 1; i <= 5; i++) {
//		v.push_back(i);
//		v.push_back(i);
//	}
//	for (int i : v) cout << i << " ";
//	cout << '\n';
//
//	auto it = unique(v.begin(), v.end()); //중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환
//	cout << it - v.begin() << '\n'; //중복되지 않은 요소의 범위가 출력
//
//	for (int i : v) cout << i << " "; //앞에서부터 중복되지 않게 채운 후, 나머지 요소들은 그대로 둔다
//}

//sort를 먼저 써서 정렬한 후, unique와 erase를 사용하여 중복된 요소를 제거한 완전한 값을 얻어낼 수 있다!
int main() {
	vector<int> s{ 4, 3, 3, 5, 1, 2, 3 };
	sort(s.begin(), s.end());

	//unique는 중복되지 않은 부분으로 채운 다음 부분의 이터레이터를 반환한다.
	//erase를 사용하여, 중복되지 않은 파트를 제외한 나머지를 지운다.
	s.erase(unique(s.begin(), s.end()), s.end()); //erase(지울 부분 시작점, 지울 부분 끝점)

	for (int i : s) cout << i << " ";
	return 0;
}
#pragma endregion

