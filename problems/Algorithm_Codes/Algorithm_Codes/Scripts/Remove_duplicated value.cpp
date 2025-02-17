#include <bits/stdc++.h>
using namespace std;

vector<int> values = { 1,1,2,2,3,3,4,4,5,5,5 };
vector<int> values_2 = { 2,3,3,4,1,1,1,1,4,5,6,7,8,9 };

void Solution_1() {
	map<int, bool> value_map; //맵은 중복 키를 허용하지 않으니, 이를 이용하여 배열에서 중복 원소를 제거할 수 있다.

	for (int i : values) {
		if (value_map[i])
			continue;
		value_map[i] = true;
	}

	vector<int> result;
	for (auto value : value_map) {
		result.push_back(value.first); //키값 저장
	}

	for (auto value : result)
		cout << value << " ";
}
void Solution_2() {
	//Unique() 메서드 활용하기
	sort(values_2.begin(), values_2.end()); //오름차순 정렬
	auto endIdx=unique(values_2.begin(), values_2.end()); //unique 반환값은, 원래 배열의 모든 원소 포함되고 중복된 부분은 제거된 완전한 배열의 끝 다음 위치(중복원소 개수+1 인 위치)
	values_2.erase(endIdx, values_2.end()); //중복없는 완전한 원소배열만 남도록 나머지 지움

	for (auto value : values_2)
		cout << value << " ";

	
}
int main() {
	//Solution_1();
	Solution_2();
}