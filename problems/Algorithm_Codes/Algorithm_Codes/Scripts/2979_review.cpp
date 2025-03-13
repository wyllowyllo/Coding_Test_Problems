#include<bits/stdc++.h>
using namespace std;

int A, B, C;

#pragma region MySol
int truck_1[101];
int truck_2[101];
int truck_3[101];

pair<int, int > t1;
pair<int, int > t2;
pair<int, int > t3;

int cnt[101];
void Cal_Fee() {

	int total = 0;
	int fee;

	for (int i = t1.first; i < t1.second; i++) {
		truck_1[i] = 1;
	}
	for (int i = t2.first; i < t2.second; i++) {
		truck_2[i] = 1;
	}
	for (int i = t3.first; i < t3.second; i++) {
		truck_3[i] = 1;
	}

	for (int i = 1; i < 100; i++) {
		int count = truck_1[i] + truck_2[i] + truck_3[i];

		if (count == 1) fee = A;
		else if (count == 2) fee = B;
		else if (count == 3) fee = C;


		total += count * fee;
	}


	cout << total;
}
#pragma endregion

#pragma region Sol_1
void Sol_1() {
	int a, b;
	
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) { //시간은? a이상,b미만
			cnt[j]++;
		}
	}

	for (int i = 1; i < 100; i++) {
		if (cnt[i]) {
			if (cnt[i] == 1) ret += A;
			else if (cnt[i] == 2) ret += B * 2;
			else if (cnt[i] == 3) ret += C * 3;
		}
	}

	cout << ret << "\n";
}
#pragma endregion



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;

	/*cin >> t1.first >> t1.second;
	cin >> t2.first >> t2.second;
	cin >> t3.first >> t3.second;*/

	//Cal_Fee();
	Sol_1();
}