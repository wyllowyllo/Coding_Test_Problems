
#include <bits/stdc++.h>


using namespace std;

void Make_Permutation(int n, int r, int depth);
void Swap(int& a, int& b);


vector<int> a = { 2,1,3,100,200 };
int b[] = {1,2,3};


void Permutation_Sol_1() {
	//Solution 1 , nPr 결과 생성하기
	sort(a.begin(), a.end());

	do {
		for (int i = 0; i < 2; i++)
			cout << a[i] << " ";
		cout << "\n";
	} while (next_permutation(a.begin(), a.end())); //오름차순 순열 생성


}
void Permutation_Sol_2() {
	//Solution 2 , nPr 결과 생성하기

	Make_Permutation(3, 3, 0); //n, r, depth(current_state)
}

int main() {
	

	Permutation_Sol_1();
	//Permutation_Sol_2();
	

}



void Make_Permutation(int n, int r, int depth) {
	if (r == depth) {
		for (int i = 0; i < r; i++)
			cout << b[i] << " : ";
		cout << '\n';
		return;
	}
		

	//DFS
	for (int i = depth; i < n; i++) {
		Swap(b[i], b[depth]);
		Make_Permutation(n, r, depth + 1);
		Swap(b[i], b[depth]);
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}