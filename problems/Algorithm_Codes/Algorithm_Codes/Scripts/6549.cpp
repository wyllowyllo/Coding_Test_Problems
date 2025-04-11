#include <bits/stdc++.h>
using namespace std;


//idea : 특정 막대 하나로부터 양옆으로 최대한 확장해나가며 가장 큰 사각형을 찾는다
//그러나 brutForce로는 불가능(n*n의 시간복잡도)

//idea 2 : 모노톤 스택을 활용(top 보다 더큰 or 더 작은 막대 발견하기)
//그래프를 왼쪽에서부터 오른쪽으로 스캔해나간다
//1.만약 스택의 top보다 현재 스캔하는 막대기가 더 크다면 push (더 큰 막대기가 오른쪽에 있다면, 왼쪽에서부터 사각형을 만들 때 더 크게 만들 수 있는 가능성이 있기 때문)
//2. 만약 스택의 top보다 현재 스캔하는 막대기가 더 작다면 pop시작(왜냐하면, 더 작은 막대기가 오른쪽에 생기기 시작한 그 시점부터는 더 이상 왼쪽에서부터 사각형 만들때 더 크게 만들 수 있는 가능성이 이제는 없기 때문(분기점이 됨))

int n;
int h[100001];
typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n;
		if (n == 0) break;

		vector<int> sticks;
		int temp;
		ll ret=0;
		memset(h, 0, sizeof(h));

		for (int i = 0; i < n; i++) {
			cin >> temp;

			sticks.push_back(i); //인덱스 저장
			h[i] = temp; //높이 저장
		}

		stack<int> stk;
		for (int i = 0; i <=n; i++) { //n 포함하는 이유? 4 1000 1000 1000 와 같이 1000이후 더 작은 거 안들어오고 끝나는 경우, h[n]==0이므로 이를 이용하여 이전까지의 스틱을 통한 사각형 계산함
			if (stk.size() && h[stk.top()] > h[i]) { //더 작은 막대 발견

				//pop시작
				while (!stk.empty() && h[stk.top()] > h[i]) {
					ll height = h[stk.top()];
					stk.pop();

					ll width;

					if (stk.empty()) width = i;
					else  width = i - stk.top() - 1;
					
					ret = max(ret, width * height);
				}
			}

			stk.push(i);
		}

		cout << ret << "\n";


	}
}