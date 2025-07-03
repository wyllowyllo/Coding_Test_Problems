#include <bits/stdc++.h>

using namespace std;


namespace My {
    int solution(int n, vector<int> stations, int w)
    {
        int answer = 0;
        int idx = 0;
        int l, r;
        for (int i = 1; i <= n;) {

            if (idx >= stations.size()) {
                int dist = n - i + 1;
                answer += (int)ceil((double)dist / (2 * w + 1));

                break;
            }

            l = max(stations[idx] - w, 1);
            r = min(stations[idx] + w, n);

            if (l <= i && i <= r) { i = r + 1; continue; }
            else if (i > r) {
                idx++;
                continue;
            }
            else if (i < l) {
                int dist = l - i;
                answer += (int)ceil((double)dist / (2 * w + 1));
                i = r + 1;
            }
        }

        return answer;
    }
}

namespace Sol {
    int solution(int n, vector<int> stations, int w) {
        int prev = 0; //마지막으로 커버된 아파트의 위치
        int ret = 0;

        for (int station : stations) {
            int a = (station - w - 1) - prev;

            int b = (int)ceil(double(a) / (double)(w * 2 + 1));

            ret += max(0, b);

            prev = station + w;
        }

        ret += (int)ceil((double)(n - prev) / (double)(w * 2 + 1));

        return ret;
    }
}
