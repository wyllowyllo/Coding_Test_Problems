#include <bits/stdc++.h>
using namespace std;



//--------------------------------------------My Solution -------------------------------------------------------------
// 
// �� ������ �ֿ� ���� : ���� ���� !! (100������ ���ڰ� �Էµ� ���, long long �� �ʰ��ϴ� ������ ������ ���� �� ���� -> string���� �����ؾ� ��!)
// sort�Լ��� Ŀ���� ���Լ� ����� �˱�!

/*
int n;
string input;
vector<string> ret;

bool cmp(string L1, string L2) {
	//���ڿ� �� -> ���̰� ���ٸ�, �ܼ� ũ�� ��. ���̰� �ٸ��ٸ�, ���̰� �� ��� ū ���̹Ƿ� ũ�� ��
	if (L1.size() == L2.size()) return L1 < L2;
	else return L1.size() < L2.size();
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			char c = input[j];
			if (!isdigit(c)) continue;
			else if (c == '0' && (j != input.size() - 1 && isdigit(input[j + 1]))) continue; //0�� ���ڿ� ���� �ְų�, 0�յڷ� ���ڰ� ������ �Է�, �ƴϸ� ����
			else {
				string num; int k;

				for (k = j; k < input.size(); k++) {
					if (!isdigit(input[k]))break;
					num += input[k];
				}
				ret.push_back(num);
				j = k - 1;
			}
		}


	}

	//Ŀ���� ���Լ� ������ sort
	//cmp�Լ��� ��� true�� �ߵ��� ret������
	sort(ret.begin(), ret.end(), cmp);

	for (auto i : ret) cout << i << '\n';

}*/
//-------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------Solution 1-------------------------------------------------------------

int n;
vector<string> v;
string s, ret;

void go() {
	while (true) {
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin()); //���ڿ� ũ�Ⱑ 1�̻��̰�, 0�� �� �տ� ���� ��� ������ ����
		else break;
	}
	if (ret.size() == 0) ret = "0"; // ���� 0000��� ���� ���� ���, ���� �ڵ忡�� 0�� ��� ������. ->0���� ����
	v.push_back(ret);
	ret = "";
}
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 65) ret += s[j]; //s[j]�� ������ ��� �߰�(�ƽ�Ű �ڵ� 65(A)����)
			else if (ret.size()) go(); //���� ������ ���, �������� �߰��� ret�� ���� ���(����) 0�����۾� ����
		}
		if (ret.size()) go();
	}
	sort(v.begin(), v.end(), cmp); //v�� ��� ��Ұ� cmp�� �����ϵ��� ����(cmp�� true�� �ߵ���)
	for (string i : v) cout << i << "\n";
}
