
#include <bits/stdc++.h>


using namespace std;

void Make_Permutation(int n, int r, int depth, int&count);
void Swap(int& a, int& b);


vector<int> a = { 2,1,3,100,200 };


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

	int count = 0;
	Make_Permutation(5, 3, 0, count); //n, r, depth(current_state)
	cout << "총 개수 : " << count;
}

int main() {
	

	//Permutation_Sol_1();
	Permutation_Sol_2();
	

}




void Make_Permutation(int n, int r, int depth, int &count) {
	if (r == depth) {
		for (int i = 0; i < r; i++)
			cout << a[i] << " : ";
		cout << '\n';
		count++; //순열 종류(개수) 추가
		return;
	}
		

	//DFS
	for (int i = depth; i < n; i++) {
		Swap(a[i], a[depth]);
		Make_Permutation(n, r, depth + 1, count);
		Swap(a[i], a[depth]);
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}