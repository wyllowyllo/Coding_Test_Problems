#include <bits/stdc++.h>
using namespace std;


#pragma region 재귀로 Permutation 구하기
    //기본적으로 순열을 구한다는 것은, {1,2,3}등의 수열이 있을 때, {1,3,2} 이런식으로 원소간 순서를 바꿔나가며 총 경우의 수를 구하는 것
    //따라서 재귀를 통해 원소간 순서를 계속 바꿔나가며 순열을 구할 수 있다

vector<int> v = { 1,2,3 };

void printV(vector<int>* v) {
    for (int i : *v) cout << i << ", ";
    cout << "\n";
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Make_Permutation(int n, int r, int depth) {

    if (depth == r) {
        printV(&v);
        return;
    }

    for (int i = depth; i < n; i++) {
        Swap(&v[i], &v[depth]);
        Make_Permutation(n, r, depth + 1);
        Swap(&v[i], &v[depth]);
    }
}
int main() {
    
    Make_Permutation(3, 3, 0);

}
#pragma endregion

