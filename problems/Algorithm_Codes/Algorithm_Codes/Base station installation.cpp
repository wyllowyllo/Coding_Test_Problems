#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int idx = 0;
    int l, r;
    for (int i = 1; i <= n;) {

        if (idx >= stations.size()) {
            int dist = n - i;
            answer += (int)ceil((double)dist / (2 * w));
           
            break;
        }

        l = max(stations[idx] - w,0);
        r = min(stations[idx] + w, n);

        if (l <= i && i <= r) { i++; continue; }
        else if (i > r) {
            idx++;
            continue;
        }
        else if (i < l) {
            int dist = l - i;
            answer += (int)ceil((double)dist / (2*w));
            i = r+1;
        }
    }

    return answer;
}