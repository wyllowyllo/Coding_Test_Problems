#include <bits/stdc++.h>
using namespace std;


map<string, int> closet;
vector <pair< string, int>> temp;

int sum = 0;

void combi(int start, int r, vector<string> set) {
	
	if (set.size() == r) {
		int num_of_case=1;
		for (auto type : set) {
			num_of_case *= closet[type];
		}
		sum += num_of_case;
		return;
	}
	
	for (int i = start + 1; i < temp.size();i++) { //추가한 인덱스 다음부터 탐색해야 함
		set.push_back(temp[i].first);
		combi(i, r, set);
		set.pop_back();
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	int clothesNum;
	string cloth, clothType;
	cin >> testcase;

	//-------------------------------------------My Solution---------------------------------

	//맵 생성
	for (int i = 0; i < testcase; i++) {
		cin >> clothesNum;

		for (int j = 0; j < clothesNum; j++) {
			cin >> cloth >> clothType;

			if (closet.find(clothType) != closet.end()) { //존재
				closet[clothType]++; //개수 증가
			}
			else {
				closet.insert({ clothType,1 }); //새로 추가
			}
		}

		
		//for (auto item : closet) {
		//	temp.push_back({ item.first, item.second }); //인덱스를 통한 접근을 위해 맵 데이터들을 리스트로 복사
		//}

		//for (int i = 1; i <= temp.size(); i++) { //옷 1개만 입는 경우부터, 모든 타입의 옷 입는 경우까지의 조합 구하기
		//	vector<string> set;
		//	combi(-1, i, set);
		//}

		/*처음엔 위 주석처리된 부분을 통해 착장 집합(옷 선택 조합(Combination))을 구해서 총 경우의 수 구하려 했으나
	      조합을 구하는 거 자체가 시간복잡도가 높음. 굳이 가능한 조합 일일이 구할필요 없이 총 경우의 수만 구하면 되므로 로직 수정함*/

		int num_of_case = 1;

		for (auto item : closet) {
			num_of_case*=(item.second + 1); //각 아이템 품목별 경우의 수 곱함
		}
		num_of_case--; //아무것도 안입는 경우 제외.


		cout << num_of_case << "\n";
		closet.clear();
	}

	//------------------------------------------------------------------------------------------

	//-----------------------------Solution 1--------------------------------------------------

	int n;
	string a, b;
	while (testcase--) {
		map<string, int> _map;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			_map[b]++;
		}

		long long ret=1; //경우의 수는 그 크기가 클 수 있으므로 long long으로 선언하기!
		for (auto c : _map) {
			ret *= (c.second + 1);
		}

		ret--;
		cout << ret << "\n";
	}

	return 0;
}