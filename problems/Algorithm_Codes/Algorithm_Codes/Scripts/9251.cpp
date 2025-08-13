//#include <bits/stdc++.h>
//using namespace std;
//
//string s1, s2;
//int cnt[1004];
//int offset[1004];
//int len;
//
//int main() {
//	cin >> s1 >> s2;
//
//	
//	for (int i = 0; i < s1.size(); i++) {
//		auto pos = s2.find(s1[i]);
//		if (pos == string::npos) continue;
//		cnt[i] = 1;
//		offset[i] = (int)(pos + 1);
//		len = max(len, cnt[i]);
//
//		for (int j = 0; j < i; j++) {
//			auto pos = s2.find(s1[i], offset[j]);
//			if (pos != string::npos) {
//
//				
//				
//				if (cnt[i] <cnt[j] + 1) {
//					
//					cnt[i] = cnt[j] + 1;
//					offset[i] = (int)(pos + 1);
//					len = max(len, cnt[i]);
//				}
//				
//			}
//			
//		}
//	}
//
//	cout << len << "\n";
//
//}