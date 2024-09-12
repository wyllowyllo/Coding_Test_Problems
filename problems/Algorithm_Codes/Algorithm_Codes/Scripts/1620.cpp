#include <bits/stdc++.h>
using namespace std;

string a[100004]; //만약 숫자로 검색하여 이름을 찾을 때 배열을 활용할 경우, O(1)의 시간복잡도 걸림

int main() {
	int N, M;

	//-----------------------------My Solution---------------------------------//
	//map<string, int> dictionary_forName;
	//map<int, string> dictionary_forNum;
	//cin >> N >> M;

	//string name;
	//for (int i = 0; i < N; i++) {
	//	cin >> name;
	//	dictionary_forName.insert({ name,i + 1 });
	//	dictionary_forNum.insert({ i+1,name });
	//}

	//vector<string> search_data;
	//string input;
	//for (int i = 0; i < M; i++) {
	//	cin >> input;
	//	search_data.push_back(input);
	//}

	//for (auto data : search_data) {
	//	if (isalpha(data[0])) { //이름으로 검색
	//		cout << dictionary_forName.find(data)->second << '\n'; //숫자 반환
	//	}
	//	else { //숫자로 검색
	//		int idx = stoi(data);
	//		cout<< dictionary_forNum.find(idx)->second << '\n'; //이름 반환
	//	}
	//}

	//----------------------------------------------------------------------------------

	//--------------------------Solution 1 ----------------------------------------------

	map<string, int> mp; //map자료구조는 red-black tree로 구현되므로, 검색에 O(logN)의 시간 걸림
	map<int, string> mp2;
	string s;
	
	//입출력 싱크 풀어서 cin, cout 속도 빠르게
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		mp[s] = i + 1; //이름을 키로 하고, 입력 순서를 value로 함
		mp2[i + 1] = s; //입력 순서를 키로 하고, 이름을 value로 함
		a[i + 1] = s;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0) { //atoi()는 문자열을 integer로 변환해줌. 이때 변환할 문자열이 숫자가 아닐경우 0반환
			//이름으로 검색한 경우
			cout << mp[s] << "\n"; //해당 이름에 해당하는 숫자 반환
		}
		else {
			//숫자로 검색한 경우
			//cout << mp2[atoi(s.c_str())] << "\n"; //해당 숫자에 해당하는 이름 반환
			cout << a[atoi(s.c_str())] << "\n"; //위 코드처럼 map을 활용하여 대응값을 반환해도 되지만, 숫자->이름 변환같은 경우 배열을 활용하면 O(1)에 처리가능하므로 더 효율적

		}
	}
	//------------------------------------------------------------------------------------
	return 0;
	
}