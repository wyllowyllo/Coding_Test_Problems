#include <bits/stdc++.h>
using namespace std;

int n, k;
const int INF = 500001;
int visited[2][INF];


int t = 1;
bool flag;


// 수빈이와 동생이 만나는 경우는
//1. 같은 타임라인(t)에 수빈이와 동생이 동시에 이동했을 때 같은 지점에 도착해서 만나거나
//2. 수빈이가 동생보다 앞에 있고, 그 위치에서 계속 +1,-1하여 와리가리할때 동생이 나중에 도착해서 만나거나

//위의 생각을 가지고 로직을 짯는데, 내가 간과한 부분 -> 2번이 만족하려면, 타임라인(t)의 홀/짝이 맞아야 한다.
//예를들어 수빈이와 동생이 만날 어떤지점 p에 대해 수빈이가 t=홀수일때 p에 도착하면 동생도 t=홀수일때 도착해야하고, 짝수인 경우도 그러하다

//결론(내가 놓친 것 ) : 어느 위치 p에 홀수번째에 도착하는지, 짝수번째에 도착하는지를 모두 관리해야 한다.

int main() {
	cin >> n >> k;

	
	queue<int> q;
	vector<int> list;
	q.push(n);
	visited[0][n] = 1;
	
	if (n == k) {
		cout << 0 << "\n";
		return 0;
	}
	
	while (true) {

		k += t;

		if (k > 500000) {
			cout << -1 << "\n";;
			return 0;
		}

		//2번 케이스
		if (visited[t % 2][k]) { //수빈이가 동생에 올 곳에  먼저 도착한 경우(이때 홀짝이 맞음 -> 동생이 홀수 t에 도착하고 수빈도 홀수 t에 도착 or 동생이 짝수 t에 도착하고 수빈도 짝수 t에 도착)
			flag = true;
			break;
		}

		list.clear();
		
		while (q.size()) {
			int pos = q.front(); q.pop();


			for (int np : {pos - 1, pos + 1, pos * 2}) {
				if (np < 0 || np >= INF) continue;

				/*if (!visited[(t + 1) % 2][np]) { //같은 타임라인(t)에 동일한 위치를 큐에 또 push하는 경우를 막음
					visited[(t + 1) % 2][np] = visited[t % 2][pos] + 1;
					list.push_back(np);
				}

				//와리가리 치는 경우
				else if (visited[(t+1) % 2][np] < visited[t % 2][pos]+1) { //다시 돌아온 경우(이전에 방문했지만, 이후의 타임라인(t)에서 다시 방문)
					visited[(t+1) % 2][np] = visited[t % 2][pos] + 1;
					list.push_back(np);
				}*/

				// 타임라인을 짝/홀 구분하여 해당 위치 재방문(push)할 것인지 결정
				if (visited[t % 2][np]) continue;
				visited[t % 2][np] = visited[(t + 1) % 2][pos] + 1;

				//1번 케이스
				if (np == k) {
					flag = true;
					
					break;
				}
				list.push_back(np);

				
			}

		}
		if (flag) break;
		for (int i : list) {
			q.push(i);
		}
		
		t++;
	}

	if (!flag) cout << -1 << '\n';
	else cout << t  << "\n";
	

}

#pragma region Sol_1

void Sol_1() {
	int turn = 1;

	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		return;
	}

	queue<int> q;
	visited[0][n] = 1;
	q.push(n);

	while(q.size()) {
		k += turn;
		if (k >= INF) {
			flag = true;
			break;
		}
		if (visited[turn % 2][k]) {
			flag = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();

			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx < 0 || nx >= INF) continue;
				if (visited[turn % 2][nx]) continue;

				visited[turn % 2][nx] = visited[(turn+1) % 2][x] + 1;

				if (nx == k) {
					flag = true;
					break;
				}
				q.push(nx);
			}
			
		}
		if (flag) break;
		turn++;
	}
	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";
	return;
}
#pragma endregion
