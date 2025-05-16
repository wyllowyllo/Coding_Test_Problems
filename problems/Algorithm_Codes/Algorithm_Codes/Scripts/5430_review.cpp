#include <bits/stdc++.h>
using namespace std;

int t, n;
string p;
string x;

deque<int> v;
bool flag;
bool state;

int main() {
	cin >> t;
	while (t--)
	{
		cin >> p;
		cin >> n;
		cin >> x;

		v.clear();
		flag = false;
		state = false;


		int num = 0;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] == '[') continue;
			if (x[i] == ',' || x[i] == ']') {
				if (num > 0) {
					v.push_back(num);
					num = 0;
				}

			}
			else {
				num *= 10;
				num += x[i] - '0';
			}

		}



		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				state = !state;
			}
			else {
				if (v.empty()) { flag = true; break; }

				if (state) v.pop_back();
				else v.pop_front();
			}
		}

		if (flag) cout << "error\n";
		else {

			if (state) reverse(v.begin(), v.end());


			cout << "[";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i < v.size() - 1){
					cout << ",";
				}
			}
			cout << "]\n";
			
		}


	}
}