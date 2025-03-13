

#include<bits/stdc++.h>
using namespace std;

#pragma region MySolution

//조합 문제(9개중 7개를 뽑았을 때, 그 합이 100이 되야 함)
	int n = 9, r = 7, total = 100;
	int tall[9];

	void PrintV(vector<int>& v) {
		sort(v.begin(), v.end());
		for (auto value : v) {
			cout << value << "\n";
		}

		exit(0);
	}
	void combi(int startIdx, int sum, vector<int>& v) {
		if (v.size() == r) {
			if (sum == total) {
				PrintV(v);
				return;
			}
			else {
				return;
			}
		}

		for (int j = startIdx + 1; j < n; j++) {
			v.push_back(tall[j]);
			sum += tall[j];

			combi(j, sum, v);

			v.pop_back();
			sum -= tall[j];
		}


	}

#pragma endregion


#pragma region Solution_1
	//순열을 활용한 풀이

	void Solution_1() {
		sort(tall, tall + 9); //next_permutation 사용 전 항상 오름차순 정렬!

		do {
			int sum = 0;
			for (int i = 0; i < 7; i++) sum += tall[i];

			if (sum == 100) break;
		} while (next_permutation(tall, tall + 9));


		for (int i = 0; i < 7; i++)
			cout << tall[i] << " ";
	}

#pragma endregion


#pragma region Solution_2
	//9C7 == 9C2
	//중첩 반복문으로 조합 구하기

	pair<int, int> Solve() {
		int all = 0;
		pair<int, int> ret;
		for (int i = 0; i < 9; i++) all += tall[i];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < i; j++) {
				if (all - tall[i] - tall[j] == 100) {
					ret = { tall[i],tall[j] };
					return ret;
				}
			}
		}

		return { -1,-1 };
	}
	void Solution_2() {

		
		auto v = Solve();
		vector<int> result;

		for (int i = 0; i < 9; i++) {
			if (tall[i] == v.first || tall[i] == v.second) continue;
			else result.push_back(tall[i]);
		}
		
		sort(result.begin(), result.end());
		for (auto v : result) {
			cout << v << "\n";
		}
	}
#pragma endregion

#pragma region Solution_3
	//순열을 사용하여 풀되, next_permutation 대신 재귀로 풀어보기

	void Print() {
		sort(tall, tall + 7);
		for (int i = 0; i < 7;i++) cout << tall[i] << "\n";

		exit(0);
	}
	void Swap(int idx1, int idx2) {
		int temp = tall[idx1];
		tall[idx1] = tall[idx2];
		tall[idx2] = temp;
	}
	void Get_Permutation(int n, int r, int depth) {
		if (depth == r) {
			int sum = 0;
			for (int i = 0; i < 7; i++) {
				sum += tall[i];
			}
			if (sum == 100) {
				Print();
				
			}
			return;
		}

		for (int i = depth; i < n; i++) {
			Swap(i, depth);
			Get_Permutation(n,r,depth+1);
			Swap(i, depth);
		}
	}
	void Solution_3() {
		Get_Permutation(9,7,0);
	}
#pragma endregion



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++)
		cin >> tall[i];

	/*vector<int> smallGuys;
	combi(-1, 0, smallGuys);*/

	//Solution_1();

	//Solution_2();

	//Solution_3();
}
