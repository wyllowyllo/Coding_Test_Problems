#include <bits/stdc++.h>
using namespace std;


int n, m, j;
int dist = 0;


int main() {

//-------------------------------------My Solution----------------------------------------------
	//int box_leftX, box_rightX;
	//int dropPos;

	//cin >> n >> m;
	//cin >> j;

	//box_leftX = 1;
	//box_rightX = box_leftX+(m-1);

	//while (j--) {
	//	cin >> dropPos;

	//	if (box_leftX >dropPos) { //�ڽ����� ���ʿ��� ������
	//	
	//		while (box_leftX >dropPos) {
	//			box_leftX--;
	//			box_rightX=box_leftX+ (m - 1);
	//			dist++;
	//		}
	//	}
	//	else if (box_rightX <dropPos) { //�ڽ����� �����ʿ��� ������
	//		while (box_rightX <dropPos) {
	//			box_rightX++;
	//			box_leftX = box_rightX- (m - 1);
	//			dist++;
	//		}
	//	}

	//	//���� ���� ��(����, ������ ��ǥ ����) ���� ����� �������ٸ� ���� �̵��� �ʿ� x
	//}

	//cout << dist << "\n";

//------------------------------------------------------------------------------------

//------------------------------------Solution 1--------------------------------------
	int l, r, temp;
	cin >> n >> m >> j;
	l = 1;
	for (int i = 0; i < j; i++) {
		r = l + (m - 1);

		cin >> temp;
		if (l <= temp && r >= temp) continue;
		if (temp < l) {
			dist += (l - temp);  //�Ÿ� ���̸�ŭ�� dist�� ���ϰ�
			l = temp; //�����̵� (���� �ݺ������� drop��ġ���� ������ ������, �� ����� �ð����⵵ ����)
		}
		else {
			dist += (temp - r);
			l += (temp - r);
		}
	}

	cout << dist << "\n";
}