#include <bits/stdc++.h>
using namespace std;

int n, m, j;

#pragma region MySol

queue<int> dropPos;
int dist = 0;

void MoveCarrier(int left, int right) {
	while (dropPos.size()) {
		int pos = dropPos.front(); dropPos.pop();

		if (pos > right) {
			//처음에 고안한 방법 : 바구니 한칸씩 이동
			/*for (int i = right; i < pos; i++) {

				left += 1;
				right += 1;
				dist++;
			}*/

			//두번째 고안한 방법 : 굳이 바구니 위치 움직일 필요없이, 거리 차만큼을 dist에 더함
			dist += pos - right;
			right = pos;
			left = right - m + 1;
		}
		else if (left > pos) {
			//처음에 고안한 방법 : 바구니 한칸씩 이동
			/*for (int i = left; i > pos; i--) {

				left -= 1;
				right -= 1;
				dist++;


			}*/

			//두번째 고안한 방법 : 굳이 바구니 위치 움직일 필요없이, 거리 차만큼을 dist에 더함
			dist += left - pos;
			left = pos;
			right = left + m - 1;
		}

	}
}

void MySol() {
	int v;
	for (int i = 0; i < j; i++) {
		cin >> v;
		dropPos.push(v);
	}
	MoveCarrier(1, 1 + m - 1);
	cout << dist << "\n";
}
#pragma endregion

#pragma region Sol_1
//나는 처음에 왼쪽좌표, 오른쪽좌표를 정의하고, 바구니를 옮길때 그 둘을 업데이트하는방식으로 함
//여기서는 l 기준으로, 바구니를 옮길때마다 r을 새로 정의함
//바구니 크기는 m이고, 사과를 담을 수 있는 범위 term은 l<=term<=r이다. 
//이때 사과를 담을 수 있는 범위 term은 곧 바구니 크기 m이므로, l <= m <= r
//따라서 m = r - l +1 이고, r = m+l-1 이다
void Sol_1() {
	int l = 1;
	int r;
	int temp;
	int ret = 0;

	for (int i = 0; i < j; i++) {
		r = l + m - 1;
		cin >> temp;

		if (temp >= l && temp <= r) continue;
		else {
			if (temp < l) {
				ret += (l - temp);
				l = temp;
			}
			else {
				l += (temp - r);
				ret += (temp - r);
			}
		}

		cout << ret << "\n";
	}
}

#pragma endregion


int main() {
	cin >> n >> m;
	cin >> j;


}