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

	//	if (box_leftX >dropPos) { //박스보다 왼쪽에서 떨어짐
	//	
	//		while (box_leftX >dropPos) {
	//			box_leftX--;
	//			box_rightX=box_leftX+ (m - 1);
	//			dist++;
	//		}
	//	}
	//	else if (box_rightX <dropPos) { //박스보다 오른쪽에서 떨어짐
	//		while (box_rightX <dropPos) {
	//			box_rightX++;
	//			box_leftX = box_rightX- (m - 1);
	//			dist++;
	//		}
	//	}

	//	//상자 범위 내(왼쪽, 오른쪽 좌표 사이) 에서 사과가 떨어진다면 상자 이동할 필요 x
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
			dist += (l - temp);  //거리 차이만큼을 dist에 더하고
			l = temp; //순간이동 (나는 반복문으로 drop위치까지 가도록 했지만, 이 방법이 시간복잡도 낮음)
		}
		else {
			dist += (temp - r);
			l += (temp - r);
		}
	}

	cout << dist << "\n";
}