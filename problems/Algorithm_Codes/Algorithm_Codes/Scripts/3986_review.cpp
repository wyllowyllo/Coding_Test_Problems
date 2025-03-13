#include <bits/stdc++.h>
using namespace std;


int n;
int cnt = 0;
string word;


int main() {
	cin >> n;

	while (n--) {
		stack<char> s;
		

		cin >> word;
		for (char c : word) {
			if (!s.empty() && s.top() == c) {
				s.pop();
			}
			else s.push(c);
			
		}

		if (s.empty()) cnt++;
		
	}

	cout << cnt << "\n";
}