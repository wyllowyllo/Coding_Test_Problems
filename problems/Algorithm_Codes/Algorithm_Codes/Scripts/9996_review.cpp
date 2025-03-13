#include <bits/stdc++.h>
using namespace std;

int n;
string pattern;
string first, last;
string input;

#pragma region MySol

void Split() {
	int start = 0;
	int end = pattern.find("*");

	first = pattern.substr(start, end - start);
	last = pattern.substr(end + 1);
}

void MySol() {
	Split();

	while (n--) {
		cin >> input;

		if (input.size() < first.size() + last.size()) {
			cout << "NE" << "\n";
			continue;
		}


		if (first == "" || input.substr(0, first.size()) == first) {

			int idx = input.size() - last.size();
			if (last == "" || input.substr(idx) == last) {
				cout << "DA" << "\n";
			}
			else {
				cout << "NE" << "\n";
			}
		}
		else {
			cout << "NE" << "\n";
		}




	}
}
#pragma endregion

#pragma region Sol_1
void Sol_2() {
	int pos = pattern.find("*");
	string pre = pattern.substr(0, pos);
	string suf = pattern.substr(pos + 1);

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (pre.size() + suf.size() > input.size()) {
			cout << "NE" << "\n";
		}
		else {
			if (pre == input.substr(0, pre.size()) && suf == input.substr(input.size() - suf.size()))
			{
				cout << "DA" << "\n";
			}

		}
	}
}
#pragma endregion




int main() {
	cin >> n;
	cin >> pattern;

	
}