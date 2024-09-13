#include <bits/stdc++.h>
using namespace std;

string name;
map<char, int> alphaMap; //�̸� �� �� ���ĺ� ���� ����� ��

int cnt[200]; //map ��� count�迭 �����Ͽ� ���� �ذ��� ���� ����(solution 1)

int main() {
	cin >> name;

	//-------------------------------------My Solution--------------------------------------------
	for (int i = 0; i < name.length(); i++) {
		alphaMap[name[i]]++;
	}

	int startIdx = 0;
	int endIdx = name.length() - 1;
	int midIdx = (startIdx + endIdx) / 2;

	if (name.length() % 2 == 0) { //�� ���̰� ¦��
		for (auto alpha : alphaMap) {
			if (alpha.second % 2 != 0) { //¦�����̿��� �� ���ĺ� ������ ¦������ �ƴϸ� �Ӹ���� ���� x
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}
			else {
				while (alpha.second > 0) {
					name[startIdx++] = alpha.first;
					name[endIdx--] = alpha.first;
					alpha.second-= 2;
				}
			}
		}
	}
	else { //�� ���̰� Ȧ��
		char midIdxC = NULL;
		for (auto alpha : alphaMap) {
			if (alpha.second % 2 != 0) { 
				if (midIdxC == NULL) { //Ȧ������ ���ĺ��� �� �ϳ��� ������, �� �ܾ� �ϳ����� �߾����� �̵�. �������ϰ�� �Ӹ���� ���� x
					midIdxC = alpha.first;
					alpha.second--;
				}
				else {
					cout << "I'm Sorry Hansoo" << "\n";
					return 0;
				}
			}
				while (alpha.second > 0) {
					name[startIdx++] = alpha.first;
					name[endIdx--] = alpha.first;
					alpha.second -= 2;
				}
			
		}
		name[midIdx] = midIdxC; //�߾ӿ� Ȧ������ ���ĺ��̵�
	}

	cout << name << "\n";

	//-------------------------------------------------------------------------------------

	//---------------------------------Solution 1-----------------------------------------

	//Ȧ������ ���� ������ 2�� �̻��̸� �Ӹ������ �������� ���ϴ� ���� Ȱ��.
	char mid;
	int flag;
	string ret;
	for (char a : name) cnt[a]++;
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) //��Ʈ��ȯ�ҽ� ¦���� 11..0, Ȧ���� 11..1 �̷������� �����Ƿ�, Ȧ����� �ش� ������ true�� �ȴ�.
			{
				mid = char(i); flag++;
				cnt[i]--;
			}
			if (flag == 2) break; //Ȧ������ ���ڰ� 2�� �̻���

			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret; //ret�տ� ���� ���̱�
				ret += char(i); //ret �ڿ� ���� ���̱�
			}
		}
	}
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid); //�߾ӿ� ����
	if (flag == 2) cout << "I'm Sorry Hanson\n";
	else cout << ret << "\n";

	//----------------------------------------------------------------------------------
	return 0;
}