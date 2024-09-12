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
	
	for (int i = start + 1; i < temp.size();i++) { //�߰��� �ε��� �������� Ž���ؾ� ��
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

	//�� ����
	for (int i = 0; i < testcase; i++) {
		cin >> clothesNum;

		for (int j = 0; j < clothesNum; j++) {
			cin >> cloth >> clothType;

			if (closet.find(clothType) != closet.end()) { //����
				closet[clothType]++; //���� ����
			}
			else {
				closet.insert({ clothType,1 }); //���� �߰�
			}
		}

		
		//for (auto item : closet) {
		//	temp.push_back({ item.first, item.second }); //�ε����� ���� ������ ���� �� �����͵��� ����Ʈ�� ����
		//}

		//for (int i = 1; i <= temp.size(); i++) { //�� 1���� �Դ� ������, ��� Ÿ���� �� �Դ� �������� ���� ���ϱ�
		//	vector<string> set;
		//	combi(-1, i, set);
		//}

		/*ó���� �� �ּ�ó���� �κ��� ���� ���� ����(�� ���� ����(Combination))�� ���ؼ� �� ����� �� ���Ϸ� ������
	      ������ ���ϴ� �� ��ü�� �ð����⵵�� ����. ���� ������ ���� ������ �����ʿ� ���� �� ����� ���� ���ϸ� �ǹǷ� ���� ������*/

		int num_of_case = 1;

		for (auto item : closet) {
			num_of_case*=(item.second + 1); //�� ������ ǰ�� ����� �� ����
		}
		num_of_case--; //�ƹ��͵� ���Դ� ��� ����.


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

		long long ret=1; //����� ���� �� ũ�Ⱑ Ŭ �� �����Ƿ� long long���� �����ϱ�!
		for (auto c : _map) {
			ret *= (c.second + 1);
		}

		ret--;
		cout << ret << "\n";
	}

	return 0;
}