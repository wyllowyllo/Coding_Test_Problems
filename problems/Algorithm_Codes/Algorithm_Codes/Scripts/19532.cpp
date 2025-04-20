#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

float mat[2][2];
float ret[2][1];
float sol[2][1];

void Sol_1() {
	//그냥 단순 반복으로도 될거같긴한데, 행렬식배운거 써먹어보자
	cin >> a >> b >> c >> d >> e >> f;

	mat[0][0] = e;
	mat[0][1] = -b;
	mat[1][0] = -d;
	mat[1][1] = a;
	ret[0][0] = c;
	ret[1][0] = f;



	float f = (a * e) - (b * d);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			mat[i][j] /= f;
		}
	}

	sol[0][0] = (mat[0][0] * ret[0][0]) + (mat[0][1] * ret[1][0]);
	sol[1][0] = (mat[1][0] * ret[0][0]) + (mat[1][1] * ret[1][0]);

	cout << round(sol[0][0]) << " " << round(sol[1][0]) << "\n";

}

void Sol_2() {
	cin >> a >> b >> c >> d >> e >> f;
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			int cal_1 = (a * i) + (b * j);
			int cal_2 = (d * i) + (e * j);

			if (cal_1 == c && cal_2 == f) {
				cout << i << " " << j;
				exit(0);
			}
		}
	}
}

int main() {
	Sol_1();
	//Sol_2();
}