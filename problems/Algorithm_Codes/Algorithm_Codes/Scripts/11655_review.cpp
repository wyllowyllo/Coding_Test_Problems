#include <bits/stdc++.h>
using namespace std;

string input;

#pragma region MySol
void MySol() {
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i])) {
			if (input[i] <= 'Z') { //대문자
				if ((int)input[i] + 13 > 'Z') input[i] -= 13;
				else input[i] += 13;
			}
			else { //소문자
				if ((int)input[i] + 13 > 'z') input[i] -= 13;
				else input[i] += 13;
			}
		}
	}

	cout << input << "\n";
}
#pragma endregion

#pragma region Sol_1
void Sol_1() {
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 65 && input[i] < 97) {
			if (input[i] + 13 > 90) input[i] = input[i] + 13 - 26;
			else input[i] = input[i] + 13;
		}
		else if (input[i] >= 97 && input[i] <=122) {
			if (input[i] + 13 > 122) input[i] = input[i] + 13 - 26;
			else input[i] = input[i] + 13;
		}

		cout << input[i];
	}

	
	}
#pragma endregion



int main() {
	MySol();
}