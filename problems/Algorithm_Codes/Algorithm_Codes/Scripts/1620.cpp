#include <bits/stdc++.h>
using namespace std;

string a[100004]; //���� ���ڷ� �˻��Ͽ� �̸��� ã�� �� �迭�� Ȱ���� ���, O(1)�� �ð����⵵ �ɸ�

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
	//	if (isalpha(data[0])) { //�̸����� �˻�
	//		cout << dictionary_forName.find(data)->second << '\n'; //���� ��ȯ
	//	}
	//	else { //���ڷ� �˻�
	//		int idx = stoi(data);
	//		cout<< dictionary_forNum.find(idx)->second << '\n'; //�̸� ��ȯ
	//	}
	//}

	//----------------------------------------------------------------------------------

	//--------------------------Solution 1 ----------------------------------------------

	map<string, int> mp; //map�ڷᱸ���� red-black tree�� �����ǹǷ�, �˻��� O(logN)�� �ð� �ɸ�
	map<int, string> mp2;
	string s;
	
	//����� ��ũ Ǯ� cin, cout �ӵ� ������
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		mp[s] = i + 1; //�̸��� Ű�� �ϰ�, �Է� ������ value�� ��
		mp2[i + 1] = s; //�Է� ������ Ű�� �ϰ�, �̸��� value�� ��
		a[i + 1] = s;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0) { //atoi()�� ���ڿ��� integer�� ��ȯ����. �̶� ��ȯ�� ���ڿ��� ���ڰ� �ƴҰ�� 0��ȯ
			//�̸����� �˻��� ���
			cout << mp[s] << "\n"; //�ش� �̸��� �ش��ϴ� ���� ��ȯ
		}
		else {
			//���ڷ� �˻��� ���
			//cout << mp2[atoi(s.c_str())] << "\n"; //�ش� ���ڿ� �ش��ϴ� �̸� ��ȯ
			cout << a[atoi(s.c_str())] << "\n"; //�� �ڵ�ó�� map�� Ȱ���Ͽ� �������� ��ȯ�ص� ������, ����->�̸� ��ȯ���� ��� �迭�� Ȱ���ϸ� O(1)�� ó�������ϹǷ� �� ȿ����

		}
	}
	//------------------------------------------------------------------------------------
	return 0;
	
}