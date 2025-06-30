#include <bits/stdc++.h>
using namespace std;

namespace MySOl {
    vector<string> str;
    bool check(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(s[i]);
            else {
                if (stk.size() && stk.top() == '(') stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }

    string getBalanceString(string p) {

        if (check(p)) return p;

        int lCnt = 0, rCnt = 0;

        bool flag;
        string ret = "";
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '(') lCnt++;
            else rCnt++;

            if (lCnt == rCnt) {

                string s = p.substr(0, i + 1);
                if (check(s)) {
                    ret = s;
                    ret += getBalanceString(p.substr(i + 1));
                }

                else {
                    ret += "(";
                    ret += getBalanceString(p.substr(i + 1));
                    ret += ")";

                    s = s.substr(1, (int)(s.end() - s.begin()) - 2);

                    for (int i = 0; i < s.size(); i++) {
                        s[i] = ((s[i] == '(') ? ')' : '(');
                    }

                    ret += s;
                }

                break;
            }

        }

        return ret;
    }
    string solution(string p) {
        string answer = "";

        answer = getBalanceString(p);
        return answer;
    }
}

namespace Sol {
    bool check(string a) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false; //이 경우는 괄호 쌍이 안맞는 경우임
        }

        return cnt == 0;
    }

    string go(string a) {
        if (check(a)) return a;
        int i, cnt1 = 0, cnt2 = 0;

        for (i = 0; i < a.size(); i++) {
            if (a[i] == '(') cnt1++;
            else cnt2++;
            if (cnt1 == cnt2) break;
        }

        string b = a.substr(0, i + 1);
        string c = a.substr(i + 1, a.size() - (i + 1));

        if (check(b))
            return b + go(c);

        else {
            string ret = "";
            ret += '(';
            ret += go(c);
            ret += ')';

            b = b.substr(1, b.size() - 2);

            for (int i = 0; i < b.size(); i++) {
                if (b[i] == ')') ret += '(';
                else ret += ')';
            }
            return ret;
        }
    }

    string solution(string p) {
        string answer = go(p);
        return answer;
    }
    
}
